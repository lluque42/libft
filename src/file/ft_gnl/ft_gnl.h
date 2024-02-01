/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:18:23 by lluque            #+#    #+#             */
/*   Updated: 2024/01/28 14:44:21 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

# ifndef MAX_SYS_FD_NUMBER
#  define MAX_SYS_FD_NUMBER 4096
# endif

# include <stddef.h>

typedef struct s_archive
{
	char	*d;
	long	s;
}				t_archive;

typedef struct s_read
{
	char	d[BUFFER_SIZE];
	long	s;
}				t_read;

int			init_struct(t_archive **data, long size);

void		gnl_free_data(t_archive **data);

t_archive	*gnl_datacat(t_archive *ad, t_read *rd);

#endif 
