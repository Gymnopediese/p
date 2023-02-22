/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progressbar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:30:19 by albaud            #+#    #+#             */
/*   Updated: 2023/02/14 11:42:53 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p.h"

void	progressbar(char *name, int iter, int max)
{
	int		i;

	i = -1;
	p(1 SS "\r" SS name SS ": " END);
	while (++i < ((double)iter / max) * PROGRESSBARSIZE)
	{
		p(1 SS "█" END);
	}
	while (++i < PROGRESSBARSIZE)
	{
		p(1 SS "_" END);
	}
	p(1 SS ": " DD ((double)iter / max) * 100 SS "%" END);
}
