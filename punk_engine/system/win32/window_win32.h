/*
File: Window.h
	Author: Abramov Nickolai
	Description: Wrapper around os api
	*/

#ifndef _H_WIN32_WINDOW
#define _H_WIN32_WINDOW

#include <windows.h>
#include <map>
#include "types_win32.h"
#include "../config.h"
#include "../string.h"
#include "../singletone.h"

namespace System
{
	LRESULT CALLBACK WindowCallBack(HWND, UINT, WPARAM, LPARAM);

	SingletoneInterface(Window, LIB_SYSTEM);

	class LIB_SYSTEM Window : public Singletone(Window)
	{
	public:
		Window();
		~Window();
//		void SubscribeHandler(unsigned message, Handler handler);
//		void UnsubscribeHandler(unsigned message, Handler handler);
//		void SetAsGlobalDesktop();
		int GetDesktopWidth() const;
		int GetDesktopHeight() const;
		int GetDesktopBitsPerPixel() const;
		int GetDesktopRefreshRate() const;
		int GetWidth() const;
		int GetHeight() const;
		int GetX() const;
		int GetY() const;
		void SetSize(int width, int height);
		void SetPosition(int x, int y);
		int Loop();
		void SetTitle(const string& text);
		string GetTitle() const;

		void Quite();
		operator HWND ();

		void DrawPixel(int x, int y);
		void DrawPixel(int x, int y, int r, int g, int b);
		void DrawLine(int x1, int y1, int x2, int y2);
		void SwapBuffer();
	private:

		//std::multimap<unsigned, Handler> m_handlers;
		HWND m_windowHandle;
		friend LRESULT CALLBACK WindowCallBack(HWND, UINT, WPARAM, LPARAM);
	};
}

#endif	//_H_WIN32_WINDOW