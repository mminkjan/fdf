/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 13:18:33 by mminkjan       #+#    #+#                */
/*   Updated: 2019/01/31 17:24:25 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	size_t			end;

	i = 0;
	end = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end >= i)
		end--;
	str = ft_strsub(s, i, (end - i) + 1);
	if (!(str))
		return (NULL);
	return (str);
}
