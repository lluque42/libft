/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:21:02 by lluque            #+#    #+#             */
/*   Updated: 2024/01/30 16:52:54 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_utils.h"

static int	print_pointer_not_null(t_format *format, char **new_nbr, char *nbr)
{
	size_t	new_nbr_len;

	nbr = ft_ultoa_b((unsigned long)format->data.ptr_type, 16, 0);
	if (nbr == NULL)
		return (0);
	new_nbr_len = ft_strlen(nbr) + 2;
	*new_nbr = malloc((new_nbr_len + 1) * sizeof (char));
	if (*new_nbr == NULL)
	{
		free(nbr);
		return (0);
	}
	(*new_nbr)[0] = '0';
	(*new_nbr)[1] = 'x';
	ft_strlcpy(*new_nbr + 2, nbr, new_nbr_len -1);
	free(nbr);
	return (1);
}

int	print_pointer(t_format *format, va_list *arg_list)
{
	char	*nbr;
	char	*new_nbr;
	size_t	printed_chars;
	int		exit_status;

	nbr = NULL;
	format->data.ptr_type = va_arg(*arg_list, void *);
	exit_status = print_pointer_not_null(format, &new_nbr, nbr);
	if (!exit_status)
		return (0);
	if (!add_width_alignment(format, &new_nbr))
	{
		free(new_nbr);
		return (0);
	}
	printed_chars = ft_putstr_fd_safe(new_nbr, 1);
	if (ft_strlen(new_nbr) != printed_chars)
	{
		free(new_nbr);
		return (0);
	}
	free(new_nbr);
	format->printed_chars += printed_chars;
	return (1);
}
/*
When compiling for Linux (Ubuntu distro) a NULL pointer would print "(nil)".
In MacOS it's supposed to print "0x0".
static int	print_pointer_null(char **new_nbr)

static int	print_pointer_null(char **new_nbr)
{
	*new_nbr = ft_strdup("(nil)");
	if (*new_nbr == NULL)
		return (0);
	return (1);
}

int	print_pointer(t_format *format, va_list *arg_list)
{
	char	*nbr;
	char	*new_nbr;
	size_t	printed_chars;
	int		exit_status;

	nbr = NULL;
	format->data.ptr_type = va_arg(*arg_list, void *);
	if (format->data.ptr_type != NULL)
		exit_status = print_pointer_not_null(format, &new_nbr, nbr);
	else
		exit_status = print_pointer_null(&new_nbr);
	if (!exit_status)
		return (0);
	if (!add_width_alignment(format, &new_nbr))
	{
		free(new_nbr);
		return (0);
	}
	printed_chars = ft_putstr_fd_safe(new_nbr, 1);
	if (ft_strlen(new_nbr) != printed_chars)
	{
		free(new_nbr);
		return (0);
	}
	free(new_nbr);
	format->printed_chars += printed_chars;
	return (1);
}

*/
