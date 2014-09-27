clear;
close all;
I=dicomread('dicomfile.dcm'); 
X=double(I);
%A=25*I;
%imshow(A);
subplot(1,2,1);
%[]将自动选择一个参数进行归一化处理来显示一幅图像。
imshow(I,[]); title('直接打开dicom');
info=dicominfo('dicomfile.dcm');
wincenter=info.WindowCenter;
winwidth=info.WindowWidth;
width=info.Width;
height=info.Height;
A=zeros(height,width);
for i=1:height
    for j=1:width
        if X(i,j)>(wincenter+winwidth/2)
            A(i,j)=255;
        elseif X(i,j)<(wincenter-winwidth/2)
            A(i,j)=0;
        else
            A(i,j)=(X(i,j)-(wincenter-winwidth /2))*256/winwidth;
        end;
    end;
end;
%A=(I-(wincenter-width /2))*(255 /winwidth );
%imshow(A);
disp('wincenter=');disp(wincenter);
disp('winwidth=');disp(winwidth);
disp('width=');disp(width);
disp('height=');disp(height);
%A=A*255;
A=A/255;   %归一化
subplot(1,2,2);
imshow(A);title('通过窗位窗宽打开dicom');