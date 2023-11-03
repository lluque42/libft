/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:14:35 by lluque            #+#    #+#             */
/*   Updated: 2023/11/03 17:40:57 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define WORDS_PER_LINE 8
#define BYTES_PER_WORD 2
#define BYTES_PER_LINE 16

static void	print_words(unsigned int byt, unsigned int size, void *ad)
{
	int	word_in_line;
	int	byte_in_word;

	word_in_line = 0;
	while (word_in_line < WORDS_PER_LINE)
	{
		byte_in_word = 0;
		while (byte_in_word < BYTES_PER_WORD)
		{
			if (byt >= size)
				ft_putstr_fd("  ", 1);
			else
			{
				if (*((unsigned char *)ad + byt) < 16)
					ft_putchar_fd('0', 1);
				ft_putstr_fd(ft_itoa_b(*((unsigned char *)ad + byt), 16, 1), 1);
			}
			byte_in_word++;
			byt++;
		}
		ft_putstr_fd(" ", 1);
		word_in_line++;
	}
}

static void	print_as_chars(unsigned int byte, unsigned int size, void *ad)
{
	int	byte_in_line;

	byte_in_line = 0;
	while (byte_in_line < BYTES_PER_LINE)
	{
		if (byte >= size)
		{
			ft_putchar_fd(' ', 1);
			byte_in_line++;
			continue ;
		}
		if (ft_isprint(*((unsigned char *)ad + byte)))
			ft_putchar_fd(*((unsigned char *)ad + byte), 1);
		else
			ft_putchar_fd('.', 1);
		byte_in_line++;
		byte++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	byte_in_block;
	int				line_in_block;
	int				lines_per_block;

	if (addr == NULL || size == 0)
		return (NULL);
	lines_per_block = size / BYTES_PER_LINE;
	if (size % BYTES_PER_LINE)
		lines_per_block++;
	byte_in_block = 0;
	line_in_block = 0;
	while (line_in_block < lines_per_block)
	{
		ft_putstr_fd(ft_ltoa_b((unsigned long)addr + byte_in_block, 16, 1), 1);
		ft_putstr_fd(": ", 1);
		print_words(byte_in_block, size, addr);
		print_as_chars(byte_in_block, size, addr);
		ft_putchar_fd('\n', 1);
		byte_in_block += BYTES_PER_LINE;
		line_in_block++;
	}
	return (addr);
}
