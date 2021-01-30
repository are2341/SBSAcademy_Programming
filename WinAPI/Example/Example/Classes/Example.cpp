#include "Example_01/Example_01.h"
#include "Example_02/Example_02.h"
#include "Example_03/Example_03.h"

//! 메인 함수
int WINAPI _tWinMain(HINSTANCE a_hInst, HINSTANCE a_hPrevInst, TCHAR *a_pszCmdLine, int a_nShowOpts) {
	SIZE stWndSize = {
		480, 320
	};

	//Example_01 oApp(a_hInst, stWndSize, a_nShowOpts);
	//Example_02 oApp(a_hInst, stWndSize, a_nShowOpts);
	Example_03 oApp(a_hInst, stWndSize, a_nShowOpts);

	return oApp.run();
}
