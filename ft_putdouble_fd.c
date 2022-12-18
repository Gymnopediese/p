/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:41:51 by albaud            #+#    #+#             */
/*   Updated: 2022/12/17 20:32:11 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p.h"

void	ft_putdouble_fd(double d, int fd)
{
	ft_putnbr_fd((long long)d, fd);
	ft_putstr_fd(".", fd);
	ft_putnbr_fd((long long)((d - (long long)d) * 1000000), fd);
}
