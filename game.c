#include "chess.h"

int	get_player_turn(int fullmove)
{
	if (fullmove % 2 == 0)
		return (0);
	return (1);
}

char	*get_player_input(void);

int	check_input_valid(char *input);

void	updateMoveBoard(board ChessBoard, char *player_move);


