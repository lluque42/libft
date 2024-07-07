/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:18:23 by lluque            #+#    #+#             */
/*   Updated: 2024/07/08 00:39:39 by lluque           ###   ########.fr       */
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

// Private function. Prefixed to avoid linking issues when using this library
// in projects with same public function names
int			ft_gnl_init_struct(t_archive **data, long size);

// Private function. Prefixed to avoid linking issues when using this library
// in projects with same public function names
void		ft_gnl_free_data(t_archive **data);

// Private function. Prefixed to avoid linking issues when using this library
// in projects with same public function names
t_archive	*ft_gnl_datacat(t_archive *ad, t_read *rd);

#endif 
