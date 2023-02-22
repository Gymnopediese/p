/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:37:42 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 13:07:00 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../p.h"

void	p_putpointer_fd(long long d, int fd)
{
	if (*base() == 10)
	{
		p_putstr_fd("0x", fd);
		*base() = 16;
		p_putnbr_fd(d, fd);
		*base() = 10;
	}
	else
		p_putnbr_fd(d, fd);
}
