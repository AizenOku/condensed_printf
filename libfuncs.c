/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 22:40:34 by ihuang            #+#    #+#             */
/*   Updated: 2018/09/30 23:08:17 by ihuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_printf.h"

char	*convert(unsigned long n, int b)
{
	char	*rep;
	char	*buff;
	char	*ptr;

	if (n == 0)
		return ("0");
	rep = "0123456789abcdef";
	buff = (char*)malloc(sizeof(char) * 50);
	ptr = &buff[49];
	*ptr = '\0';
	while (n != 0)
	{
		*--ptr = rep[n % b];
		n /= b;
	}
	free(buff);
	return (ptr);
}

int		ft_write(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (*s == c)
		return ((char*)s);
	return (NULL);
}
