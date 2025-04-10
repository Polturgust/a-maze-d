/*
** EPITECH PROJECT, 2025
** B-CPE-200-NCE-2-1-amazed-florent.serra
** File description:
** parthing.c
*/

#include "../../include/amazed.h"

static graph_t *del(graph_t *graph, char **file, int error)
{
    destroy_array((void **)file);
    if (!graph)
        return NULL;
    if (error || graph->first == -1 || graph->last == -1) {
        if (graph->name)
            free(graph->name);
        if (graph->mat)
            destroy_array((void **)(graph->mat));
        free(graph);
        graph = NULL;
    }
    return graph;
}

void writer(char *str)
{
    write(1, str, my_strlen(str));
    write(1, "\n", 1);
}

static int testroom_way(char **file, int *nb, graph_t *graph)
{
    char **line = NULL;

    line = str_to_word_array(file[*nb], " ");
    if (my_arraylen(line) == 3) {
        destroy_array((void **)line);
        return add_node(file[*nb], graph);
    }
    destroy_array((void **)line);
    line = str_to_word_array(file[*nb], "-");
    if (my_arraylen(line) == 2) {
        destroy_array((void **)line);
        return add_way(file[*nb], graph);
    }
    destroy_array((void **)line);
    return 1;
}

static int test_line(char **file, int *nb, graph_t *graph)
{
    if (!file)
        return 1;
    if (*nb == 0)
        return init(file, graph);
    if (file[*nb][0] == '#') {
        if (file[*nb][0] == '#' && file[*nb][1] == '#' && file[*nb][2] != '#')
            return add_strart_end(file, nb, graph);
        return 0;
    }
    if (is_in('#', file[*nb]))
        return 1;
    return testroom_way(file, nb, graph);
}

static void manage_fd(char **file, int *nb)
{
    static int zone;
    char **line;

    if (*nb == 0)
        zone = 1;
    line = str_to_word_array(file[*nb], "-");
    if (*nb != 0 && zone == 1 && my_arraylen(line) == 2) {
        write(1, "#tunnels\n", 9);
        zone = 2;
    }
    destroy_array((void **)line);
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
    int i = 0;

    if (!graph)
        return NULL;
    for (; file[i]; i++) {
        manage_fd(file, &i);
        error = test_line(file, &i, graph);
        if (error)
            break;
    }
    if (error)
        write_error(i);
    graph = del(graph, file, error);
    return graph;
}
