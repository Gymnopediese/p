/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:34:00 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 13:10:46 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../p.h"

// typedef struct s_list
// {
// 	struct s_list	*next;
// 	void			*data;
// }	t_list;

void	putlst(void *lst, int fd, int type)
{
	if (lst)
	{
		if (type == INT || type == BOOL)
			p(fd, type, ((int **)lst)[1][0] END);
		else if (type == STR)
			p(fd SS "\"" SS ((char **)lst)[1] SS "\"" END);
		else if (type == DOUBLE || type == FLOAT)
			p(fd DD ((double **)lst)[1][0] END);
		if (((void **)lst)[0])
			p(fd SS ", " END);
		putlst(((void **)lst)[0], fd, type);
	}
}

int	ft_putlst_fd(va_list *l, int fd)
{
	void	*lst;
	int		type;

	p(fd SS "{" END);
	lst = va_arg(*l, void *);
	type = va_arg(*l, int);
	putlst(lst, fd, type);
	p(fd SS "}" END);
	return (0);
}
