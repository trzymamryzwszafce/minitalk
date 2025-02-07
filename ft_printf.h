/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szmadeja <szmadeja@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 01:14:59 by szmadeja          #+#    #+#             */
/*   Updated: 2025/01/11 02:16:26 by szmadeja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_format(char letter, va_list ap);
int	ft_ptr(void *ptr);
int	ft_str(char *str);
int	ft_char(char c);
int	ft_uhex(unsigned int n);
int	ft_lhex(unsigned int n);
int	ft_udec(unsigned int n);
int	ft_dec(int n);
int	ft_hexptr(unsigned long n);

#endif
