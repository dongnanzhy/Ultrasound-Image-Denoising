#ifndef _INSIDE_VISUAL_CPP_WLTTRANSFORM
#define _INSIDE_VISUAL_CPP_WLTTRANSFORM
#include "ImageCenterDib.h"

//小波变换类
class transeform_wavelet : public ImgCenterDib
{
public:
	int m_nBitCountOut;
	unsigned char * m_pImgDataOut;
	LPRGBQUAD m_pColorTableOut;
	int m_nColorTableLengthOut;
	double* pCoeff;
public:
	void ReplaceDIBForNew(CSize size, int nBitCount, LPRGBQUAD lpColorTable, unsigned char *pImgData);
	//分解尺度
	int m_nScale;
	transeform_wavelet();
	transeform_wavelet(CSize size, int nBitCount, LPRGBQUAD pColorTable, unsigned char *pImgData);
	~transeform_wavelet();
	
	//矩阵区域复制
	void MatrixRegionCopy(unsigned char *matrixRegion, int heightRegion, int widthRegion,
		unsigned char *matrixDest, int heightDest, int widthDest);
	
	//矩阵相减
	void MatrixSub(unsigned char *matrixA, unsigned char *matrixB, int height, int width, unsigned char *result);	
	
	//行采样
	void MatrixSampleRow(unsigned char *matrixInput, unsigned char *matrixOutputOdd,
		unsigned char *matrixOutputEven, int heightOutput, int widthOutput, int widthInput);
	
	//列采样
	void MatrixSampleLine(unsigned char *matrixInput, unsigned char *matrixOutputOdd,
		unsigned char *matrixOutputEven, int heightOutput, int widthOutput, int widthInput);
	
	//一次小波分解
	void Trans(unsigned char *inputData, int inputHeight, int inputWidth, int lineByte, int scale, unsigned char *outputData);
	
	//小波变换
	void SimpleWaveletTrans(int scale);
	
	//矩阵相加
	void transeform_wavelet::MatrixPlus(unsigned char *matrixA, unsigned char *matrixB, int height, int width, unsigned char *result);
	
	//行插点
	void transeform_wavelet::MatrixInsertRow(unsigned char *matrixInputOdd, unsigned char *matrixInputEven,
		unsigned char *matrixOutput, int heightInput, int widthInput, int widthOutput);
	
	//列插点
	void transeform_wavelet::MatrixInsertLine(unsigned char *matrixInputOdd, unsigned char *matrixInputEven,
		unsigned char *matrixOutput, int heightInput, int widthInput, int widthOutput);
	
	//一次小波重构
	void Reverse(unsigned char *inputData, int inputHeight, int inputWidth, int lineByte, int scale, unsigned char *outputData);
	
	//小波重构
	void SimpleWaveletReverse();
	
	//高频系数置零方法去噪声
	void H2Zero(double* coeff, int cHeight, int cWidth, 
						  int staticHeight, int staticWidth);
	void SetH2Zero();
	
	//硬阈值方法去噪声
	void Hard(double* coeff, int cHeight, int cWidth, double threshold,
						  int staticHeight, int staticWidth);
	//硬阈值方法去噪的对外接口
	void HardThreshold();
	
	int GetSgn(double number);
	//软阈值方法去噪声
	void Soft(double* coeff, int cHeight, int cWidth, double threshold,
						  int staticHeight, int staticWidth);
	//软阈值方法去噪的对外接口
	void SoftThreshold();
	
	void Sym8WaveletTrans(int scale);
	void Sym8WaveletReverse();
};
#endif // _INSIDE_VISUAL_CPP_WLTTRANSFORM