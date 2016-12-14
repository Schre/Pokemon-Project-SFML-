#include "mainApplication.h"
#include <Windows.h>

Application::Application()
{
	mainPage.create(sf::VideoMode(800, 600), "Main Page");
}

void Application::runApp()
{
	// INITIATE VARIABLES
	FreeConsole(); // close console
	MainPlayer player;
	Opponent opponent("Opponent Joe");
	bool firstIteration = true; // initiate map on first iteration
	Map mainMap("Area1.txt");
	mainMap.loadCurrentMap();
	mainCamera.playerCamera(View, player.getPlayerPosition(), false);
	mainPage.setView(View);
	mainMap.drawCurrentMap(mainPage);
	player.updateMap(mainMap);
	player.Party.insertAtFront(10, 10, 10, "Picachu", "Tackle", "Growl", "", "");
	opponent.Party.insertAtFront(10, 10, 10, "Squirtle", "Tackle", "Growl", "", "");
	/////////////////////

	//startBattle(player, opponent);

	// main game loop
	while (mainPage.isOpen())
	{
		mainMap.drawCurrentMap(mainPage);
		player.updatePlayer(Event, mainPage, mainMap, View, mainCamera);
		while (mainPage.pollEvent(Event))
		{
			if (Event.key.code == sf::Keyboard::R)
			{
				player.setRunMode();
			}
			if (Event.type == sf::Event::Closed)
			{
				mainPage.close();
			}
			_sleep(15); // avoid using too much processing power
		}
		// event operations/////////////////////////////////////////////
		//updatePlayer(mainMap, Event, player); // also updates map shifting
		////////////////////////////////////////////////////////////////

		// DISPLAY SCREEN
		if (firstIteration == true)
		{
			firstIteration = false;
			mainPage.display();
			mainPage.clear();
		}
		//
	}
	system("pause");
}

void Application::updatePlayer(Map & mainMap, sf::Event &Event, MainPlayer &player)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
			mainMap.drawCurrentMap(mainPage);
			player.updatePlayer(Event, mainPage, mainMap, View, mainCamera);			
	}
	else
	{
		Event.key.code = sf::Keyboard::Unknown;
	}

}

bool Application::startBattle(MainPlayer & player, Opponent & opponent)
{
	bool battleIsOver = false;
	PokemonObject *pPlayerIndex = player.Party.getHeadPtr();
	PokemonObject *pOpponentIndex = opponent.Party.getHeadPtr();

	while (!battleIsOver)
	{
		while (pPlayerIndex != nullptr && pPlayerIndex->hasFainted() == true) // calculate current pokemon
		{
			pPlayerIndex = pPlayerIndex->getNextPtr();
		}
		while (pOpponentIndex != nullptr && pOpponentIndex->hasFainted() == true) // calculate current pokemon
		{
			pOpponentIndex = pOpponentIndex->getNextPtr();
		}

		system("cls");
		std::cout << "Battling..." << std::endl << std::endl << "vs " << opponent.getName() << std::endl << std::endl;


		if (player.Party.getTotalPokemonAlive() > 0 && opponent.Party.getTotalPokemonAlive() > 0)
		{
			std::cout << "Player Pokemon: " << pPlayerIndex->getName() << "   " << " -)|(- "<< "   Opponent Pokemon: " << pOpponentIndex->getName();

			// check speed first of pokemon to decide who goes first

			if (pPlayerIndex->getSpeed() >= pOpponentIndex->getSpeed())
			{
				// Player goes first if faster
				std::cout << std::endl << std::endl << "Player's turn";
				playerTurn(pPlayerIndex, pOpponentIndex);
			}
			else
			{
				// opponent goes first
				std::cout << std::endl << std::endl << "Opponent's turn";
				opponentTurn(pPlayerIndex, pOpponentIndex);
			}
		}
		else
		{
			battleIsOver = true;
		}
		_sleep(20);
	}
	std::cout << std::endl;
	system("pause");
	return true;
}

void Application::playerTurn(PokemonObject *& playerPokemon, PokemonObject *& opponentPokemon)
{
}

void Application::opponentTurn(PokemonObject *& playerPokemon, PokemonObject *& opponentPokemon)
{
}
