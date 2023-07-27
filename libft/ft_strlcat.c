/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:14:46 by dnishsha          #+#    #+#             */
/*   Updated: 2023/05/10 13:56:26 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* strlcat() take the
full size of the buffer (not just the length) and guarantee to
NUL-terminate the result
(as long as size is larger than 0 or, in the case of strlcat(),
as long as there is at least one byte free in dst).
Note that a byte for the NUL should be included in size.

The strlcpy() and strlcat() functions return the total length of the
string they tried to create.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	if (!src && !dst)
		return (0);
	src_len = ft_strlen(src);
	if (!size || size == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i ++;
	}
	dst[i + dst_len] = '\0';
	if (dst_len > size)
		return (size + src_len);
	return (dst_len + src_len);
}
