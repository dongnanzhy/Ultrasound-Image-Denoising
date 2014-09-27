function f=adpmedian(g,Smax)
%adpmedian  Perform adaptive median filtering
%首先判断smax是否符合要求：smax应该是大于1的奇数
if    ((Smax<=1)||(Smax/2==round(Smax/2))||(Smax~=round(Smax)))
    error('SMAX must be an odd integer>1 .')
end
%[M,N]=size(g);
%初始化
f=g;
f(:)=0;
alreadyProcessed=false(size(g));
%开始滤波
for k=3:2:Smax
%相当于k×k的极小值滤波
    zmin=ordfilt2(g,1,ones(k,k),'symmetric');
%相当于k×k的极大值滤波
    zmax=ordfilt2(g,k*k,ones(k,k),'symmetric');
%相当于k×k的中值滤波
    zmed=medfilt2(g,[k,k],'symmetric');
%判断Z med是否为一脉冲
    processUsingLevelB=(zmed>zmin) & (zmax>zmed) & ~alreadyProcessed;
%判断Z x，y是否为一脉冲
    zB=(g<zmin) & (zmax>g);
    outputZxy=processUsingLevelB & zB;
    outputZmed=processUsingLevelB & ~zB;
%输出一个不变的像素值Z x，y来代替邻域中值作为输出
    f(outputZxy)=g(outputZxy);
%输出中值滤波的值作为输出
    f(outputZmed)=zmed(outputZmed);
    alreadyProcessed=alreadyProcessed|processUsingLevelB;
    if all(alreadyProcessed(:))
        break;
    end
end




