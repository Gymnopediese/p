/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_putstra_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:21:16 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 13:07:07 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../p.h"

void	p_putstra_clean(char **arr, int fd)
{
	int	loop;

	loop = -1;
	p_putstr_fd("{", fd);
	while (arr[++loop])
	{
		p_putstr_fd("\"", fd);
		p_putstr_fd(arr[loop], fd);
		p_putstr_fd("\"", fd);
		if (arr[loop + 1])
		{
			p_putstr_fd(", ", fd);
		}
	}
	p_putstr_fd("};", fd);
}
