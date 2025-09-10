/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:23:18 by grhaddad          #+#    #+#             */
/*   Updated: 2025/06/04 16:23:18 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_worddup(const char *s, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_freeall(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

static int	ft_split_fill(char **result, const char *s, char c, int words)
{
	int	i;

	i = 0;
	while (*s && i < words)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			result[i] = ft_worddup(s, c);
			if (!result[i])
				return (i);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		fail;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	fail = ft_split_fill(result, s, c, words);
	if (fail != -1)
	{
		ft_freeall(result, fail - 1);
		return (NULL);
	}
	result[words] = NULL;
	return (result);
}
