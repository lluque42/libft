/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:12:10 by lluque            #+#    #+#             */
/*   Updated: 2024/07/08 00:40:29 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_gnl.h"

t_archive	*ft_gnl_datacat(t_archive *ad, t_read *rd)
{
	char	*new_ad_d;
	long	new_ad_s;

	if (ad == NULL)
		return (NULL);
	if (rd->s == 0)
		return (ad);
	new_ad_s = ad->s + rd->s;
	new_ad_d = malloc(new_ad_s);
	if (new_ad_d == NULL)
		return (NULL);
	if (ad->s != 0)
		ft_memcpy(new_ad_d, ad->d, ad->s);
	if (rd->s != 0)
		ft_memcpy(new_ad_d + ad->s, rd->d, rd->s);
	free(ad->d);
	ad->d = new_ad_d;
	ad->s = new_ad_s;
	return (ad);
}

int	ft_gnl_init_struct(t_archive **data, long size)
{
	if (*data == NULL)
	{
		*data = malloc(sizeof (t_archive));
		if (*data == NULL)
			return (0);
		(*data)->s = 0;
		if (size == 0)
			(*data)->d = NULL;
		else
		{
			(*data)->d = malloc(size * sizeof (char));
			if ((*data)->d == NULL)
			{
				ft_gnl_free_data(data);
				return (0);
			}
		}
	}
	return (1);
}

void	ft_gnl_free_data(t_archive **data)
{
	if (data == NULL || *data == NULL)
		return ;
	if ((*data)->d != NULL)
	{
		free((*data)->d);
		(*data)->d = NULL;
	}
	free(*data);
	*data = NULL;
}
