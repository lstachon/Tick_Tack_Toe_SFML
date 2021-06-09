//
// Created by Lukasz Stachon on 04/06/2021.
//

#include "winningSeq.h"

int **winningSeq::check_if_won() {
	int **result;
	result = new int*[3];
	for (int h = 0; h < 3; h++){
		result[h] = new int[3];
		for (int w = 0; w < 3; w++){
			result[h][w] = 0;
		}
	}

	if(board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1){
		result[0][0] = 1;
		result[0][1] = 1;
		result[0][2] = 1;
		win = 1;
		return result;
	}
	if(board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1){
		result[1][0] = 1;
		result[1][1] = 1;
		result[1][2] = 1;
		win = 1;
		return result;
	}
	if(board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1){
		result[2][0] = 1;
		result[2][1] = 1;
		result[2][2] = 1;
		win = 1;
		return result;
	}
	if(board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1){
		result[0][0] = 1;
		result[1][0] = 1;
		result[2][0] = 1;
		win = 1;
		return result;
	}
	if(board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1){
		result[0][1] = 1;
		result[1][1] = 1;
		result[2][1] = 1;
		win = 1;
		return result;
	}
	if(board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1){
		result[0][2] = 1;
		result[1][2] = 1;
		result[2][2] = 1;
		win = 1;
		return result;
	}
	if(board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1){
		result[0][0] = 1;
		result[1][1] = 1;
		result[2][2] = 1;
		win = 1;
		return result;
	}
	if(board[2][0] == 1 && board[1][1] == 1 && board[0][2] == 1){
		result[2][0] = 1;
		result[1][1] = 1;
		result[0][2] = 1;
		win = 1;
		return result;
	}



	if(board[0][0] == 2 && board[0][1] == 2 && board[0][2] == 2){
		result[0][0] = 2;
		result[0][1] = 2;
		result[0][2] = 2;
		win = 2;
		return result;
	}
	if(board[1][0] == 2 && board[1][1] == 2 && board[1][2] == 2){
		result[1][0] = 2;
		result[1][1] = 2;
		result[1][2] = 2;
		win = 2;
		return result;
	}
	if(board[2][0] == 2 && board[2][1] == 2 && board[2][2] == 2){
		result[2][0] = 2;
		result[2][1] = 2;
		result[2][2] = 2;
		win = 2;
		return result;
	}
	if(board[0][0] == 2 && board[1][0] == 2 && board[2][0] == 2){
		result[0][0] = 2;
		result[1][0] = 2;
		result[2][0] = 2;
		win = 2;
		return result;
	}
	if(board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 2){
		result[0][1] = 2;
		result[1][1] = 2;
		result[2][1] = 2;
		win = 2;
		return result;
	}
	if(board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 2){
		result[0][2] = 2;
		result[1][2] = 2;
		result[2][2] = 2;
		win = 2;
		return result;
	}
	if(board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2){
		result[0][0] = 2;
		result[1][1] = 2;
		result[2][2] = 2;
		win = 2;
		return result;
	}
	if(board[2][0] == 2 && board[1][1] == 2 && board[0][2] == 2){
		result[2][0] = 2;
		result[1][1] = 2;
		result[0][2] = 2;
		win = 2;
		return result;
	}

	return result;
}

void winningSeq::restart_board() {
	for(int i = 0; i < 3 ;i++){
		for(int j = 0; j < 3 ; j++){
			board[i][j] = 0;
		}
	}
}
