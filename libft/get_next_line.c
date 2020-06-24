/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 10:06:07 by mminkjan       #+#    #+#                */
/*   Updated: 2019/12/23 19:00:50 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_line(t_list *box, char **line)
{
	int		i;
	char	*temp;
	int		len;

	i = 0;
	temp = (char *)box->content;
	len = ft_strlen(temp);
	if (len == 0)
	{
		*line = NULL;
		return (0);
	}
	while (temp[i] != '\n' && i < len)
		i++;
	*line = ft_strsub(temp, 0, i);
	if (line == NULL)
		return (-1);
	if (i < len)
		box->content = ft_strsub(temp, i + 1, len);
	else if (i == len)
		box->content = ft_strnew(0);
	if (box->content == NULL)
		return (-1);
	free(temp);
	return (1);
}

char	*packing(t_list *box, char *buff)
{
	char	*temp;

	temp = box->content;
	box->content = ft_strjoin(temp, buff);
	if (box->content == NULL)
		return (NULL);
	free(temp);
	return (box->content);
}

t_list	*basement(int fd)
{
	static t_list	*lst = NULL;
	t_list			*current;
	size_t			i;
	char			*str;

	i = 0;
	current = lst;
	str = NULL;
	while (current != NULL && current->content_size != (size_t)fd)
		current = current->next;
	if (current == NULL)
	{
		str = ft_strnew(0);
		if (str == NULL)
			return (NULL);
		current = ft_lstnew(str, 1);
		if (current == NULL)
			return (NULL);
		current->content_size = fd;
		ft_lstadd(&lst, current);
		free(str);
	}
	return (current);
}

int		get_next_line(const int fd, char **line)
{
	int		ret;
	t_list	*box;
	char	buff[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	ret = read(fd, buff, 0);
	if (ret < 0)
		return (-1);
	box = basement(fd);
	if (box == NULL)
		return (-1);
	ret = 1;
	while (ret > 0 && ft_strchr(box->content, '\n') == NULL)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (ret > 0)
			box->content = packing(box, buff);
		if (box->content == NULL)
			return (-1);
	}
	return (find_line(box, line));
}
