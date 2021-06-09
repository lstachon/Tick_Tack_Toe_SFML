//
// Created by Lukasz Stachon on 04/06/2021.
//

#ifndef KOLKOKRZYZYKPROJEKT_TIC_TAC_TOE_H
#define KOLKOKRZYZYKPROJEKT_TIC_TAC_TOE_H

#include <SFML/Graphics.hpp>
#include "textureRouting.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "winningSeq.h"


struct Tile
{
	sf::RectangleShape shape;
};

class tic_tac_toe {
private:
	sf::Vector2u WINDOW_SIZE{ 900,900 };
	sf::Vector2f TILE_SIZE{ 300.f,300.f };
	sf::Vector2f MENU_SIZE{900.f, 900.f };
	sf::RenderWindow window{ sf::VideoMode{WINDOW_SIZE.x,WINDOW_SIZE.y},"" };
	sf::Texture X;
	sf::Texture O;
	sf::Texture X_WIN;
	sf::Texture O_WIN;
	sf::Texture MENU;
	bool multi;
	bool taken[3][3];
	int Ctr;
	int moves;
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	void loadTextures();
	void start();
	void game();
	sf::View view;
	winningSeq seq;

public:
	tic_tac_toe();
};


#endif //KOLKOKRZYZYKPROJEKT_TIC_TAC_TOE_H
