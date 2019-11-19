/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbelov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:01:02 by kbelov            #+#    #+#             */
/*   Updated: 2019/02/23 17:32:10 by kbelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strlcat() appends string src to the end of dst.  It will append at most
** dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
** dstsize is 0 or the original dst string was longer than dstsize (in prac-
** tice this should not happen as it means that either dstsize is incorrect or
** that dst is not a proper string).
** If the src and dst strings overlap, the behavior is undefined.
*/

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t		len_dst;
	size_t		len_src;
	size_t		len_total;
	long int	src_index;
	long int	max_src_index;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst > dstsize)
		len_total = len_src + dstsize;
	else
		len_total = len_src + len_dst;
	src_index = 0;
	max_src_index = dstsize - len_dst - 1;
	while ((src[src_index] != '\0') && (src_index < max_src_index))
	{
		dst[len_dst + src_index] = src[src_index];
		src_index++;
	}
	dst[len_dst + src_index] = '\0';
	return (len_total);
}

/*
** int		main(void)
**{
**	char		*restrict dst = "there is no stars in the sky";
**	const char	*restrict src = "the cake is a lie !\0I'm hidden lol\r\n";
**	size_t		dstsize = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
**
**	printf("%lu\n", ft_strlcat(dst, src, dstsize));
**	return (0);
**}
*/
