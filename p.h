/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:14:51 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 13:23:09 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_H
# define P_H

# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>

enum e_text_mode
{
	normal = 10,
	uppercase,
	lowercase,
};

enum e_color
{
	salut,
	gras,
	clair,
	italic,
	souligne,
	clignote,
	bare = clignote + 4,
	dsouligne = clignote + 16,
	black = 30,
	red,
	green,
	yellow,
	blue,
	purple,
	cyan,
	white,
	hblack,
	hred,
	hgreen,
	hyellow,
	hblue,
	hpurple,
	hcyan,
	hwhite,
};

enum e_types
{
	THEEND,
	INT,
	CHAR,
	BOOL,
	STR,
	DOUBLE,
	FLOAT,
	INT_A,
	STR_A,
	POINTER,
	FILENAME,
	FILEDESCRIPTOR,
	STRUCT,
	LIST,
	ARRAY,
	MATRIX,
	ENDL,
	VERTICALTAB,
	SEPARATOR,
	CHANGEBASE,
	CHANGETEXT,
	CHANGECOLOR,
	RESETTEXT,
};

# define TRUE_TEXT "true"
# define FALSE_TEXT  "false"

# define CC , CHAR,
# define SS , STR,
# define II , INT,
# define DD , DOUBLE,
# define FF , DOUBLE,
# define BB , BOOL,
# define IA , INT_A,
# define SA , STR_A,
# define PP , POINTER,
# define NL , ENDL
# define VT , VERTICALTAB
# define SE , SEPARATOR
# define ST , STRUCT,
# define FN , FILENAME,
# define FD , FILEDESCRIPTOR,
# define AR , ARRAY,
# define MA , MATRIX,
# define LS , LIST,
# define END , THEEND
# define CBASE , CHANGEBASE,
# define CCOL , CHANGECOLOR,
# define RST , RESETTEXT
# define CTXT , CHANGETEXT,

int		p(int fd, ...);

int		ft_putlst_fd(va_list *l, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstra_clean(char **arr, int fd);
void	ft_putia_clean(int *arr, int size, int fd);
void	ft_put_struct(va_list *l, int fd);
void	ft_putfd_fd(int src, int dest);
void	ft_putfile_fd(char *filename, int fd);
void	ft_putdouble_fd(double d, int fd);
void	ft_putbool_fd(int d, int fd);
void	ft_putpointer_fd(long long d, int fd);
int		*base(void);
void	ft_putnbr_fd(long long n, int fd);
int		arr(va_list *l, int fd);
int		arrarr(va_list *l, int fd);

int		ru(double num);
int		round_counter(int *c, int r);
int		a(int *c, int r);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		*text_mode(void);

#endif