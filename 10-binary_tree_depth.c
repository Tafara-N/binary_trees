#include "binary_trees.h"

/**
 * binary_tree_depth - Function measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * Return: If tree is NULL - (0),
 *			Otherwise the depth
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
