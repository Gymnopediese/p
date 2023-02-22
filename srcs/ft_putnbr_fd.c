/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:02:47 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 13:06:58 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../p.h"
#define NUM "0123456789abcdefghijklmnopqrs"

int	*base(void)
{
	static int	base;

	if (base == 0)
		base = 10;
	return (&base);
}

void	p_putnbr_fd(long long n, int fd)
{
	long long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= *base())
	{
		p_putnbr_fd(nb / *base(), fd);
		nb = nb % *base();
	}
	if (nb < *base())
		write(fd, &NUM[nb], 1);
}
