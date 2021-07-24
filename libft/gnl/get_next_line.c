/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:16:19 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/24 19:38:28 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_strjoin_free_s1(char const *s1, char const *s2)
{
	char			*d;
	unsigned int	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1;
	d = malloc(sizeof(char) * (size));
	if (!d)
		return (0);
	ft_memcpy(d, (const void *) s1, ft_strlen((char *) s1));
	ft_memcpy(&d[ft_strlen((char *) s1)], s2, ft_strlen((char *) s2));
	ft_memcpy(&d[ft_strlen((char *) s1)], s2, ft_strlen((char *) s2));
	d[size - 1] = '\0';
	free((char *) s1);
	return (d);
}

static char	*ft_next_line(char *rprogress, char **line, int *result_int)
{
	int		i;
	char	*temp;

	i = 0;
	while (rprogress[i] && (rprogress[i] != '\n'))
		i++;
	*line = ft_substr(rprogress, 0, i);
	if (rprogress[i] == '\n')
	{
		temp = ft_strdup(rprogress + i + 1);
		free(rprogress);
		rprogress = temp;
		*result_int = 1;
		if (rprogress[0] == '\0')
		{
			free(rprogress);
			rprogress = NULL;
		}
		return (rprogress);
	}
	*result_int = 0;
	free(rprogress);
	rprogress = NULL;
	return (rprogress);
}

static int	ft_return_zero_emptystring(char **line)
{
	*line = ft_strdup("");
	return (0);
}

static void	ft_set_rprogress(char **rprogress, char *buffer)
{
	if (!*rprogress)
		*rprogress = ft_strdup(buffer);
	else
		*rprogress = ft_strjoin_free_s1(*rprogress, buffer);
}

int	get_next_line(int fd, char **line)
{
	static char	*rprogress[MAXFD];
	int			result_int;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if ((!line) || (!(buffer)))
		return (-1);
	result_int = read(fd, buffer, BUFFER_SIZE);
	while (result_int > 0)
	{
		buffer[result_int] = '\0';
		ft_set_rprogress(&rprogress[fd], buffer);
		if (ft_strchr(rprogress[fd], '\n'))
			break ;
		result_int = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if ((result_int == 0 && !rprogress[fd]))
		return (ft_return_zero_emptystring(line));
	if (result_int < 0)
		return (-1);
	rprogress[fd] = ft_next_line(rprogress[fd], line, &result_int);
	return (result_int);
}
