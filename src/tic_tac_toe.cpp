//
// Created by Lukasz Stachon on 04/06/2021.
//

#include "tic_tac_toe.h"

using namespace std;

void tic_tac_toe::loadTextures() {
	if (!X.loadFromFile(Routing::X_PATH)) {
		std::cout << "textures not foud";
		exit(1);
	}
	if (!X_WIN.loadFromFile(Routing::X_WIN_PATH)){
		std::cout << "textures not foud";
		exit(1);
	}
	if (!O.loadFromFile(Routing::O_PATH)){
		std::cout << "textures not foud";
		exit(1);
	}
	if (!O_WIN.loadFromFile(Routing::O_WIN_PATH)){
		std::cout << "textures not foud";
		exit(1);
	}
	if (!MENU.loadFromFile(Routing::MENU_PATH)){
		std::cout << "textures not foud";
		exit(1);
	}
}


tic_tac_toe::tic_tac_toe() {
	loadTextures();
	window.setFramerateLimit(20);
	window.setPosition(sf::Vector2i{ window.getPosition().x,0 });
	view = window.getDefaultView();
	game();
}

void tic_tac_toe::game() {

	for(auto & i : taken){
		for(bool & j : i){
			j = false;
		}
	}

	Ctr=0;
	moves = 0;
	seq.restart_board();
	seq.win = 0;

	std::vector<std::vector<Tile>> doubleTileMap;
	auto x=0, y=0;
	doubleTileMap.emplace_back();
	auto tile = new Tile();
	tile->shape.setSize({MENU_SIZE.x, MENU_SIZE.y });
	tile->shape.setFillColor({sf::Color::White});
	doubleTileMap[y].push_back(*tile);
	doubleTileMap[y][x].shape.setTexture(&MENU, false);

	int flag =0;
	while (window.isOpen() && flag == 0) {
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		sf::Event event{};
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed ||
				event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
				exit(0);
			}
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
					case sf::Keyboard::S:
						flag =1 ;
						multi = false;
						std::cout << "singleplayer\n";
						break;
					case sf::Keyboard::M:
						flag =1 ;
						multi = true;
						std::cout << "multiplayer\n";
						break;
					default:
						break;
				}
			}
			if (event.type == sf::Event::Resized) {
				view.setSize(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
			}
		}

		window.setView(view);
		window.clear();
		for (auto& index : doubleTileMap) {
			for (auto& it : index) {
				window.draw(it.shape);
			}
		}
		window.setView(window.getDefaultView());
		window.display();

	}
	start();
}

void tic_tac_toe::start() {
	std::vector<std::vector<Tile>> doubleTileMap;
	for (auto y = 0; y < WINDOW_SIZE.y / TILE_SIZE.y; y++) {
		for (auto x = 0; x < WINDOW_SIZE.x / TILE_SIZE.x; x++) {
			doubleTileMap.emplace_back();
			auto tile = new Tile();
			tile->shape.setSize({ TILE_SIZE.x,TILE_SIZE.y });
			tile->shape.setFillColor({sf::Color::White});
			tile->shape.setOutlineThickness(4.0f);
			tile->shape.setOutlineColor({ sf::Color::Black });
			tile->shape.setPosition(x * TILE_SIZE.x, y * TILE_SIZE.y);
			doubleTileMap[y].push_back(*tile);
		}
	}

	while (window.isOpen() && seq.win == 0) {

		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;

		sf::Event event{};

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
				exit(0);
			}
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
					case sf::Keyboard::R:
						game();
						break;
					default:
						break;
				}
			}
			if (event.type == sf::Event::Resized) {
				view.setSize(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
			}
		}

		auto mousePos = sf::Mouse::getPosition(window);
		auto mouseWorldPos = window.mapPixelToCoords(mousePos, view);

		window.setTitle("Mouse Position: (" + std::to_string(int(mouseWorldPos.y / 300.f))  + ", " +
						std::to_string(int(mouseWorldPos.x / 300.f)) + ")");

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (mouseWorldPos.x >= 0 && mouseWorldPos.y >= 0 &&
				mouseWorldPos.x < WINDOW_SIZE.x && mouseWorldPos.y < WINDOW_SIZE.y){
				auto position = mousePos;
				position.x = int(mouseWorldPos.x / 300.f);
				position.y = int(mouseWorldPos.y / 300.f);

				if(position.x>=0 && position.x<=2) {
					if (position.y >= 0 && position.y <= 2) {
						if(!taken[position.y][position.x]) {
							if (Ctr % 2 == 0) {
								doubleTileMap[position.y][position.x].shape.setTexture(&X, false);
								seq.board[position.y][position.x] = 1;
								moves++;
								if(!multi){
									taken[position.y][position.x] = true;
									if(moves < 5){
										srand(time(NULL));
										int x = rand()% 3 + 0;
										int y = rand()% 3 + 0;
										while(taken[y][x]){
											x = rand()% 3 + 0;
											y = rand()% 3 + 0;
										}

										taken[y][x] = true;
										doubleTileMap[y][x].shape.setTexture(&O, false);
										seq.board[y][x] = 2;
									}
								}
							} else {
								doubleTileMap[position.y][position.x].shape.setTexture(&O, false);
								seq.board[position.y][position.x] = 2;
							}
							if(multi) {
								taken[position.y][position.x] = true;
								Ctr++;
							}
							int **winArr = seq.check_if_won();
							for(int i = 0 ; i < 3; i++){
								for(int j = 0; j < 3 ; j++){
									if(winArr[i][j] == 1) {
										doubleTileMap[i][j].shape.setTexture(&X_WIN, false);
									}
									if(winArr[i][j] == 2) {
										doubleTileMap[i][j].shape.setTexture(&O_WIN, false);
									}
								}
							}
							for (int h = 0; h < 3; h++){
								delete [] winArr[h];
							}
							delete [] winArr;
							winArr = 0;
						}
					}
				}
			}
		}

		window.setView(view);

		window.clear();

		for (auto& index : doubleTileMap) {
			for (auto& it : index) {
				window.draw(it.shape);
			}
		}

		window.setView(window.getDefaultView());

		window.display();

		if(seq.win != 0){
			sf::sleep(sf::seconds(2.0));
		}

		if(moves == 5){
			sf::sleep(sf::seconds(1.0));
			game();
		}
	}
	game();
}





