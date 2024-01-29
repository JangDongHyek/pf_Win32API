#pragma once

/*
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


BOOL TranslateMessage(
  [in] const MSG *lpMsg
);
# 메세지에 값을 이벤트에 대응하는 메세지로 변환하는 함수인자값이 주소값인이유


LRESULT DispatchMessage(
  [in] const MSG *lpMsg
);
# TranslateMessage로 변환된 메세지를 WndProc으로 보내는 함수


HDC GetDC(
  [in] HWND hWnd
);
# 인자값의 핸들프로그램의 DC(Device Context)를 가져온다
# 프로그램에 그림을 그릴수있는 구조체? 장치?


BOOL Rectangle(
  [in] HDC hdc,
  [in] int left,
  [in] int top,
  [in] int right,
  [in] int bottom
);
# 해당 hdc에 인자값의 위치에 사각형을 그리는 함수


*/