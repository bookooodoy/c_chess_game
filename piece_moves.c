#include "chess.h"

int	check_square_valid(board ChessBoard, int y, int x, unsigned int team)
{
	// TODO: add check function to verify if we are not in check and if so the move is valid
	if (ChessBoard.ChessSquare[y][x] && ChessBoard.ChessSquare[y][x].isEmpty == 1)
		return (1);
	if (ChessBoard.ChessSquare[y][x] && ChessBoard.ChessSquare[y][x].ChessPiece.color != team && ChessBoard.ChessSquare[y][x].ChessPiece.name != 'k' && ChessBoard.ChessSquare[y][x].ChessPiece.name != 'K')
		return (2);
	return (0);
}

int	**get_legal_moves_bpawn(piece piece, board ChessBoard)
{
	int	**legal_moves;
	int	coordinates[2];
	int	i = 0;

	legal_moves = (int **)malloc(sizeof(int *) * 5);
	if (!legal_moves)
		return (NULL);
	if (check_square_valid(ChessBoard, piece.y_cords + 1, piece.x_cords, piece.color))
	{
		coordinates[0] = piece.y_cords + 1;
		coordinates[1] = piece.x_cords;
		legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords + 2, piece.x_cords, piece.color) && piece.piece_fullmove == 0)
	{
		coordinates[0] = piece.y_cords + 2;
		coordinates[1] = piece.x_cords;
		legal_moves[i++] = coordinates;
	}
	//Check for capture
	if (check_square_valid(ChessBoard, piece.y_cords + 1, piece.x_cords - 1, piece.color))
	{
		coordinates[0] = piece.y_cords + 1;
		coordinates[1] = piece.x_cords - 1;
		legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords + 1, piece.x_cords + 1, piece.color))
	{
		coordinates[0] = piece.y_cords + 1;
		coordinates[1] = piece.x_cords + 1;
		legal_moves[i++] = coordinates;
	}
	// TODO: En passant
	// TODO: Promotion
	legal_moves[i] = NULL;
	return (legal_moves);
}


int	**get_legal_moves_wpawn(piece piece, board ChessBoard)
{
	int	**legal_moves;
	int	coordinates[2];
	int	i = 0;

	legal_moves = (int **)malloc(sizeof(int *) * 5);
	if (!legal_moves)
		return (NULL);
	if (check_square_valid(ChessBoard, piece.y_cords - 1, piece.x_cords, piece.color))
	{
		coordinates[0] = piece.y_cords - 1;
		coordinates[1] = piece.x_cords;
		legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords - 2, piece.x_cords, piece.color) && piece.piece_fullmove == 0)
	{
		coordinates[0] = piece.y_cords - 2;
		coordinates[1] = piece.x_cords;
		legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords - 1, piece.x_cords - 1, piece.color))
	{
		coordinates[0] = piece.y_cords - 1;
		coordinates[1] = piece.x_cords - 1;
		legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords - 1, piece.x_cords + 1, piece.color))
	{
		coordinates[0] = piece.y_cords - 1;
		coordinates[1] = piece.x_cords + 1;
		legal_moves[i++] = coordinates;
	}
	// TODO: En passant
	// TODO: Promotion
	legal_moves[i] = NULL;
	return (legal_moves);
}

int	**get_legal_moves_knight(piece piece, board ChessBoard)
{
	int	**legal_moves;
	int	coordinates[2];
	int	i = 0;

	legal_moves = (int **)malloc(sizeof(int *) * 9);
	if (!legal_moves)
		return (NULL);
	if (check_square_valid(ChessBoard, piece.y_cords + 2, piece.x_cords + 1, piece.color))
	{
		coordinates[0] = piece.y_cords + 2;
		coordinates[1] = piece.x_cords + 1;
		legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords + 2, piece.x_cords - 1, piece.color))
	{
		coordinates[0] = piece.y_cords + 2;
		coordinates[1] = piece.x_cords - 1;
		legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords - 2, piece.x_cords + 1, piece.color))
	{
		coordinates[0] = piece.y_cords - 2;
		coordinates[1] = piece.x_cords + 1;
		legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords - 2, piece.x_cords - 1, piece.color))
	{
		coordinates[0] = piece.y_cords - 2;
		coordinates[1] = piece.x_cords - 1;
		legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords + 1, piece.x_cords + 2, piece.color))
	{
		coordinates[0] = piece.y_cords + 1;
		coordinates[1] = piece.x_cords + 2;
		legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords - 1, piece.x_cords + 2, piece.color))
	{
		coordinates[0] = piece.y_cords - 1;
		coordinates[1] = piece.x_cords + 2;
		legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords + 1, piece.x_cords - 2, piece.color))
	{
		coordinates[0] = piece.y_cords + 1;
		coordinates[1] = piece.x_cords - 2;
		legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords - 1, piece.x_cords - 2, piece.color))
	{
		coordinates[0] = piece.y_cords + 1;
		coordinates[1] = piece.x_cords + 2;
		legal_moves[i++] = coordinates;
	}
	legal_moves[i] = NULL;
	return (legal_moves);
}

int	**get_legal_moves_rook(piece piece, board ChessBoard)
{
	int	**legal_moves;
	int	coordinates[2]
	int	i;
	int	j;
	int	ret;

	j = 0;
	legal_moves = (int **)malloc(sizeof(int *) * 15);
	if (!legal_moves)
		return (NULL);
	while (1)
	{
		i = 1;
		while (ret = check_valid(ChessBoard, piece.y_cords - i, piece.x_cords, piece.color)) 
		{
			if (ret == 2)
			{
				coordinates[0] = piece.y_cords - i;
				coordinates[1] = piece.x_cords;
				legal_moves[j++] = coordinates;
				break ;
			}
			else if (ret == 1)
			{
				coordinates[0] = piece.y_cords - i;
				coordinates[1] = piece.x_cords;
				legal_moves[j++] = coordinates;
			}
			i++;
		}
		i = 1;
		while (ret = check_valid(ChessBoard, piece.y_cords + i, piece.x_cords, piece.color)) 
		{
			if (ret == 2)
			{
				coordinates[0] = piece.y_cords + i;
				coordinates[1] = piece.x_cords;
				legal_moves[j++] = coordinates;
				break ;
			}
			else if (ret == 1)
			{
				coordinates[0] = piece.y_cords + i;
				coordinates[1] = piece.x_cords;
				legal_moves[j++] = coordinates;
			}
			i++;
		}
		i = 1;
		while (ret = check_valid(ChessBoard, piece.y_cords, piece.x_cords - i, piece.color)) 
		{
			if (ret == 2)
			{
				coordinates[0] = piece.y_cords;
				coordinates[1] = piece.x_cords - i;
				legal_moves[j++] = coordinates;
				break ;
			}
			else if (ret == 1)
			{
				coordinates[0] = piece.y_cords;
				coordinates[1] = piece.x_cords - i;
				legal_moves[j++] = coordinates;
			}
			i++;
		}
		i = 1;
		while (ret = check_valid(ChessBoard, piece.y_cords, piece.x_cords + i, piece.color)) 
		{
			if (ret == 2)
			{
				coordinates[0] = piece.y_cords;
				coordinates[1] = piece.x_cords + i;
				legal_moves[j++] = coordinates;
				break ;
			}
			else if (ret == 1)
			{
				coordinates[0] = piece.y_cords;
				coordinates[1] = piece.x_cords + i;
				legal_moves[j++] = coordinates;
			}
			i++;
		}
		break ;
	}
	legal_moves[j] = NULL;
	return (legal_moves);
}

int	**get_legal_moves_bishop(piece piece, board ChessBoard)
{
	int	**legal_moves;
	int	coordinates[2]
	int	i;
	int	j;
	int	ret;

	j = 0;
	legal_moves = (int **)malloc(sizeof(int *) * 15);
	if (!legal_moves)
		return (NULL);
	while (1)
	{
		i = 1;
		while (ret = check_valid(ChessBoard, piece.y_cords - i, piece.x_cords - i, piece.color)) 
		{
			if (ret == 2)
			{
				coordinates[0] = piece.y_cords - i;
				coordinates[1] = piece.x_cords - i;
				legal_moves[j++] = coordinates;
				break ;
			}
			else if (ret == 1)
			{
				coordinates[0] = piece.y_cords - i;
				coordinates[1] = piece.x_cords - i;
				legal_moves[j++] = coordinates;
			}
			i++;
		}
		i = 1;
		while (ret = check_valid(ChessBoard, piece.y_cords + i, piece.x_cords - i, piece.color)) 
		{
			if (ret == 2)
			{
				coordinates[0] = piece.y_cords + i;
				coordinates[1] = piece.x_cords - i;
				legal_moves[j++] = coordinates;
				break ;
			}
			else if (ret == 1)
			{
				coordinates[0] = piece.y_cords + i;
				coordinates[1] = piece.x_cords - i;
				legal_moves[j++] = coordinates;
			}
			i++;
		}
		i = 1;
		while (ret = check_valid(ChessBoard, piece.y_cords - i, piece.x_cords + i, piece.color)) 
		{
			if (ret == 2)
			{
				coordinates[0] = piece.y_cords - i;
				coordinates[1] = piece.x_cords + i;
				legal_moves[j++] = coordinates;
				break ;
			}
			else if (ret == 1)
			{
				coordinates[0] = piece.y_cords - i;
				coordinates[1] = piece.x_cords + i;
				legal_moves[j++] = coordinates;
			}
			i++;
		}
		i = 1;
		while (ret = check_valid(ChessBoard, piece.y_cords + i, piece.x_cords + i, piece.color)) 
		{
			if (ret == 2)
			{
				coordinates[0] = piece.y_cords + i;
				coordinates[1] = piece.x_cords + i;
				legal_moves[j++] = coordinates;
				break ;
			}
			else if (ret == 1)
			{
				coordinates[0] = piece.y_cords + i;
				coordinates[1] = piece.x_cords + i;
				legal_moves[j++] = coordinates;
			}
			i++;
		}
		break ;
	}
	legal_moves[j] = NULL;
	return (legal_moves);
}

int	**get_legal_moves_queen(piece piece, board ChessBoard)
{
	int	**legal_moves;
	int	*diagonal;
	int	*vertical;

	diagonal = get_legal_moves_bishop(piece, ChessBoard);
	vertical = get_legal_moves_rook(piece, ChessBoard);
	legal_moves = ft_strjoin(diagonal, vertical);
	return (legal_moves);
}

int	**get_name_move(piece piece, board ChessBoard)
{
	if (piece.name == 'p')
		return (get_legal_moves_bpawn(piece, ChessBoard));
	if (piece.name == 'P')
		return (get_legal_moves_wpawn(piece, ChessBoard));
	if (piece.name == 'q' || piece.name == 'Q')
		return (get_legal_moves_queen(piece, ChessBoard));
	if (piece.name == 'n' || piece.name == 'N')
		return (get_legal_moves_knight(piece, ChessBoard));
	if (piece.name == 'r' || piece.name == 'R')
		return (get_legal_moves_rook(piece, ChessBoard));
	if (piece.name == 'b' || piece.name == 'B')
		return (get_legal_moves_bishop(piece, ChessBoard));
	return (NULL);
}

int	**get_threatmap(board ChessBoard, unsigned int team)
{
	int	i;
	int	k;
	int	len;
	int	***threatmap;

	all_moves = (int ***)malloc(sizeof(int **) * 17);
	if (!all_moves)
		return (NULL);
	i = len = 0;
	while (ChessBoard.ChessSquare[i])
	{
		k = 0;
		while (ChessBoard.ChessSquare[i][k])
		{
			if (ChessBoard.ChessSquare[i][k].isEmpty == 0 && ChessBoard.ChessSquare[i][k].ChessPiece.color != team)
				threatmap[len++] = get_name_move(ChessBoard.ChessSquare[i][k].ChessPiece, ChessBoard);
			k++;
		}
		i++;
	}
	threatmap[len] = NULL;
	return (threatmap);
}

int	**get_legal_moves_king(piece piece, board ChessBoard, int ***threatmap)
{
	int	**legal_moves;
	int	coordinates[2]
	int	i;

	i = 0;
	legal_moves = (int **)malloc(sizeof(int *) * 5);
	if (!legal_moves)
		return (NULL);
}
