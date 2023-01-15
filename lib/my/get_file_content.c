/*
** EPITECH PROJECT, 2019
** main
** File description:
** navy
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

char *get_file_content(char *path)
{
    int fd = open(path, O_RDONLY);
    char *buffer;
    ssize_t size;
    __off_t len;
    struct stat filestat;

    stat(path, &filestat);
    len = filestat.st_size;
    buffer = malloc(sizeof(char) * (len + 1));
    size = read(fd, buffer, (size_t)len);
    buffer[size] = '\0';
    close(fd);
    return buffer;
}
