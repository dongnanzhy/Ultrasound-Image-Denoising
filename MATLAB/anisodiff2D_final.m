clear;
%I=imread('lady.bmp');
I=dicomread('dicomfile.dcm'); 
X=double(I);
%A=25*I;
%imshow(A);
%[]将自动选择一个参数进行归一化处理来显示一幅图像。
%imshow(I,[]); title('直接打开dicom');
info=dicominfo('dicomfile.dcm');
wincenter=info.WindowCenter;
winwidth=info.WindowWidth;
width=info.Width;
height=info.Height;
D=zeros(height,width);
for i=1:height
    for j=1:width
        if X(i,j)>(wincenter+winwidth/2)
            D(i,j)=255;
        elseif X(i,j)<(wincenter-winwidth/2)
            D(i,j)=0;
        else
            D(i,j)=(X(i,j)-(wincenter-winwidth /2))*256/winwidth;
        end;
    end;
end;
%A=(I-(wincenter-width /2))*(255 /winwidth );
%imshow(A);
disp('wincenter=');disp(wincenter);
disp('winwidth=');disp(winwidth);
disp('width=');disp(width);
disp('height=');disp(height);
figure;
imshow(uint8(D));title('原始图像');

init = 2055615866; randn('seed',init);
A = D + 30*randn(size(D));
figure;
imshow(uint8(A));
title(' 含噪图像 ');

%s = phantom(512) + randn(512);
   num_iter = 15;
   delta_t = 1/7;
   kappa = 30;
   option = 2;
   ad = anisodiff2D(A,num_iter,delta_t,kappa,option);
   figure;
   imshow(uint8(ad));
   title(' 降噪后图像 ');