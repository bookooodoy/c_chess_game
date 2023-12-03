#include "chess.h"

board Fill_starting_position(char *fenstring)
{
        board   ChessBoard;
        int     i;
        int     j;
        int     count;

        i = count = 0;
        while (i < 8)
        {
                j = 0;
                while (j < 8)
                {
                        if (isdigit(fenstring[count]))
                        {
                                while (j < fenstring[count] - '0')
                                {
                                        ChessBoard.ChessSquare[i][j].isEmpty = 1;
                                        j++;
                                }
                        }
                        else
                        {
                                ChessBoard.ChessSquare[i][j].isEmpty = 0;
                                ChessBoard.ChessSquare[i][j].ChessPiece.name = fenstring[count];
                                ChessBoard.ChessSquare[i][j].ChessPiece.x_cords = j;
                                ChessBoard.ChessSquare[i][j].ChessPiece.y_cords = i;
                                j++;
                        }
                        count++;
                }
                i++;
        }
        return (ChessBoard);
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
			if (ChessBoard.ChessSquare[i][j].isEmpty == 1)
				write(1, ". ", 1);
			else
				write(1, &(ChessBoard.ChessSquare[i][j].ChessPiece.name), 1);
			j++;
		}
		i++;
	}
}


int	main(void)
{
	char *fenstring = "r1bk3r/p2pBpNp/n4n2/1p1NP2P/6P1/3P4/P1P1K3/q5b1";
	board ChessBoard = Fill_starting_position(fenstring);

	ptr_tab(ChessBoard);
	return 0;
}
