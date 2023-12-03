#include "chess.h"

static void	ptr_pieceval(char piece)
{
	switch(piece)
	{
		case	'p':
			write(1, "p", 1);
			break;
		case	'r':
			write(1, "r", 1);
			break;
		case	'n':
			write(1, "n", 1);
			break;
		case	'b':
			write(1, "b", 1);
			break;
		case	'k':
			write(1, "k", 1);
			break;
		case	'q':
			write(1, "q", 1);
			break;
		case	'P':
			write(1, "P", 1);
			break;
		case	'R':
			write(1, "R", 1);
			break;
		case	'N':
			write(1, "N", 1);
			break;
		case	'B':
			write(1, "B", 1);
			break;
		case	'K':
			write(1, "K", 1);
			break;
		case	'Q':
			write(1, "Q", 1);
			break;
		case	'/':
			write(1, "\n", 1);
			break;
		default:
			break;
	}
}

void	ptr_tab(const char *fenstring)
{
	int	i;
	int	k;

	i = k = 0;
	while (i < 64)
	{
		if (isdigit(fenstring[i]))
		{
			k = fenstring[i] - '0';
			while (k >= 0)
			{
				write(1, ". ", 3);
				k--;
			}
		}
		else
			ptr_pieceval(fenstring[i]);
		write(1, " ", 1);
		i++;
	}
}
/*
int	main(void)
{
	char *fenstring = "r1bk3r/p2pBpNp/n4n2/1p1NP2P/6P1/3P4/P1P1K3/q5b1";
	ptr_tab(fenstring);
	return 0;
}*/
