/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:10:07 by mminkjan       #+#    #+#                */
/*   Updated: 2019/12/11 14:03:48 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_arrayalloc(const char *s, char c, int *index)
{
	char	*array;
	size_t	i;
	int		j;

	i = 0;
	j = *index;
	while (j != c && s[j])
		j++;
	array = (char *)ft_memalloc(sizeof(array) * (j - *index));
	if (!array)
	{
		ft_strarradel(array);
		return (NULL);
	}
	while (s[*index] != c && s[*index])
	{
		array[i] = s[*index];
		i++;
		*index = *index + 1;
	}
	array[i] = '\0';
	while (s[*index] == c && s[*index])
		*index = *index + 1;
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
	array = (char**)ft_memalloc(sizeof(char *) * numofparts + 1);
	if (!array)
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < numofparts && s[i])
	{
		array[j] = ft_arrayalloc(s, c, &i);
		j++;
	}
	array[j] = 0;
	return (array);
}
