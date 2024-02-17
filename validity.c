// Fonction pour valider l'entrée de l'utilisateur
int validate_input(char *input)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	// Boucle pour parcourir chaque caractère de la chaîne d'entrée
	while (input[i])
	{
		// Vérifie si le caractère courant n'est ni un chiffre valide (entre '1' et '4') ni un espace
		// Si le caractère est en dehors de cette plage et n'est pas un espace, retourne 0 (entrée invalide)
		if ((input[i] < '1' || input[i] > '4') && input[i] != ' ')
			return 0;

		// Si le caractère courant est un chiffre valide (entre '1' et '4'), incrémente le compteur
		if (input[i] >= '1' && input[i] <= '4')
		{
			count++;
		}
 
		// Incrémente l'index pour passer au caractère suivant dans la chaîne d'entrée
		i++;
	}
	// Vérifie si le nombre total de chiffres valides dans l'entrée est exactement 16,
	// ce qui correspond à 4 vues pour chacun des 4 côtés d'une grille 4x4.
	// Retourne 1 (true) si le compte est correct, sinon retourne 0 (false).
	return count == 16;
}
