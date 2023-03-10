/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:59:16 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 13:07:03 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../p.h"

void	p_putstr_fd(char const *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		p_putchar_fd(s[i], fd);
}
