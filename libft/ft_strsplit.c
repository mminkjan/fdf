/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:10:07 by mminkjan       #+#    #+#                */
/*   Updated: 2019/02/04 20:35:22 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	size_t			i;
	int				count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] == '\0')
			return (count);
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	strt;
	unsigned char	n;
	char			**ar;
	int				count;

	i = 0;
	count = ft_words(s, c);
	ar = (char**)ft_strnew((sizeof(char*) * (count + 1)));
	if (ar == NULL)
		return (NULL);
	n = 0;
	while (s[i] != '\0' && count > 0)
	{
		while (s[i] == c)
			i++;
		strt = i;
		count--;
		while (s[i] != c && s[i] != '\0')
			i++;
		ar[n] = ft_strsub(s, strt, (i - strt));
		n++;
	}
	return (ar);
}
