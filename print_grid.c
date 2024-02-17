#include <unistd.h>

// Fonction pour afficher la grille de la solution du puzzle
void print_grid(int grid[4][4])
{
	int i; // Initialise l'indice de la ligne à 0 pour démarrer avec la première ligne
	int j; // Initialise l'indice de la ligne à 0 pour démarrer avec la première ligne
	char num; // Variable pour stocker le caractère numérique à affiche
 
	i = 0;
	// Boucle sur chaque ligne de la grille en utilisant une boucle while
	while (i < 4)
	{
		j = 0; // Initialise l'indice de la colonne à 0 pour chaque nouvelle ligne

		// Boucle sur chaque colonne de la ligne actuelle en utilisant une boucle while
		while (j < 4)
		{
			num = grid[i][j] + '0'; // Convertit le nombre (int) en son équivalent caractère
			write(1, &num, 1); // Affiche le caractère numérique

			// Si ce n'est pas le dernier nombre de la ligne, ajoute un espace après
			if (j < 4 - 1)
				write(1, " ", 1); // Ajoute un espace entre les nombres pour une meilleure lisibilité

			j++; // Incrémente l'indice de la colonne pour passer à la colonne suivante
		}
		write(1, "\n", 1); // Après avoir affiché tous les nombres de la ligne, ajoute un saut de ligne
		i++; // Incrémente l'indice de la ligne pour passer à la ligne suivante
	}
}
