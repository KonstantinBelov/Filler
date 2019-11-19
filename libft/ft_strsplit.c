/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:14:03 by kbelov            #+#    #+#             */
/*   Updated: 2019/02/28 18:28:04 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char		**strs;
	size_t		i;
	size_t		j;
	size_t		start;
	size_t		len;

	i = 0;
	j = 0;
	if (!s || !(strs = (char **)malloc(sizeof(*strs) * ft_strsplit_len(s, c))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i])
		{
			start = i;
			len = ft_word_len(s, start, c);
			strs[j] = ft_strsub(s, start, len);
			j++;
			i += len - 1;
		}
		i++;
	}
	strs[j] = NULL;
	return (strs);
}
