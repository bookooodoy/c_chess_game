#include "chess.h"1

int	**get_legal_moves_bpawn(piece piece, board ChessBoard)
{
	int	**legal_moves;
	int	coordinates[2]
	int	i;

	i = 0;
	legal_moves = (int **)malloc(sizeof(int) * 5);
	if (!legal_moves)
		return (NULL);
	// check for y+1 and 2 
	if (ChessBoard.ChessSquare[piece.y_cords + 1][piece.x_cords].isEmpty)
	{
		coordinates[0] = piece.y_cords + 1;
		coordinates[1] = piece.x_cords;
		legal_moves[i++] = coordinates;
	}
	if (ChessBoard.ChessSquare[piece.y_cords + 2][piece.x_cords] && ChessBoard.ChessSquare[piece.y_cords + 2][piece.x_cords].isEmpty)
	{
		coordinates[0] = piece.y_cords + 2;
		coordinates[1] = piece.x_cords;
		legal_moves[i++] = coordinates;
	}
	//Check for capture
	if (ChessBoard.ChessSquare[piece.y_cords + 1][piece.x_cords - 1] && ChessBoard.ChessSquare[piece.y_cords + 1][piece.x_cords - 1].isEmpty == 0 && ChessBoard.ChessSquare[piece.y_cords + 1][piece.x_cords - 1].ChessPiece.color == 0 ChessBoard.ChessSquare[piece.y_cords + 1][piece.x_cords - 1].ChessPiece.name != 'K')
	{
		coordinates[0] = piece.y_cords + 1;
		coordinates[1] = piece.x_cords - 1;
		legal_moves[i++] = coordinates;
	}
	if (ChessBoard.ChessSquare[piece.y_cords + 1][piece.x_cords + 1] && ChessBoard.ChessSquare[piece.y_cords + 1][piece.x_cords - 1].isEmpty == 0 && ChessBoard.ChessSquare[piece.y_cords + 1][piece.x_cords - 1].ChessPiece.color == 0 ChessBoard.ChessSquare[piece.y_cords + 1][piece.x_cords - 1].ChessPiece.name != 'K')
	{
		coordinates[0] = piece.y_cords + 1;
		coordinates[1] = piece.x_cords + 1;
		legal_moves[i++] = coordinates;
	}
	// TODO: En passant
	legal_moves[i] = NULL;
	return (legal_moves);
}


int	**get_legal_moves_wpawn(piece piece, board ChessBoard)
{
	int	**legal_moves;
	int	coordinates[2]
	int	i;

	i = 0;
	legal_moves = (int **)malloc(sizeof(int) * 5);
	if (!legal_moves)
		return (NULL);
	// check for y+1 and 2 
	if (ChessBoard.ChessSquare[piece.y_cords - 1][piece.x_cords].isEmpty)
	{
		coordinates[0] = piece.y_cords - 1;
		coordinates[1] = piece.x_cords;
		legal_moves[i++] = coordinates;
	}
	if (ChessBoard.ChessSquare[piece.y_cords - 2][piece.x_cords] && ChessBoard.ChessSquare[piece.y_cords - 2][piece.x_cords].isEmpty)
	{
		coordinates[0] = piece.y_cords - 2;
		coordinates[1] = piece.x_cords;
		legal_moves[i++] = coordinates;
	}
	//Check for capture
	if (ChessBoard.ChessSquare[piece.y_cords - 1][piece.x_cords - 1] && ChessBoard.ChessSquare[piece.y_cords - 1][piece.x_cords - 1].isEmpty == 0 && ChessBoard.ChessSquare[piece.y_cords - 1][piece.x_cords - 1].ChessPiece.color == 0 ChessBoard.ChessSquare[piece.y_cords - 1][piece.x_cords - 1].ChessPiece.name != 'k')
	{
		coordinates[0] = piece.y_cords - 1;
		coordinates[1] = piece.x_cords - 1;
		legal_moves[i++] = coordinates;
	}
	if (ChessBoard.ChessSquare[piece.y_cords - 1][piece.x_cords + 1] && ChessBoard.ChessSquare[piece.y_cords - 1][piece.x_cords + 1].isEmpty == 0 && ChessBoard.ChessSquare[piece.y_cords - 1][piece.x_cords + 1].ChessPiece.color == 0 ChessBoard.ChessSquare[piece.y_cords - 1][piece.x_cords + 1].ChessPiece.name != 'k')
	{
		coordinates[0] = piece.y_cords - 1;
		coordinates[1] = piece.x_cords + 1;
		legal_moves[i++] = coordinates;
	}
	// TODO: En passant
	legal_moves[i] = NULL;
	return (legal_moves);
}



int	**get_legal_moves_king(piece piece, board ChessBoard, int **threatmap)
{
	int	**legal_moves;
	int	coordinates[2]
	int	i;

	i = 0;
	legal_moves = (int **)malloc(sizeof(int) * 5);
	if (!legal_moves)
		return (NULL);
		
}
