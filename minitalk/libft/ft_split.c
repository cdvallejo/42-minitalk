/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:27:54 by cvallejo          #+#    #+#             */
/*   Updated: 2022/05/04 17:07:46 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getcad(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	trigger;

	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
			trigger = 1;
		if ((s[i] == c || s[i + 1] == '\0') && trigger == 1)
		{
			count++;
			trigger = 0;
		}
		i++;
	}
	return (count);
}

static int	ft_getsubstr(char const *s, char c, size_t start)
{
	size_t	count;

	count = 0;
	while (s[start] != '\0' && s[start] != c)
	{
		count++;
		start++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**strcad;
	size_t	i;
	int		count_split;

	if (!s)
		return (NULL);
	i = 0;
	count_split = 0;
	strcad = (char **)malloc(sizeof(char *) * (ft_getcad(s, c) + 1));
	if (strcad == 0)
		return (0);
	while (i < ft_strlen(s) || s[i] != '\0')
	{
		if (s[i] != c)
		{
			strcad[count_split] = ft_substr(s, i, ft_getsubstr(s, c, i));
			count_split++;
			i = i + ft_getsubstr(s, c, i);
		}
		else
			i++;
	}
	strcad[count_split] = NULL;
	return (strcad);
}
