/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:35:12 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/21 19:57:19 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

 //utiliser strchr pour lui permettre d'afficher jusqu'au \n mais attention car le read s'il depasse le \n va quand meme le lire donc trouver moyen de stocker ce qui a ete lu (voir variables statiques).

int     read_from_fd_into_stock(const int fd, char **stock)
{
    static char     buff[BUFF_SIZE + 1];
    int             read_bytes;
    char            *nstr;

    //*buff = '\n';
    read_bytes = read(fd, buff, BUFF_SIZE);
    if (read_bytes > 0)
    {
        buff[read_bytes] = '\0';
        nstr = ft_strjoin(*stock, buff);
        if (!nstr)
            return (-1);
        free(*stock);
        *stock = nstr;
    }
    return (read_bytes);
}

int     get_next_line(const int fd, char **line)
{
   /* char    *temp;
    int     ret;*/
    static char *stock;
    char        *endl_index;
    int         ret;

    stock = NULL;
    if (!stock && (stock = (char *)ft_memalloc(sizeof(char))) == NULL)
        return (-1);
    // endl_index garde en memoire l'emplacement de \n
    endl_index = ft_strchr(stock, '\n');
    while (endl_index == NULL)
    {
        ret = read_from_fd_into_stock(fd, &stock);
        if (ret == 0)
        {
            if ((endl_index = ft_strchr(stock, '\0')) == stock)
                return (0);
        }
        else if (ret < 0)
            return (-1);
        else
            endl_index = ft_strchr(stock, '\n');
    }
    *line = ft_strsub(stock, 0, endl_index - stock);
    if (!*line)
        return (-1);
    endl_index = ft_strdup(endl_index + 1);
    free(stock);
    stock = endl_index;
    return (1);
    /*if (!(temp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
        return (0);
    ret = read(fd, temp, BUFF_SIZE);
    temp[ret] = '\0';
    ft_putnbr(ret);
    ft_putstr(temp);
    return (0);*/
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
    while (i < 3)
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
