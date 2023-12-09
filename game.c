#include "chess.h"

char	*get_castling_rights(const board ChessBoard, piece *king)
{
	char	*castling_rights;
	int	x = 1;
	int 	i = 0;

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

/*char	*get_player_input(void);

int	check_input_valid(char *input);

void	updateMoveBoard(board ChessBoard, char *player_move);*/
