/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackjack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbin <aherbin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:54:27 by aherbin           #+#    #+#             */
/*   Updated: 2024/07/03 14:25:13 by aherbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_invalid(char *hand)
{
	int		i;
	int		j;
	int		c;
	char	*card;

	card = "23456789TJDKA";
	i = 0;
	while (hand[i])
	{
		c = 0;
		j = 0;
		while (card[j])
		{
			if (card[j] == hand[i])
				c = 1;
			++j;
		}
		if (!c)
			return (0);
		++i;
	}
	return (1);
}

int	calc_score(char c)
{
	int		i;
	char	*card;

	card = "0123456789TA";
	i = 0;
	while (c != card[i])
		++i;
	return (i);
}

int	calc_cor(int score, int n_a)
{
	if (score == 21)
		return (printf("Blackjack!\n"));
	if (score > 21 && n_a > 0)
	{
		score = score - 10;
		calc_cor(score, n_a - 1);
	}
	else
		return (printf("%i\n", score));
}

int	main(int argc, char **argv)
{
	int		i;
	int		score;
	int		n_a;
	char	c;

	i = 0;
	n_a = 0;
	score = 0;
	if (argc != 2 || !is_invalid(argv[1]))
		exit(2);
	while (argv[1][i])
	{
		c = argv[1][i];
		if (c == 'J' || c == 'D' || c == 'K')
			c = 'T';
		if (c == 'A')
			n_a++;
		score += calc_score(c);
		++i;
	}
	return (calc_cor(score, n_a));
}
