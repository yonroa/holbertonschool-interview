#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: First node
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/
int is_palindrome(listint_t **head)
{
    listint_t *first = *head, *last = *head, *temp = *head;
    int num_nodes = 0, half_node = 0;

    if (*head == NULL)
        return (1);
    while (temp)
    {
        num_nodes += 1;
        temp = temp->next;
    }
    while (half_node != (num_nodes / 2))
    {
        half_node += 1;
        last = last->next;
    }
    reverse_linked_list(&last);
    while (first && last)
    {
        if (first->n != last->n)
            return (0);
        first = first->next;
        last = last->next;
    }
    return (1);
}

/**
 * reverse_linked_list - reverse a single linked list
 * @head: First node
*/
void reverse_linked_list(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;
	listint_t *next = NULL;

	while (current)
	{
		next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
