#include "chess.h"

int	check_square_valid(board ChessBoard, int y, int x, unsigned int team)
{
	// TODO: add check function to verify if we are not in check and if so the move is valid
	if (y < 0 || y >= 8 || x < 0 || x >= 8)
        	return (0);
	if (ChessBoard.ChessSquare[y][x].isEmpty == 1)
		return (1);
	if (ChessBoard.ChessSquare[y][x].isEmpty == 0 && ChessBoard.ChessSquare[y][x].ChessPiece.color != team && ChessBoard.ChessSquare[y][x].ChessPiece.name != 'k' && ChessBoard.ChessSquare[y][x].ChessPiece.name != 'K')
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
	int	coordinates[2];
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
		while ((ret = check_square_valid(ChessBoard, piece.y_cords - i, piece.x_cords, piece.color))) 
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
		while ((ret = check_square_valid(ChessBoard, piece.y_cords + i, piece.x_cords, piece.color))) 
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
		while ((ret = check_square_valid(ChessBoard, piece.y_cords, piece.x_cords - i, piece.color)))
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
		while ((ret = check_square_valid(ChessBoard, piece.y_cords, piece.x_cords + i, piece.color))) 
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
	int	coordinates[2];
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
		while ((ret = check_square_valid(ChessBoard, piece.y_cords - i, piece.x_cords - i, piece.color))) 
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
		while ((ret = check_square_valid(ChessBoard, piece.y_cords + i, piece.x_cords - i, piece.color))) 
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
		while ((ret = check_square_valid(ChessBoard, piece.y_cords - i, piece.x_cords + i, piece.color))) 
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
		while ((ret = check_square_valid(ChessBoard, piece.y_cords + i, piece.x_cords + i, piece.color))) 
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
	int	**diagonal;
	int	**vertical;

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

int	***get_threatmap(board ChessBoard, unsigned int team)
{
	int	i;
	int	k;
	int	len;
	int	***threatmap;

	threatmap = (int ***)malloc(sizeof(int **) * 17);
	if (!threatmap)
		return (NULL);
	i = len = 0;
	while (i < 8)
	{
		k = 0;
		while (k < 8)
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

int	cords_in_threatmap(int *cords, int ***threatmap)
{
	int	i;
	int	j;
	int	k;
	int	c;

	i = c = 0;
	while (threatmap[i])
	{
		j = 0;
		while (threatmap[i][j])
		{
			k = 0;
			while (threatmap[i][j][k])
			{
				if (threatmap[i][j][k] == cords[k])
					c++;
				k++;			
			}
			if (c == 2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	**get_legal_moves_king(piece piece, board ChessBoard, int ***threatmap)
{
	int	**legal_moves;
	int	coordinates[2];
	int	i;

	i = 0;
	legal_moves = (int **)malloc(sizeof(int *) * 9);
	if (!legal_moves)
		return (NULL);
	if (check_square_valid(ChessBoard, piece.y_cords + 1, piece.x_cords, piece.color))
	{
		coordinates[0] = piece.y_cords + 1;
		coordinates[1] = piece.x_cords;
		if (!cords_in_threatmap(coordinates, threatmap))
			legal_moves[i++] = coordinates;

	}
	if (check_square_valid(ChessBoard, piece.y_cords + 1, piece.x_cords + 1, piece.color))
	{
		coordinates[0] = piece.y_cords + 1;
		coordinates[1] = piece.x_cords + 1;
		if (!cords_in_threatmap(coordinates, threatmap))
			legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords + 1, piece.x_cords - 1, piece.color))
	{
		coordinates[0] = piece.y_cords + 1;
		coordinates[1] = piece.x_cords - 1;
		if (!cords_in_threatmap(coordinates, threatmap))
			legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords - 1, piece.x_cords, piece.color))
	{
		coordinates[0] = piece.y_cords - 1;
		coordinates[1] = piece.x_cords;
		if (!cords_in_threatmap(coordinates, threatmap))
			legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords - 1, piece.x_cords + 1, piece.color))
	{
		coordinates[0] = piece.y_cords - 1;
		coordinates[1] = piece.x_cords + 1;
		if (!cords_in_threatmap(coordinates, threatmap))
			legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords - 1, piece.x_cords - 1, piece.color))
	{
		coordinates[0] = piece.y_cords - 1;
		coordinates[1] = piece.x_cords - 1;
		if (!cords_in_threatmap(coordinates, threatmap))
			legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords, piece.x_cords + 1, piece.color))
	{
		coordinates[0] = piece.y_cords;
		coordinates[1] = piece.x_cords + 1;
		if (!cords_in_threatmap(coordinates, threatmap))
			legal_moves[i++] = coordinates;
	}
	if (check_square_valid(ChessBoard, piece.y_cords, piece.x_cords - 1, piece.color))
	{
		coordinates[0] = piece.y_cords;
		coordinates[1] = piece.x_cords - 1;
		if (!cords_in_threatmap(coordinates, threatmap))
			legal_moves[i++] = coordinates;
	}
	legal_moves[i] = NULL;
	return (legal_moves); 
}

int	main(void)
{
	char *fenstring = "2B1R3/4q3/1K1P3n/P1N2p1P/2k2B2/2p1p3/1P4p1/8";
	board ChessBoard = Fill_starting_position(fenstring);
	
	ptr_tab(ChessBoard);
        /*// update the board
	ChessBoard.ChessSquare[1][0].isEmpty = 1;
        ChessBoard.ChessSquare[3][0].ChessPiece.name = 'p';
        ChessBoard.ChessSquare[3][0].ChessPiece.y_cords = 3;
        ChessBoard.ChessSquare[3][0].ChessPiece.x_cords = 0;
	ChessBoard.ChessSquare[3][0].ChessPiece.piece_fullmove += 1;

         // get the new fenstring*/
	 //int	**legal_king_moves;
	 //int	***threatmap = get_threatmap(ChessBoard, 0);
	 //legal_king_moves = get_legal_moves_king(ChessBoard.ChessSquare[0][4].ChessPiece, ChessBoard, threatmap);
	int i = 0;
	int k = 0;
	int j;
	int	***threatmap;

	threatmap = get_threatmap(ChessBoard, 1); 
	while (threatmap[i])
	{
		while (threatmap[i][k])
		{
			j = 0;
			while (j < 2)
			{
				if (threatmap[i][k])
					printf("[%i,", threatmap[i][k][j]);
				j++;
			}
			printf("\n");
			k++;
		}
		i++;
	}
	return 0;
}
