/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:57:58 by aarrien-          #+#    #+#             */
/*   Updated: 2022/10/11 09:01:32 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

# define CONVERSIONS     "cspdiuxX"
# define FLAGS           "-0.#+ "
# define ALTERNATE_TYPES "oxXaAeRfFgG"

typedef struct s_flags {
	int		left_align;  // '-' [requires a value] Alignes the value to de left followed by X-value_size spaces [overrides '0']
	int		right_align; // '0' [requires a value] Alignes the values to the right preceded by zeros
	int		precision;   // '.' [requires a value] It is followed by the minimum number of characters that should be printed (int => zeros at the start, float => zeros after the point, char* => number of characters)
	char	alternate;   // '#' [requires a char] Can be followed by: 'o'(adds a 0 at the start), 'x'(adds a 0x), 'X'(0X), 'aAeEfFgG' (places decimal point even if there's not)
	int		sign;        // '+' Forces a sign inclusión (+ or -) [overrides ' ']
	int		space;       // ' ' A space should be printed before a positive number
} t_flags;

typedef struct s_node {
	char *	full_content;
	int		is_valid;
	int		is_formatted;
	t_flags	flags;
} t_node;

/*-FT_PRINTF_BONUS-*/
int		ft_printf(char const *s, ...);

/*-FT_PRINTF_UTILS_BONUS-*/
void	ft_delete_node(void *content);
void	ft_print_node(void *content);

/*-FT_FLAGS_BONUS-*/
char*	ft_extract_flag_value(char flag, char* str);
void	ft_insert_flag_value(t_node* node, char flag, char* value);
void	ft_set_flags(t_node* node, char* node_flags);
void	ft_fill_node_data(void *content);

/*-FT_LIST_BONUS-*/
void	ft_init_node(t_node* node);
t_list*	ft_create_nodes(char const *s);

#endif
