/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:39:00 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 13:17:58 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p.h"

int	papa(int fd, va_list *l, int num)
{
	if (num == POINTER)
		ft_putpointer_fd(va_arg(*l, long long), fd);
	else if (num == LIST)
		ft_putlst_fd(l, fd);
	else if (num == ARRAY)
		arr(l, fd);
	else if (num == MATRIX)
		arrarr(l, fd);
	else if (num == SEPARATOR)
		ft_putstr_fd(" : ", fd);
	else if (num == VERTICALTAB)
		ft_putstr_fd("\t", fd);
	else if (num == CHAR)
		ft_putchar_fd(va_arg(*l, int), fd);
	else if (num == CHANGEBASE)
		*(base()) = va_arg(*l, int);
	else if (num == CHANGECOLOR)
		p(fd SS "\033[0;" II va_arg(*l, int) SS "m" END);
	else if (num == RESETTEXT)
		p(fd CTXT normal SS "\033[0m" END);
	else if (num == CHANGETEXT)
		*(text_mode()) = va_arg(*l, int);
	else
		return (0);
	return (1);
}

int	pa(int fd, va_list *l, int num)
{
	if (num == INT)
		ft_putnbr_fd(va_arg(*l, int), fd);
	else if (num == STR)
		ft_putstr_fd(va_arg(*l, char *), fd);
	else if (num == INT_A)
		ft_putia_clean(va_arg(*l, int *), va_arg(*l, int), fd);
	else if (num == DOUBLE)
		ft_putdouble_fd(va_arg(*l, double), fd);
	else if (num == BOOL)
		ft_putbool_fd(va_arg(*l, int), fd);
	else if (num == STR_A)
		ft_putstra_clean(va_arg(*l, char **), fd);
	else if (num == BOOL)
		ft_putstr_fd(va_arg(*l, char *), fd);
	else if (num == ENDL)
		ft_putstr_fd("\n", fd);
	else if (num == STRUCT)
		ft_put_struct(l, fd);
	else if (num == FILENAME)
		ft_putfile_fd(va_arg(*l, char *), fd);
	else if (num == FILEDESCRIPTOR)
		ft_putfd_fd(va_arg(*l, int), fd);
	else
		return (papa(fd, l, num));
	return (1);
}

int	p(int fd, ...)
{
	va_list	l;

	va_start(l, fd);
	while (pa(fd, &l, va_arg(l, int)))
		;
	return (1);
}
