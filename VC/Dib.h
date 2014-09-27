// Dib.h: interface for the CDib class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIB_H__47172EBE_159C_499D_91C6_B86A503538C9__INCLUDED_)
#define AFX_DIB_H__47172EBE_159C_499D_91C6_B86A503538C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDib  
{
public:
	CDib();
	virtual ~CDib();

public:
	bool LoadFile(const char *FileName);
    bool Save(const char *pFilename);
	void Draw(CDC *pDC);
	void Huanyuan();

	//加噪声
    void AddPepperSaltNoise();
	void AddRandomNoise();
	double NoiseVariance();
	double Noiseq(unsigned char * Bits,int t);
	double NoiseDensity();
    void SNR();
    void PSNR();

	//自适应滤波
	void Midchanged();

	//小波变换
	void HardThreshold();
	void SoftThreshold();
	void HardThreshold2();
	void SoftThreshold2();
	void Hard(double* coeff, int cHeight, int cWidth, double threshold,
						  int staticHeight, int staticWidth);
	void Soft(double* coeff, int cHeight, int cWidth, double threshold,
						  int staticHeight, int staticWidth);
	void Sym8WaveletTrans(int scale);
	void Sym8WaveletReverse();
	void Sym8WaveletTransDisp(int scale=1);
	void Sym8WaveletReverseDisp();
	void SymHaarWaveletTrans(int scale);
	void SymHaarWaveletReverse();
	int GetSgn(double number);
	int m_nScale;
	double * pCoeff;

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
	void SimpleWaveletTrans(int scale=1);
	//矩阵相加
	void MatrixPlus(unsigned char *matrixA, unsigned char *matrixB, int height, int width, unsigned char *result);	
	//行插点
	void MatrixInsertRow(unsigned char *matrixInputOdd, unsigned char *matrixInputEven,
		unsigned char *matrixOutput, int heightInput, int widthInput, int widthOutput);	
	//列插点
	void MatrixInsertLine(unsigned char *matrixInputOdd, unsigned char *matrixInputEven,
		unsigned char *matrixOutput, int heightInput, int widthInput, int widthOutput);	
	//一次小波重构
	void Reverse(unsigned char *inputData, int inputHeight, int inputWidth, int lineByte, int scale, unsigned char *outputData);	
	//小波重构
	void SimpleWaveletReverse();
	
private:
	unsigned char *m_pDib;
	unsigned char *m_pDibOrig;
	unsigned char *m_pDibBits;
	unsigned char *m_pDibBitstemp;
	unsigned char *m_pDibBitsOrig;

	long m_width;
	long m_height;
	BITMAPINFOHEADER *m_pBIH;
	BITMAPFILEHEADER BFH;
	RGBQUAD *m_pPalette;
	CPalette m_Palette;    //创建一个调色板对象
	int PaletteEntries;    //调色板的颜色个数
	long linebytes;
	int pixelbyte;
	DWORD dwDibsize;
//Dib图像相关参数

	int m_WindowLevel;
	int m_WindowWidth;
	unsigned char *m_pDicom;
	unsigned char *m_pName;
	unsigned char *m_pNumber;
	unsigned char *m_pBirthday;
	unsigned char *m_pSex;
	unsigned char *m_pHospitalName;
	unsigned char *m_pHosipitalAddress;
	unsigned char *m_pHeight;
	unsigned char *m_pWidth;
	unsigned char *m_pWindowLevel;
	unsigned char *m_pWindowWidth;
	unsigned char *m_pPixelBit;
	unsigned char *m_pComponentBit;
	unsigned char *m_pEffectiveBit;
	unsigned char *m_pDicomBits;
//dicom图像相关参数
	BOOL style;

};

#endif // !defined(AFX_DIB_H__47172EBE_159C_499D_91C6_B86A503538C9__INCLUDED_)
