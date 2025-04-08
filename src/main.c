/*
** EPITECH PROJECT, 2025
** B-CPE-200-NCE-2-1-amazed-florent.serra
** File description:
** main.c
*/

#include "../include/amazed.h"

static int is_good_arg(int argc, char **argv)
{
    if (argc == 1)
        return 1;
    if (argc > 2)
        return 84;
    if (my_strcmp(argv[1], "-h") == 0)
        my_printf("USAGE:\n\t./amazed < [your path file]\n");
    return 84;
}

int main(int argc, char **argv)
{
    graph_t *info_graph = NULL;
    int error = is_good_arg(argc, argv);

    if (error != 1)
        return error;
    info_graph = pars();
    if (!info_graph)
        return 84;
    del_graph(info_graph);
    return 0;
}
