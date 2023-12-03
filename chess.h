#ifndef CHESS_H
# define CHESS_H

# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>

typedef struct
{
        char	name;
	int	piece_value;
} piece;

typedef struct
{
        int     isEmpty;
	int	enPassant;
        piece ChessPiece;
} square;

typedef struct
{
        square ChessSquare[8][8];
} board;

void    ptr_tab(board ChessBoard);
board 	Fill_starting_position(const char *fenstring);
char    *update_fenstring(const board ChessBoard);

#endif
