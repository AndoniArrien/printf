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
	int		right_align; // '0' [requires a value] Alignes the values to the right preceded by X-value_size zeros
	int		precision;   // '.' [requires a value] It is followed by the minimum number of characters that should be printed ((unsigned) int => zeros at the start, float => zeros after the point, char* => number of characters)
	char	alternate;   // '#' **JUST ADDS A 0x or 0X in front of x or X types**
	int		sign;        // '+' [requires a value] Forces a sign inclusión (+ or -) [overrides ' '] X-value_size-1 spaces at the start
	int		space;       // ' ' [requires a value] A space should be printed before a positive number, X-value_size-1 spaces at the start
} t_flags;

typedef struct s_node {
	char *	full_content;
	char	conversion;
	int		is_valid;
	int		is_formatted;
	t_flags	flags;
} t_node;

/*-FT_PRINTF_BONUS-*/
void	ft_process(va_list ptr, t_list* head, int *len);
int		ft_printf(char const *s, ...);

/*-FT_PRINTF_UTILS_BONUS-*/
void	ft_putstr_len(char* str, int* len);
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

/*-FT_PROCESS_CONVERSIONS-*/
void	ft_process_c(t_node* node, char c, int* len);
void	ft_process_s(t_node* node, char* s, int* len);
void	ft_process_p(t_node* node, unsigned long long int p, int* len);
void	ft_process_di(t_node* node, int di, int* len);
void	ft_process_u(t_node* node, unsigned int u, int* len);
void	ft_process_xX(t_node* node, int xX, int* len);

#endif
