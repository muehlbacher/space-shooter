#include "Framework.hpp"
#include "Game.hpp"

int main (int argc, char *argv[])
{
	// Framework initialisieren
	if (g_pFramework->Init (800, 600, 16, true) == false)
		return (0);

	// Neue Instanz des Spiels
	CGame Game;

	// Spiel initialisieren
	Game.Init ();

	// Spiel laufen lassen. Diese Funktion l?uft so lange,
	// bis das Spiel geschlossen oder die Escape-Taste
	// gedr?ckt wird
	Game.Run ();

	// Spiel beenden
	Game.Quit ();

	// Framework beenden
	g_pFramework->Quit ();
	g_pFramework->Del ();

	return (0);

}
