/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:51:45 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 11:31:53 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p.h"

int	*text_mode(void)
{
	static int	mode;

	return (&mode);
}

int	ft_tolower(int c)
{
	if (c <= 'Z' && c >= 'A')
		c += 32;
	return (c);
}

int	ft_toupper(int c)
{
	if (c <= 'z' && c >= 'a')
		c -= 32;
	return (c);
}

void	ft_putchar_fd(char c, int fd)
{
	if (*text_mode() == uppercase)
		c = ft_toupper(c);
	else if (*text_mode() == lowercase)
		c = ft_tolower(c);
	write(fd, &c, 1);
}
