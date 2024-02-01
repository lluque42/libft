/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:11:14 by lluque            #+#    #+#             */
/*   Updated: 2024/02/01 18:36:41 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stdarg.h>
# include "libft.h"

# define SUPP_FLAGS "- +0#"
# define SUPP_CONV_SPEC "cspdiuxX%"

//	LEFT_JUSTIFY = 0x1,			// '-' flag		b00000001	0x01
//	ZERO_PADDING = 0x2,			// '0' flag		b00000010   0x02
//	ALTERNATE_FORM = 0x4,		// '#' flag		b00000100   0x04
//	BLANK_IF_POS_NUM = 0x8,		// ' ' flag		b00001000   0x08
//	SIGN_BEF_NUM =	0x10		// '+' flag		b00010000   0x10
typedef enum e_flags
{
	NO_FLAGS = 0,
	LEFT_JUSTIFY = 1,
	ZERO_PADDING = 2,
	ALTERNATE_FORM = 4,
	BLANK_IF_POS_NUM = 8,
	SIGN_BEF_NUM =	16
}				t_flags;

typedef enum e_data_type
{
	NO_TYPE,
	INT,
	CHAR,
	STRING,
	POINTER,
	UINT,
	DECIMAL,
	HEX_LOWER,
	HEX_UPPER,
	ESCAPED_PERCENT,
	LITERAL_CHAR
}				t_data_type;

typedef union u_data
{
	int				int_type;
	unsigned int	uint_type;
	long			long_type;
	char			*string_type;
	char			char_type;
	void			*ptr_type;
}				t_data;

typedef struct s_format
{
	t_flags			flags;
	unsigned int	width;
	int				precision;
	unsigned int	prec_value;
	t_data_type		data_type;
	t_data			data;
	unsigned int	printed_chars;
	char			literal_char;
	int				(*printer_function)(struct s_format *, va_list *);
	int				(*parser_function)(struct s_format *, char **);
}				t_format;

void	init_format(t_format *format);
int		parser_select(t_format *format, char **str);
int		parse_format(t_format *format, char **str);
int		parse_conversion(t_format *format, char **str);
int		parse_literal_char(t_format *format, char **str);
int		printer_select(t_format *format);
int		print_char(t_format *format, va_list *arg_list);
int		print_string(t_format *format, va_list *arg_list);
int		print_pointer(t_format *format, va_list *arg_list);
int		print_integer(t_format *format, va_list *arg_list);
int		print_hex_integer(t_format *format, va_list *arg_list);
int		has_flag(t_flags flags_word, t_flags flag);
void	set_flag(t_flags *flags_word, t_flags flag);
int		free_and_return_value(void *pointer, int ret_value);
int		add_precision_for_numbers(t_format *format, char **nbr);
int		add_width_alignment(t_format *format, char **nbr);

#endif
