#include "binary_trees.h"
#include <unistd.h>
#include <stdio.h>
/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_node = malloc(sizeof(binary_tree_t));

	if (parent == NULL || right_node == NULL)
	{
		return (NULL);
	}

	if (parent->right != NULL)
	{
		parent->right->parent = right_node;
		right_node->right = parent->right;
	}

	right_node->n = value;
	parent->right = right_node;

	return (parent->right);
}
