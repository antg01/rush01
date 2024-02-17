#define GRID_SIZE 4

// Fonction pour analyser et extraire les vues des quatre côtés de la grille à partir de l'entrée de l'utilisateur
void parse_views(char *input, int up[GRID_SIZE], int down[GRID_SIZE], int left[GRID_SIZE], int right[GRID_SIZE]) 
{
	int	index;
	int	i;
	// Déclaration et initialisation de l'index pour parcourir l'entrée et d'un compteur
	index = 0;
	i = 0;

	// Boucle pour extraire les vues du haut (up) à partir de l'entrée
	// Elle continue jusqu'à ce que toutes les vues du haut soient extraites (pour la grille 4x4)
	while (i < GRID_SIZE)
	{
		// Convertit le caractère à l'index courant en entier et l'assigne au tableau des vues du haut
		up[i] = input[index] - '0';
		index += 2; // Incrémente l'index pour passer au prochain nombre, en sautant un espace
		i++; // Incrémente le compteur pour passer à la vue suivante
	}

	// Réinitialisation du compteur pour l'extraction des vues suivantes
	i = 0;
	// Boucle pour extraire les vues du bas (down)
	while (i < GRID_SIZE)
	{
		down[i] = input[index] - '0'; // Processus similaire pour les vues du bas
		index += 2; // Passe au prochain nombre valide, en sautant un espace
		i++;
	}

	// Réinitialisation du compteur pour l'extraction des vues de gauche (left)
	i = 0;
	while (i < GRID_SIZE)
	{
		left[i] = input[index] - '0'; // Processus similaire pour les vues de gauche
		index += 2; // Passe au prochain nombre valide
		i++;
	}

	// Réinitialisation du compteur pour l'extraction des vues de droite (right)
	i = 0;
	while (i < GRID_SIZE)
	{
		right[i] = input[index] - '0'; // Processus similaire pour les vues de droite
		index += 2; // Passe au prochain nombre valide
		i++;
	}
}
