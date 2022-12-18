/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:51:45 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 11:01:59 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p.h"

int	*text_mode(void)
{
	static int	mode;

	return (&mode);
}

void	ft_putchar_fd(char c, int fd)
{
	if (*text_mode() == normal)
		write(fd, &c, 1);
	else
	{
		if (*text_mode() == toupper)
			c = ft_toupper(c);
		else if (*text_mode() == tollower)
			c = ft_tolower(c);
		write(fd, &c, 1);
	}
}
