//dibapi.h
#ifndef _INC_DIBAPI
#define _INC_DIBAPI

//DIB handle
DECLARE_HANDLE(HDIB);

//palette version
#define PALVERSION 0x300;

//judge Win3.0 DIB
#define IS_WIN30_DIB(lpbi) ((*(LPDWORD)(lpbi))==sizeof(BITMAPINFOHEADER))

//wideth
#define RECTWIDTH(lpRect) ((lpRect)->right-(lpRect)->left)

//height
#define RECTHEIGHT(lpRect) ((lpRect)->bottom-(lpRect)->top)

//byte of pixels per line
#define WIDTHBYTES(bits) (((bits)+31)/32*4)

//paint DIB
BOOL WINAPI PaintDIB(HDC,LPRECT,HDIB,LPRECT,CPalette* pPal);

//paint DIBBits
BOOL WINAPI PaintDIBBits(HDC,LPRECT,HDIB,LPBYTE,LPRECT,CPalette* pPal);

//create DIB palette
BOOL WINAPI CreateDIBPalette(HDIB hDIB,CPalette* pPal);

//copy palette
HPALETTE WINAPI CopyPalette(HPALETTE hPalSrc);

//get system palette
HPALETTE WINAPI GetSystemPalette();

//create identify palette
HPALETTE WINAPI CreateIdentifyPalette(HPALETTE hPalSrc);

//find start pixel of DIB
LPSTR WINAPI FindDIBBits(LPSTR lpbi);

//width of DIB
DWORD WINAPI DIBWidth(LPSTR lpDIB);

//height of DIB
DWORD WINAPI DIBHeight(LPSTR lpDIB);

//size of palette
WORD WINAPI PaletteSize(LPSTR lpbi);

//number of the palette colors
WORD WINAPI DIBNumColors(LPSTR lpbi);

//bits per pixel
WORD WINAPI DIBBitCount(LPSTR lpbi); 

//copy handle
HGLOBAL WINAPI CopyHandle(HGLOBAL h);

//save DIB
BOOL WINAPI SaveDIB(HDIB hDib,CFile& file);

//read DIB
HDIB WINAPI ReadDIBFile(CFile& file);

template <class T>
void WINAPI ReverseDIBBits(T* lpDibBits, int hrow, int vrow)
{
	int i,j;
	T temp;
	for(j =0; j <vrow; j++)
	{
		for(i =0; i <hrow/2; i++)
		{
			temp =lpDibBits[i*vrow+j];
			lpDibBits[i*vrow+j] =lpDibBits[(hrow-i-1)*vrow+j];
			lpDibBits[(hrow-i-1)*vrow+j] =temp;
		}
	}
}

template <class T1, class T2>
void WINAPI CopyPositive(T1 *original, int hrow1, int vrow1, T2 *newmatrix, int hrow2, int vrow2)
{
//	if(original == 0)
//		throw NullPointerException();
	
	int minh, minv, i, j;
//
	T1 temp,max=*original,min=*original;

	T1* positive =new T1[hrow1 * vrow1];
	minh = (hrow1 < hrow2) ? hrow1 : hrow2;
	minv = (vrow1 < vrow2) ? vrow1 : vrow2;
///*	
	for(i = 0; i < hrow1 ; i ++)
	{         
		for(j = 0; j < vrow1; j++)
		{   
			if(*(original + i * vrow1 + j)>0)
			{
				*(positive + i * vrow2 + j) = *(original + i * vrow1 + j);
			}
			else
			{
				*(positive + i * vrow2 + j) = *(original + i * vrow1 + j) * (-1);
			}
			max = *(positive + i * vrow2 + j) > max ? *(positive + i * vrow2 + j) : max;
			min = *(positive + i * vrow2 + j) < min ? *(positive + i * vrow2 + j) : min;
		}
	}
	int middle1 =150, middle2 =150, middle3 =150;

	for(i = 0; i < minh ; i++)
	{         
		for(j = 0; j < minv; j++)
		{
///*
			if(*(positive + i * vrow2 + j)<4)
			{
				*(newmatrix + i * vrow2 + j) = (T2)*(positive + i * vrow2 + j);
			}
			else if(*(positive + i * vrow2 + j)<middle1)
			{
				temp = *(positive + i * vrow1 + j) -min;
				temp *=(middle2 - 0);
				temp /=(middle1 - min);
				*(newmatrix + i * vrow2 + j) = (T2)temp;
			}
			else
			{
				temp = *(positive + i * vrow1 + j) -middle1;
				temp *=(255 - middle3);
				temp /=(max - middle1);
				temp +=middle3;
				*(newmatrix + i * vrow2 + j) = (T2)temp;
			}
//*/
/*
			temp = *(positive + i * vrow1 + j) -min;
			temp *=255;
			temp /=(max-min);
			*(newmatrix + i * vrow2 + j) = (T2)temp;
*/
//*/
		}
	}

	delete[] positive;
	return;
}

template <class T1, class T2>
void Copy(T1 *original, int mHeight, int mWidth, T2 *newmatrix, int nHeight, int nWidth)
{
	int minh, minv;
	minh = (mHeight < nHeight) ? mHeight : nHeight;
	minv = (mWidth < nWidth) ? mWidth : nWidth;
	
	for(int i = 0; i < minh ; i ++)
	{         
		for(int j = 0; j < minv; j++)
		{                       
			*(newmatrix + i * nWidth + j) = (T2)*(original + i * mWidth + j);
		}
	}
	return;
}

#endif //!-INC-DIBAPI