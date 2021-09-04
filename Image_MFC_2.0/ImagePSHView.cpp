
// ImagePSHView.cpp: CImagePSHView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImagePSH.h"
#endif

#include "ImagePSHDoc.h"
#include "ImagePSHView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImagePSHView

IMPLEMENT_DYNCREATE(CImagePSHView, CView)

BEGIN_MESSAGE_MAP(CImagePSHView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_EQUAL_IMAGE, &CImagePSHView::OnEqualImage)
	ON_COMMAND(IDM_BW_127_IMAGE, &CImagePSHView::OnBw127Image)
	ON_COMMAND(IDM_BW_INPUT_IMAGE, &CImagePSHView::OnBwInputImage)
	ON_COMMAND(IDM_GRAY_IMAGE, &CImagePSHView::OnGrayImage)
	ON_COMMAND(IDM_NGTV_IMAGE, &CImagePSHView::OnNgtvImage)
	ON_COMMAND(IDM_LIGHT_PM_IMAGE, &CImagePSHView::OnLightPmImage)
	ON_COMMAND(IDM_LIGHT_MD_IMAGE, &CImagePSHView::OnLightMdImage)
	ON_COMMAND(IDM_PARA_CAP_IMAGE, &CImagePSHView::OnParaCapImage)
	ON_COMMAND(IDM_PARA_CUP_IMAGE, &CImagePSHView::OnParaCupImage)
	ON_COMMAND(IDM_GAMMA_IMAGE, &CImagePSHView::OnGammaImage)
	ON_COMMAND(IDM_ZMIN_NRML_IMAGE, &CImagePSHView::OnZminNrmlImage)
	ON_COMMAND(IDM_ZMIN_NH_IMAGE, &CImagePSHView::OnZminNhImage)
	ON_COMMAND(IDM_ZMIN_YS_IMAGE, &CImagePSHView::OnZminYsImage)
	ON_COMMAND(IDM_ZOUT_IMAGE, &CImagePSHView::OnZoutImage)
	ON_COMMAND(IDM_TURN_IMAGE, &CImagePSHView::OnTurnImage)
	ON_COMMAND(IDM_MOVE_IMAGE, &CImagePSHView::OnMoveImage)
	ON_COMMAND(IDM_MIRROR_UD_IMAGE, &CImagePSHView::OnMirrorUdImage)
	ON_COMMAND(IDM_MIRROR_LR_IMAGE, &CImagePSHView::OnMirrorLrImage)
	ON_COMMAND(IDM_EMBOS_IMAGE, &CImagePSHView::OnEmbosImage)
	ON_COMMAND(IDM_BLR_AVG_IMAGE, &CImagePSHView::OnBlrAvgImage)
	ON_COMMAND(IDM_BLR_GAUS_IMAGE, &CImagePSHView::OnBlrGausImage)
	ON_COMMAND(IDM_HPF_IMAGE, &CImagePSHView::OnHpfImage)
	ON_COMMAND(IDM_LPF_IMAGE, &CImagePSHView::OnLpfImage)
	ON_COMMAND(IDM_CALC_USA_IMAGE, &CImagePSHView::OnCalcUsaImage)
	ON_COMMAND(IDM_CALC_MNS_IMAGE, &CImagePSHView::OnCalcMnsImage)
	ON_COMMAND(IDM_RBRTS_IMAGE, &CImagePSHView::OnRbrtsImage)
	ON_COMMAND(IDM_PRW_IMAGE, &CImagePSHView::OnPrwImage)
	ON_COMMAND(IDM_SOBL_IMAGE, &CImagePSHView::OnSoblImage)
	ON_COMMAND(IDM_LAPLA_IMAGE, &CImagePSHView::OnLaplaImage)
	ON_COMMAND(IDM_LOG_IMAGE, &CImagePSHView::OnLogImage)
	ON_COMMAND(IDM_DOG_IMAGE, &CImagePSHView::OnDogImage)
	ON_COMMAND(IDM_HIST_CHART_IMAGE, &CImagePSHView::OnHistChartImage)
	ON_COMMAND(IDM_HIST_STCH_IMAGE, &CImagePSHView::OnHistStchImage)
	ON_COMMAND(IDM_HIST_EQUAL_IMAGE, &CImagePSHView::OnHistEqualImage)
	ON_COMMAND(IDM_BW_AVG_IMAGE, &CImagePSHView::OnBwAvgImage)
	ON_COMMAND(ID_EDIT_UNDO, &CImagePSHView::OnEditUndo)
	ON_COMMAND(ID_EDIT_REDO, &CImagePSHView::OnEditRedo)
END_MESSAGE_MAP()

// CImagePSHView 생성/소멸

CImagePSHView::CImagePSHView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImagePSHView::~CImagePSHView()
{
}

BOOL CImagePSHView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CImagePSHView 그리기

void CImagePSHView::OnDraw(CDC* pDC)
{
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	//// 느린 OnDraw
	/*  
	int RR, GG, BB;
	for (int i = 0; i < pDoc->m_inH; i++) {
		for (int k = 0; k < pDoc->m_inW; k++) {
			RR = pDoc->m_InputImageR[i][k];
			GG = pDoc->m_InputImageG[i][k];
			BB = pDoc->m_InputImageB[i][k];
			pDC->SetPixel(k + 5, i + 5, RGB(RR, GG, BB));
		}
	}
	for (int i = 0; i < pDoc->m_outH; i++) {
		for (int k = 0; k < pDoc->m_outW; k++) {
			RR = pDoc->m_OutputImageR[i][k];
			GG = pDoc->m_OutputImageG[i][k];
			BB = pDoc->m_OutputImageB[i][k];
			pDC->SetPixel(pDoc->m_inW + k + 20, i + 5, RGB(RR, GG, BB));
		}
	}
	*/

	////빠른 OnDraw
	int i, k;
	unsigned char RR, GG, BB;

	// 메모리 DC 선언 (DC : 출력)
	CDC memDC; // CDC 클래스 가져오기
	CBitmap* pOldBitmap, bitmap;

	// * Input 출력 (원본)
	// pDC와 연동가능한 메모리 DC 선언
	memDC.CreateCompatibleDC(pDC);

	// pDC와 호환되는 bitmap 생성 (BMP)
	bitmap.CreateCompatibleBitmap(pDC, pDoc->m_inW, pDoc->m_inH);
	pOldBitmap = memDC.SelectObject(&bitmap);
	// 패턴방식 초기화 
	memDC.PatBlt(0, 0, pDoc->m_inW, pDoc->m_inH, SRCCOPY); 
	// WHITENESS : 흰색으로 초기화 , SRCCOPY : 원래 비트맵 그대로 출력
	
	// 메모리에 DC 가져오기
	for (i = 0; i < pDoc->m_inH; i++) {
		for (k = 0; k < pDoc->m_inW; k++) {
			RR = pDoc->m_InputImageR[i][k];
			GG = pDoc->m_InputImageG[i][k];
			BB = pDoc->m_InputImageB[i][k];
			memDC.SetPixel(k, i, RGB(RR, GG, BB));
		}
	}
	// 출력 : 메모리 DC를 화면 DC에 고속 복사
	/// BitBlt : 메모리 DC비트맵을 현재 DC로 고속복사.
	/// 두 화면다 호환되거나, 한쪽이 흑백이여야한다.
	pDC->BitBlt(5, 5, pDoc->m_inW, pDoc->m_inH, &memDC, 0, 0, SRCCOPY);
	// WHITENESS : 흰색으로 초기화 , SRCCOPY : 원래 비트맵 그대로 출력
	// -> 이 영역에서 	Invalidate() 부분과 연관이 있다.
	///	에러가 뜬다면 : Invalidate(FALSE)를 TRUE로 변경
	//// (어차피 "SRCCOPY" 때문에Invalidate(FALSE)처리와 같다)
	
	// 메모리 Free
	memDC.SelectObject(pOldBitmap);
	memDC.DeleteDC();
	bitmap.DeleteObject();

	// * Output 출력
	// pDC와 호환되는 메모리DC 생성
	memDC.CreateCompatibleDC(pDC);
	/// pDC와 호환되는 bitmap 생성
	bitmap.CreateCompatibleBitmap(pDC, pDoc->m_outW, pDoc->m_outH);
	pOldBitmap = memDC.SelectObject(&bitmap);
	// 패턴방식 초기화 
	memDC.PatBlt(pDoc->m_outW, pDoc->m_outH, 0, 0, SRCCOPY);
	
	//메모리 DC에 그리기
	for (i = 0; i < pDoc->m_outH; i++) {
		for (k = 0; k < pDoc->m_outW; k++) {
			RR = pDoc->m_OutputImageR[i][k];
			GG = pDoc->m_OutputImageG[i][k];
			BB = pDoc->m_OutputImageB[i][k];
			memDC.SetPixel(k, i, RGB(RR, GG, BB));
		}
	}
	// 출력 : 메모리 DC를 화면 DC에 고속 복사 
	pDC->BitBlt(pDoc->m_inW + 10, 5, pDoc->m_outW, pDoc->m_outH, &memDC, 0, 0, SRCCOPY);

	// Free
	memDC.SelectObject(pOldBitmap);
	memDC.DeleteDC();
	bitmap.DeleteObject();
}


// CImagePSHView 인쇄

BOOL CImagePSHView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImagePSHView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImagePSHView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CImagePSHView 진단

#ifdef _DEBUG
void CImagePSHView::AssertValid() const
{
	CView::AssertValid();
}

void CImagePSHView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImagePSHDoc* CImagePSHView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImagePSHDoc)));
	return (CImagePSHDoc*)m_pDocument;
}
#endif //_DEBUG


// CImagePSHView 메시지 처리기


void CImagePSHView::OnEqualImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnEqualImage();
	Invalidate(TRUE);
}


void CImagePSHView::OnBw127Image()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnBw127Image();
	Invalidate(FALSE);
}


void CImagePSHView::OnBwInputImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnBwInputImage();
	Invalidate(FALSE);
}

void CImagePSHView::OnBwAvgImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnBwAvgImage();
	Invalidate(FALSE);
}

void CImagePSHView::OnGrayImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnGrayImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnNgtvImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnNgtvImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnLightPmImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnLightPmImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnLightMdImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnLightMdImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnParaCapImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnParaCapImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnParaCupImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnParaCupImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnGammaImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnGammaImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnZminNrmlImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnZminNrmlImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnZminNhImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnZminNhImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnZminYsImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnZminYsImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnZoutImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnZoutImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnTurnImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnTurnImage();
	Invalidate(TRUE); 
}


void CImagePSHView::OnMoveImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnMoveImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnMirrorUdImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnMirrorUdImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnMirrorLrImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnMirrorLrImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnEmbosImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnEmbosImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnBlrAvgImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnBlrAvgImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnBlrGausImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnBlrGausImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnHpfImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnHpfImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnLpfImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnLpfImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnCalcUsaImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnCalcUsaImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnCalcMnsImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnCalcMnsImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnRbrtsImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnRbrtsImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnPrwImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnPrwImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnSoblImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnSoblImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnLaplaImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnLaplaImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnLogImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnLogImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnDogImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnDogImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnHistChartImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnHistChartImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnHistStchImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnHistStchImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnHistEqualImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->OnHistEqualImage();
	Invalidate(FALSE);
}


void CImagePSHView::OnEditUndo()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->Undo();
	Invalidate(FALSE);
}


void CImagePSHView::OnEditRedo()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImagePSHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->Redo();
	Invalidate(FALSE);
}
