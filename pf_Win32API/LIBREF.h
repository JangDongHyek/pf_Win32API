#pragma once

/*
BOOL PeekMessageA(
  [out]          LPMSG lpMsg,
  [in, optional] HWND  hWnd,
  [in]           UINT  wMsgFilterMin,
  [in]           UINT  wMsgFilterMax,
  [in]           UINT  wRemoveMsg
); 
# �޽��� ť���� �޽����� �д� �Լ� 
# ������������ �޽����� ������������
# ť�� ��������� ��������ʰ� ������ ���ش�


BOOL TranslateMessage(
  [in] const MSG *lpMsg
);
# �޼����� ���� �̺�Ʈ�� �����ϴ� �޼����� ��ȯ�ϴ� �Լ����ڰ��� �ּҰ�������


LRESULT DispatchMessage(
  [in] const MSG *lpMsg
);
# TranslateMessage�� ��ȯ�� �޼����� WndProc���� ������ �Լ�


HDC GetDC(
  [in] HWND hWnd
);
# ���ڰ��� �ڵ����α׷��� DC(Device Context)�� �����´�
# ���α׷��� �׸��� �׸����ִ� ����ü? ��ġ?


BOOL Rectangle(
  [in] HDC hdc,
  [in] int left,
  [in] int top,
  [in] int right,
  [in] int bottom
);
# �ش� hdc�� ���ڰ��� ��ġ�� �簢���� �׸��� �Լ�


*/