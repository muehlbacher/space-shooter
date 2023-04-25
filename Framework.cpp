#include "Framework.hpp"

// Init
//
// Aufgabe: Framework initialisieren
//
bool CFramework::Init (int ScreenWidth, int ScreenHeight,
					   int ColorDepth, bool bFullscreen)
{
	// Alle Systeme der SDL initialisieren
	if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1 )
	{
		cout << "SDL konnte nicht initialisiert werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;

		Quit ();

		return (false);
	}

	// Vollbild oder Fenstermodus einstellen
	if (bFullscreen == true)
	{
            m_pWindow = SDL_CreateWindow("My Game VWindow",
                                         SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                         ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

            m_pRenderer = SDL_CreateRenderer( m_pWindow, -1, SDL_RENDERER_ACCELERATED );
            if( m_pRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );

            }
            //Old Version -> not supported anymore, cause of new function
            //which supports multiple windows
            // m_pScreen = SDL_SetVideoMode (ScreenWidth, ScreenHeight, ColorDepth,
			//SDL_HWSURFACE | SDL_DOUBLEBUF |
			//SDL_FULLSCREEN);
	}
	else
	{
        m_pWindow = SDL_CreateWindow("My Game VWindow",
                                                  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                                  ScreenWidth, ScreenHeight, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
        m_pRenderer = SDL_CreateRenderer( m_pWindow, -1, SDL_RENDERER_ACCELERATED );

        //SDL_SetVideoMode (ScreenWidth, ScreenHeight, ColorDepth,
			//SDL_HWSURFACE | SDL_DOUBLEBUF);
	}

	// Pr�fen, ob alles funktioniert hat
	if (m_pWindow == NULL)
	{
		cout << "Videomodus konnte nicht gesetzt werden!" << endl;
		cout << "Fehlermeldung: " << SDL_GetError () << endl;

		Quit ();

		return (false);
	}

	// Zeiger auf internes Array f�r Tastaturstatus ermitteln
	m_pKeystate = SDL_GetKeyboardState(NULL);

	// Alles ging glatt, also true zur�ckliefern
	return (true);

} // Init

// Quit
//
// Aufgabe: Framework (SDL) beenden
//
void CFramework::Quit ()
{
	// SDL beenden
	SDL_Quit ();

} // Quit

// Update
//
// Aufgabe: Timer und Keyboardstatus updaten
//
void CFramework::Update ()
{
	// Timer updaten
	g_pTimer->Update ();

	// Tastaturstatus ermitteln
	SDL_PumpEvents ();

} // Update

// Keydown
//
// Aufgabe: Tastendruck abfragen
//
bool CFramework::KeyDown (int Key_ID)
{
	// Pr�fen, ob Taste gedr�ckt ist
	return (m_pKeystate[Key_ID] ? true : false);
    //return (m_pKeystate[0] ? true : false);

} // KeyDown

// Clear
//
// Aufgabe: Buffer l�schen
//
void CFramework::Clear ()
{
	// Buffer (Surface) mit Hintergrundfarbe f�llen

    SDL_Surface * m_pSurface = SDL_GetWindowSurface(m_pWindow);

    SDL_FillRect (m_pSurface, NULL,
		SDL_MapRGB (m_pSurface->format, 0, 0, 0));

} // Clear

// Flip
//
// Aufgabe: Surface umschalten (flippen)
//
void CFramework::Flip ()
{
    //Updates Screen
    SDL_RenderPresent( m_pRenderer );

    //SDL_Flip (m_pScreen);

} // Flip

