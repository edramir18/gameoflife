/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:26:41 by edramire          #+#    #+#             */
/*   Updated: 2020/02/03 21:26:15 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	ft_stc_strlen(char const *s)
{
	size_t n;

	n = 0;
	if (s == NULL)
		return (0);
	while (*s++ != '\0')
		n++;
	return (n);
}

size_t			strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_stc_strlen(src);
	if (size == 0 || dst == NULL)
		return (len);
	while (*src != '\0' && (size > 1 ? size-- : 0))
		*dst++ = *src++;
	if (size > 0)
		*dst = '\0';
	return (len);
}
