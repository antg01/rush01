#include <unistd.h>

// Déclaration des fonctions utilisées dans le programme
int 	validate_input(char *input);
void	parse_views(char *input, int up[4], int down[4], int left[4], int right[4]);
int	solve_grid(int grid[4][4], int row, int col, int up[], int down[], int left[], int right[]);
void	print_grid(int grid[4][4]);

int main(int ac, char **av)
{
	// Déclaration des tableaux pour stocker les vues de chaque côté de la grille
	int	up[4];
	int	down[4];
	int	left[4];
	int	right[4];

	// Initialisation de la grille à zéro
	int grid[4][4] = {{0}};

	// Vérifie si le programme est appelé avec le bon nombre d'arguments et si l'entrée est valide
	if (ac == 2 && validate_input(av[1]))
	{
		// Analyse les vues à partir de l'entrée de l'utilisateur et les stocke dans les tableaux appropriés
		parse_views(av[1], up, down, left, right);
		// Tente de résoudre le puzzle. Si une solution est trouvée, affiche la grille.
		if (solve_grid(grid, 0, 0, up, down, left, right))
			print_grid(grid);
		else // Si aucune solution n'est trouvée, affiche une erreur.
			write(1, "Error\n", 6);
	}
	else // Si les arguments ne sont pas valides, affiche une erreur.
	{
		write(1, "Error\n", 6);
	}
	return 0;
}
