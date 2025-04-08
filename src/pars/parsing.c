/*
** EPITECH PROJECT, 2025
** B-CPE-200-NCE-2-1-amazed-florent.serra
** File description:
** parthing.c
*/

#include "../../include/amazed.h"

static graph_t *del(graph_t *graph, char **file, int error, int fd)
{
    destroy_array((void **)file);
    if (fd != -1)
        close(fd);
    if (!graph)
        return NULL;
    if (error || graph->first == -1 || graph->last == -1) {
        fd = open("bonus/rooms.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
        if (fd != -1) {
            write(fd, "error", 5);
            close(fd);
        }
        if (graph->name)
            free(graph->name);
        if (graph->mat)
            destroy_array((void **)(graph->mat));
        free(graph);
        graph = NULL;
    }
    return graph;
}

void writer(int fd, char *str)
{
    write(1, str, my_strlen(str));
    write(1, "\n", 1);
    if (fd == -1)
        return;
    write(fd, str, my_strlen(str));
    write(fd, "\n", 1);
}

static int testroom_way(char **file, int *nb, graph_t *graph, int fd)
{
    char **line = NULL;

    line = str_to_word_array(file[*nb], " ");
    if (my_arraylen(line) == 3) {
        destroy_array((void **)line);
        return add_node(file[*nb], graph, fd);
    }
    destroy_array((void **)line);
    line = str_to_word_array(file[*nb], "-");
    if (my_arraylen(line) == 2) {
        destroy_array((void **)line);
        return add_way(file[*nb], graph, fd);
    }
    destroy_array((void **)line);
    return 1;
}

static int test_line(char **file, int *nb, graph_t *graph, int fd)
{
    if (!file)
        return 1;
    if (*nb == 0)
        return init(file, graph);
    if (file[*nb][0] == '#') {
        if (file[*nb][0] == '#' && file[*nb][1] == '#' && file[*nb][2] != '#')
            return add_strart_end(file, nb, graph, fd);
        return 0;
    }
    if (is_in('#', file[*nb]))
        return 1;
    return testroom_way(file, nb, graph, fd);
}

static int manage_fd(char **file, int *nb, int fd_room, int fd_tu)
{
    static int fd;
    static int zone;
    char **line;

    if (*nb == 0) {
        fd = fd_room;
        zone = 1;
    }
    line = str_to_word_array(file[*nb], "-");
    if (*nb != 0 && zone == 1 && my_arraylen(line) == 2) {
        write(1, "#tunnels\n", 9);
        fd = fd_tu;
        zone = 2;
    }
    destroy_array((void **)line);
    return fd;
}

static void write_error(int line)
{
    write(2, "an error occured on line : ", 28);
    my_puterror_str(my_itoa(line));
    write(2, "\n", 1);
}

graph_t *pars(void)
{
    char **file = get_stdin_file();
    int error = 0;
    graph_t *graph = malloc(sizeof(graph_t));
    int fd_ro = open("bonus/rooms.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
    int fd_tu = open("bonus/tunneles.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
    int i = 0;

    if (!graph)
        return NULL;
    for (; file[i]; i++) {
        error = test_line(file, &i, graph, manage_fd(file, &i, fd_ro, fd_tu));
        if (error)
            break;
    }
    if (fd_tu != -1)
        close(fd_tu);
    if (error)
        write_error(i);
    graph = del(graph, file, error, fd_ro);
    return graph;
}
