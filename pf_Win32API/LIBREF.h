#pragma once

/*
***********************************************
BOOL PeekMessageA(
  [out]          LPMSG lpMsg,
  [in, optional] HWND  hWnd,
  [in]           UINT  wMsgFilterMin,
  [in]           UINT  wMsgFilterMax,
  [in]           UINT  wRemoveMsg
); 
# 메시지 큐에서 메시지를 읽는 함수 
# 무조건적으로 메시지를 삭제하지않음
# 큐가 비어있을떄 대기하지않고 리턴을 해준다
***********************************************


***********************************************
BOOL TranslateMessage(
  [in] const MSG *lpMsg
);
# 메세지에 값을 이벤트에 대응하는 메세지로 변환하는 함수인자값이 주소값인이유
***********************************************


***********************************************
LRESULT DispatchMessage(
  [in] const MSG *lpMsg
);
# TranslateMessage로 변환된 메세지를 WndProc으로 보내는 함수
***********************************************


***********************************************
HDC GetDC(
  [in] HWND hWnd
);
# 인자값의 핸들프로그램의 DC(Device Context)를 가져온다
# 프로그램에 그림을 그릴수있는 구조체? 장치?
***********************************************


***********************************************
BOOL Rectangle(
  [in] HDC hdc,
  [in] int left,
  [in] int top,
  [in] int right,
  [in] int bottom
);
# 해당 hdc에 인자값의 위치에 사각형을 그리는 함수
***********************************************


***********************************************
BOOL GetKeyboardState(
  [out] PBYTE lpKeyState
);
# 인자로 받는 vector에 키보드의 상태를 가져와 덮어 씌워준다 성공시 True반환 실패시 False반환
# 즉 vector안의 각각의 값들이 키별로 상태값이 저장된다
***********************************************


***********************************************
BOOL GetCursorPos(
  [out] LPPOINT lpPoint
);
# 현재 화면의 마우스 좌표를 가져온다 성공시 0이아닌값 실패시 0을 반환한다
***********************************************


***********************************************
BOOL QueryPerformanceFrequency(
  [out] LARGE_INTEGER *lpFrequency
);
# 설치된 하드웨어의 고성능 타이머 주파수를 가져오는 함수 실패시 0 성공시 0이아닌값
***********************************************


***********************************************
BOOL QueryPerformanceCounter(
  [out] LARGE_INTEGER *lpPerformanceCount
);
#위의해당하는 함수 타이머를 사용하여 시스템의 경과된 시간을 측정하는함수
# 성공시 True 실패시 False를 반환한다
***********************************************


***********************************************
BOOL TextOutW(
  [in] HDC     hdc,
  [in] int     x,
  [in] int     y,
  [in] LPCWSTR lpString,
  [in] int     c
);
# 해당 DC 원하는 좌표에 글자를 쓰는 함수
***********************************************


static_assert( constant-expression, string-literal );
# 함수인자내 표현식이 False일경우 에러를뱉어내고 Ture일경우 넘어간다
# 컴파일단계에서 잡아주고 잡혔을떈 C2338로 에러를 뱉어낸다


template <class From, class To>
struct is_convertible;
# From 형식이 To 형식으로 변할수있는지 체킹하는 함수
# 올바른 형식일시 True 아닐시 False
*/