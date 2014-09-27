%打开dicom图像
clear;
close all;
I=dicomread('dicomfile.dcm'); 
X=double(I);
%A=25*I;
%imshow(A);
%[]将自动选择一个参数进行归一化处理来显示一幅图像。
%imshow(I,[]);
info=dicominfo('dicomfile.dcm');
wincenter=info.WindowCenter;
winwidth=info.WindowWidth;
width=info.Width;
height=info.Height;
D=zeros(height,width);
for i=1:height
    for j=1:width
        if X(i,j)>(wincenter+winwidth/2)
            D(i,j)=254;
        elseif X(i,j)<(wincenter-winwidth/2)
            D(i,j)=1;
        else
            D(i,j)=(X(i,j)-(wincenter-winwidth /2))*256/winwidth;
        end;
    end;
end;
%D=D/255;
E=D/255;
figure;
imshow(uint8(D));
title(' 原始图像 ');

%自适应中值滤波去噪方法
salt=imnoise(E,'salt & pepper',0.25);    %椒盐噪声密度0.25
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
[method2,cxd,sxd,perf0,perf12]=wdencmp('lvd',c,s,'sym4',3,thr3,'s');   %sym8小波信噪比会更高
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
temp1=0;temp2=0;
for i=1:height
    for j=1:width
        temp1=temp1+gaussian(i,j)*gaussian(i,j);
        temp2=temp2+(gaussian(i,j)-D(i,j))*(gaussian(i,j)-D(i,j));
    end;
end;
SNR1=10*log10(double(temp1))-10*log10(double(temp2));
P1=10*log10(double(temp2));
PSNR1=10*log10(255*255)+10*log10(double(height*width))-P1;    %高斯噪声
temp1=0;temp2=0;
for i=1:height
    for j=1:width
        temp1=temp1+method2(i,j)*method2(i,j);
        temp2=temp2+(method2(i,j)-D(i,j))*(method2(i,j)-D(i,j));
    end;
end;
SNR2=10*log10(double(temp1))-10*log10(double(temp2));
P2=10*log10(double(temp2));
PSNR2=10*log10(255*255)+10*log10(double(height*width))-P2;      %小波去噪
temp1=0;temp2=0;
for i=1:height
    for j=1:width
        temp1=temp1+method3(i,j)*method3(i,j);
        temp2=temp2+(method3(i,j)-D(i,j))*(method3(i,j)-D(i,j));
    end;
end;
SNR3=10*log10(double(temp1))-10*log10(double(temp2));
P3=10*log10(double(temp2));
PSNR3=10*log10(255*255)+10*log10(double(height*width))-P3;    %各向异性去噪

temp1=0;
for i=1:height
    for j=1:width
        if method1(i,j)==E(i,j)
            temp1=temp1+1;
        end;
    end;
end;
d=double(temp1/height);
density=1-d/double(width);                                  %自适应中值滤波噪声密度

temp1=0;
for i=1:height
    for j=1:width
        if medfilt2(i,j)==E(i,j)
            temp1=temp1+1;
        end;
    end;
end;
 d1=double(temp1/height);
density1=1-d1/double(width);                            %普通中值滤波噪声密度

temp1=0;temp2=0;
for i=1:height
    for j=1:width
        temp1=temp1+salt(i,j)*salt(i,j);
        temp2=temp2+(salt(i,j)-E(i,j))*(salt(i,j)-E(i,j));
    end;
end;
SNR4=10*log10(double(temp1))-10*log10(double(temp2));
P4=10*log10(double(temp2));
PSNR4=10*log10(255*255)+10*log10(double(height*width))-P4;        %椒盐噪声图像

temp1=0;temp2=0;
for i=1:height
    for j=1:width
        temp1=temp1+medfilt2(i,j)*medfilt2(i,j);
        temp2=temp2+(medfilt2(i,j)-E(i,j))*(medfilt2(i,j)-E(i,j));
    end;
end;
SNR5=10*log10(double(temp1))-10*log10(double(temp2));
P5=10*log10(double(temp2));
PSNR5=10*log10(255*255)+10*log10(double(height*width))-P5;        %普通中值滤波

temp1=0;temp2=0;
for i=1:height
    for j=1:width
        temp1=temp1+method1(i,j)*method1(i,j);
        temp2=temp2+(method1(i,j)-E(i,j))*(method1(i,j)-E(i,j));
    end;
end;
SNR6=10*log10(double(temp1))-10*log10(double(temp2));
P6=10*log10(double(temp2));
PSNR6=10*log10(255*255)+10*log10(double(height*width))-P6;       %自适应中值滤波

disp('含椒盐噪声图像信噪比');disp(SNR4);
disp('含椒盐噪声图像峰值信噪比');disp(PSNR4);
disp('自适应中值滤波去噪后图像信噪比');disp(SNR6);
disp('自适应中值滤波去噪后图像峰值信噪比');disp(PSNR6);
disp('自适应中值滤波去噪后图像噪声密度');disp(density);
disp('中值滤波去噪后图像信噪比');disp(SNR5);
disp('中值滤波去噪后图像峰值信噪比');disp(PSNR5);
disp('中值滤波去噪后图像噪声密度');disp(density1);
disp('含高斯噪声图像信噪比');disp(SNR1);
disp('含高斯噪声图像峰值信噪比');disp(PSNR1);
disp('小波去噪后图像信噪比');disp(SNR2);
disp('小波去噪后图像峰值信噪比');disp(PSNR2);
disp('各向异性去噪后图像信噪比');disp(SNR3);
disp('各项异性去噪后图像峰值信噪比');disp(PSNR3);
