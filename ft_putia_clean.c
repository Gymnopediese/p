/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putia_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:21:16 by albaud            #+#    #+#             */
/*   Updated: 2022/12/17 18:55:28 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p.h"

void	ft_putia_clean(int *arr, int size, int fd)
{
	int	loop;

	loop = -1;
	ft_putstr_fd("{", fd);
	while (++loop < size)
	{
		ft_putnbr_fd(arr[loop], fd);
		if (loop < size - 1)
		{
			ft_putstr_fd(", ", fd);
		}
	}
	ft_putstr_fd("}", fd);
}
