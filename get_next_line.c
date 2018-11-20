/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:35:12 by psentilh          #+#    #+#             */
/*   Updated: 2018/11/20 17:34:02 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char    *ft_read(void)
{
    int total_size;
    int size_count;
    char *temp;
    char *result;
    char buff[32];
    //int fd;

    result = NULL;
    total_size = 0;
    while ((size_count = read(0, buff, 31)) > 0)
    {
        total_size = total_size + size_count;
        printf("1 : %d\n", size_count);
        temp = result;
        buff[size_count] = '\0';
        if (!(result = (char *)malloc(sizeof(char) * (total_size + 1))))
            return (0);
        *result = '\0';
        if (temp)
            ft_strcpy(result, temp);
        ft_strcat(result, buff);
        if (temp)
            free(temp);
    }
    printf("2 : %s\n", result);
    return (result);
}

int     get_next_line(const int fd, char **line)
{
    /*char    *temp;
    int     ret;

    if(!(temp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
        return (0);
    ret = read(fd, temp, BUFF_SIZE);
    temp[ret] = '\0';
    ft_putnbr(ret);
    ft_putstr(temp);*/
    while (fd)
        ft_read();
    return (0);
}

int     main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        ft_putstr("open() failed\n");
        return (1);
    }
    get_next_line(fd, &line);
    if (close(fd) == -1)
    {
        ft_putstr("close() failed\n");
        return (1);
    }
    return (0);
}
