/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:20:21 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 13:07:29 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../p.h"

int	ru(double num)
{
	if ((num - (int)num) * 10 > 0)
		return ((int)num + 1);
	return ((int) num);
}

int	round_counter(int *c, int r)
{
	if (*c % r == 0)
		return (1);
	*c = *c + ru(((double) *c / (double)r));
	return (1);
}

int	a(int *c, int r)
{
	int	t;

	t = *c;
	*c += r;
	return (t);
}
