//#include <iostream>
//#include<chrono>
//#include<fstream>
//#include<iomanip>
//#include<string>
//using namespace std;
//using namespace std::chrono;
//bool white_en_passant = false;
//bool black_en_passant = false;
//bool white_king_first_move = true;
//bool black_king_first_move = true;
//bool white_a1_rook_not_moved = true;
//bool white_h1_rook_not_moved = true;
//bool black_a8_rook_not_moved = true;
//bool black_h8_rook_not_moved = true;
//bool handshake = false;
//bool resign = false;
//int white_time;
//int black_time;
//int mode_choice;
//bool isvalidmove(char board[8][8], bool isplayeroneturn, char src[2], char dst[2]);
//void displayboard(char board[][8]) {
//	cout << right << setw(85) << "GAME DATA" << endl;
//	cout << right << setw(100) << "Player 1: White (Upper Case)" << endl;
//	cout << right << setw(100) << "Player 2: Black (Lower Case)" << endl;
//	cout << right << setw(90) << "White Player Time:" << white_time << " seconds" << endl;
//	cout << right << setw(90) << "Black Player Time:" << black_time << " seconds" << endl;
//	if (mode_choice == 1 || mode_choice == 2 || mode_choice == 3)
//	{
//		cout << right << setw(99) << "To RESIGN press R in source" << endl;
//		cout << right << setw(102) << "To HANDSHAKE press H in source" << endl;
//	}
//	cout << right << setw(97) << "Press 0 to exit in source" << endl;
//	cout << "  a b c d e f g h" << endl;
//	cout << "  ________________" << endl;
//	int r = 8;
//	for (int i = 0; i < 8; i++) {
//		cout << r << "|";
//		for (int j = 0; j < 8; j++) {
//			cout << board[i][j] << " ";
//		}
//		cout << "|" << r;
//		cout << endl;
//		r--;
//	}
//	cout << "  ________________" << endl;
//	cout << "  a b c d e f g h" << endl;
//}
//
//char getgoti(char board[8][8], char idx[2]) {
//	return board[abs(idx[1] - 56)][idx[0] - 97];
//}
//
//void setgoti(char board[8][8], char idx[2], char goti) {
//	board[abs(idx[1] - 56)][idx[0] - 97] = goti;
//}
//
//bool isanyrook(char piece) {
//	return (piece == 'R' || piece == 'r');
//}
//
//bool isanyking(char piece) {
//	return (piece == 'K' || piece == 'k');
//}
//
//bool iswhitepiece(char piece) {
//	if (
//		piece == 'P' ||
//		piece == 'R' ||
//		piece == 'H' ||
//		piece == 'B' ||
//		piece == 'Q' ||
//		piece == 'K')
//	{
//		return true;
//	}
//	else
//		return false;
//}
//
//bool isblackpiece(char piece)
//{
//	if (
//		piece == 'p' ||
//		piece == 'r' ||
//		piece == 'h' ||
//		piece == 'b' ||
//		piece == 'q' ||
//		piece == 'k')
//	{
//		return true;
//	}
//	else
//		return false;
//}
//
//bool p1_pawn(char board[8][8], char src[2], char dst[2]) {
//	int i1 = abs(src[1] - 56);
//	int j1 = src[0] - 97;
//	int i2 = abs(dst[1] - 56);
//	int j2 = dst[0] - 97;
//	if (i1 == i2 && j1 == j2)
//		return false;
//	else if (i1 == i2 && j1 != j2)
//		return false;
//	else if (i1 <= i2)
//		return false;
//	else if (board[i2][j2] > 97 && board[i2][j2] < 123) {
//		if (j1 != j2) {
//			if (abs(j1 - j2) == 1) {
//				if ((i2 < i1) && (abs(i1 - i2) == 1))
//					return true;
//				else
//					return false;
//			}
//			else
//				return false;
//		}
//		else
//			return false;
//	}
//	else if (i1 == 6) {
//		if ((abs(i1 - i2) == 2) && j1 == j2 && board[i2 + 1][j2] == ' ' && board[i2][j2] == ' ' || (abs(i1 - i2) == 1) && j1 == j2 && board[i2][j2] == ' ') {
//			if (abs(i1 - i2) == 2)
//				white_en_passant = true;
//			return true;
//		}
//		else
//			return false;
//	}
//	else if (j1 == j2 && abs(i1 - i2) == 1 && i2 != 0)
//		return true;
//	else
//		return false;
//}
//
//bool p2_pawn(char board[8][8], char src[2], char dst[2]) {
//	int i1 = abs(src[1] - 56);
//	int j1 = src[0] - 97;
//	int i2 = abs(dst[1] - 56);
//	int j2 = dst[0] - 97;
//	if (i1 == i2 && j1 == j2)
//		return false;
//	else if (i1 == i2 && j1 != j2)
//		return false;
//	else if (i1 >= i2)
//		return false;
//	else if (board[i2][j2] > 64 && board[i2][j2] < 91) {
//		if (j1 != j2) {
//			if (abs(j1 - j2) == 1) {
//				if ((i2 > i1) && (abs(i1 - i2) == 1))
//					return true;
//				else
//					return false;
//			}
//			else
//				return false;
//		}
//		else
//			return false;
//	}
//	else if (i1 == 1) {
//		if ((abs(i1 - i2) == 2) && j1 == j2 && board[i2 - 1][j2] == ' ' && board[i2][j2] == ' ' || (abs(i1 - i2) == 1) && j1 == j2 && board[i2][j2] == ' ') {
//			if (abs(i1 - i2) == 2)
//				black_en_passant = true;
//			return true;
//		}
//		else
//			return false;
//	}
//	else if (j1 == j2 && abs(i1 - i2) == 1 && i2 != 7)
//		return true;
//	else
//		return false;
//}
//
//bool isvalidhorsemove(char board[8][8], bool isplayeroneturn, char src[2], char dst[2])
//{
//	int i1 = abs(src[1] - 56);
//	int j1 = src[0] - 97;
//	int i2 = abs(dst[1] - 56);
//	int j2 = dst[0] - 97;
//	if (i1 == i2 && j1 == j2)
//		return false;
//	else if (isplayeroneturn && (!iswhitepiece(getgoti(board, dst))) || (!isplayeroneturn) && (!isblackpiece(getgoti(board, dst)))) {
//		if (abs(i1 - i2) + abs(j1 - j2) == 3 && abs(i1 - i2) != 0 && abs(j1 - j2) != 0)
//			return true;
//		else
//			return false;
//	}
//	else
//		return false;
//}
//
//bool islocationunderattack(char board[8][8], bool isplayeroneturn, char location[2]) {
//	for (int row = 0; row < 8; row++) {
//		for (int col = 0; col < 8; col++) {
//			char current_src[2] = { char('a' + col), char('8' - row) };
//			if (isvalidmove(board, isplayeroneturn, current_src, location))
//				return true;
//		}
//	}
//	return false;
//}
//
//bool isvalidkingcastling(char board[8][8], char src[2], char dst[2]) {
//	int i1 = '8' - src[1];
//	int j1 = src[0] - 'a';
//	int i2 = '8' - dst[1];
//	int j2 = dst[0] - 'a';
//	bool isplayeroneturn = iswhitepiece(getgoti(board, src));
//	if (i1 == i2 && abs(j1 - j2) == 2) { // castling
//		if (
//			isplayeroneturn && (white_king_first_move && white_h1_rook_not_moved || white_king_first_move && white_a1_rook_not_moved) ||
//			(!isplayeroneturn) && (black_king_first_move && black_h8_rook_not_moved || black_king_first_move && black_a8_rook_not_moved)
//			) {
//			//change ? required
//			int left = j1 > j2 ? 0 : j1;
//			int right = j1 > j2 ? j1 : j2;
//			char kingrow = isplayeroneturn ? '1' : '8';
//			char attacklocation[2] = { 'a' + left, kingrow };
//			while (left <= right && (getgoti(board, attacklocation) == ' ' || isanyking(getgoti(board, attacklocation)) || isanyrook(getgoti(board, attacklocation))) && (!islocationunderattack(board, isplayeroneturn, attacklocation))) {
//				left++;
//				attacklocation[0] = 'a' + left;
//			}
//			if (left > right)
//				return true;
//			else
//				return false;
//		}
//		else
//			return false;
//	}
//	else
//		return false;
//}
//
//bool isvalidkingmove(char board[8][8], bool isplayeroneturn, char src[2], char dst[2]) {
//	int i1 = '8' - src[1];
//	int j1 = src[0] - 'a';
//	int i2 = '8' - dst[1];
//	int j2 = dst[0] - 'a';
//	if (i1 == i2 && j1 == j2)
//		return false;
//	else if (isplayeroneturn && (!iswhitepiece(getgoti(board, dst))) || (!isplayeroneturn) && (!isblackpiece(getgoti(board, dst)))) {
//		if (abs(i1 - i2) < 2 && abs(j1 - j2) < 2)
//			return true;
//		else
//			return false;
//	}
//	else if (isvalidkingcastling(board, src, dst))
//		return true;
//	else
//		return false;
//}
//
//bool isvalidbishopmove(char board[8][8], bool isplayeroneturn, char src[2], char dst[2]) {
//	int i1 = abs(src[1] - 56);
//	int j1 = src[0] - 97;
//	int i2 = abs(dst[1] - 56);
//	int j2 = dst[0] - 97;
//	int spaces = 0;
//	if (i1 == i2 && j1 == j2)
//		return false;
//	else if (abs(i1 - i2) == abs(j1 - j2)) {
//		if (isplayeroneturn && (!iswhitepiece(getgoti(board, dst))) || (!isplayeroneturn) && (!isblackpiece(getgoti(board, dst)))) {
//			if (i2 < i1 && j2 > j1) {
//				for (int s = 1; s <= abs(i1 - i2) - 1; s++) {
//					if (board[i1 - s][j1 + s] == ' ')
//						spaces++;
//				}
//				if (spaces == abs(i1 - i2) - 1)
//					return true;
//				else
//					return false;
//			}
//			else if (i2 < i1 && j2 < j1) {
//				for (int s = 1; s <= abs(i1 - i2) - 1; s++) {
//					if (board[i1 - s][j1 - s] == ' ')
//						spaces++;
//				}
//				if (spaces == abs(i1 - i2) - 1)
//					return true;
//				else
//					return false;
//			}
//			else if (i2 > i1 && j2 < j1) {
//				for (int s = 1; s <= abs(i1 - i2) - 1; s++) {
//					if (board[i1 + s][j1 - s] == ' ')
//						spaces++;
//				}
//				if (spaces == abs(i1 - i2) - 1)
//					return true;
//				else
//					return false;
//			}
//			else if (i2 > i1 && j2 > j1) {
//				for (int s = 1; s <= abs(i1 - i2) - 1; s++) {
//					if (board[i1 + s][j1 + s] == ' ')
//						spaces++;
//				}
//				if (spaces == abs(i1 - i2) - 1)
//					return true;
//				else
//					return false;
//			}
//		}
//		else
//			return false;
//	}
//	else
//		return false;
//}
//
//bool isvalidrookmove(char board[8][8], bool isplayeroneturn, char src[2], char dst[2]) {
//	int i1 = abs(src[1] - 56);
//	int j1 = src[0] - 97;
//	int i2 = abs(dst[1] - 56);
//	int j2 = dst[0] - 97;
//	int space = 0;
//	int k;
//	if (i1 == i2 && j1 == j2)
//		return false;
//	else if (isplayeroneturn && (!iswhitepiece(getgoti(board, dst))) || (!isplayeroneturn) && (!isblackpiece(getgoti(board, dst)))) {
//		if (i1 == i2 || j1 == j2) {
//			if (i1 == i2) {
//				if (j1 > j2) {
//					for (k = j2 + 1; k <= j1 - 1; k++)
//						if (board[i1][k] == ' ')
//							space++;
//					if (space == (j1 - j2) - 1)
//						return true;
//					else
//						return false;
//				}
//				else if (j2 > j1) {
//					for (k = j1; k <= j2 - 1; k++)
//						if (board[i1][k] == ' ')
//							space++;
//					if (space == (j2 - j1) - 1)
//						return true;
//					else
//						return false;
//				}
//			}
//			else if (j1 == j2) {
//				if (i1 > i2) {
//					for (k = i2 + 1; k <= i1 - 1; k++)
//						if (board[k][j1] == ' ')
//							space++;
//					if (space == (i1 - i2) - 1)
//						return true;
//					else
//						return false;
//				}
//				else if (i2 > i1) {
//					for (k = i1; k <= i2 - 1; k++)
//						if (board[k][j1] == ' ')
//							space++;
//					if (space == (i2 - i1) - 1)
//						return true;
//					else
//						return false;
//				}
//			}
//		}
//		else
//			return false;
//	}
//	else
//		return false;
//}
//
//bool isvalidqueenmove(char board[8][8], bool isplayeroneturn, char src[2], char dst[2]) {
//	return (isvalidbishopmove(board, isplayeroneturn, src, dst) || isvalidrookmove(board, isplayeroneturn, src, dst));
//}
//
//bool isvalidmove(char board[8][8], bool isplayeroneturn, char src[2], char dst[2]) {
//	char piece = getgoti(board, src);
//	switch (piece) {
//	case 'r':
//	case 'R':
//		return isvalidrookmove(board, isplayeroneturn, src, dst);
//	case 'h':
//	case 'H':
//		return isvalidhorsemove(board, isplayeroneturn, src, dst);
//	case 'b':
//	case 'B':
//		return isvalidbishopmove(board, isplayeroneturn, src, dst);
//	case 'q':
//	case 'Q':
//		return isvalidqueenmove(board, isplayeroneturn, src, dst);
//	case 'k':
//	case 'K':
//		return isvalidkingmove(board, isplayeroneturn, src, dst);
//	case 'p':
//		return (p2_pawn(board, src, dst));
//	case 'P':
//		return (p1_pawn(board, src, dst));
//	default:
//		return false;
//	}
//}
//
//bool ispawnpromoted(char board[8][8], bool isplayeroneturn, char src[2], char dst[2])
//{
//	int i1 = abs(src[1] - '8');
//	int j1 = src[0] - 'a';
//	int i2 = abs(dst[1] - '8');
//	int j2 = dst[0] - 'a';
//	if (i1 == i2 && j1 == j2)
//		return false;
//	else if (isplayeroneturn && getgoti(board, src) == 'P' && (!iswhitepiece(getgoti(board, dst)))) {
//		// straight
//		if (j1 == j2 && i2 == 0 && abs(i2 - i1) == 1 && board[i2][j2] == ' ')
//			return true;
//		//diagonals
//		else if (abs(j1 - j2) == 1 && i2 == 0 && abs(i2 - i1) == 1 && (!(board[i2][j2] == ' ')))
//			return true;
//		else
//			return false;
//	}
//	else if (!isplayeroneturn && getgoti(board, src) == 'p' && (!isblackpiece(getgoti(board, dst)))) {
//		//straight
//		if (j1 == j2 && i2 == 7 && abs(i2 - i1) == 1 && board[i2][j2] == ' ')
//			return true;
//		//diagonals
//		else if (abs(j1 - j2) == 1 && i2 == 7 && (!(board[i2][j2] == ' ')))
//			return true;
//		else
//			return false;
//	}
//	else
//		return false;
//}
//
//bool isenpassant(char board[8][8], bool isplayeroneturn, char src[2], char dst[2]) {
//	int i1 = abs(src[1] - 56);
//	int j1 = src[0] - 97;
//	int i2 = abs(dst[1] - 56);
//	int j2 = dst[0] - 97;
//	if (i1 == i2 && j1 == j2)
//		return false;
//	else if (isplayeroneturn) {
//		if (i1 == 3) {
//			if (abs(i1 - i2) == 1 && abs(j1 - j2) == 1 && board[i2 + 1][j2] == 'p' && black_en_passant == true)
//				return true;
//		}
//		else
//			return false;
//	}
//	else if (!isplayeroneturn) {
//		if (i1 == 4) {
//			if (abs(i1 - i2) == 1 && abs(j1 - j2) == 1 && board[4][j2] == 'P' && white_en_passant == true)
//				return true;
//		}
//		else
//			return false;
//	}
//	else
//		return false;
//}
//
//bool isvalidspecialmove(char board[8][8], bool isplayeroneturn, char src[2], char dst[2]) {
//	char piece = getgoti(board, src);
//	if (piece == 'P' || piece == 'p') {
//		return ((ispawnpromoted(board, isplayeroneturn, src, dst)) || (isenpassant(board, isplayeroneturn, src, dst)));
//	}
//	else
//		return false;
//}
//
//void locateplayerking(char board[8][8], bool isplayerone, char kingposition[2]) {
//	for (int rowidx = 0; rowidx < 8; rowidx++) {
//		for (int colidx = 0; colidx < 8; colidx++) {
//			if (isplayerone && board[rowidx][colidx] == 'K' || (!isplayerone) && board[rowidx][colidx] == 'k') {
//				kingposition[0] = 'a' + colidx;
//				kingposition[1] = '8' - rowidx;
//			}
//		}
//	}
//}
//
//bool hascheckoccured(char board[8][8], bool targetplayer) {
//	char kingposition[2];
//	locateplayerking(board, targetplayer, kingposition);
//	//circulating the board
//	for (int rowidx = 0; rowidx < 8; rowidx++) {
//		for (int colidx = 0; colidx < 8; colidx++) {
//			//if player white and black piece
//			if (targetplayer && isblackpiece(board[rowidx][colidx])) {
//				//make the black piece on this index of board a current source
//				char current_src[2] = { 'a' + char(colidx), '8' - char(rowidx) };
//				//if black can kill the  white king from this position
//				if (isvalidmove(board, !targetplayer, current_src, kingposition))
//					//then return check has occured
//					return true;
//			}
//			//else if player black and white piece
//			else if ((!targetplayer) && iswhitepiece(board[rowidx][colidx])) {
//				//make the white piece on this index of board a current source
//				char current_src[2] = { 'a' + char(colidx), '8' - char(rowidx) };
//				//if white can kill the black king from this position
//				if (isvalidmove(board, !targetplayer, current_src, kingposition))
//					//then return check has occured
//					return true;
//			}
//		}
//	}
//	//if the whole board's indexes can not do this
//	//then return false
//	return false;
//}
//
//bool willcausecheck(char board[8][8], bool targetplayer, char src[2], char dst[2]) {
//	if (isvalidmove(board, targetplayer, src, dst)) {
//		char next_board_state[8][8];
//		for (int i = 0; i < 8; i++) {
//			for (int j = 0; j < 8; j++) {
//				next_board_state[i][j] = board[i][j];
//			}
//		}
//		setgoti(next_board_state, dst, getgoti(next_board_state, src));
//		setgoti(next_board_state, src, ' ');
//		return hascheckoccured(next_board_state, targetplayer);
//	}
//	else
//		return false;
//}
//
//bool hascheckmateoccured(char board[8][8], bool targetplayer) {
//	if (hascheckoccured(board, targetplayer)) {
//		for (int srcrowidx = 0; srcrowidx < 8; srcrowidx++) {
//			for (int srccolidx = 0; srccolidx < 8; srccolidx++) {
//				if (targetplayer && iswhitepiece(board[srcrowidx][srccolidx])) {
//					char current_src[2] = { 'a' + char(srccolidx), '8' - char(srcrowidx) };
//					for (int dstrowidx = 0; dstrowidx < 8; dstrowidx++) {
//						for (int dstcolidx = 0; dstcolidx < 8; dstcolidx++) {
//							char current_dst[2] = { 'a' + char(dstcolidx), '8' - char(dstrowidx) };
//							if (isvalidmove(board, targetplayer, current_src, current_dst) && (!willcausecheck(board, targetplayer, current_src, current_dst)))
//								return false;
//						}
//					}
//				}
//				else if ((!targetplayer) && isblackpiece(board[srcrowidx][srccolidx])) {
//					char current_src[2] = { 'a' + char(srccolidx), '8' - char(srcrowidx) };
//					for (int dstrowidx = 0; dstrowidx < 8; dstrowidx++) {
//						for (int dstcolidx = 0; dstcolidx < 8; dstcolidx++) {
//							char current_dst[2] = { 'a' + char(dstcolidx), '8' - char(dstrowidx) };
//							if (isvalidmove(board, targetplayer, current_src, current_dst) && (!willcausecheck(board, targetplayer, current_src, current_dst)))
//								return false;
//						}
//					}
//				}
//			}
//		}
//	}
//	else
//		return true;
//}
//
//bool hasstalemateoccured(char board[8][8], bool targetplayer) {
//	if (!hascheckoccured(board, targetplayer)) {
//		for (int srcrowidx = 0; srcrowidx < 8; srcrowidx++) {
//			for (int srccolidx = 0; srccolidx < 8; srccolidx++) {
//				if (targetplayer && iswhitepiece(board[srcrowidx][srccolidx])) {
//					char current_src[2] = { 'a' + char(srccolidx), '8' - char(srcrowidx) };
//					for (int dstrowidx = 0; dstrowidx < 8; dstrowidx++) {
//						for (int dstcolidx = 0; dstcolidx < 8; dstcolidx++) {
//							char current_dst[2] = { 'a' + char(dstcolidx), '8' - char(dstrowidx) };
//							if (isvalidmove(board, targetplayer, current_src, current_dst) && (!willcausecheck(board, targetplayer, current_src, current_dst)))
//								return false;
//						}
//					}
//				}
//				else if ((!targetplayer) && isblackpiece(board[srcrowidx][srccolidx])) {
//					char current_src[2] = { 'a' + char(srccolidx), '8' - char(srcrowidx) };
//					for (int dstrowidx = 0; dstrowidx < 8; dstrowidx++) {
//						for (int dstcolidx = 0; dstcolidx < 8; dstcolidx++) {
//							char current_dst[2] = { 'a' + char(dstcolidx), '8' - char(dstrowidx) };
//							if (isvalidmove(board, targetplayer, current_src, current_dst) && (!willcausecheck(board, targetplayer, current_src, current_dst)))
//								return false;
//						}
//					}
//				}
//			}
//		}
//	}
//	else
//		return true;
//}
//
//
//void moverookforcastling(char board[8][8], char src[2], char dst[2]) {
//	int i1 = abs(src[1] - '8');
//	int j1 = src[0] - 'a';
//	int i2 = abs(dst[1] - '8');
//	int j2 = dst[0] - 'a';
//	//needs ? change
//	char rookdst[2] = { j1 > j2 ? 'a' + j2 + 1 : 'a' + j2 - 1, src[1] };
//	char rooksrc[2] = { j1 > j2 ? 'a' : 'h', src[1] };
//	setgoti(board, rookdst, getgoti(board, rooksrc));
//	setgoti(board, rooksrc, ' ');
//}
//
//void makemove(char board[8][8], char src[2], char dst[2], char promotedgoti = ' ') {
//
//	char srcgoti = getgoti(board, src);
//
//	if (isvalidkingcastling(board, src, dst)) {
//		moverookforcastling(board, src, dst);
//	}
//
//	if (srcgoti == 'k') {
//		black_king_first_move = false;
//	}
//	else if (srcgoti == 'K') {
//		white_king_first_move = false;
//	}//change 
//	else if (srcgoti == 'r') {
//		if (src[0] == 'a' && src[1] == '8')
//			black_a8_rook_not_moved = false;
//		else if (src[0] == 'h' && src[1] == '8')
//			black_h8_rook_not_moved = false;
//	}
//	else if (srcgoti == 'R') {///same r
//		if (src[0] == 'a' && src[1] == '1')
//			white_a1_rook_not_moved = false;
//		else if (src[0] == 'h' && src[1] == '1')
//			white_h1_rook_not_moved = false;
//	}
//
//	if (promotedgoti == ' ') {
//		setgoti(board, dst, getgoti(board, src));
//	}
//	else {
//		setgoti(board, dst, promotedgoti);
//	}
//	setgoti(board, src, ' ');
//}
//
//int main()
//{
//	char promotedgoti;
//	char src[3], dst[3];
//	bool check = false, checkmate = false, stalemate = false;
//	bool isplayeroneturn = true;
//	ofstream store_moves;
//	store_moves.open("chess.txt",ios::app);
//
//	char board[8][8] = {
//		{'r', 'h', 'b', 'q', 'k', 'b', 'h', 'r'},
//		{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
//		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//		{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
//		{'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'} };
//	cout << "\tWELCOME TO CHESS!" << endl;
//	ifstream stored_moves;
//	int choose = 0;
//	do {
//		cout << "What do you want?" << endl
//			<< "1. Start a new game" << endl
//			<< "2. Replay the moves of previous game" << endl
//			<< "Enter your choice: ";
//		cin >> choose;
//		if (choose == 1)
//			stored_moves.open("CHESS.txt");
//		else if (choose == 2)
//			stored_moves.open("CHESS.txt", ios::app);
//		else
//		{
//			system("CLS");
//			cout << "Invalid choice" << endl;
//		}
//	} while (choose != 1 && choose != 2);
//	if (choose == 2) {
//		while (!stored_moves.eof()) {
//			string extract;
//			getline(stored_moves, extract);
//			cout << extract << endl;
//		}
//		exit(0);
//	}
//	do {
//		cout << "Modes:" << endl
//			<< "1: Classical" << endl
//			<< "2: Rapid(10 minutes each player)" << endl
//			<< "3: Biltz(5 minutes each player)" << endl
//			<< "4: Lightening(15 seconds for each move)" << endl
//			<< "Choose your mode: ";
//		while (!(cin >> mode_choice))
//		{
//			cout << "Error: Enter your mode: ";
//			cin.clear();
//			cin.ignore(123, '\n');
//		}
//		system("cls");
//		if (mode_choice < 1 || mode_choice > 4)
//			cout << "Invalid input!\nTry again!" << endl << endl;
//	} while (mode_choice < 1 || mode_choice > 4);
//	if (mode_choice == 1) {
//		cout << "\"You are playing under classical mode\" " << endl
//			<< "Rules:" << endl
//			<< "1.Each player has unlimited time" << endl
//			<< "2.In case of draw player with less time will have advantage\n\nLets start the play" << endl << endl;
//		white_time = 0;
//		black_time = 0;
//	}
//	else if (mode_choice == 2) {
//		cout << "\n\"You are playing under rapid mode:\" " << endl
//			<< "1.Each player has 10 minutes i.e. 600 seconds." << endl
//			<< "2.In case move is there will be increment of 10 seconds." << endl;
//		white_time = 600;
//		black_time = 600;
//	}
//	else if (mode_choice == 3) {
//		cout << "\n\"You are playing under biltz mode:\" " << endl
//			<< "1.Each player has 5 minutes i.e. 300 seconds." << endl
//			<< "2.In case move is there will be no increment." << endl;
//		white_time = 300;
//		black_time = 300;
//	}
//	else if (mode_choice == 4) {
//		cout << "\n\"You are playing under lighntening mode:\" " << endl
//			<< "1.Each player has 15 seconds for each move." << endl;
//		white_time = 15;
//		black_time = 15;
//	}
//	do {
//		displayboard(board);
//
//		if (check) {
//			cout
//				<< "Player " << (!isplayeroneturn + 1) << "! you are under check. Make a move to remove it."
//				<< endl << endl;
//		}
//		auto start = high_resolution_clock::now();
//		do {
//			do {
//				cout << "Player turn: " << (!isplayeroneturn + 1) << endl;
//				store_moves << "Player turn: " << (!isplayeroneturn + 1) << endl;
//				cout << "Enter source position: ";
//				cin >> src;
//				if (src[0] == '0')
//					exit(0);
//				else if (src[0] == 'R')
//				{
//					resign = true;
//					break;
//				}
//				else if (src[0] == 'H')
//				{
//					cout << "Do you accept handshake?" << endl;
//					cout << "Enter y or n!" << endl;
//					char choice;
//					cin >> choice;
//					if (choice == 'y')
//					{
//						handshake = true;
//						break;
//					}
//					if (choice == 'n')
//					{
//						cout << "Handshake not accepted so we continue:";
//						handshake = false;
//					}
//				}
//				store_moves << "Source position: ";
//				store_moves << src << endl;
//				if (isplayeroneturn && (!iswhitepiece(getgoti(board, src))) || (!isplayeroneturn) && (!isblackpiece(getgoti(board, src))))
//				{
//					cout << endl
//						<< "Invalid move! select your piece\ntry again\n"
//						<< endl;
//					store_moves << "Invalid move! select your piece\ntry again\n";
//				}
//
//			} while (isplayeroneturn && (!iswhitepiece(getgoti(board, src))) || (!isplayeroneturn) && (!isblackpiece(getgoti(board, src))));
//			if (!resign && !handshake) {
//				cout << "Enter destination position: ";
//				cin >> dst;
//				store_moves << "Destination position: ";
//				store_moves << dst << endl;
//				if ((!isvalidmove(board, isplayeroneturn, src, dst)) && (!isvalidspecialmove(board, isplayeroneturn, src, dst))) {
//					cout << endl
//						<< "Invalid move! selected piece cannot make this move\ntry again\n"
//						<< endl;
//					store_moves << "Invalid move! selected piece cannot make this move\ntry again\n";
//				}
//				else if (check && willcausecheck(board, isplayeroneturn, src, dst)) { // still check
//					cout << endl
//						<< "Still under check! make a move to remove check.\ntry again\n"
//						<< endl;
//					store_moves << "Still under check! make a move to remove check.\ntry again\n";
//				}
//				else if (willcausecheck(board, isplayeroneturn, src, dst)) {
//					cout << endl
//						<< "Invalid move! this move will cause check.\ntry again\n"
//						<< endl;
//					store_moves << "Invalid move! this move will cause check.\ntry again\n";
//				}
//			}
//			else
//				break;
//		} while (((!isvalidmove(board, isplayeroneturn, src, dst)) && (!isvalidspecialmove(board, isplayeroneturn, src, dst))) || (isvalidmove(board, isplayeroneturn, src, dst) && willcausecheck(board, isplayeroneturn, src, dst)));
//
//		if (ispawnpromoted(board, isplayeroneturn, src, dst)) {
//			if (!isplayeroneturn) {
//				do {
//					cout << "Convert your pawn into:\n";
//					cout << "q: queen\nr: rook\nh: horse\nb: bishop\n";
//					cin >> promotedgoti;
//					if (!isblackpiece(promotedgoti)) {
//						cout << endl
//							<< "Invalid move! select your piece\ntry again\n"
//							<< endl;
//					}
//				} while (!isblackpiece(promotedgoti));
//			}
//			else if (isplayeroneturn) {
//				do {
//					cout << "Convert your pawn into:\n";
//					cout << "Q: queen\nR: Rook\nH: Horse\nB: Bishop\n";
//					cin >> promotedgoti;
//					if (!iswhitepiece(promotedgoti)) {
//						cout << endl
//							<< "Invalid move! select your piece\ntry again\n"
//							<< endl;
//					}
//				} while (!iswhitepiece(promotedgoti));
//			}
//			makemove(board, src, dst, promotedgoti);
//		}
//		else if (isenpassant(board, isplayeroneturn, src, dst)) {
//			if (isplayeroneturn) {
//				cout << "En-passant by white: " << endl;
//				board[abs(dst[1] - 56) + 1][dst[0] - 97] = ' ';
//			}
//			else if (!isplayeroneturn) {
//				cout << "En-passant by black: " << endl;
//				board[abs(dst[1] - 56) - 1][dst[0] - 97] = ' ';
//			}
//			makemove(board, src, dst);
//		}
//		else {
//			makemove(board, src, dst);
//		}
//		auto stop = high_resolution_clock::now();
//		auto duration = duration_cast<seconds>(stop - start);
//
//		if (isplayeroneturn) {
//			isplayeroneturn = false;
//			black_en_passant = false;
//			if (mode_choice == 1)
//				white_time += duration.count();
//			else if (mode_choice == 2) {
//				white_time -= duration.count();
//				if (isplayeroneturn == false)
//					white_time += 10;
//			}
//			else if (mode_choice == 3 || mode_choice == 4)
//				white_time -= duration.count();
//		}
//		else {
//			isplayeroneturn = true;
//			white_en_passant = false;
//			if (mode_choice == 1)
//				black_time += duration.count();
//			else if (mode_choice == 2) {
//				black_time -= duration.count();
//				if (isplayeroneturn == true)
//					black_time += 10;
//			}
//			else if (mode_choice == 3 || mode_choice == 4)
//				black_time -= duration.count();
//		}
//		system("cls");
//		check = hascheckoccured(board, isplayeroneturn);
//		if (check && hascheckmateoccured(board, isplayeroneturn))
//			checkmate = true;
//		if (!check && hasstalemateoccured(board, isplayeroneturn)) {
//			stalemate = true;
//			break;
//		}
//		else if ((mode_choice == 2 || mode_choice == 3 || mode_choice == 4) && (white_time <= 0 || black_time <= 0))
//			break;
//		if (mode_choice == 4) {
//			white_time = 15;
//			black_time = 15;
//		}
//		if (mode_choice == 1 || mode_choice == 2 || mode_choice == 3)
//		{
//			if (resign || handshake)
//				break;
//		}
//	} while (!checkmate);
//	if (resign == true)
//	{
//		if (isplayeroneturn)
//			cout << "Black player wins." << endl;
//		if (!isplayeroneturn)
//			cout << "White player wins" << endl;
//	}
//	else if (stalemate) {
//		cout << endl << "Stalemate!!!\a" << endl
//			<< "Game drawn!!!";
//		if (black_time < white_time) {
//			cout << endl << "Player 2 consumed less time and has the advantage" << endl;
//		}
//		else if (white_time < black_time) {
//			cout << endl << "Player 1 consumed less time and has the advantage" << endl;
//		}
//	}
//	else if (handshake == true)
//	{
//		{
//			if (black_time < white_time) {
//				cout << endl << "Player 2 consumed less time and has the advantage" << endl;
//			}
//			else if (white_time < black_time) {
//				cout << endl << "Player 1 consumed less time and has the advantage" << endl;
//			}
//		}
//	}
//	else if (mode_choice == 2 || mode_choice == 3 || mode_choice == 4) {
//		if (white_time <= 0 || black_time <= 0)
//		{
//			if (white_time < black_time) {
//				cout << "white player ran out of time...\n";
//				cout << "the black player wins!!\n";
//				store_moves << "the black player wins!!\n";
//			}
//			else if (black_time < white_time) {
//				cout << "black player ran out of time...\n";
//				cout << "the white player wins!!\n";
//				store_moves << "the black player wins!!\n";
//			}
//		}
//	}
//	else if (checkmate) {
//		cout << "CHECKMATE!!!\a" << endl
//			<< "GAMEOVER!" << endl;
//		if (isplayeroneturn)
//			cout << "BLACK HAS WON" << endl
//			<< "CONGRATULATIONS" << endl;
//		else
//			cout << "WHITE HAS WON" << endl
//			<< "CONGRATULATIONS" << endl;
//		store_moves << "checkmate";
//	}
//	store_moves.close();
//	displayboard(board);
//	exit(0);
//	return 0;
//}