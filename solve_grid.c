#include <unistd.h>

int solve_grid(int grid[4][4], int row, int col, int up[], int down[], int left[], int right[])
{
	int	i;
	int	nextCol;
	int	nextRow;
	int	canPlace;
	int	num;

	// Base de la récursion: si on est à la fin de la grille, on a fini
	if (row == 4)
		return 1; // Toutes les lignes sont complétées

	// Calcul pour passer à la prochaine cellule
	nextCol = (col + 1) % 4;
	nextRow = row + (col + 1) / 4;

	num = 1;
	while (num <= 4) // boucle while pour tester chaque numéro possible
	{
		canPlace = 1; // Présuppose que le placement est possible

		i = 0;
		while (i < 4) // boucle while pour vérifier les doublons sur la ligne et la colonne
		{
			// Vérification sur la ligne et la colonne pour les doublons
			if (grid[row][i] == num || grid[i][col] == num)
			{
				canPlace = 0; // Numéro déjà utilisé dans la ligne ou la colonne
				break;
			}
			i++;
		}

		// Si le placement est possible, tente de placer et de résoudre le reste
		if (canPlace)
		{
			grid[row][col] = num; // Fait le placement

			// Vérifie si ce placement permet de résoudre le reste de la grille
			if (solve_grid(grid, nextRow, nextCol, up, down, left, right))
				return 1;
            
			grid[row][col] = 0; // Annule le placement (backtracking)
		}
		num++; // Passe au numéro suivant
	}
	return 0; // Aucun placement valide trouvé, échec de la résolution à cette étape
}
