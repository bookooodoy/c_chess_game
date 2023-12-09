#include "chess.h"

int	check_square_valid(const board ChessBoard, int y, int x, int team)
{
	// TODO: add check function to verify if we are not in check and if so the move is valid
	if ((y < 0 || y >= 8 )|| (x < 0 || x >= 8))
        	return (0);
	if (ChessBoard.ChessSquare[y][x].isEmpty == 1)
		return (1);
	if (ChessBoard.ChessSquare[y][x].isEmpty == 0 && ChessBoard.ChessSquare[y][x].ChessPiece.color != -1 && ChessBoard.ChessSquare[y][x].ChessPiece.color != team && ChessBoard.ChessSquare[y][x].ChessPiece.name != 'k' && ChessBoard.ChessSquare[y][x].ChessPiece.name != 'K')
		return (2);
	return (0);
}

int	**get_legal_moves_bpawn(piece *piece, board ChessBoard)
{
	int		**legal_moves;
	int	coordinates[2];
	int		i = 0;

	legal_moves = (int **)malloc(sizeof(int *) * 5);
	if (!legal_moves)
		return (NULL);
	if (check_square_valid(ChessBoard, piece->y_cords + 1, piece->x_cords, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords + 1;
		coordinates[1] = piece->x_cords;
		memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords + 2, piece->x_cords, piece->color) && piece->piece_moves == 0)
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords + 2;
		coordinates[1] = piece->x_cords;
		memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	//Check for capture
	if (check_square_valid(ChessBoard, piece->y_cords + 1, piece->x_cords - 1, piece->color) == 2)
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords + 1;
		coordinates[1] = piece->x_cords - 1;
		memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords + 1, piece->x_cords + 1, piece->color) == 2)
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords + 1;
		coordinates[1] = piece->x_cords + 1;
		memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	// TODO: En passant
	// TODO: Promotion
	legal_moves[i] = NULL;
	return (legal_moves);
}


int	**get_legal_moves_wpawn(piece *piece, board ChessBoard)
{
	int	**legal_moves;
	int	coordinates[2];
	int	i = 0;

	legal_moves = (int **)malloc(sizeof(int *) * 5);
	if (!legal_moves)
		return (NULL);
	if (check_square_valid(ChessBoard, piece->y_cords - 1, piece->x_cords, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords - 1;
		coordinates[1] = piece->x_cords;
		memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords - 2, piece->x_cords, piece->color) && piece->piece_moves == 0)
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords - 2;
		coordinates[1] = piece->x_cords;
		memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords - 1, piece->x_cords - 1, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords - 1;
		coordinates[1] = piece->x_cords - 1;
		memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords - 1, piece->x_cords + 1, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords - 1;
		coordinates[1] = piece->x_cords + 1;
		memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	// TODO: En passant
	// TODO: Promotion
	legal_moves[i] = NULL;
	return (legal_moves);
}

int	**get_legal_moves_knight(piece *piece, board ChessBoard)
{
	int	**legal_moves;
	int	coordinates[2];
	int	i = 0;

	legal_moves = (int **)malloc(sizeof(int *) * 9);
	if (!legal_moves)
		return (NULL);
	if (check_square_valid(ChessBoard, piece->y_cords + 2, piece->x_cords + 1, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords + 2;
		coordinates[1] = piece->x_cords + 1;
		memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords + 2, piece->x_cords - 1, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords + 2;
		coordinates[1] = piece->x_cords - 1;
		memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords - 2, piece->x_cords + 1, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords - 2;
		coordinates[1] = piece->x_cords + 1;
		memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords - 2, piece->x_cords - 1, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords - 2;
		coordinates[1] = piece->x_cords - 1;
		memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords + 1, piece->x_cords + 2, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords + 1;
		coordinates[1] = piece->x_cords + 2;
		memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords - 1, piece->x_cords + 2, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords - 1;
		coordinates[1] = piece->x_cords + 2;
		memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords + 1, piece->x_cords - 2, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords + 1;
		coordinates[1] = piece->x_cords - 2;
		memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords - 1, piece->x_cords - 2, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords - 1;
		coordinates[1] = piece->x_cords - 2;
		memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	legal_moves[i] = NULL;
	return (legal_moves);
}

int	**get_legal_moves_rook(piece *piece, board ChessBoard)
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
		while ((ret = check_square_valid(ChessBoard, piece->y_cords - i, piece->x_cords, piece->color))) 
		{
			if (ret == 2)
			{
				legal_moves[j] = (int *)malloc(sizeof(int) * 2);
				coordinates[0] = piece->y_cords - i;
				coordinates[1] = piece->x_cords;
				memcpy(legal_moves[j++], coordinates, sizeof(int) * 2);
				break ;
			}
			else if (ret == 1)
			{
				legal_moves[j] = (int *)malloc(sizeof(int) * 2);
				coordinates[0] = piece->y_cords - i;
				coordinates[1] = piece->x_cords;
				memcpy(legal_moves[j++], coordinates, sizeof(int) * 2);
			}
			i++;
		}
		i = 1;
		while ((ret = check_square_valid(ChessBoard, piece->y_cords + i, piece->x_cords, piece->color))) 
		{
			if (ret == 2)
			{
				legal_moves[j] = (int *)malloc(sizeof(int) * 2);
				coordinates[0] = piece->y_cords + i;
				coordinates[1] = piece->x_cords;
				memcpy(legal_moves[j++], coordinates, sizeof(int) * 2);
				break ;
			}
			else if (ret == 1)
			{
				legal_moves[j] = (int *)malloc(sizeof(int) * 2);
				coordinates[0] = piece->y_cords + i;
				coordinates[1] = piece->x_cords;
				memcpy(legal_moves[j++], coordinates, sizeof(int) * 2);
			}
			i++;
		}
		i = 1;
		while ((ret = check_square_valid(ChessBoard, piece->y_cords, piece->x_cords - i, piece->color)))
		{
			if (ret == 2)
			{
				legal_moves[j] = (int *)malloc(sizeof(int) * 2);
				coordinates[0] = piece->y_cords;
				coordinates[1] = piece->x_cords - i;
				memcpy(legal_moves[j++], coordinates, sizeof(int) * 2);
				break ;
			}
			else if (ret == 1)
			{
				legal_moves[j] = (int *)malloc(sizeof(int) * 2);
				coordinates[0] = piece->y_cords;
				coordinates[1] = piece->x_cords - i;
				memcpy(legal_moves[j++], coordinates, sizeof(int) * 2);
			}
			i++;
		}
		i = 1;
		while ((ret = check_square_valid(ChessBoard, piece->y_cords, piece->x_cords + i, piece->color))) 
		{
			if (ret == 2)
			{
				legal_moves[j] = (int *)malloc(sizeof(int) * 2);
				coordinates[0] = piece->y_cords;
				coordinates[1] = piece->x_cords + i;
				memcpy(legal_moves[j++], coordinates, sizeof(int) * 2);
				break ;
			}
			else if (ret == 1)
			{
				legal_moves[j] = (int *)malloc(sizeof(int) * 2);
				coordinates[0] = piece->y_cords;
				coordinates[1] = piece->x_cords + i;
				memcpy(legal_moves[j++], coordinates, sizeof(int) * 2);
			}
			i++;
		}
		break ;
	}
	legal_moves[j] = NULL;
	return (legal_moves);
}

int	**get_legal_moves_bishop(piece *piece, board ChessBoard)
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
		while ((ret = check_square_valid(ChessBoard, piece->y_cords - i, piece->x_cords - i, piece->color))) 
		{
			if (ret == 2)
			{
				legal_moves[j] = (int *)malloc(sizeof(int) * 2);
				coordinates[0] = piece->y_cords - i;
				coordinates[1] = piece->x_cords - i;
				memcpy(legal_moves[j++], coordinates, sizeof(int) * 2);
				break ;
			}
			else if (ret == 1)
			{
				legal_moves[j] = (int *)malloc(sizeof(int) * 2);
				coordinates[0] = piece->y_cords - i;
				coordinates[1] = piece->x_cords - i;
				memcpy(legal_moves[j++], coordinates, sizeof(int) * 2);
			}
			i++;
		}
		i = 1;
		while ((ret = check_square_valid(ChessBoard, piece->y_cords + i, piece->x_cords - i, piece->color))) 
		{
			if (ret == 2)
			{
				legal_moves[j] = (int *)malloc(sizeof(int) * 2);
				coordinates[0] = piece->y_cords + i;
				coordinates[1] = piece->x_cords - i;
				memcpy(legal_moves[j++], coordinates, sizeof(int) * 2);
				break ;
			}
			else if (ret == 1)
			{
				legal_moves[j] = (int *)malloc(sizeof(int) * 2);
				coordinates[0] = piece->y_cords + i;
				coordinates[1] = piece->x_cords - i;
				memcpy(legal_moves[j++], coordinates, sizeof(int) * 2);
			}
			i++;
		}
		i = 1;
		while ((ret = check_square_valid(ChessBoard, piece->y_cords - i, piece->x_cords + i, piece->color))) 
		{
			if (ret == 2)
			{
				legal_moves[j] = (int *)malloc(sizeof(int) * 2);
				coordinates[0] = piece->y_cords - i;
				coordinates[1] = piece->x_cords + i;
				memcpy(legal_moves[j++], coordinates, sizeof(int) * 2);
				break ;
			}
			else if (ret == 1)
			{
				legal_moves[j] = (int *)malloc(sizeof(int) * 2);
				coordinates[0] = piece->y_cords - i;
				coordinates[1] = piece->x_cords + i;
				memcpy(legal_moves[j++], coordinates, sizeof(int) * 2);
			}
			i++;
		}
		i = 1;
		while ((ret = check_square_valid(ChessBoard, piece->y_cords + i, piece->x_cords + i, piece->color))) 
		{
			if (ret == 2)
			{
				legal_moves[j] = (int *)malloc(sizeof(int) * 2);
				coordinates[0] = piece->y_cords + i;
				coordinates[1] = piece->x_cords + i;
				memcpy(legal_moves[j++], coordinates, sizeof(int) * 2);
				break ;
			}
			else if (ret == 1)
			{
				legal_moves[j] = (int *)malloc(sizeof(int) * 2);
				coordinates[0] = piece->y_cords + i;
				coordinates[1] = piece->x_cords + i;
				memcpy(legal_moves[j++], coordinates, sizeof(int) * 2);
			}
			i++;
		}
		break ;
	}
	legal_moves[j] = NULL;
	return (legal_moves);
}

int	**get_legal_moves_queen(piece *piece, board ChessBoard)
{
	int	**legal_moves;
	int	**diagonal;
	int	**vertical;

	diagonal = get_legal_moves_bishop(piece, ChessBoard);
	vertical = get_legal_moves_rook(piece, ChessBoard);
	legal_moves = ft_strjoin(diagonal, vertical);
	return (legal_moves);
}

int	**get_name_move(piece *piece, board ChessBoard)
{
	if (piece->name == 'p')
		return (get_legal_moves_bpawn(piece, ChessBoard));
	if (piece->name == 'P')
		return (get_legal_moves_wpawn(piece, ChessBoard));
	if (piece->name == 'q' || piece->name == 'Q')
		return (get_legal_moves_queen(piece, ChessBoard));
	if (piece->name == 'n' || piece->name == 'N')
		return (get_legal_moves_knight(piece, ChessBoard));
	if (piece->name == 'r' || piece->name == 'R')
		return (get_legal_moves_rook(piece, ChessBoard));
	if (piece->name == 'b' || piece->name == 'B')
		return (get_legal_moves_bishop(piece, ChessBoard));
	return (NULL);
}

int	***get_threatmap(board ChessBoard, int team)
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
				threatmap[len++] = get_name_move(&(ChessBoard.ChessSquare[i][k].ChessPiece), ChessBoard);
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

	i = 0;
	while (threatmap[i])
	{
		j = 0;
		while (threatmap[i][j])
		{
			c = k = 0;
			while (k < 2)
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

int	**get_legal_moves_king(piece *piece, board ChessBoard, int ***threatmap)
{
	int	**legal_moves;
	int	coordinates[2];
	int	i;

	i = 0;
	legal_moves = (int **)malloc(sizeof(int *) * 9);
	if (!legal_moves)
		return (NULL);
	if (check_square_valid(ChessBoard, piece->y_cords + 1, piece->x_cords, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords + 1;
		coordinates[1] = piece->x_cords;
		if (!cords_in_threatmap(coordinates, threatmap))
			memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);

	}
	if (check_square_valid(ChessBoard, piece->y_cords + 1, piece->x_cords + 1, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords + 1;
		coordinates[1] = piece->x_cords + 1;
		if (!cords_in_threatmap(coordinates, threatmap))
			memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords + 1, piece->x_cords - 1, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords + 1;
		coordinates[1] = piece->x_cords - 1;
		if (!cords_in_threatmap(coordinates, threatmap))
			memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords - 1, piece->x_cords, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords - 1;
		coordinates[1] = piece->x_cords;
		if (!cords_in_threatmap(coordinates, threatmap))
			memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords - 1, piece->x_cords + 1, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords - 1;
		coordinates[1] = piece->x_cords + 1;
		if (!cords_in_threatmap(coordinates, threatmap))
			memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords - 1, piece->x_cords - 1, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords - 1;
		coordinates[1] = piece->x_cords - 1;
		if (!cords_in_threatmap(coordinates, threatmap))
			memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords, piece->x_cords + 1, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords;
		coordinates[1] = piece->x_cords + 1;
		if (!cords_in_threatmap(coordinates, threatmap))
			memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	if (check_square_valid(ChessBoard, piece->y_cords, piece->x_cords - 1, piece->color))
	{
		legal_moves[i] = (int *)malloc(sizeof(int) * 2);
		coordinates[0] = piece->y_cords;
		coordinates[1] = piece->x_cords - 1;
		if (!cords_in_threatmap(coordinates, threatmap))
			memcpy(legal_moves[i++], coordinates, sizeof(int) * 2);
	}
	legal_moves[i] = NULL;
	return (legal_moves); 
}

void    ptr_moves(int **moves)
{
        int i = 0;
        int k;

        printf("[");
        while (moves[i])
        {
                k = 0;
                while (k < 2)
                {
                        if (k == 1)
                                printf("%d", moves[i][k]);
                        else
                                printf("%d,", moves[i][k]);
                        k++;
                }
                printf("] ");
                i++;
        }
}

void	ptr_threatmap(int ***threatmap)
{
	int i;

	i = 0;
	while (threatmap[i])
	{
		ptr_moves(threatmap[i]);
		i++;
	}
}


int	main(void)
{
	char *new_fenstring = "4k2r/6r1/8/8/8/8/3R4/R3K3";
	printf("fenstring = %s\n", new_fenstring);
	board ChessBoard = Fill_starting_position(new_fenstring);
	ptr_tab(ChessBoard);
	printf("\n=========LEGAL_MOVES=BLACK==========\n");
	int ***threatmap_b = get_threatmap(ChessBoard, 1);
	ptr_threatmap(threatmap_b);
	//ptr_threatmap(threatmap_b);
	

	printf("\n=========LEGAL_MOVES=WHITE==========\n");
	int ***threatmap_w = get_threatmap(ChessBoard, 0);
	ptr_threatmap(threatmap_w);

	//ptr_threatmap(threatmap_w);

	printf("\n==============DEBUGGING=============\n");
	ptr_parameters_debug(ChessBoard);
	/*int **bmoves = get_legal_moves_queen(&(ChessBoard.ChessSquare[3][7].ChessPiece), ChessBoard);
	ptr_moves(bmoves);*/
	
	printf("\n==============TESTING=============\n");
	char *castling_rights_white = get_castling_rights(ChessBoard, &(ChessBoard.ChessSquare[7][4].ChessPiece));
	char *castling_rights_black = get_castling_rights(ChessBoard, &(ChessBoard.ChessSquare[0][4].ChessPiece));
	printf("Castling rights (to add to FEN string) = %s%s\n", castling_rights_white, castling_rights_black);
	
	return (0);
}
