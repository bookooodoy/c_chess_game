#include "chess.h"1

int	**get_legal_moves_pawn(piece piece, board ChessBoard)
{
	int	**legal_moves;
	int	board;
	int	i;
	int	k;

	legal_moves = (int **)malloc(sizeof(int) * 4);
	if (!legal_moves)
		return (NULL);
	// check for y+1 and 2 
	if (ChessBoard.ChessSquare[piece.y_cords + 1][piece.x_cords] && )
	// check if side is also possible
	
}
