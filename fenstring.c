#include "chess.h"

void	initialize_piece(piece *piece, char name, unsigned int x_cords, unsigned int y_cords, int color, unsigned int moves)
{
	piece->name = name;
	piece->x_cords = x_cords;
	piece->y_cords = y_cords;
	piece->color = color;
	piece->piece_moves = moves;
}

board Fill_starting_position(const char *fenstring)
{
        board   ChessBoard;
	int	i;
	int	k;
	int	len;

	i = k = 0;
	while (k < (int)strlen(fenstring) && !isspace(fenstring[k]))
	{
		if (isdigit(fenstring[k]))
		{
			len = 0;
			while (len < fenstring[k] - '0')
			{
				ChessBoard.ChessSquare[i / 8][(i + len) % 8].isEmpty = 1;
				initialize_piece(&(ChessBoard.ChessSquare[i / 8][(i + len) % 8].ChessPiece), 0, (i + len) % 8, i / 8, -1, -1);
				len++;
			}
			i += len;
		}
		else if (isalpha(fenstring[k]))
		{
			ChessBoard.ChessSquare[i / 8][i % 8].isEmpty = 0;
			if (islower(fenstring[k]))
				initialize_piece(&(ChessBoard.ChessSquare[i / 8][i % 8].ChessPiece), fenstring[k], (i % 8), (i / 8), 1, 0);
			else
				initialize_piece(&(ChessBoard.ChessSquare[i / 8][i % 8].ChessPiece), fenstring[k], (i % 8), (i / 8), 0, 0);
			i++;
		}
		k++;
	}
        return (ChessBoard);
}

int	get_fullmove(const board ChessBoard)
{
	int	i;
	int	k;
	int	fullmove;

	i = fullmove = 0;
	while (i < 8)
	{
		k = 0;
		while (k < 8)
		{
			if (ChessBoard.ChessSquare[i][k].isEmpty == 0)	
				fullmove += ChessBoard.ChessSquare[i][k].ChessPiece.piece_moves;
			k++;
		}
		i++;
	}
	return (fullmove);
}

char    *get_castling_rights(const board ChessBoard, piece *king)
{
        char    *castling_rights;
        int     x = 1;
        int     i = 0;

        castling_rights = malloc(sizeof(char) * 3);
        if (!castling_rights)
                return ((char *)NULL);
        if (king->piece_moves == 0)
        {
                if (king->color == 0)
                {
                        // queen side castle check
                        while (check_square_valid(ChessBoard, king->y_cords, king->x_cords - x, 0) == 1)
                                x++;
                        if (x == 4 && ChessBoard.ChessSquare[king->y_cords][king->x_cords - x].ChessPiece.name == 'R' && ChessBoard.ChessSquare[king->y_cords][king->x_cords - x].ChessPiece.piece_moves == 0)
                                castling_rights[i++] = 'Q';
                        x = 1;
                        while (check_square_valid(ChessBoard, king->y_cords, king->x_cords + x, 0) == 1)
                                x++;
                        if (x == 3 &&  ChessBoard.ChessSquare[king->y_cords][king->x_cords + x].ChessPiece.name == 'R' && ChessBoard.ChessSquare[king->y_cords][king->x_cords + x].ChessPiece.piece_moves == 0)
                                castling_rights[i++] = 'K';
                        x = 1;
                }
                else if (king->color == 1)
                {
                        while (check_square_valid(ChessBoard, king->y_cords, king->x_cords - x, 1) == 1)
                                x++;
                        if (x == 4 && ChessBoard.ChessSquare[king->y_cords][king->x_cords - x].ChessPiece.name == 'r' && ChessBoard.ChessSquare[king->y_cords][king->x_cords - x].ChessPiece.piece_moves == 0)
                                castling_rights[i++] = 'q';
                        x = 1;
                        while (check_square_valid(ChessBoard, king->y_cords, king->x_cords + x, 1) == 1)
                                x++;
                        if (x == 3 && ChessBoard.ChessSquare[king->y_cords][king->x_cords + x].ChessPiece.name == 'r' && ChessBoard.ChessSquare[king->y_cords][king->x_cords + x].ChessPiece.piece_moves == 0)
                                castling_rights[i++] = 'k';
                }
                castling_rights[i] = '\0';
                return (castling_rights);
        }
        return ((char *)NULL);
}

char	*update_fenstring(const board ChessBoard)
{
	char	*fenstring;
	int	i;
	int	k;
	int	flen;
	int	emptyCounter;

	fenstring = (char *)malloc(sizeof(char) * 64);
	if (!fenstring)
		return (NULL);
	i = flen = 0;
	while (i < 8)
	{
		k = 0;
		while (k < 8)
		{
			emptyCounter = 0;
			if (ChessBoard.ChessSquare[i][k].isEmpty == 1)
			{
				while (ChessBoard.ChessSquare[i][k + emptyCounter].isEmpty == 1 && (k +emptyCounter) < 8)
					emptyCounter++;
				k += emptyCounter;
				fenstring[flen++] = emptyCounter + '0';
			}
			else
			{
				fenstring[flen++] = ChessBoard.ChessSquare[i][k].ChessPiece.name;
				k++;
			}
		}
		i++;
		if (i != 8)
			fenstring[flen++] = '/';
	}
	fenstring[flen] = '\0';
	return (fenstring);
}
/*
char	*update_params(const unsigned int fullmove, char *castling_rights_black, char *castling_rights_white, )
{
	if (fullmove % 2 == 0)
	{
		fenstring
	}
}*/

void	ptr_tab(board ChessBoard)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (ChessBoard.ChessSquare[i][j].isEmpty)				write(1, ". ", 1);
			else
				write(1, &(ChessBoard.ChessSquare[i][j].ChessPiece.name), 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

void	ptr_parameters_debug(board ChessBoard)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (ChessBoard.ChessSquare[i][j].isEmpty == 1)
			{
				printf("Empty Square at Square [%i][%i]... Printing possible left parameters.\n", i, j);
				if (ChessBoard.ChessSquare[i][j].ChessPiece.name)
					printf("NAME = %c\n", ChessBoard.ChessSquare[i][j].ChessPiece.name);
				printf("COLOR = %d\n", ChessBoard.ChessSquare[i][j].ChessPiece.color);
				printf("X_CORDS = %d\n", ChessBoard.ChessSquare[i][j].ChessPiece.x_cords);
				printf("Y_CORDS = %d\n", ChessBoard.ChessSquare[i][j].ChessPiece.y_cords);
				printf("FULLMOVE = %d\n", ChessBoard.ChessSquare[i][j].ChessPiece.piece_moves);
				printf("\n");
			}
			else
			{
				printf("Non empty square at Square[%i][%i]... \n", i, j);
				printf("NAME = %c\n", ChessBoard.ChessSquare[i][j].ChessPiece.name);
				printf("COLOR = %d\n", ChessBoard.ChessSquare[i][j].ChessPiece.color);
				printf("X_CORDS = %d\n", ChessBoard.ChessSquare[i][j].ChessPiece.x_cords);
				printf("Y_CORDS = %d\n", ChessBoard.ChessSquare[i][j].ChessPiece.y_cords);
				printf("FULLMOVE = %d\n", ChessBoard.ChessSquare[i][j].ChessPiece.piece_moves);
				printf("\n");
			}
			j++;
		}
		i++;
	}
}
