#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treenario {
	char *nombre;
	struct treenario *nextlista;
	struct treenario *nexthijo;
} *root = NULL;

void FreeArbolNario (struct treenario *nodo)
{
	while (nodo != NULL) {
		struct treenario *n = nodo; 
		FreeArbolNario (n->nexthijo);
		nodo = nodo->nextlista;
		free (n->nombre);
		free (n);
	}
}

void *DameBuffer (size_t n)
{
	char *p = (char *)malloc (n);
	if (p == NULL) {
		FreeArbolNario (root);
		fprintf (stderr, "\nMEMORIA INSUFICIENTE\n");
		exit (EXIT_FAILURE);
	}
	return (void *)p;
}

struct treenario *MakeNodo (char *nombre)
{
	struct treenario *nodo = (struct treenario *)DameBuffer (sizeof (struct treenario));
	nodo->nombre = (char *)DameBuffer (strlen (nombre) + 1);
	strcpy (nodo->nombre, nombre);
	nodo->nexthijo = nodo->nextlista = NULL;
	return nodo;
}

struct treenario *AgregaHijo (struct treenario **n, char *nombre)
{
	struct treenario *nodo = MakeNodo (nombre);
	if (n == &root) {
		if (root == NULL)
			root = nodo;
		else {
			struct treenario *ap;
			for (ap = root; ap->nextlista != NULL; ap = ap->nextlista)
				;
			ap->nextlista = nodo;
		}
	} else if ((*n)->nexthijo == NULL) {
		(*n)->nexthijo = nodo;
	} else {
		struct treenario *ap;
		for (ap = (*n)->nexthijo; ap->nextlista != NULL; ap = ap->nextlista)
			;
		ap->nextlista = nodo;
	}
	return nodo;
}

void PrintTree (struct treenario *nodo)
{
	static int deep = 0;
	static int nspaces = 3;
	int i, j;
	while (nodo != NULL) {
		for (i = 0; i < deep; i++)
			for (j = 0; j < nspaces; j++)
				printf (" ");
		printf ("%s\n", nodo->nombre);
		deep++;
		PrintTree (nodo->nexthijo);
		deep--;
		nodo = nodo->nextlista;
	}
}

void CreaArbolNario (struct treenario **nodo, int ntab, char *nombres[], int maxlin)
{
	static int nlin = 0;
	struct treenario *n;
	int i;

	while (nlin < maxlin) {
		for (i = 0; nombres[nlin][i] && nombres[nlin][i] == '\t'; i++)
			;
		if (i < ntab)
			return;
		else if (i == ntab)
			n = AgregaHijo (nodo, nombres[nlin++] + i);
		else
			CreaArbolNario (&n, ntab + 1, nombres, maxlin);
	}
}

main ()
{
	char *nombres[] = {
		"eva",
		"\tluis",
		"\t\tmaria",
		"\t\tcarlos",
		"\t\t\tantonio",
		"\t\t\tteresa",
		"\tmanuel",
		"\tandres",
		"\tmiguel",
		"\t\tpedro",
		"\t\tsilvia",
		"\t\tcecilia",
		"\t\tines",
		"\t\tvaleria",
		"\t\t\tgabriel",
		"\t\tmarco",
		"\t\t\tjulian",
		"\t\t\tjesus",
		"\t\t\tgilberto",
		"\t\t\t\tesperanza",
		"\t\t\t\t\troberto",
		"\t\t\t\t\t\tnidia",
		"\t\t\t\t\t\t\tangela",
		"adan",
	};
	int i;

	for (i = 0; i < sizeof (nombres) / sizeof (char *); i++)
		printf ("%s\n", nombres[i]);
	printf ("\t\tLista de nombres (presione una tecla para continuar...)");
	getchar ();

	CreaArbolNario (&root, 0, nombres, sizeof (nombres) / sizeof (char *));
	PrintTree (root);
	FreeArbolNario (root);
	printf ("\t\tArbol con los nombres (presione una tecla para continuar...)");
	getchar ();
}

