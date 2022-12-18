# p
p

## SYNOPSIS:
	int	p(int fd, ...);

## DESCRIPTION:
	p est une fonction qui fait passer printf pour un mandiant qui tue vos femmes
	p s'apelle p car nous sommes la pour obtimiser la place
	p prend comme premier parametre le fd dans lequel il écrira la data
	ce choix est du a va_arg mais il rend p plus interessant
	p c'est tlm beau que beaucoup de functions de p utilisent p pour imprimer
	des trucs, BOOOM
	p apporte une plus grande varieter de choix que le pauvre printf qui me
	fait de la peines
	p n'a pas de formatage dégueulasse avec des % à la con
	a noter que c'est 100% pour la raison susmentionée que jai coder p
	p est mon cher et tendre fils unique, je l'aime

## ARGUMENTS:
	fd :	fd dans lequel imprimer
	... :	le type de ce que l'on veux imprimer suivit de la varibale,
			les type font parties de l'enum e_types,
			0 ou THEEND signifie la fin des argument
			LE 0 EST IMPORTANT POUR UN FONCTIONEMENT CORRECT
			sans 0 le comportement est indéfinis
	exemple p(1, INT, 1, 0); -> imprime 1 sur STDOUT
	(fd)(type)(data)(type2)(data2)(...)(typeN)(dataN)(fin des arguments)
	Les macro SS II DD BB etc... permettent de simplifier la syntax
	le premiere exemple devient donc:
		p(1 II 1 END);

## MACROS:
	II -> int
	CC -> char
	SS -> string
	FF -> float
	DD -> double
	PP -> pointer
	BB -> bool			(0 -> "false" else -> "true")
	IA -> int array		EXEPTION
	SA -> char array
	FL -> print un fichier
	FD -> print un fd
	AR -> array			EXEPTION (a ça rigole plus la)
	MA -> matrice		EXEPTION (p il respect meme pas printf enft)
	ST -> structue		EXEPTION (oui je sais maintenant TOUT des structures...)
	LS -> list chainé	EXEPTION (pri quoi???)
	NL -> new line		EXEPTION
	VT -> vertical tabe	EXEPTION
	SE -> separator		EXEPTION


## EXEMPLES:
	p(fd II 1234 END) -> imprime 1234 dans fd
	p(1 SS "le resultat est " BB 0 END)
	-> 
	le resultat est faux
	
	p(1 SS "p c'est le turf" NL SS "jaime vraiment p " DD 42.42 SS
		"fois plus que printf" END)
	->
	p c'est le turf
	jaime vraiment p 42.42 fois plus que printf

## NOTE:
	-	tout non respect des exception ou de la syntaxe en général peut entrainer
		une simple erreur de compilation tout comme un segfault,
		faite donc bien attention (voir EXCEPTION plus bas);
	-	les bool sont basé sur les macros TRUE_TEXT et FALSE_TEXT
		qui peuvent etre chnager selon les desires de chaquns
	-	Les macros utilisé peuvent être changées si nécéssaire
		exemple SS -> S pour simplifier encore plus
	-	imprimer &variable ne respect pas la norme,
		a mettre en parenthese: (&variable)

## EXCEPTIONS:
	IA:
		IA doit etre suivit de la taille du tableau a imprimer
		exemple: p(1 IA tab, 10 END); attention a ','!!!
	NL:
		imprime un retour a la ligne et ne demande donc pas d'arguments
		exemple		:	p(1 II 42 NL 42 END);
						->
						42
						42;
		sans NL VT ou SE la manipulation de nombre serait plus complexe
		sans NL		:	p(1 II 42 SS "\n" 42 END);
		ce qui a la longue peux devenir une perte de temps
	VT:
		similaire a NL mais imprime un tab
	SE:
		similaire a NL mais imprime un separateur, " : " par default
		exemple		:	p(1 SS "data: " II 42 SE II 42 END)
						->
						data: 42 : 42
		pour rendre certains outputs plus lisible
	AR: 
		AR est special est a donc sa propre partie
	MA: 
		MA est special est a donc sa propre partie
	ST:
		ST est special est a donc sa propre partie
	LS: 
		LS est special est a donc sa propre partie

## ARRAY:
	p() peux imprimer des array ce qui est plutot pratique et ce qui ne
	peut etre réalisé par le misérable printf...
	format pour les array:
		p((fd) AR (array[]) (datatype) (size) END);
		###### exempls:
			char **salut = (char *[]){"salut", "les", "amis"};
			p(1 AR salut SS 3 END);
			->
			{"salut", "les", "amis"}

## MATRIX:
	p() peux imprimer des matrices ce qui est plutot tres sympa
	format pour les matrices:
		p((fd) MA (matrice[][]) (datatype) (size y) (size x) END);
		exemple:
			int **nums = (int *[]){
					(int []){0, 1, 2, 3},
					(int []){1, 2, 3, 4},
					(int []){2, 3, 4, 5},
					(int []){3, 4, 5, 6},
				};
			p(1 MA nums II 4, 4 END);
			->
			{{0, 1, 2, 3},
			{1, 2, 3, 4},
			{2, 3, 4, 5},
			{3, 4, 5, 6}}
			----------------------------------------------------------------
			char **salut = (char *[]){"salut", "les", "amis"};
			p(1 MA salut CC 3, 100 END);
			->
			{{'s', 'a', 'l', 'u', 't', },
			{'l', 'a', },
			{'m', 'i', 'f', 'f', },}
			note: 
				- pour un tableau de string l'utilisation de size x a 100
				est correct car un string sarrete de toute façon au caracter '\0'

## STRUCT (ST):
	p() peux imprimer des structure et ça, c'est beau
	(en vrai c la beta jai pas tester tout les cas possibles)
	la structure doit elle meme se finir par un END
	format pour les structures:
		struct a
		{
			int a;
			char b;
			char *c;
		};
		struct a ex = (struc a){1, 'b', "salut"};
		p(1 ST (&ex), "impression de ex" II "a" CC "b" SS "c" END NL END);
		(a noter la virgule apres (&ex))
		->
		impression de ex
		a:	1
		b:	b
		c:	salut
	on donne donc en parametre le pointeur de la structure
	suivit du message header a imprimer,
	chaque data doit etre suivit d'un nom peu importe ce que c'est
	note:		- les bools doivent etre des int pas des char ou des shorts!!!
				un bool char ou short donne un comportement indéfinis.
				- la prise en charge des struct incite l'utilisateur a creer une fonction
				qui utilisera p pour afficher sa structure car l'apelle de p est certe plus
				efficace que d'autre méthode (PRINTF),  mais reste néanmoin trop long.
	attention:	- ne fonctionne pas avec les structure composant d'autres structures;
				- ne fonctionne pas avec des array autre que SA et IA;

## LIST (LS):
	p() peux imprimer des liste...
	p se base sur cette variante des listes chainé
	typedef struct s_list
	{
		struct s_list	*next;
		void			*data;
	}	t_list;
	
	format pour les list:
		p((fd) LS (ton t_list *), (DATATYPE) END);
		exempl:
			t_
	structure:
		les noms n'ont pas dimportance seul le squelette importe
		typedef struct <s_list_name>
		{
			struct s_list	*<next_name>;
			void			*<data_name>;
		}	 <t_list_name>;
		
		la structure ci dessous fonctionne donc très bien:
		typedef struct salut
		{
			struct s_list	*previouslol;
			void			*voiddatanameofthevoid;
		}	 wshwsh;

		tandis que la structure ci dessous ne fonctionnera pas (swap):
		typedef struct s_list
		{
			void			*data;
			struct s_list	*next;
		}	t_list;

		la structure ci dessous fonctionne:
		typedef struct s_list
		{
			struct s_list	*next;
			char			*data;
		}	t_list;
		
		la structure ci dessous fonctionne mais n'imprimera que "data":
		typedef struct s_list
		{
			struct s_list	*next;
			void			*data;
			void			*data2;
			void			*data3;
		}	t_list;

		la structure ci dessous ne fonctionne pas:
		typedef struct s_list
		{
			struct s_list	*next;
			int				data;
		}	t_list;
