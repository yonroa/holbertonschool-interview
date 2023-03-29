#include "binary_trees.h"

/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new_node = NULL;

	if (!array || !size)
		return (NULL);

	new_node = binaryToAVL(array, 0, size - 1, NULL);
	return (new_node);
}

/**
 * binary_tree_node - function that builds a binary tree
 * @parent: Pointer to the firts node
 * @index: position of the data of node
 * @array: pointer to the first element of the array to be converted
 * Return: a pointer to the first node of the binary tree
 */
avl_t *binary_tree_node(avl_t *parent, int index, int *array)
{
	avl_t *new_node = NULL;

	new_node = malloc(sizeof(avl_t));
	if (!new_node)
		return (NULL);

	new_node->left = new_node->right = NULL;
	new_node->n = array[index];
	new_node->parent = parent;

	return (new_node);
}

/**
 * binaryToAVL - makes a binary tree AVL
 * @array: pointer to the first element of the array to be converted
 * @start: first node to sort
 * @end: last node to sort
 * @root: pointer to the first node
 * Return: pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *binaryToAVL(int *array, size_t start, size_t end, avl_t *root)
{
	size_t mid;
	avl_t *new_node = NULL;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	new_node = binary_tree_node(root, mid, array);
	if (!new_node)
		return (NULL);

	if (mid != start)
		new_node->left = binaryToAVL(array, start, mid - 1,
									 new_node);

	if (mid != end)
		new_node->right = binaryToAVL(array, mid + 1, end,
									  new_node);

	return (new_node);
}
