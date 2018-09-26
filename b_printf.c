/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:35:53 by ihuang            #+#    #+#             */
/*   Updated: 2018/09/26 00:48:50 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

int		parse_format(const char *fmt, va_list list)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (fmt[i])
	{
		while (fmt[i] && fmt[i] != '%')
		{
			write(1, &fmt[i++], 1);
			count++;
		}
		if (fmt[i] == '%')
		{
			if (ft_strchr("scdipoux", fmt[++i]))
				count += handle(fmt[i++], list);
			else
				return (-1);
		}
	}
	return (count);
}

int		b_printf(const char *restrict format, ...)
{
	va_list	list;
	int		res;

	va_start(list, format);
	if ((res = parse_format(format, list)) == -1)
	{
		ft_putstr("Invalid operator");
		va_end(list);
		return (-1);
	}
	va_end(list);
	return (res);
}
