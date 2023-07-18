/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:01:37 by fwatanab          #+#    #+#             */
/*   Updated: 2023/02/07 17:01:38 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		check_sign(const char *mstr, va_list args);
int		sign_type(int c, va_list args);
int		put_char(char c);
int		put_string(char	*str);
int		put_pointer(unsigned long long pointer);
char	*count_pointer(uintptr_t pointer);
int		pointer_size(uintptr_t pointer);
int		put_number(int nbr);
int		put_unsigned_number(unsigned int nbr);
char	*unsigned_itoa(unsigned int n);
int		put_hexa_lower(unsigned int nbr);
int		put_hexa_upper(unsigned int nbr);

size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
char	*ft_strdup(const char *s1);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
int		ft_toupper(int c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
