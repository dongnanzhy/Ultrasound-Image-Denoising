// 毕业设计Doc.cpp : implementation of the CMyDoc class
//

#include "stdafx.h"
#include "毕业设计.h"

#include "毕业设计Doc.h"
#include "Dib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDoc

IMPLEMENT_DYNCREATE(CMyDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyDoc, CDocument)
	//{{AFX_MSG_MAP(CMyDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDoc construction/destruction

CMyDoc::CMyDoc()
{
	// TODO: add one-time construction code here
	m_pDib=NULL;
}

CMyDoc::~CMyDoc()
{
	if (m_pDib!=NULL)
	{
// 		delete []m_pDib;
// 		m_pDib=NULL;
		delete m_pDib;
		
	}
}

BOOL CMyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyDoc serialization

void CMyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyDoc diagnostics

#ifdef _DEBUG
void CMyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyDoc commands

BOOL CMyDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	m_pDib=new CDib;
	if (m_pDib!=NULL)
	{
		m_pDib->LoadFile(lpszPathName);
		UpdateWindow(NULL);
	}
	// TODO: Add your specialized creation code here
	
	return TRUE;
}

//DEL void CMyDoc::OnFileSave() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	CFileDialog dlg(FALSE,_T("BMP"),_T("*.BMP"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("位图文件(*.BMP)|*.BMP|"));	
//DEL     if(IDOK==dlg.DoModal())
//DEL 	{
//DEL 		CString  filename;
//DEL 		filename.Format ("%s",dlg.GetPathName() );    
//DEL 		m_pDib->Save(filename);
//DEL 	}
//DEL     SetModifiedFlag(TRUE);
//DEL 	UpdateAllViews(NULL);
//DEL }
