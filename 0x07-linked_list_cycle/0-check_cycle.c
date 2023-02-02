#include "lists.h"

int check_cycle(listint_t *list)
{
    listint_t *node1 = list;
    listint_t *node2 = list;

    while (node1 && node2 && node2->next)
    {
        node1 = node1->next;
        node2 = node2->next->next;
        if (node1 == node2)
            return (1);
    }
    return (0);
}
