/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 17:51:57 by mminkjan       #+#    #+#                */
/*   Updated: 2019/04/05 18:06:45 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	str = (char*)malloc(sizeof(char *) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (*s1 && i < len)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
