#include "chess.h"

typedef struct Piece
{
	char			name;
	const unsigned int	color;
	unsigned int		x_cords;
	unsigned int		y_cords;
} piece;

typedef struct Square
{
	int	isEmpty;
	piece ChessPiece;
} square;

typedef struct Board
{
	square ChessSquare[8][8];
} board;

int	**get_legal_moves_pawn(piece *piece, char **board)
{
	int	**legal_moves;
	int	*coordinates;
	int	i;
	
	i = 1;
	coordinates = (int *)malloc(sizeof(int) * 2);
	if (!coordinates)
		return (NULL);
	legal_moves = (int **)malloc(sizeof(int *) * 4);
	if (!legal_moves)
	{
		free(coordinates);
		return (NULL);
	}
	if (piece->color == 1)
	{
		if (board[piece->x_chords][piece->y_chords - i] && board[piece->x_chors][piece->y_chords - i] == '.')
		{
			coordinates[0] = x_chords;
			coordinates[1] = y_chords - i;	
		}
		if (board[piece->x_chords])
	}
}


int	**get_legal_moves_rook(piece *piece, char **board)
{
	int	**legal_moves;
	int	*coordinates;
	int	i;
	int	k;

	i = 1;
	k = 0;
	coordinates = (int *)malloc(sizeof(int) * 2);
	if (!coordinates)
		return (NULL);
	if (piece->name == 'r')
	{
		legal_moves = (int **)malloc(sizeof(int *) * 15);
		if (!legal_moves)
		{
			free(coordinates);
			return (NULL);
		}
		while (board[piece->x_cords + i][piece->y_chords] && board[piece->x_cords + i][piece->y_chords] == '.')
		{
			coordinates[0] = piece->x_cords + i;
			coordinates[1] = piece->y_cords;
			coordinates[3] = NULL;
			legal_moves[k++] == coordinates; 
			i++;
		}
		i = 1
		while (board[piece->x_cords - i][piece->y_chords] && board[piece->x_cords - i][piece->y_chords] == '.')
		{
			coordinates[0] = piece->x_cords - i;
			coordinates[1] = piece->y_cords;
			coordinates[3] = NULL;
			legal_moves[k++] == coordinates; 
			i++;
		}
		i = 1; 
		while (board[piece->x_cords][piece->y_chords + i] && board[piece->x_cords][piece->y_chords + i] == '.')
		{
			coordinates[0] = piece->x_cords;
			coordinates[1] = piece->y_cords + i;
			coordinates[3] = NULL;
			legal_moves[k++] == coordinates; 
			i++;
		}
		i = 1;
		while (board[piece->x_cords][piece->y_chords - i] && board[piece->x_cords][piece->y_chords - i] == '.')
		{
			coordinates[0] = piece->x_cords;
			coordinates[1] = piece->y_cords - i;
			coordinates[3] = NULL;
			legal_moves[k++] == coordinates; 
			i++;
		}
	       	legal_moves[k] = NULL;
	}
	return (legal_moves);
}

int	main(void)
{
	piece *ptr, rook;

	ptr = &rook;
	ptr->name = 'r';
	ptr->x_cords = 0;
	ptr->y_cords = 0;
	printf("%c\n%d\n%d\n", ptr->name, ptr->x_cords, ptr->y_cords);
	return 0;
}
