//
// Created by Lukasz Stachon on 04/06/2021.
//

#ifndef KOLKOKRZYZYKPROJEKT_WINNINGSEQ_H
#define KOLKOKRZYZYKPROJEKT_WINNINGSEQ_H


class winningSeq {
public:
	int win = 0;
	int board[3][3];
	int** check_if_won();
	void restart_board();
};


#endif //KOLKOKRZYZYKPROJEKT_WINNINGSEQ_H
