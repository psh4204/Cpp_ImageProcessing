
// ImagePSHDoc.h: CImagePSHDoc 클래스의 인터페이스
//


#pragma once


class CImagePSHDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CImagePSHDoc() noexcept;
	DECLARE_DYNCREATE(CImagePSHDoc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CImagePSHDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();

	// ==================== 영상 처리 =========================
	unsigned char** malloc2D(int h, int w);
	void free2D(unsigned char** memory, int h);
	unsigned char** m_InputImageR = NULL;
	unsigned char** m_InputImageG = NULL;
	unsigned char** m_InputImageB = NULL;
	unsigned char** m_OutputImageR = NULL;
	unsigned char** m_OutputImageG = NULL;
	unsigned char** m_OutputImageB = NULL;
	int m_inH = 0;
	int m_inW = 0;
	int m_outH = 0;
	int m_outW = 0;
	void OnEqualImage();
	double doubleABS(double x);
	double** malloc2D_double(int h, int w);
	void free2D_double(double** memory, int h);
	void OnBw127Image();
	void OnBwInputImage();
	void OnGrayImage();
	void OnNgtvImage();
	void OnLightPmImage();
	void OnLightMdImage();
	void OnParaCapImage();
	void OnParaCupImage();
	void OnGammaImage();
	void OnZminNrmlImage();
	void OnZminNhImage();
	void OnZminYsImage();
	void OnZoutImage();
	void OnTurnImage();
	void OnMoveImage();
	void OnMirrorUdImage();
	void OnMirrorLrImage();
	void OnEmbosImage();
	void OnBlrAvgImage();
	void OnBlrGausImage();
	void OnHpfImage();
	void OnLpfImage();
	void OnCalcUsaImage();
	void OnCalcMnsImage();
	void OnRbrtsImage();
	void OnPrwImage();
	void OnSoblImage();
	void OnLaplaImage();
	void OnLogImage();
	void OnDogImage();
	void OnHistChartImage();
	void OnHistStchImage();
	void OnHistEqualImage();
	void OnBwAvgImage();

	// ================ Redo, Undo 부분 ====================
	// // 활동 정보 저장 및 처리
	void AddPoint(char* functionName, double input);
	// 뒤로가기 Ctrl + Z
	void Undo();
	void Redo();
	// 파일 입출력 및 사진bin파일저장
	void AutoSavePoint();
	void ActionRun(char* functionName, double input);
	void OnBwInputImageUnRe(double input);
	void OnLightPmImageUnRe(double input);
	void OnLightMdImageUnRe(double input);
	void OnGammaImageUnRe(double input);
	void OnZminNrmlImageUnRe(double input);
	void OnZminNhImageUnRe(double input);
	void OnZminYsImageUnRe(double input);
	void OnZoutImageUnRe(double input);
	void OnTurnImageUnRe(double input);
	void OnMoveImageUnRe(double input);
	void OnBlrAvgImageUnRe(double input);
	// 저장할 때 temp 파일 삭제
	void DeletSavPoint();
};
