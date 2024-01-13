#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree, or 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);
	int front = 0, rear = 0;
	size_t height = 0;

	if (!tree || !queue)
	{
		return (0);
	}

	queue[rear++] = (binary_tree_t *)tree;

	while (front != rear)
	{
		int level_count = rear - front;

		while (level_count > 0)
		{
			binary_tree_t *node = queue[front++];

			if (node->left != NULL)
			{
				queue[rear++] = node->left;
			}

			if (node->right != NULL)
			{
				queue[rear++] = node->right;
			}

			level_count--;
		}

		height++;
	}

	free(queue);

	return (height - 1);
}
