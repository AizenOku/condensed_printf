/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 22:12:52 by ihuang            #+#    #+#             */
/*   Updated: 2018/09/26 00:48:51 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

char	*convert(unsigned long num, int base)
{
	char	*rep;
	char	*buff;
	char	*ptr;

	if (num == 0)
		return ("0");
	rep = "0123456789abcdef";
	buff = (char*)malloc(sizeof(char) * 50);
	buff[49] = '\0';
	ptr = &buff[49];
	*ptr = '\0';
	while (num != 0)
	{
		ptr--;
		*ptr = *(rep + (num % base));
		num /= base;
	}
	free(buff);
	return (ptr);
}

int		print_memory(va_list list)
{
	void			*ptr;

	write(1, "0x", 2);
	ptr = va_arg(list, void*);
	if (ptr == NULL)
		return (2 + ft_putstr("0"));
	return (2 + ft_putstr(convert((unsigned long)ptr, 16)));
}

int		handle_int(const char c, va_list list)
{
	int				i;
	unsigned int	u;

	if (c == 'd' || c == 'i')
	{
		i = va_arg(list, int);
		if (i < 0)
		{
			write(1, "-", 1);
			return (1 + ft_putstr(convert((unsigned int)i, 10)));
		}
		else
			return (ft_putstr(convert((unsigned int)i, 10)));
	}
	else if (c == 'u' || c == 'x' || c == 'o')
	{
		u = va_arg(list, unsigned int);
		if (c == 'u')
			return (ft_putstr(convert(u, 10)));
		else if (c == 'o')
			return (ft_putstr(convert(u, 8)));
		else if (c == 'x')
			return (ft_putstr(convert(u, 16)));
	}
	return (print_memory(list));
}

int		handle(const char c, va_list list)
{
	char			*s;
	char			ch;

	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else if (c == 'c')
	{
		ch = va_arg(list, int);
		write(1, &ch, 1);
		return (1);
	}
	else if (c == 's')
	{
		if ((s = va_arg(list, char*)) != NULL)
			return (ft_putstr(s));
		else
			return (ft_putstr("(null)"));
	}
	else
		return (handle_int(c, list));
}
