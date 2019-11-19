/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:59:53 by kbelov            #+#    #+#             */
/*   Updated: 2019/11/03 16:59:58 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ftoa(long double n)
{
	size_t		len_f;
	char		*ip;
	char		*fp;
	char		*f_pad;
	intmax_t	i;

	i = (intmax_t)(n * 10000000);
	(i % 10 >= 5) ? i += 10 : 1;
	(i % 10 <= -5) ? i -= 10 : 1;
	i /= 10;
	n = i % 1000000;
	i /= 1000000;
	ip = ft_strjoin(ft_itoa(i), ".");
	(n < 0 && (int)i == 0) ? ip = ft_strjoin("-", ip) : "a";
	(n < 0) ? n *= -1 : 1;
	fp = ft_itoa(n);
	len_f = ft_strlen(fp);
	(len_f < 6) ? f_pad = ft_strnew(6 - len_f) : "a";
	(len_f < 6) ? ft_memset(f_pad, '0', 6 - len_f) : "a";
	(len_f < 6) ? fp = ft_strjoin(f_pad, fp) : "a";
	(len_f < 6) ? ft_strdel(&f_pad) : "a";
	f_pad = ft_strjoin(ip, fp);
	free(ip);
	free(fp);
	return (f_pad);
}
