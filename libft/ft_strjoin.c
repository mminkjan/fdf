/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 11:19:41 by mminkjan       #+#    #+#                */
/*   Updated: 2019/04/05 18:17:54 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		si;
	size_t	len;

	i = 0;
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = ft_memalloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	si = 0;
	while (s2[si] != '\0')
	{
		str[i] = s2[si];
		i++;
		si++;
	}
	return (str);
}
