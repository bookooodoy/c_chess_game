#include "chess.h"

size_t	tab_len(int **tab)
{
	size_t	i = 0;

	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

int	**ft_strjoin(int **a, int **b)
{
	int	**new_tab;
	int	i;
	int	k;

	i = k = 0;
	new_tab = (int **)malloc(sizeof(int *) * (tab_len(a) + tab_len(b)) + 1);
	if (!new_tab)
		return (NULL);
	while (a[i])
	{
		new_tab[i] = a[i];
		i++;
	}
	while (b[k])
	{
		new_tab[i + k] = b[k];
		k++;
	}
	new_tab[i + k] = NULL;
	return (new_tab);
}

void    free_tab(int **tab)
{
        int i = 0;
        while (tab[i])
        {
                free(tab[i]);
                i++;
        }
        free(tab);
}

void	free_threatmap(int ***threatmap)
{
	int i = 0;

	while (threatmap[i])
	{
		free_tab(threatmap[i]);
		i++;
	}
	free(threatmap);
}
