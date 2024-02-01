/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:11:48 by lluque            #+#    #+#             */
/*   Updated: 2024/01/28 15:10:16 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_gnl.h"

static char	*buff_to_str(t_archive *data, int len)
{
	char	*ret_val;

	if (data == NULL || data->d == NULL)
		return (NULL);
	if (data->s == 0 || len == 0)
	{
		ret_val = malloc(sizeof (char));
		if (ret_val == NULL)
			return (NULL);
		ret_val[0] = '\0';
		return (ret_val);
	}
	ret_val = malloc((len + 1) * sizeof (char));
	if (ret_val == NULL)
		return (NULL);
	ft_memcpy(ret_val, data->d, len);
	ret_val[len] = '\0';
	return (ret_val);
}

static t_archive	*resize_buffer(t_archive **ad, size_t start_pos)
{
	char	*new_d;
	size_t	new_s;

	if (ad == NULL || *ad == NULL)
		return (NULL);
	if (start_pos == 0)
		return (*ad);
	new_s = (*ad)->s - start_pos;
	new_d = NULL;
	if (new_s == 0)
	{
		free((*ad)->d);
		(*ad)->d = NULL;
	}
	else
	{
		new_d = malloc(new_s * sizeof (char));
		if (new_d == NULL)
			return (NULL);
	}
	ft_memcpy(new_d, (*ad)->d + start_pos, new_s);
	free((*ad)->d);
	(*ad)->d = new_d;
	(*ad)->s = new_s;
	return (*ad);
}

static char	*extract_line(t_archive **arch_data, int bytes_read)
{
	int		line_len;
	char	*line;

	if (arch_data == NULL || *arch_data == NULL)
		return (NULL);
	if ((*arch_data)->d == NULL || (*arch_data)->s == 0)
		return (NULL);
	line_len = 0;
	while (line_len < (*arch_data)->s)
	{
		if (*((*arch_data)->d + line_len) == '\n')
			break ;
		line_len++;
	}
	if (line_len < (*arch_data)->s)
		line_len++;
	else if (line_len == (*arch_data)->s && bytes_read == BUFFER_SIZE)
		line_len = 0;
	line = buff_to_str(*arch_data, line_len);
	if (resize_buffer(arch_data, line_len) == NULL)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

static t_archive	*get_arch_data(int fd, t_archive **arch_array)
{
	t_archive	*current_arch_data;

	if (fd < 0 || fd > 1400)
		return (NULL);
	current_arch_data = arch_array[fd];
	if (!init_struct(&current_arch_data, 0))
		return (NULL);
	return (current_arch_data);
}

char	*ft_gnl(int fd)
{
	static t_archive	*arch_array[MAX_SYS_FD_NUMBER] = {0};
	t_archive			*arch_data;
	t_read				read_data;
	char				*line;

	arch_data = get_arch_data(fd, arch_array);
	if (arch_data == NULL)
		return (NULL);
	line = NULL;
	while (1)
	{
		read_data.s = read(fd, read_data.d, BUFFER_SIZE);
		if (read_data.s == -1 || gnl_datacat(arch_data, &read_data) == NULL)
			break ;
		line = extract_line(&arch_data, read_data.s);
		if (line == NULL || line[0] != '\0')
			break ;
		free(line);
		line = NULL;
	}
	if (line == NULL)
		gnl_free_data(&arch_data);
	arch_array[fd] = arch_data;
	return (line);
}
