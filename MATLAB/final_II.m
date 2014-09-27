%打开dicom图像
clear;
close all;
I=imread('ultrasound.bmp'); 
D=double(I);
figure;
imshow(uint8(D));
title(' 原始图像 ');

%自适应中值滤波去噪方法
salt=imnoise(I,'salt & pepper',0.25);    %椒盐噪声密度0.25
figure;
subplot(1,2,1);
imshow(salt);
title(' 加椒盐噪声图像 ');
%对加噪声图像进行中值滤波，滤波窗口[7 7]
medfilt2=Medfilt2(salt,[7 7],'symmetric');
subplot(1,2,2);
imshow(medfilt2);
title(' 普通中值滤波去噪图像 ');
%对加噪声图像进行自适应中值滤波，滤波最大窗口[7 7]
method1=adpmedian(salt,7);
figure;
imshow(method1);
title(' 自适应中值滤波去噪图像');

%小波变换阈值去噪方法
init = 2055615866; randn('seed',init);
gaussian = D + 20*randn(size(D));                %随机噪声标准差20
figure;
subplot(1,2,1);
imshow(uint8(gaussian));
title(' 含高斯噪声图像 ');
[thr,sorh,keepapp]=ddencmp('den','wv',gaussian);
%disp('thr=');disp(thr);
wavelet=wdencmp('gbl',gaussian,'sym4',2,thr,sorh,keepapp);   %sym8小波信噪比会更高
subplot(1,2,2);
imshow(uint8(wavelet));
title('小波变换降噪后图像');
%对图像进行3层二维小波分解
[c,s]=wavedec2(gaussian,3,'sym4');                                    %sym8小波信噪比会更高
[thr3,nkeep3]=wdcbm2(c,s,1.5,2.7*prod(s(1,:)));
%disp('thr3=');disp(thr3);
%disp('nkeep3=');disp(nkeep3);
[method2,cxd,sxd,perf0,perf12]=wdencmp('lvd',c,s,'sym8',3,thr3,'s');   %sym8小波信噪比会更高
figure;
imshow(uint8(method2));
title('使用分层阈值降噪图像');

%各向异性去噪方法
num_iter = 15;
delta_t = 1/7;
kappa = 30;
option = 2;
method3 = anisodiff2D(gaussian,num_iter,delta_t,kappa,option);
figure;
imshow(uint8(method3));
title(' 各向异性降噪后图像 ');

%性能测试
%两组降噪图像同原图像的误差
err1=norm(wavelet-D);
err2=norm(method2-D);
%求保留的能量成分
per1=norm(wavelet)/norm(gaussian);
per2=norm(method2)/norm(gaussian);
disp('err1=');disp(err1);
disp('err2=');disp(err2);
disp('per1=');disp(per1);
disp('per2=');disp(per2);
%降噪后图像和降噪前图像信噪比

