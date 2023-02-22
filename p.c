/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:39:00 by albaud            #+#    #+#             */
/*   Updated: 2023/02/14 01:09:05 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p.h"

int	*length(void)
{
	static int	mode;

	return (&mode);
}

int	papapa(int fd, va_list *l, int num)
{
	(void) fd;
	if (num == LEN)
		*(length()) = va_arg(*l, int);
	else
		return (0);
	return (1);
}

int	papa(int fd, va_list *l, int num)
{
	if (num == POINTER)
		p_putpointer_fd(va_arg(*l, long long), fd);
	else if (num == LIST)
		p_putlst_fd(l, fd);
	else if (num == ARRAY)
		arr(l, fd);
	else if (num == MATRIX)
		arrarr(l, fd);
	else if (num == SEPARATOR)
		p_putstr_fd(" : ", fd);
	else if (num == VERTICALTAB)
		p_putstr_fd("\t", fd);
	else if (num == CHAR)
		p_putchar_fd(va_arg(*l, int), fd);
	else if (num == CHANGEBASE)
		*(base()) = va_arg(*l, int);
	else if (num == CHANGECOLOR)
		p(fd SS "\033[0;" II va_arg(*l, int) SS "m" END);
	else if (num == RESETTEXT)
		p(fd CTXT normal SS "\033[0m" END);
	else if (num == CHANGETEXT)
		*(text_mode()) = va_arg(*l, int);
	else
		return (papapa(fd, l, num));
	return (1);
}

int	pa(int fd, va_list *l, int num)
{
	if (num == INT)
		p_putnbr_fd(va_arg(*l, int), fd);
	else if (num == STR)
		p_putstr_fd(va_arg(*l, char *), fd);
	else if (num == INT_A)
		p_putia_clean(va_arg(*l, int *), va_arg(*l, int), fd);
	else if (num == DOUBLE)
		p_putdouble_fd(va_arg(*l, double), fd);
	else if (num == BOOL)
		p_putbool_fd(va_arg(*l, int), fd);
	else if (num == STR_A)
		p_putstra_clean(va_arg(*l, char **), fd);
	else if (num == BOOL)
		p_putstr_fd(va_arg(*l, char *), fd);
	else if (num == ENDL)
		p_putstr_fd("\n", fd);
	else if (num == STRUCT)
		p_put_struct(l, fd);
	else if (num == FILENAME)
		p_putfile_fd(va_arg(*l, char *), fd);
	else if (num == FILEDESCRIPTOR)
		p_putfd_fd(va_arg(*l, int), fd);
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
