//WaveletApi.h

#ifndef _WAVELETAPI_H_
#define _WAVELETAPI_H_

/*
*
*	功能：求卷积
*
*/
void Convolution(double *signal, int signLen, double *filter, int filterLen, double *conv);

/*
*
*	功能：求逆卷积
*
*/
void Iconvolution(double *signal, int signLen, double *filter, int filterLen, double *conv);

/*
*
*	功能：矩阵转置
*
*/
void Revert(double *matrix1, int mHeight, int mWidth, double *matrix2);

/*
*
*	功能：向下采样
*
*/
void Downsample(double *matrix1, int mHeight, int mWidth, double *matrix2);

/*
*
*	功能：向上采样
*
*/
void Upsample(double *matrix1, int mHeight, int mWidth, double *matrix2);

/*
*
*	功能：矩阵加法
*
*/
void Plus(double *matrix1, int mHeight, int mWidth, double *matrix2);

/*
*
*	功能：矩阵复制
*
*/
void Copy_f2f(double *original, int mHeight, int mWidth, double *newmatrix, int nHeight, int nWidth);

/*
* 功能：Mallat多辨率小波分解
*/
BOOL MallatDWT(double *matrix, int mHeight, int mWidth, int nscale,
					  double *pFilterLow, double *pFilterHigh, int filterLength, double *coeff, int staticHeight, int staticWidth);


/*
* 功能：Mallat多辨率小波重构
*/
BOOL MallatIDWT(double *coeff, int mHeight, int mWidth, int nscale,
					   double *pFilterLow, double *pFilterHigh, int filterLength, int staticHeight, int staticWidth);

/*
* 函数名：Wavelet
*
* 功能：Mallat多辨率小波分解
*
* 参数：
* @param matrix 要分解的二维矩阵
* @param mHeight 行数（输入矩阵高度）
* @param mWidth 列数（输入矩阵宽度）
* @param nscale 分解尺度
* @param filterType 滤波器类别（0为二次B样条，1为三次B样条，2为db9/7，3为sym7，4为sym8）
* @param coeff 分解后系数矩阵
* @param staticHeight 图像固定高度（一般同mHeight）
* @param staticWidth 图像的固定宽度（一般同mWidth）
*
* 输入：matrix
*
* 输出：coeff
*
* 返回值：TRUE为分解成功
*/
BOOL Wavelet(double *matrix, int mHeight, int mWidth, int nscale,
					  int filterType, double *coeff, int staticHeight, int staticWidth);

/*
* 函数名：InverseWavelet
*
* 功能：Mallat多辨率小波重构
*
* 参数：
* @param coeff 要重构的二维小波系数矩阵
* @param mHeight 行数（输入矩阵高度）
* @param mWidth 列数（输入矩阵宽度）
* @param nscale 分解尺度
* @param filterType 滤波器类别（0为二次B样条，1为三次B样条，2为db9/7，3为sym7，4为sym8）
* @param staticHeight 图像固定高度（一般同mHeight）
* @param staticWidth 图像的固定宽度（一般同mWidth）
*
* 输入：coeff
*
* 输出：coeff
*
* 返回值：TRUE为重构成功
*/
BOOL InverseWavelet(double *coeff, int mHeight, int mWidth, int nscale,
						   int filterType, int staticHeight, int staticWidth);

#endif //_WAVELETAPI_H_