/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_putfd_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:51:39 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 13:06:43 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../p.h"

void	p_putfd_fd(int src, int dest)
{
	char	buffer[1000];
	int		size;

	size = 1;
	while (size)
	{
		size = read(src, buffer, 999);
		if (size == -1 && p(2 SS "cannot read file" END))
			return ;
		buffer[size] = 0;
		p(dest SS buffer END);
	}
}
