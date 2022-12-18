/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarrma_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:18:22 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 13:22:29 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../p.h"

int	arrarr(va_list *l, int fd)
{
	int		i;
	int		type;
	int		s;
	int		size;
	void	*ar;

	i = -1;
	ar = va_arg(*l, void *);
	type = va_arg(*l, int);
	size = va_arg(*l, int);
	s = va_arg(*l, int);
	p(1 SS "{" END);
	while (++i < size)
	{
		if (i < size - 1 && ((long *)ar)[i])
			p(fd AR ((long *)ar)[i], type, s SS "," NL END);
		else if (((long *)ar)[i])
			p(fd AR ((long *)ar)[i], type, s END);
		else if (p(1 SS "}" END))
			return (0);
	}
	p(1 SS "}" END);
	return (0);
}

int	arr2(int type, int fd, void *ar, int i)
{
	if (type == CHAR && ((char *)ar)[i])
		p(fd SS "\'" CC ((char *)ar)[i] SS "\'" END);
	else if ((type == INT || type == BOOL))
		p(fd, type, ((int *)ar)[i] END);
	else if (type == STR && ((long long *)ar)[i])
		p(fd SS "\"", type, ((long long *)ar)[i] SS "\"" END);
	else if (type > BOOL && ((long long *)ar)[i])
		p(fd, type, ((long long *)ar)[i] END);
	else if (p(1 SS "}" END))
		return (0);
	return (1);
}

int	arr(va_list *l, int fd)
{
	int		type;
	int		size;
	void	*ar;
	int		i;

	i = -1;
	ar = va_arg(*l, void *);
	type = va_arg(*l, int);
	size = va_arg(*l, int);
	p(1 SS "{" END);
	while (++i < size)
	{
		if (!arr2(type, fd, ar, i))
			return (0);
		if (i < size - 1)
			p(fd SS ", " END);
	}
	p(1 SS "}" END);
	return (0);
}
