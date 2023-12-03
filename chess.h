#ifndef CHESS_H
# define CHESS_H

# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <stdlib.h>

typedef struct
{
        char                    name;
        unsigned int            x_cords;
        unsigned int            y_cords;
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
board 	Fill_starting_position(char *fenstring);

#endif
