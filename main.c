/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:39:11 by albaud            #+#    #+#             */
/*   Updated: 2022/12/18 11:35:50 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p.h"
#include <stdio.h>

typedef struct s_v
{
	char	x;
	char	y;
	char	zz;
	int		z;
	char	*salut;
	char	*sss;
	int		w;
	int		e;
	char	**srx;
}	t_v;

struct s_a
{
	int		a;
	char	b;
	char	*c;
};

// THEEND,
// 	INT_A,
// 	STR_A,
// 	POINTER,
// 	FILENAME,
// 	FILEDESCRIPTOR,
// 	STRUCT,
// 	LIST,
// 	ARRAY,
// 	MATRIX,
// 	ENDL,
// 	VERTICALTAB,
// 	SEPARATOR,
// 	CHANGEBASE,
// 	CHANGECOLOR,
// 	RESETCOLOR

void shortcuts()
{
	p(1 SS "SHORTCUTS\t:\n" END);
	p(1 VT SS "1 tab\n" END);
	p(1 VT VT SS "2 tab\n" END);
	p(1 VT VT VT SS "3 tab\n" END);

	p(1 NL SS "this is on a new line" NL NL END);

	p(1 SS "voici quelques chiffres: " II 12 SE II 42 SE II 777
		SS " voilà." NL END);
}

void	basic_usage()
{
	p(1 SS "BASIC USAGE\t:\n" END);
	p(1 SS "############INT#################" NL END);
	p(1 II 123123123 NL END);
	p(1 II 2147483647 NL END);
	p(1 II 'a' NL END);
	p(1 SS "############CHAR################" NL END);
	p(1 CC 97 NL END);
	p(1 CC 'b' NL END);
	p(1 CC 'c' NL END);
	p(1 SS "############STR#################" NL END);
	p(1 SS "moi\t:\tsalut p, tu es mon fils" NL END);
	p(1 SS "p\t:\tok par ou commençons nous la conquête du monde?" NL END);
	p(1 SS "moi\t:\tallons rendre visite a printf..." NL END);
	p(1 SS "############BOOL################" NL END);
	p(1 SS "'\\0'\t->\t" BB '\0' NL END);
	p(1 SS "'b'\t->\t" BB 'b' NL END);
	p(1 SS "0\t->\t" BB 0 NL END);
	p(1 SS "############DOUBLE##############" NL END);
	p(1 DD 24.24 NL END);
	p(1 DD 42.42 NL END);
	p(1 DD 777.42 NL END);
	p(1 SS "############FLOAT###############" NL END);
	p(1 DD 24.24 NL END);
	p(1 DD 42.42 NL END);
	p(1 DD 777.42 NL END);
	p(1 SS "############pointer###############" NL END);
	p(1 PP 0 NL END);
	p(1 PP (&basic_usage) NL END);
	p(1 PP (&shortcuts) NL END);
	p(1 SS "############INT_A###############" NL END);
	p(1 IA (int []){0, 1, 2, 3, 4, 5}, 6 NL END);
	p(1 IA (int []){3, 1, 4, 3, 5, 5}, 6 NL END);
	p(1 IA (int []){0, 1, 3, 3, 4, 3}, 6 NL END);
	p(1 SS "############STR_A###############" NL END);
	p(1 SA (char *[]){"yoo", "mec", "ca", "vas", "?", 0} NL END);
	p(1 SA (char *[]){"yoo", "mec", "en", "vrai", "t", "bien", "la", "?", 0} NL END);
	p(1 SA (char *[]){"yoo", "mec", 0} NL END);
	p(1 SS "############FILE################" NL END);
	p(1 FN "Makefile" NL END);
	p(1 SS "############FD##################" NL END);
	int fd = open("Makefile", O_RDONLY);
	p(1 FD fd NL END);
	p(1 SS "################################" NL END);

}

void	array(void)
{
	p(1 SS "ARRAYS\t:\n" END);
	p(1 SS "############DOUBLE##############" NL END);
	p(1 AR (double []){0.2, 1.2, 3.2, 3.2, 4.2, 3.2} DD 6 NL END);
	p(1 AR (double []){9999999999.99999, 123} DD 2 NL END);
	p(1 AR (double []){24.24, 42.42} DD 2 NL END);
	p(1 SS "############BOOL################" NL END);
	p(1 AR (int []){0, 1, 2, '\0', 'd'} BB 5 NL END);
	p(1 AR (int []){1, 1, 2, 9999, 222} BB 5 NL END);
	p(1 AR (int []){0, 0, 0, '\0', 0} BB 5 NL END);
	p(1 SS "############FILE################" NL END);
	p(1 AR (char *[]){"Makefile", "ft_putchar_fd.c"} FN 2 NL END);
}

void	matrices(void)
{
	p(1 SS "MATRICES\t:\n" END);
	p(1 SS "############DOUBLE##############" NL END);
	p(1 MA (double *[]){
		(double []){0.1, 0.2, 0.3},
		(double []){0.2, 0.3, 0.4},
		(double []){0.3, 0.4, 0.5},
	} DD 3, 3 NL END);
	p(1 SS "############INT#################" NL END);
	p(1 MA (int *[]){
		(int []){1, 2, 3},
		(int []){2, 3, 4},
		(int []){3, 4, 5},
	} II 3, 3 NL END);
	p(1 SS "############STR_A#################" NL END);
	p(1 MA (char *[]){"yoo", "mec", "en", "vrai", "t", "bien", "la", "?", 0}
		CC 999, 999 NL END);
}

void	base_changement()
{
	p(1 SS "BASE CHANGEMENT\t:\n" END);
	p(1 SS "42 BASE 10\t:\t" CBASE 10 II 42 NL END);
	p(1 SS "42 BASE 16\t:\t" CBASE 16 II 42 NL END);
	p(1 SS "42 BASE 2\t:\t" CBASE 2 II 42 NL END);
	p(1 SS "42 BASE 8\t:\t" CBASE 8 II 42 NL END);
	p(1 SS "42000 BASE 36\t:\t" CBASE 36 II 42000 NL END);
	p(1 CBASE 10 END);
}

void	color_changement()
{
	p(1 SS "TEXT CHANGEMENT\t:\n" END);
	p(1 SS "42 GRAS\t\t:\t" CCOL gras II 42 RST NL END);
	p(1 SS "42 CLAIR\t:\t" CCOL clair II 42 RST NL END);
	p(1 SS "42 ITALIC\t:\t" CCOL italic II 42 RST NL END);
	p(1 SS "42 SOULIGNE\t:\t" CCOL souligne II 42 RST NL END);
	p(1 SS "42 CLIGNOTE\t:\t" CCOL clignote II 42 RST NL END);
	p(1 SS "42 BARE\t\t:\t" CCOL bare II 42 RST NL END);
	p(1 SS "42 DSOULIGNE\t:\t" CCOL dsouligne SS "salut" II 42 RST NL END);

	p(1 SS "COLOR CHANGEMENT\t:\n" END);
	p(1 SS "42 IN RED\t:\t" CCOL red II 42 RST NL END);
	p(1 SS "42 IN GREEN\t:\t" CCOL green II 42 RST NL END);
	p(1 SS "42 IN BLUE\t:\t" CCOL blue II 42 RST NL END);
	p(1 SS "42 IN YELLOW\t:\t" CCOL yellow II 42 RST NL END);
	p(1 SS "42 IN WHITE\t:\t" CCOL white II 42 RST NL END);
	p(1 SS "42 IN BLACK\t:\t" CCOL black II 42 RST NL END);
	p(1 SS "42 IN CYAN\t:\t" CCOL cyan II 42 RST NL END);

	p(1 SS "COLOR BACKGROUND\t:\n" END);
	p(1 SS "42 IN HRED\t:\t" CCOL hred II 42 RST NL END);
	p(1 SS "42 IN HGREEN\t:\t" CCOL hgreen II 42 RST NL END);
	p(1 SS "42 IN HBLUE\t:\t" CCOL hblue II 42 RST NL END);
	p(1 SS "42 IN HYELLOW\t:\t" CCOL hyellow II 42 RST NL END);
	p(1 SS "42 IN HWHITE\t:\t" CCOL hwhite II 42 RST NL END);
	p(1 SS "42 IN HBLACK\t:\t" CCOL hblack II 42 RST NL END);
	p(1 SS "42 IN HCYAN\t:\t" CCOL hcyan II 42 RST NL END);

	p(1 SS "UPPER LOWER\t:\n" END);
	p(1 SS "NOMAL\t\t:\t" II 42 SS " ca VAs La mIFf" RST NL END);
	p(1 SS "LOWERCASE\t:\t" CTEXT lowercase II 42 SS " ca VAs La mIFf" RST NL END);
	p(1 SS "UPPERCASE\t:\t" CTEXT uppercase II 42 SS " ca VAs La mIFf" RST NL END);
}


void	list(void)
{
	t_list	*lst;
	t_list	*lst2;
	t_list	*lst3;

	lst = 0;
	lst2 = 0;
	lst3 = 0;

	ft_lstadd_back(&lst, ft_lstnew((int []){0}));
	ft_lstadd_back(&lst, ft_lstnew((int []){1}));
	ft_lstadd_back(&lst, ft_lstnew((int []){2}));
	ft_lstadd_back(&lst, ft_lstnew((int []){3}));
	ft_lstadd_back(&lst, ft_lstnew((int []){4}));

	ft_lstadd_back(&lst2, ft_lstnew((char []){"salut"}));
	ft_lstadd_back(&lst2, ft_lstnew((char []){"comment"}));
	ft_lstadd_back(&lst2, ft_lstnew((char []){"ça"}));
	ft_lstadd_back(&lst2, ft_lstnew((char []){"vas"}));
	ft_lstadd_back(&lst2, ft_lstnew((char []){"la"}));
	ft_lstadd_back(&lst2, ft_lstnew((char []){"miff"}));

	ft_lstadd_back(&lst3, ft_lstnew((double []){42.42}));
	ft_lstadd_back(&lst3, ft_lstnew((double []){999.999}));
	ft_lstadd_back(&lst3, ft_lstnew((double []){21.32}));
	ft_lstadd_back(&lst3, ft_lstnew((double []){323232.3333}));
	ft_lstadd_back(&lst3, ft_lstnew((double []){999.0000}));

	p(1 SS "LISTS\t\t:\n" END);
	p(1 SS "INT LIST\t:\t" LS lst, INT NL END);
	p(1 SS "STR LIST\t:\t" LS lst2, STR NL END);
	p(1 SS "BOOL LIST\t:\t" LS lst, BOOL NL END);
	p(1 SS "DOUBLE LIST\t:\t" LS lst3, DOUBLE NL END);
	p(1 SS "FLOAT LIST\t:\t" LS lst3, FLOAT NL END);
}

int	main(void)
{
	// shortcuts();
	// basic_usage();
	// array();
	// matrices();
	 color_changement();
	// base_changement();
	// list();
	return (0);
	// nums = (int *[]){
	// 	(int []){0, 1, 2, 3},
	// 	(int []){1, 2, 3, 4},
	// 	(int []){2, 3, 4, 5},
	// 	(int []){3, 4, 5, 6},
	// 	};
	// p(1 MA nums II 4, 4 NL END);
	// p(1 CC 'a' CC 'b' CC 'c' NL END);
	// string = (char *){"savala miff"};
	// s = (char *[]){"salut", "la", "miff", 0};
	// p(1 MA s CC 3, 12 NL END);
	// p(1 AR string CC 3 NL END);
	// p(1 AR (double []){12.32, 123.333, 12332.999} DD 3 NL END);
	// return (0);
	// v = (t_v){'s', 'o', 's', 777, "salut", "mec", 123, 321,
	// 	(char *[]){"t pas src la", "jai tord?"}};
	// aa = (struct s_a){911, 'z', "jaime p"};
	// p(1 II 123 NL IA (&v), 3 NL BB 1 SS
	// 	" is only the spirit way of thinking about what is " BB 0 NL END);
	// p(1 SS "mmmmmm" NL END);
	// p(1 SS "start\n" ST (&v), "printing t_v" CC "x" CC "y" CC "h" II
	// 	"z" SS "salut" SS "sss" II "w" II "e" SA "Srx mec" END SS "end" NL END);
	// p(1 SS "p c'est le turf" NL SS "jaime vraiment p + que " DD 123.123 NL END);
	// p(1 ST (&aa), "printing a" II "a" CC "b" SS "c" END NL END);
	// p(1 FN "Makefile" NL END);
	// p(1 PP (&v) NL END);
	// p(1 SA s SS string NL END);
	// printf("%p\n", &v);
}
