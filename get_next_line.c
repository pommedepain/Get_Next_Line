/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:34:40 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/22 19:55:54 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*readline(const int fd, char *buff, int *ret)
{
	char	tmp[BUFF_SIZE + 1];
	char	*tmp2;

	*ret = read(fd, tmp, BUFF_SIZE);
	tmp[*ret] = '\0';
	tmp2 = buff;
	if (!(buff = ft_strjoin(buff, tmp)))
		return (NULL);
	ft_strdel(&tmp2);
	return (buff);
}

int		ft_cpy_end(char **line, char **buff)
{
	if (!(*line = ft_strdup(*buff)))
		return (-1);
	ft_bzero(*buff, ft_strlen(*buff));
	return (1);
}

int     get_next_line(const int fd, char **line)
{
	static char	*buff = "";
	int			ret;
	char		*str;

	ret = 1;
	if (!line || fd < 0 || (buff[0] == '\0' && (!(buff = ft_strnew(0)))))
		return (-1);
	while (ret > 0)
	{
		if ((str = ft_strchr(buff, '\n')) != NULL)
		{
			*str = '\0';
			if (!(*line = ft_strdup(buff)))
				return (-1);
			ft_memmove(buff, str + 1, ft_strlen(str + 1) + 1);
			return (1);
		}
		if (!(buff = readline(fd, buff, &ret)))
			return (-1);
	}
	ft_strdel(&str);
	if (ret == 0 && ft_strlen(buff))
		ret = ft_cpy_end(&(*line), &buff);
	return (ret);
}

int     main(void)
{
    int fd;
    char *line;
    int i = 0;
    int j;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        ft_putstr("open() failed\n");
        return (1);
    }
    while (i < 11)
    {
        j = get_next_line(fd, &line);
        ft_putnbr(j);
        ft_putchar('\n');
        ft_putstr(line);
        ft_putchar('\n');
        i++;
    }
    if (close(fd) == -1)
    {
        ft_putstr("close() failed\n");
        return (1);
    }
    return (0);
}
