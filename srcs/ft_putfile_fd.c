/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfile_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:46:02 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 13:06:45 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../p.h"

void	ft_putfile_fd(char *filename, int fd)
{
	int		_fd;
	char	buffer[1000];
	int		size;

	_fd = open(filename, O_RDONLY);
	if (_fd == -1 && p(2 SS "cannot open file" END))
		return ;
	size = 1;
	while (size)
	{
		size = read(_fd, buffer, 999);
		if (size == -1 && p(2 SS "cannot read file" END))
			return ;
		buffer[size] = 0;
		p(fd SS buffer END);
	}
}
