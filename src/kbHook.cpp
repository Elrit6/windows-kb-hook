#include <iostream>
#include <windows.h>
#include "kbHook.hpp"

// private

LRESULT CALLBACK KbHook::KbProc(int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode >= 0) {
		KBDLLHOOKSTRUCT* pKeyboard = (KBDLLHOOKSTRUCT*)lParam;
		if (wParam == WM_KEYDOWN)
			std::cout << "pressed: " << pKeyboard->vkCode << std::endl;
        if (wParam == WM_KEYUP)
			std::cout << "released: " << pKeyboard->vkCode << std::endl;

	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

// public

KbHook::KbHook() {
	keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KbProc, NULL, 0);
	if (keyboardHook == NULL)
		std::cerr << "Failed to install the keyboard hook." << std::endl;
}

KbHook::~KbHook() {
	if (keyboardHook != NULL)
		UnhookWindowsHookEx(keyboardHook);
}

void KbHook::start() {
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	 }
}


