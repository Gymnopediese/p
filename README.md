# p

# Foobar

Foobar is a Python library for dealing with word pluralization.

## SYNOPSIS
    int	p(int fd, ...);

## DESCRIPTION:
P est une fonction qui fait passer printf pour un mandiant qui tue vos femmes.__
p s'apelle p car nous sommes la pour obtimiser la place.__
p a un main de test très complet, allez checker ça.__
p prend comme premier parametre le fd dans lequel il écrira la data.__
ce choix est du a va_arg mais il rend p plus interessant.__
p c'est tlm beau que beaucoup de functions de p utilisent p pour imprimer des trucs, BOOOM.__
p apporte une plus grande varieter de choix que le pauvre printf qui me fait de la peines.__
p n'est pas compliqué a utiliser mais nécéssite une bonne utilisation, je conseil donc de lire le manuel.__
p n'a pas de formatage dégueulasse avec des % à la con,	a noter que c'est 100% pour la raison susmentionée que jai coder p.__
p est mon cher et tendre fils unique, je l'aime.__

## ARGUMENTS:
##### fd :
fd dans lequel imprimer
##### ... :
le type de ce que l'on veux imprimer suivit de la varibale, les type font parties de l'enum e_types, 0 ou THEEND signifie la fin des argument. LE 0 EST IMPORTANT POUR UN FONCTIONEMENT CORRECT. Sans 0 le comportement est indéfinis.
##### usage:
    p((fd)(type)(data)(type2)(data2)(...)(typeN)(dataN)(fin des arguments))
##### exemple basic :
    p(1, INT, 1, 0); -> imprime 1 sur STDOUT
	Les macro SS II DD BB etc... permettent de simplifier la syntax
	le première exemple devient donc:
		p(1 II 1 END);

## MACROS:
	II      -> int
	CC      -> char
	SS      -> string
	FF      -> float
	DD      -> double
	PP      -> pointer
	BB      -> bool			                (0 -> "false" else -> "true")
	IA      -> int array		            EXEPTION
	SA      -> char array
	FL      -> print un fichier
	FD      -> print un fd
	AR      -> array			            EXEPTION (a ça rigole plus la)
	MA      -> matrice		                EXEPTION (p il respect meme pas printf enft)
	ST      -> structue	    	            EXEPTION (oui je sais maintenant TOUT des structures...)
	LS      -> list chainé	                EXEPTION (pri quoi???)
	NL      -> new line		                EXEPTION
	VT      -> vertical tabe	            EXEPTION
	SE      -> separator		            EXEPTION
	CTEXT   -> change le text               EXEPTION
	CCOL    -> change la couleur du text    EXEPTION
	CBASE   -> change la base numeric       EXEPTION
	RST     -> reset les parametre de text  EXEPTION
	END     -> fin des argument


## EXEMPLES:
	p(fd II 1234 END) -> imprime 1234 dans fd
	p(1 SS "le resultat est " BB 0 END)
	-> 
	le resultat est faux
	
	p(1 SS "p c'est le turf" NL SS "jaime vraiment p " DD 42.42 SS "fois plus que printf" END)
	->
	p c'est le turf
	jaime vraiment p 42.42 fois plus que printf

## NOTE:
-	tout non respect des exception ou de la syntaxe en général peut entrainer une simple erreur de compilation tout comme un segfault, faite donc bien attention (voir EXCEPTION plus bas).
-	les bool sont basé sur les macros TRUE_TEXT et FALSE_TEXT qui peuvent etre changer selon les desires de chaquns
-	Les macros utilisé peuvent être changées si nécéssaire exemple SS -> S pour simplifier encore plus
-	imprimer &variable ou *variable ne respect pas la norme, a mettre en parenthese: (&variable) (*variable)

## EXCEPTIONS:
##### IA:
IA doit etre suivit de la taille du tableau a imprimer

	p(1 IA tab, 10 END); attention a ','!!!
##### NL:
imprime un retour a la ligne et ne demande donc pas d'arguments

	p(1 II 42 NL 42 END);
	->
	42
	42;
sans NL VT ou SE la manipulation de nombre serait plus complexe.
sans NL		:	

    p(1 II 42 SS "\n" 42 END);
Ce qui a la longue peux devenir une perte de temps.
##### VT:
Similaire a NL mais imprime un tab.
##### SE:
similaire a NL mais imprime un separateur, " : " par default.

    p(1 SS "data: " II 42 SE II 42 END)
	->
	data: 42 : 42
Pour rendre certains outputs plus lisible.
##### CTEXT:
CTEXT se base sur l'enum e_text_cmode et permet d'imprimer tous en uppercase ou lowercase

    p(1 CTEXT uppercase SS "salut les amis" END)
	->
	SALUT LES AMIS
##### CCOL:
CCOL se base sur l'enum e_color et permet d'imprimer le text en couleur ou meme en italic gras etc..., allez voir l'enum ;)
```diff
p(1 CCOL red "- salut les amis" RST END)
 ->
- salut les amis
```

##### RST:
RST remet a la normal les text mode et ne nécéssite dont pas d'arguments

##### AR: 
AR est special est a donc sa propre partie
##### MA:
MA est special est a donc sa propre partie
##### ST:
ST est special est a donc sa propre partie
##### LS: 
LS est special est a donc sa propre partie

## ARRAY:
p() peux imprimer des array ce qui est plutot pratique et ce qui ne peut etre réalisé par le misérable printf...
######  format pour les array:
	p((fd) AR (array[]) (datatype) (size) END);
###### exempls:
```c
char **salut = (char *[]){"salut", "les", "amis"};
p(1 AR salut SS 3 END);
->
{"salut", "les", "amis"}
```

## MATRIX:
p() peux imprimer des matrices ce qui est plutot tres sympa
###### format pour les matrices:

	p((fd) MA (matrice[][]) (datatype) (size y) (size x) END);
###### exemples:
```c
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
{'a', 'm', 'i', 's', },}
```
###### note: 
- pour un tableau de string l'utilisation de size x -> 100 est correct car un string sarrete de toute façon au caracter '\0'

## STRUCT (ST):
p() peux imprimer des structure et ça, c'est beau (en vrai c le moin stable de tous j'ai pas tester sur 40 structures differentes)
ST doit se finir par un END
###### format pour les structures:
    p(1 ST (struct pointer), (header text) (elem1 datatype) (elem1 name) ... (elemn datatype) (elemn name) END END)
    (a noter la virgule apres le pointer et les deux END, un pour ST et un pour p)
###### exemple:
	struct a
	{
		int a;
		char b;
		char *c;
	};
	struct a ex = (struc a){1, 'b', "salut"};
	p(1 ST (&ex), "impression de ex" II "a" CC "b" SS "c" END NL END);
	->
	impression de ex
	a:	1
	b:	b
	c:	salut
###### note:
- les bools doivent etre des int pas des char ou des shorts!!! Un bool char ou short donne un comportement indéfinis.
- la prise en charge des struct incite l'utilisateur à créer une fonction qui utilisera p pour afficher sa structure car l'apelle de p est certe plus efficace que d'autre méthode (PRINTF),  mais reste néanmoin trop long.

###### attention:
- ne fonctionne pas avec les structure composant d'autres structures.
- ne fonctionne pas avec des array autre que SA et IA.

## LIST (LS):
p() peux imprimer des liste...
p se base sur cette variante des listes chainé
```c
typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;
```
###### format pour les list:
		p((fd) LS (ton t_list *), (DATATYPE) END);
###### structure:
les noms n'ont pas dimportance seul le squelette importe
```c
		typedef struct <s_list_name>
		{
			struct s_list	*<next_name>;
			void			*<data_name>;
		}	 <t_list_name>;
```
la structure ci dessous fonctionne donc très bien:
```c
typedef struct salut
{
	struct s_list	*previouslol;
	void			*voiddatanameofthevoid;
}	 wshwsh;
```
tandis que la structure ci dessous ne fonctionnera pas (swap):
```c
typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;
```
la structure ci dessous fonctionne:
```c
typedef struct s_list
{
	struct s_list	*next;
	char			*data;
}	t_list;
```	
la structure ci dessous fonctionne mais n'imprimera que "data":
```c
typedef struct s_list
{
	struct s_list	*next;
	void			*data;
	void			*data2;
	void			*data3;
}	t_list;
```
la structure ci dessous ne fonctionne pas:
```c
typedef struct s_list
{
	struct s_list	*next;
	int				data;
}	t_list;
```