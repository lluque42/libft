/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:55:05 by lluque            #+#    #+#             */
/*   Updated: 2024/07/20 23:25:43 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <fcntl.h>
//#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include "libft.h"

void	*integer_double(void *content)
{
	int	*ret_val;

	ret_val = malloc(sizeof (int));
	if (ret_val == NULL)
		return (NULL);
	*ret_val = 2 * *(int *)content;
	return (ret_val);
}

int		integer_cmp(void *a, void *b)
{
	ft_printf("Comparando %d con %d\n", *(int *)a, *(int *)b);
	if (*(int *)a == *(int *)b)
		return (1);
	return (0);
}

void	integer_del(void *content)
{
	free(content);
}

void	integer_print(void *content)
{
	ft_printf("\tEl elemento es: \t%d\n", *((int *)content));
}

void	free_and_exit(t_dlclst *lst)
{
	ft_dlclst_clear(&lst, integer_del);
}

int main_for_aisi(int argc, char **argv)
{
	//char	*str = "123";
	//char	*str = "2147483647";
	//char	*str = "-2147483648";
	//char	*str = "2147483648";
	//char	*str = "-2147483649";
	//char	*str = "+123";
	//char	*str = "+2147483647";
	//char	*str = "123";
	char	*str = argv[1];
	
	if (argc != 2)
		return (1);
	ft_printf("El rango valido de enteros es [%i, %i]\n", INT_MIN, INT_MAX);
	if (ft_aisi(str))
		ft_printf("El string '%s' SI es un entero valido\n", str);
	else
		ft_printf("El string '%s' NO es un entero valido\n", str);
	return (0);
}

//int		main_for_dlclst(int argc, char **argv)
int		main(int argc, char **argv)
{
	ft_printf("INT_MAX = %d, INT_MIN = %d\n", INT_MAX, INT_MIN);
	ft_printf("El string '%s' interpretado con base '%d' resulta en el entero '%d'\n", argv[1], ft_atoi(argv[2]), ft_atoi_b(argv[1], ft_atoi(argv[2])));

	return (0);
	t_dlclst	*lst_a;
	t_dlclst	*lst_b;
	t_dlclst	*lst_c;
	int			*content;
	int			i;

	ft_printf("Lista a >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	lst_a = NULL;
	if (argc == 1)
		exit(1);
	i = 1;
	while (i < argc)
	{
		content = malloc(sizeof (int));
		if (content == NULL)
			free_and_exit(lst_a);
		ft_printf("Insertando al inicio '%s'\n", argv[i]);
		*content = ft_atoi(argv[i]);
		ft_dlclst_insfront(&lst_a, ft_dlclst_new(content));
		ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_a));
		ft_dlclst_iter(lst_a, integer_print);
		ft_printf("El ultimo elemento es: '%d'\n", *((int *)ft_dlclst_last(lst_a)->content));
		ft_printf("\n");
		i++;
	}
	ft_printf("Borrando el elemento 3\n");
	ft_dlclst_rempos(&lst_a, integer_del, 3);
	ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_a));
	if (lst_a != NULL)
		ft_dlclst_iter(lst_a, integer_print);
	else
		ft_printf("La lista esta vacia\n");
	ft_printf("Borrando el elemento 0\n");
	ft_dlclst_rempos(&lst_a, integer_del, 0);
	ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_a));
	if (lst_a != NULL)
		ft_dlclst_iter(lst_a, integer_print);
	else
		ft_printf("La lista esta vacia\n");
	
	ft_printf("Borrando la lista\n");
	ft_dlclst_clear(&lst_a, integer_del);
	ft_printf("Cantidad de elementos en la lista borrada '%d'\n", ft_dlclst_size(lst_a));

	
	ft_printf("Lista b >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	//lst_a = NULL;
	i = 1;
	lst_b = NULL;
	while (i < argc)
	{
		content = malloc(sizeof (int));
		if (content == NULL)
			free_and_exit(lst_b);
		ft_printf("Insertando al final '%s'\n", argv[i]);
		*content = ft_atoi(argv[i]);
		ft_dlclst_insback(&lst_b, ft_dlclst_new(content));
		ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_b));
		if (lst_b != NULL)
			ft_dlclst_iter(lst_b, integer_print);
		else
			ft_printf("La lista esta vacia\n");
		ft_printf("El ultimo elemento es: '%d'\n", *((int *)ft_dlclst_last(lst_b)->content));
		ft_printf("\n");
		i++;
	}
	ft_printf("Borrando el primer elemento\n");
	ft_dlclst_remfront(&lst_b, integer_del);
	ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_b));
	if (lst_b != NULL)
		ft_dlclst_iter(lst_b, integer_print);
	else
		ft_printf("La lista esta vacia\n");

	ft_printf("Borrando el ultimo elemento\n");
	ft_dlclst_remback(&lst_b, integer_del);
	ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_b));
	if (lst_b != NULL)
		ft_dlclst_iter(lst_b, integer_print);
	else
		ft_printf("La lista esta vacia\n");
	
	ft_printf("Borrando la lista\n");
	ft_dlclst_clear(&lst_b, integer_del);
	ft_printf("Cantidad de elementos en la lista borrada '%d'\n", ft_dlclst_size(lst_b));

	ft_printf("Lista c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	i = 1;
	lst_c = NULL;
	while (i < argc)
	{
		content = malloc(sizeof (int));
		if (content == NULL)
			free_and_exit(lst_c);
		ft_printf("Insertando en la posicion 3 '%s'\n", argv[i]);
		*content = ft_atoi(argv[i]);
		ft_dlclst_inspos(&lst_c, ft_dlclst_new(content), 3);
		ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_c));
		if (lst_c != NULL)
			ft_dlclst_iter(lst_c, integer_print);
		else
			ft_printf("La lista esta vacia\n");
		ft_printf("El ultimo elemento es: '%d'\n", *((int *)ft_dlclst_last(lst_c)->content));
		ft_printf("\n");
		i++;
	}

	ft_printf("Lista d >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	t_dlclst	*lst_d = NULL;

	ft_printf("Duplicando los contenidos\n");
	lst_d = ft_dlclst_map(lst_c, integer_double, integer_del);
	ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_d));
	if (lst_d != NULL)
		ft_dlclst_iter(lst_d, integer_print);
	else
		ft_printf("La lista esta vacia\n");
	ft_printf("El ultimo elemento es: '%d'\n", *((int *)ft_dlclst_last(lst_d)->content));
	ft_printf("\n");
	printf("SSIZE_MAX = %lu\n", SSIZE_MAX);
	printf("SIZE_MAX  = %lu\n", SIZE_MAX);

	int a = 4;
	ft_printf("El numero %d esta en la lista? %d\n", a, ft_dlclst_search(lst_d, integer_cmp, &a));
	a = 8;
	ft_printf("El numero %d esta en la lista? %d\n", a, ft_dlclst_search(lst_d, integer_cmp, &a));
	a = 1871;
	ft_printf("El numero %d esta en la lista? %d\n", a, ft_dlclst_search(lst_d, integer_cmp, &a));

	ft_printf("Rotando la lista en sentido next\n");
	ft_dlclst_rotatenext(&lst_d, 1);
	ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_d));
	if (lst_d != NULL)
		ft_dlclst_iter(lst_d, integer_print);
	else
		ft_printf("La lista esta vacia\n");
	ft_printf("El ultimo elemento es: '%d'\n", *((int *)ft_dlclst_last(lst_d)->content));
	ft_printf("\n");

	ft_printf("Rotando la lista en sentido next\n");
	ft_dlclst_rotatenext(&lst_d, 1);
	ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_d));
	if (lst_d != NULL)
		ft_dlclst_iter(lst_d, integer_print);
	else
		ft_printf("La lista esta vacia\n");
	ft_printf("El ultimo elemento es: '%d'\n", *((int *)ft_dlclst_last(lst_d)->content));
	ft_printf("\n");

	ft_printf("Rotando la lista en sentido prev\n");
	ft_dlclst_rotateprev(&lst_d, 1);
	ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_d));
	if (lst_d != NULL)
		ft_dlclst_iter(lst_d, integer_print);
	else
		ft_printf("La lista esta vacia\n");
	ft_printf("El ultimo elemento es: '%d'\n", *((int *)ft_dlclst_last(lst_d)->content));
	ft_printf("\n");

	ft_printf("Rotando la lista en sentido prev\n");
	ft_dlclst_rotateprev(&lst_d, 1);
	ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_d));
	if (lst_d != NULL)
		ft_dlclst_iter(lst_d, integer_print);
	else
		ft_printf("La lista esta vacia\n");
	ft_printf("El ultimo elemento es: '%d'\n", *((int *)ft_dlclst_last(lst_d)->content));
	ft_printf("\n");

	ft_printf("Rotando la lista en sentido prev\n");
	ft_dlclst_rotateprev(&lst_d, 1);
	ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_d));
	if (lst_d != NULL)
		ft_dlclst_iter(lst_d, integer_print);
	else
		ft_printf("La lista esta vacia\n");
	ft_printf("El ultimo elemento es: '%d'\n", *((int *)ft_dlclst_last(lst_d)->content));
	ft_printf("\n");

	ft_printf("Haciendo un swapfront\n");
	ft_dlclst_swapfront(&lst_d);
	ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_d));
	if (lst_d != NULL)
		ft_dlclst_iter(lst_d, integer_print);
	else
		ft_printf("La lista esta vacia\n");
	ft_printf("El ultimo elemento es: '%d'\n", *((int *)ft_dlclst_last(lst_d)->content));
	ft_printf("\n");

	ft_printf("Haciendo un swapfront\n");
	ft_dlclst_swapfront(&lst_d);
	ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_d));
	if (lst_d != NULL)
		ft_dlclst_iter(lst_d, integer_print);
	else
		ft_printf("La lista esta vacia\n");
	ft_printf("El ultimo elemento es: '%d'\n", *((int *)ft_dlclst_last(lst_d)->content));
	ft_printf("\n");

	ft_printf("Haciendo un swapback\n");
	ft_dlclst_swapback(&lst_d);
	ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_d));
	if (lst_d != NULL)
		ft_dlclst_iter(lst_d, integer_print);
	else
		ft_printf("La lista esta vacia\n");
	ft_printf("El ultimo elemento es: '%d'\n", *((int *)ft_dlclst_last(lst_d)->content));
	ft_printf("\n");

	ft_printf("Haciendo un swapback\n");
	ft_dlclst_swapback(&lst_d);
	ft_printf("Cantidad de elementos en la lista: '%d'\n", ft_dlclst_size(lst_d));
	if (lst_d != NULL)
		ft_dlclst_iter(lst_d, integer_print);
	else
		ft_printf("La lista esta vacia\n");
	ft_printf("El ultimo elemento es: '%d'\n", *((int *)ft_dlclst_last(lst_d)->content));
	ft_printf("\n");

	ft_printf("Se borraran todas las listas\n");
	ft_printf("La a...\n");
	ft_dlclst_clear(&lst_a, integer_del);
	ft_printf("La b...\n");
	ft_dlclst_clear(&lst_b, integer_del);
	ft_printf("La c...\n");
	ft_dlclst_clear(&lst_c, integer_del);
	ft_printf("La d...\n");
	ft_dlclst_clear(&lst_d, integer_del);
	return (0);
	
	/*
	int		fd;
	char	*line;
	int		line_nbr;	
	
	//ft_printf("El BUFFER_SIZE es %i\n", BUFFER_SIZE);

	if (argc == 1)
		fd = 1;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			ft_printf("[main] Error al abrir el archivo '%s'\n", argv[1]);
			return (1);
		}
	}
	line_nbr = 1;
	while (1)
	{
		line = ft_gnl(fd);
		if (line == NULL)
			break ;
		ft_printf("[main][linea %d] '%s'\n", line_nbr, line);
		line_nbr++;
	}
	ft_printf("[main][linea %d] '%s'", line_nbr, line);
	close(fd);
	return (0);
	*/
}
