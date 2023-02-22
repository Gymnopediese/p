/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_putia_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:21:16 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 13:06:47 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../p.h"

void	p_putia_clean(int *arr, int size, int fd)
{
	int	loop;

	loop = -1;
	p_putstr_fd("{", fd);
	while (++loop < size)
	{
		p_putnbr_fd(arr[loop], fd);
		if (loop < size - 1)
		{
			p_putstr_fd(", ", fd);
		}
	}
	p_putstr_fd("}", fd);
}
