#ifndef KBHOOK_HPP
#define KBHOOK_HPP

#include <iostream>
#include <windows.h>

class KbHook {
private:
	HHOOK keyboardHook;
	static LRESULT CALLBACK KbProc(int nCode, WPARAM wParam, LPARAM lParam);

public:
	KbHook();
	~KbHook();
	void start();
};

#endif
