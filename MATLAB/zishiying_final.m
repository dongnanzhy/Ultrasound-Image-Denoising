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
A=zeros(height,width);
for i=1:height
    for j=1:width
        if X(i,j)>(wincenter+winwidth/2)
            A(i,j)=254;
        elseif X(i,j)<(wincenter-winwidth/2)
            A(i,j)=1;
        else
            A(i,j)=(X(i,j)-(wincenter-winwidth /2))*256/winwidth;
        end;
    end;
end;
A=A/255;
figure;
imshow(A);
B=imnoise(A,'salt & pepper',0.25);
figure;
imshow(B);
%对加噪声图像进行中值滤波，滤波窗口[7 7]
C=Medfilt2(B,[7 7],'symmetric');
figure;
imshow(C);
%对加噪声图像进行自适应中值滤波，滤波最大窗口[7 7]
D=adpmedian(B,7);
figure;
imshow(D);

temp1=0;
for i=1:height
    for j=1:width
        if C(i,j)==A(i,j)
            temp1=temp1+1;
        end;
    end;
end;
% density1=double((height*width-temp1))/double((height*width));    %
 d1=double(temp1/height);
density1=1-d1/double(width);
% density1=d1/width ;   %
 
temp1=0;
for i=1:height
    for j=1:width
        if D(i,j)==A(i,j)
            temp1=temp1+1;
        end;
    end;
end;
 d2=double(temp1/height);
density2=1-d2/double(width);

temp1=0;temp2=0;
for i=1:height
    for j=1:width
        temp1=temp1+B(i,j)*B(i,j);
        temp2=temp2+(B(i,j)-A(i,j))*(B(i,j)-A(i,j));
    end;
end;
SNR3=10*log10(double(temp1))-10*log10(double(temp2));
P3=10*log10(double(temp2));
PSNR3=10*log10(255*255)+10*log10(double(height*width))-P3;    %

temp1=0;temp2=0;
for i=1:height
    for j=1:width
        temp1=temp1+C(i,j)*C(i,j);
        temp2=temp2+(C(i,j)-A(i,j))*(C(i,j)-A(i,j));
    end;
end;
SNR1=10*log10(double(temp1))-10*log10(double(temp2));
P1=10*log10(double(temp2));
PSNR1=10*log10(255*255)+10*log10(double(height*width))-P1;    %

temp1=0;temp2=0;
for i=1:height
    for j=1:width
        temp1=temp1+D(i,j)*D(i,j);
        temp2=temp2+(D(i,j)-A(i,j))*(D(i,j)-A(i,j));
    end;
end;
SNR2=10*log10(double(temp1))-10*log10(double(temp2));
P2=10*log10(double(temp2));
PSNR2=10*log10(255*255)+10*log10(double(height*width))-P2;    %

disp('噪图像信噪比');disp(SNR3);
disp('噪图像峰值信噪比');disp(PSNR3);

disp('自适应中值滤波去噪后图像信噪比');disp(SNR2);
disp('自适应中值滤波去噪后图像峰值信噪比');disp(PSNR2);
disp('自适应中值滤波去噪后图像噪声密度');disp(double(density2));

disp('中值滤波去噪后图像信噪比');disp(SNR1);
disp('中值滤波去噪后图像峰值信噪比');disp(PSNR1);
disp('中值滤波去噪后图像噪声密度');disp(density1);