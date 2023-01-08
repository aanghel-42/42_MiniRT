#include "../../inc/minirt.h"

/**
 * @brief   Calculates the roots of a quadratic equation.
 *          Used to calculate whether a ray intersects a sphere or a cylinder
 * 
 * @param   top_relor rappresenta il prodotto tra il vettore originale e la direzione del raggio.
 * @param   toprd rappresenta il prodotto tra la direzione del raggio e se stessa.
 * @param   h_2 rappresenta il prodotto tra l'altezza del cilindro e la metà.
 * @param   t rappresenta il risultato del prodotto tra h_2 e il prodotto tra top_roco e top_roco meno il prodotto tra toprd e il quadrato della metà dell'altezza del cilindro.
 * */
double	ft_calc_root(double top_relor, double toprd, double h_2, double t)
{
	double	root;

	if (t < 0)
		root = -top_relor / toprd;
	else
		root = (h_2 - top_relor) / toprd;
	return (root);
}
