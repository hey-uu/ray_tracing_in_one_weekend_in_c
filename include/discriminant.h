#ifndef DISCRIMINANT_H
# define DISCRIMINANT_H

typedef struct s_discriminant
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root1;
	double	root2;
}	t_discriminant;

typedef t_discriminant	t_discr;

t_discr	get_discriminant(double a, double b, double c);

#endif