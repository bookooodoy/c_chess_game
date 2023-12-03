#include "chess.h"

board Fill_starting_position(const char *fenstring)
{
        board   ChessBoard;
	int	i;
	int	k;
	int	len;

	i = k = 0;
	while (k < (int)strlen(fenstring))
	{
		if (isdigit(fenstring[k]))
		{
			len = 0;
			while (len < fenstring[k] - '0')
			{
				ChessBoard.ChessSquare[i / 8][(i + len) % 8].isEmpty = 1;
				len++;
			}
			i += len;
		}
		else if (isalpha(fenstring[k]))
		{
			ChessBoard.ChessSquare[i / 8][i % 8].isEmpty = 0;
			ChessBoard.ChessSquare[i / 8][i % 8].ChessPiece.name = fenstring[k];
			i++;
		}
		k++;
	}
        return (ChessBoard);
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


int	main(void)
{
	//char *fenstring = "r1bk3r/p2pBpNp/n4n2/1p1NP2P/6P1/3P4/P1P1K3/q5b1";
	char *fenstring = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
	board ChessBoard = Fill_starting_position(fenstring);

	ptr_tab(ChessBoard);
	// update the board
	ChessBoard.ChessSquare[1][0].isEmpty = 1;
	ChessBoard.ChessSquare[3][0].isEmpty = 0;
	ChessBoard.ChessSquare[3][0].ChessPiece.name = 'p';

	// get the new fenstring
	char *newfenstring = update_fenstring(ChessBoard);

	printf("\n\n\n SECOND BOARD AFTER CHANGE \n\n\n");
	ptr_tab(ChessBoard);
	printf("\n%s\n", newfenstring);
	return 0;
}
