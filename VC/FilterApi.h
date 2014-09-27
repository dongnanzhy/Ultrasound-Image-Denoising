//FilterApi.h

#ifndef _FILTERAPI_H_
#define _FILTERAPI_H_
//////////////////////////////////////////////////////////////////////////////////////////////
/*
*
*	功能：寻找中位值
*
*/
/*
double FindMedianValue(double* lpbArray, int iArrayLen);
*/
/*
*
*	功能：中值滤波
*
*/
/*
BOOL MedianFilter(HDIB hDIB,	double* lpDIBBits, int iFilterH, int iFilterW, int iFilterCX, 
						 int iFilterCY);
*/
//////////////////////////////////////////////////////////////////////////////////////////////

/*
*
*	功能：快速排序法中一次排序
*
*/
int Partition(int* L, int low, int high);

/*
*
*	功能：快速排序法
*
*/
void QSort (double* L, int low, int high);

/*
*
*	功能：求小波系数的中位值
*
*/
double MedianCoeff(double* coeff, int h, int w);

/*
*
*	功能：取得一个数的符号
*
*/
int GetSgn(int number);

/*
* 函数名：GetThreshold
*
* 功能：求噪声方差、阈值
*
* 参数：
* @param coeff 取阈值的区域矩阵（如：小波系数的高频区域）
* @param cHeight 行数（输入矩阵高度）
* @param cWidth 列数（输入矩阵宽度）
* @param type 阈值公式类别（0为sqrt(2*log(n))*q，
*							1为0.3*sqrt(2*log(n))*q，
*							2为sqrt(2*log(n)/n)*q，
*							3为3*q，
*							其中q为噪声方差，log为自然对数）
*
* 输入：coeff
*
* 输出：return
*
* 返回值：阈值
*/
double GetThreshold(double* coeff, int h, int w, int type/* =1*/);

/*
* 函数名：SoftThreshold
*
* 功能：用输入的阈值使用软阈值方法对输入的矩阵切分
*
* 参数：
* @param coeff 输入矩阵（如：小波系数的高频区域）
* @param cHeight 行数（输入矩阵高度）
* @param cWidth 列数（输入矩阵宽度）
* @param threshold 阈值
* @param staticHeight 图像固定高度（一般同mHeight）
* @param staticWidth 图像的固定宽度（一般同mWidth）
*
* 输入：coeff
*
* 输出：coeff
*
* 返回值：无
*/
void SoftThreshold(double* coeff, int cHeight, int cWidth, double threshold,
						  int staticHeight, int staticWidth);

/*
* 函数名：HardThreshold
*
* 功能：用输入的阈值使用硬阈值方法对输入的矩阵切分
*
* 参数：
* @param coeff 输入矩阵（如：小波系数的高频区域）
* @param cHeight 行数（输入矩阵高度）
* @param cWidth 列数（输入矩阵宽度）
* @param threshold 阈值
* @param staticHeight 图像固定高度（一般同mHeight）
* @param staticWidth 图像的固定宽度（一般同mWidth）
*
* 输入：coeff
*
* 输出：coeff
*
* 返回值：无
*/
void HardThreshold(double* coeff, int cHeight, int cWidth, double threshold,
						  int staticHeight, int staticWidth);

/*
*
*	功能：根据模值和相角初始化模极大值
*
*/
void FindMoMax(int scale, double** pMo, int cHeight, int cWidth,
					  unsigned char* pMoMax1/* =NULL*/, unsigned char* pMoMax2/* =NULL*/, unsigned char* pMoMax3/* =NULL*/);

/*
* 函数名：GetMoMax
*
* 功能：先找到模值和相角，然后初始化各尺度模极大值矩阵pMoMax1（pMoMax2, pMoMax3）
*
* 参数：
* @param coeff 输入小波系数矩阵
* @param cHeight 行数（输入矩阵高度）
* @param cWidth 列数（输入矩阵宽度）
* @param scaleSum 分解尺度
* @param threshold1 尺度1的模极大值阈值，初始为0
* @param threshold2 尺度2的模极大值阈值，初始为0
* @param threshold3 尺度3的模极大值阈值，初始为0
* @param pMoMax1 尺度1的模极大值矩阵，本函数不会为改指针申请空间
* @param pMoMax2 尺度2的模极大值矩阵，本函数不会为改指针申请空间
* @param pMoMax3 尺度3的模极大值矩阵，本函数不会为改指针申请空间
*
* 输入：coeff, pMoMax1, pMoMax2, pMoMax3
*
* 输出：pMoMax1, pMoMax2, pMoMax3
*
* 返回值：无
*/
void GetMoMax(double* coeff, int cHeight, int cWidth, int scaleSum,
					 double threshold1/* =0*/, double threshold2/* =0*/, double threshold3/* =0*/, 
					 unsigned char* pMoMax1/* =NULL*/, unsigned char* pMoMax2/* =NULL*/, unsigned char* pMoMax3/* =NULL*/);


#endif //_FILTERAPI_H_