/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_putstruct_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:40:19 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 13:07:20 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../p.h"

int	suc(int type)
{
	int	*a;

	a = (int []){
		0,
		sizeof(int),
		sizeof(char),
		sizeof(char *),
		sizeof(double),
		sizeof(int *),
		sizeof(char **),
		sizeof(int),
		sizeof(long long),
		sizeof(char *),
		sizeof(int),};
	if (type <= 10)
		return (a[type]);
	return (0);
}

int	struc2(int fd, int *ctr, void *po)
{
	if (ctr[1] == POINTER && round_counter(ctr, ctr[2]))
		p_putpointer_fd(((long long *)po)
		[ru((double)afunction(ctr, ctr[2]) / ctr[2])], fd);
	else if (ctr[1] == DOUBLE && round_counter(ctr, ctr[2]))
		p_putdouble_fd(((double *)po)
		[ru((double)afunction(ctr, ctr[2]) / ctr[2])], fd);
	else if (ctr[1] == FILENAME && round_counter(ctr, ctr[2]))
		p_putfile_fd(((char **)po)[ru((double)afunction(ctr, ctr[2]) / ctr[2])], fd);
	else if (ctr[1] == FILEDESCRIPTOR && round_counter(ctr, ctr[2]))
		p_putfd_fd(((int *)po)[ru((double)afunction(ctr, ctr[2]) / ctr[2])], fd);
	else
		return (0);
	return (1);
}

int	struc(va_list *l, int fd, int *ctr, void *po)
{
	ctr[1] = va_arg(*l, int);
	if (ctr[1] == THEEND)
		return (0);
	ctr[2] = suc(ctr[1]);
	p(fd SS va_arg(*l, char *) SS ":\t" END);
	if (ctr[1] == INT && round_counter(ctr, ctr[2]))
		p_putnbr_fd(((int *)po)[ru((double)afunction(ctr, ctr[2]) / ctr[2])], fd);
	else if (ctr[1] == CHAR)
		p_putchar_fd(((char *)po)[afunction(ctr, 1)], fd);
	else if (ctr[1] == BOOL && round_counter(ctr, ctr[2]))
		p_putbool_fd(((int *)po)[ru((double)afunction(ctr, ctr[2]) / ctr[2])], fd);
	else if (ctr[1] == STR && round_counter(ctr, ctr[2]))
		p_putstr_fd(((char **)po)[ru((double)afunction(ctr, ctr[2]) / ctr[2])], fd);
	else if (ctr[1] == STR_A && round_counter(ctr, ctr[2]))
		p_putstra_clean(((char ***)po)
		[ru((double)afunction(ctr, ctr[2]) / ctr[2])], fd);
	else if (ctr[1] == INT_A && round_counter(ctr, ctr[2]))
		p_putia_clean(&((int *)po)[ru((double)afunction(ctr, ctr[2]) / ctr[2])],
			va_arg(*l, int), fd);
	else
		return (struc2(fd, ctr, po));
	return (1);
}

void	p_put_struct(va_list *l, int fd)
{
	void	*po;
	int		ctr[3];

	po = va_arg(*l, void *);
	p(fd SS va_arg(*l, char *) NL END);
	*ctr = 0;
	ctr[1] = 0;
	ctr[2] = 0;
	while (struc(l, fd, ctr, po))
		p(fd NL END);
}
