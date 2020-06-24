/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:10:07 by mminkjan       #+#    #+#                */
/*   Updated: 2020/01/07 16:24:25 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_arrayalloc(const char *s, char c, int *index, char **strs)
{
	char	*array;
	size_t	i;
	int		j;

	i = 0;
	j = *index;
	while (j != c && s[j])
		j++;
	array = (char *)malloc(sizeof(array) * (j - *index));
	if (!array)
	{
		ft_strarradel(array);
		ft_free_strarr(strs);
		return (NULL);
	}
	while (s[*index] != c && s[*index])
	{
		array[i] = s[*index];
		i++;
		*index = *index + 1;
	}
	array[i] = '\0';
	return (array);
}

static size_t	ft_wrdscount(char const *s, char c)
{
	size_t i;
	size_t word;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i] != '\0')
			word++;
		i++;
	}
	if (s[0] != '\0')
		word++;
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	j;
	int		i;
	size_t	numofparts;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	numofparts = ft_wrdscount(s, c);
	array = (char**)malloc(sizeof(char *) * numofparts + 1);
	if (array == NULL)
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < numofparts && s[i])
	{
		array[j] = ft_arrayalloc(s, c, &i, array);
		j++;
		while (s[i] == c && s[i])
			i++;
	}
	array[j] = 0;
	return (array);
}
