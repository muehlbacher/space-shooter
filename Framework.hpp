#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <iostream>
#include "Singleton.hpp"
#include "Timer.hpp"

using namespace std;

#define g_pFramework CFramework::Get()

class CFramework : public TSingleton<CFramework>
{
	public:
		bool  Init    (int ScreenWidth, int ScreenHeight, int ColorDepth, bool bFullscreen);
		void  Quit    ();
		void  Update  ();
		void  Clear   ();
		void  Flip    ();
		bool  KeyDown (int Key_ID);
		SDL_Window *GetScreen () {return m_pWindow;}
        SDL_Renderer *GetRenderer(){return m_pRenderer;}

	private:
		SDL_Window        *m_pWindow;   // Surface f�r den Screen
		const Uint8       *m_pKeystate; // Array f�r aktuellen Tastaturstatus
        SDL_Renderer      *m_pRenderer = NULL;


};

#endif
