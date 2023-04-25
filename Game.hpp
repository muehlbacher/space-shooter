#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Asteroid.hpp"

class CGame
{
	public:
		CGame ();

		void Init ();
		void Run  ();
		void Quit ();

	private:
		void ProcessEvents   ();
		void SpawnAsteroids  ();
		void RenderAsteroids ();
		void CheckCollisions ();

		CPlayer *m_pPlayer;             // Spieler-Instanz
		CSprite *m_pSpriteBackground;   // Sprite f?r den Hintergrund
		CSprite *m_pSpriteAsteroid;     // Sprite f?r die Asteroiden
		float    m_fAsteroidTimer;      // Zeitgeber f?r n?chsten Asteroiden
		bool     m_bGameRun;            // L?uft das Spiel noch?
		list<CAsteroid> m_AsteroidList; // Liste der Asteroiden

};

#endif
