/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:52:15 by cvallejo          #+#    #+#             */
/*   Updated: 2022/05/11 17:47:09 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_checkmalloc(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
	{
		substr = malloc(sizeof(char));
		*substr = '\0';
		return (substr);
	}
	substr = (char *)malloc(ft_checkmalloc(ft_strlen(s), len) + 1);
	if (substr == 0)
		return (0);
	i = start;
	j = 0;
	while (s[i] && i < start + len)
	{
		substr[j] = s[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}
