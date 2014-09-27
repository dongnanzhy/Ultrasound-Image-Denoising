// 毕业设计View.h : interface of the CMyView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEW_H__1E7BECF6_7264_4601_B7A1_A258F01AEC1C__INCLUDED_)
#define AFX_VIEW_H__1E7BECF6_7264_4601_B7A1_A258F01AEC1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyView : public CView
{
protected: // create from serialization only
	CMyView();
	DECLARE_DYNCREATE(CMyView)

// Attributes
public:
	CMyDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyView)
	afx_msg void OnMidchanged();
	afx_msg void OnAddnoise();
	afx_msg void OnFileSave();
	afx_msg void OnAddnoise2();
	afx_msg void OnWavelethard();
	afx_msg void OnWaveletsoft();
	afx_msg void OnHaarwavelettrans();
	afx_msg void OnHaarwaveletitrans();
	afx_msg void OnSnr();
	afx_msg void OnPsnr();
	afx_msg void OnHuanyuan();
	afx_msg void OnHardthreshold2();
	afx_msg void OnSoftthreshold2();
	afx_msg void OnSym8wavelettrans();
	afx_msg void OnSym8waveletreverse();
	afx_msg void OnNoisevariance();
	afx_msg void OnNoisedensity();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 毕业设计View.cpp
inline CMyDoc* CMyView::GetDocument()
   { return (CMyDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEW_H__1E7BECF6_7264_4601_B7A1_A258F01AEC1C__INCLUDED_)
