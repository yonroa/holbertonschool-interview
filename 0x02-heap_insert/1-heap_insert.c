#include "binary_trees.h"

int check_leaves(const binary_tree_t *tree, int depth, int level);
int binary_tree_is_perfect(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
void swap(heap_t **arg_node, heap_t **arg_child);

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @value: value to store in the node to be inserted
 * @root: double pointer to the root node of the Heap
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new;

    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    if (binary_tree_is_perfect(*root) || !binary_tree_is_perfect((*root)->left))
    {
        if ((*root)->left)
        {
            new = heap_insert(&((*root)->left), value);
            swap(root, &((*root)->left));
            return (new);
        }
        else
        {
            new = (*root)->left = binary_tree_node(*root, value);
            swap(root, &((*root)->left));
            return (new);
        }
    }

    if ((*root)->right)
    {
        new = heap_insert(&((*root)->right), value);
        swap(root, (&(*root)->right));
        return (new);
    }
    else
    {
        new = (*root)->right = binary_tree_node(*root, value);
        swap(root, &((*root)->right));
        return (new);
    }

    return (NULL);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth = 0;

	if (tree == NULL)
		return (0);
	depth = binary_tree_height(tree);
	return (check_leaves(tree, depth, 0));
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height
 * Return: the height of a binary tree or 0 if tree is null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

/**
 * check_leaves - Verify if all leaves are in the same level
 * @tree: pointer to the root node of the tree to check
 * @depth: level where the leaves should be are
 * @level: level of the node
 * Return: 1 if the leaves are in the same level,
 * 0 if not
 */
int check_leaves(const binary_tree_t *tree, int depth, int level)
{
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (check_leaves(tree->left, depth, level + 1) &&
			check_leaves(tree->right, depth, level + 1));
}

/**
 * swap - swaps nodes when child is greater than parent
 * @arg_node: parent node
 * @arg_child: child node
 */
void swap(heap_t **arg_node, heap_t **arg_child)
{
    heap_t *node, *child, *node_child, *node_left, *node_right, *parent;
    int left_right;

    node = *arg_node, child = *arg_child;
    if (child->n > node->n)
    {
        if (child->left)
            child->left->parent = node;
        if (child->right)
            child->right->parent = node;
        if (node->left == child)
            node_child = node->right, left_right = 0;
        else
            node_child = node->left, left_right = 1;
        node_left = child->left, node_right = child->right;
        if (left_right == 0)
        {
            child->right = node_child;
            if (node_child)
                node_child->parent = child;
            child->left = node;
        }
        else
        {
            child->left = node_child;
            if (node_child)
                node_child->parent = child;
            child->right = node;
        }
        if (node->parent)
        {
            if (node->parent->left == node)
                node->parent->left = child;
            else
                node->parent->right = child;
        }
        parent = node->parent, child->parent = parent;
        node->parent = child, node->left = node_left;
        node->right = node_right, *arg_node = child;
    }
}
