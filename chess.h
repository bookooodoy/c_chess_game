#ifndef CHESS_H
# define CHESS_H

# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>

typedef struct
{
        char		name;
	unsigned int	piece_value;
	unsigned int	x_cords;
	unsigned int	y_cords;
	unsigned int	color;
	unsigned int	piece_fullmove;
} piece;

typedef struct
{
        int     isEmpty;
        piece ChessPiece;
} square;

typedef struct
{
        square ChessSquare[8][8];
} board;

void    ptr_tab(board ChessBoard);
char    *update_fenstring(const board ChessBoard);
board 	Fill_starting_position(const char *fenstring);
int     check_square_valid(board ChessBoard, int y, int x, unsigned int team);
int     **get_legal_moves_bpawn(piece piece, board ChessBoard);
int     **get_legal_moves_wpawn(piece piece, board ChessBoard);
int     **get_legal_moves_knight(piece piece, board ChessBoard);
int     **get_legal_moves_rook(piece piece, board ChessBoard);
int     **get_legal_moves_bishop(piece piece, board ChessBoard);
int     **get_legal_moves_queen(piece piece, board ChessBoard);
int     **get_name_move(piece piece, board ChessBoard);
int     **get_threatmap(board ChessBoard, unsigned int team);
int     **get_legal_moves_king(piece piece, board ChessBoard, int ***threatmap);

#endif
