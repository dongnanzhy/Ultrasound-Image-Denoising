// 毕业设计View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "毕业设计.h"

#include "毕业设计Doc.h"
#include "毕业设计View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	//{{AFX_MSG_MAP(CMyView)
	ON_COMMAND(ID_MIDCHANGED, OnMidchanged)
	ON_COMMAND(ID_ADDNOISE, OnAddnoise)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_ADDNOISE2, OnAddnoise2)
	ON_COMMAND(ID_WAVELETHARD, OnWavelethard)
	ON_COMMAND(ID_WAVELETSOFT, OnWaveletsoft)
	ON_COMMAND(ID_HAARWAVELETTRANS, OnHaarwavelettrans)
	ON_COMMAND(ID_HAARWAVELETITRANS, OnHaarwaveletitrans)
	ON_COMMAND(ID_SNR, OnSnr)
	ON_COMMAND(ID_PSNR, OnPsnr)
	ON_COMMAND(ID_HUANYUAN, OnHuanyuan)
	ON_COMMAND(ID_HARDTHRESHOLD2, OnHardthreshold2)
	ON_COMMAND(ID_SOFTTHRESHOLD2, OnSoftthreshold2)
	ON_COMMAND(ID_SYM8WAVELETTRANS, OnSym8wavelettrans)
	ON_COMMAND(ID_SYM8WAVELETREVERSE, OnSym8waveletreverse)
	ON_COMMAND(ID_NOISEVARIANCE, OnNoisevariance)
	ON_COMMAND(ID_NOISEDENSITY, OnNoisedensity)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyView construction/destruction

CMyView::CMyView()
{
	// TODO: add construction code here

}

CMyView::~CMyView()
{
}

BOOL CMyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyView drawing

void CMyView::OnDraw(CDC* pDC)
{
	CMyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	if (pDoc->m_pDib!=NULL)
	{
		pDoc->m_pDib->Draw(pDC);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyView printing

BOOL CMyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyView diagnostics

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDoc* CMyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}
#endif //_DEBUG



void CMyView::OnMidchanged() 
{
	CMyDoc* pDoc = GetDocument();
	
	if (pDoc->m_pDib!=NULL)
	{
		pDoc->m_pDib->Midchanged();
	}
	Invalidate(NULL);
	
}

void CMyView::OnAddnoise() 
{
	// TODO: Add your command handler code here
	CMyDoc* pDoc = GetDocument();
	
	if (pDoc->m_pDib!=NULL)
	{
		pDoc->m_pDib->AddPepperSaltNoise();
	}
	Invalidate(NULL);
}

void CMyView::OnFileSave() 
{
	// TODO: Add your command handler code here
	CFileDialog dlg(FALSE,_T("BMP"),_T("*.BMP"),
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("位图文件(*.BMP)|*.BMP|"));	

	CMyDoc* pDoc = GetDocument();
	
	if(dlg.DoModal() == IDOK)
	{
		pDoc->m_pDib->Save(dlg.GetPathName());  //GetPathName()--得到完整的文件名，包括目录名和扩展名
	}

}

void CMyView::OnAddnoise2() 
{
	// TODO: Add your command handler code here
	CMyDoc* pDoc = GetDocument();
	
	if (pDoc->m_pDib!=NULL)
	{
		pDoc->m_pDib->AddRandomNoise();
	}
	Invalidate(NULL);
}

void CMyView::OnWavelethard() 
{
	// TODO: Add your command handler code here
	CMyDoc* pDoc = GetDocument();
	
	if (pDoc->m_pDib!=NULL)
	{
		pDoc->m_pDib->HardThreshold();
	}
	Invalidate(NULL);
}

void CMyView::OnWaveletsoft() 
{
	// TODO: Add your command handler code here
	CMyDoc* pDoc = GetDocument();
	
	if (pDoc->m_pDib!=NULL)
	{
		pDoc->m_pDib->SoftThreshold();
	}
	Invalidate(NULL);
}

void CMyView::OnHaarwavelettrans() 
{
	// TODO: Add your command handler code here
	CMyDoc* pDoc = GetDocument();
	
	if (pDoc->m_pDib!=NULL)
	{
		pDoc->m_pDib->SimpleWaveletTrans(2);
	}
	Invalidate(NULL);
}

void CMyView::OnHaarwaveletitrans() 
{
	// TODO: Add your command handler code here
	CMyDoc* pDoc = GetDocument();
	
	if (pDoc->m_pDib!=NULL)
	{
		pDoc->m_pDib->SimpleWaveletReverse();
	}
	Invalidate(NULL);
}

void CMyView::OnSnr() 
{
	// TODO: Add your command handler code here
	CMyDoc* pDoc = GetDocument();
	
	if (pDoc->m_pDib!=NULL)
	{
		pDoc->m_pDib->SNR();
	}
	Invalidate(NULL);
}

void CMyView::OnPsnr() 
{
	// TODO: Add your command handler code here
	CMyDoc* pDoc = GetDocument();
	
	if (pDoc->m_pDib!=NULL)
	{
		pDoc->m_pDib->PSNR();
	}
	Invalidate(NULL);
}

void CMyView::OnHuanyuan() 
{
	// TODO: Add your command handler code here
	CMyDoc* pDoc = GetDocument();
	
	if (pDoc->m_pDib!=NULL)
	{
		pDoc->m_pDib->Huanyuan();
	}
	Invalidate(NULL);
}

void CMyView::OnHardthreshold2() 
{
	// TODO: Add your command handler code here
	CMyDoc* pDoc = GetDocument();
	
	if (pDoc->m_pDib!=NULL)
	{
		pDoc->m_pDib->HardThreshold2();
	}
	Invalidate(NULL);
}

void CMyView::OnSoftthreshold2() 
{
	// TODO: Add your command handler code here
	CMyDoc* pDoc = GetDocument();
	
	if (pDoc->m_pDib!=NULL)
	{
		pDoc->m_pDib->SoftThreshold2();
	}
	Invalidate(NULL);
}

void CMyView::OnSym8wavelettrans() 
{
	// TODO: Add your command handler code here
	CMyDoc* pDoc = GetDocument();
	
	if (pDoc->m_pDib!=NULL)
	{
		pDoc->m_pDib->Sym8WaveletTransDisp(2);
	}
	Invalidate(NULL);
}

void CMyView::OnSym8waveletreverse() 
{
	// TODO: Add your command handler code here
	CMyDoc* pDoc = GetDocument();
	
	if (pDoc->m_pDib!=NULL)
	{
		pDoc->m_pDib->Sym8WaveletReverseDisp();
	}
	Invalidate(NULL);
}

void CMyView::OnNoisevariance() 
{
	// TODO: Add your command handler code here
	CMyDoc* pDoc = GetDocument();
	double Variance;
	if (pDoc->m_pDib!=NULL)
	{
		Variance=pDoc->m_pDib->NoiseVariance();
		CString StrVariance;
		StrVariance.Format("%f",Variance);
	    ::MessageBox(NULL,StrVariance,"随机噪声标准差",MB_OK);
	}
	Invalidate(NULL);
}

void CMyView::OnNoisedensity() 
{
	// TODO: Add your command handler code here
	CMyDoc* pDoc = GetDocument();
    double Density;
	if (pDoc->m_pDib!=NULL)
	{
	   Density=pDoc->m_pDib->NoiseDensity();
	   CString StrDensity;
	   StrDensity.Format("%f",Density);
	   ::MessageBox(NULL,StrDensity,"椒盐噪声密度",MB_OK);
	}
	Invalidate(NULL);
}
