/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_putdouble_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:41:51 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 13:06:40 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../p.h"

void	p_put(long long n, int fd, int v)
{
	long long	nb;

	nb = n;
	// if (v == 0)
	// 	write(fd, ".", 1);
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= *base())
	{
		p_put(nb / *base(), fd, v - 1);
		nb = nb % *base();
	}
	if (nb < *base())
	{
		if (v == 0)
			write(fd, ".", 1);
		write(fd, &"0123456789"[nb], 1);
	}
}

void	p_putdouble_fd(double d, int fd)
{
	long long	t;
	long long	n;

	n = d * 1000000;
	if (n < 0)
	{
		n *= -1;
		p_putstr_fd("-", fd);
	}
	if (n == 0)
		write(fd, "0", 2);
	else if (n < 1000000)
	{
		t = n * 10;
		write(fd, "0.", 2);
		while (t < 1000000)
		{
			t *= 10;
			write(fd, "0", 1);
		}
		p_put(n, fd, 99);
	}
	else
		p_put(n, fd, 5);
}
