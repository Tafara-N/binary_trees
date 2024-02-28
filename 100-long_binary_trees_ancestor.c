#include "binary_trees.h"

size_t depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - Function finds the lowest common ancestor of two nodes
 * @first: First node's pointer
 * @second: Second node's pointer
 *
 * Return: If no common ancestors return NULL,
 *			Otherwise the common ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t first_depth, scnd_depth;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);

	for (first_depth = depth(first); first_depth > 1; first_depth--)
		first = first->parent;
	for (scnd_depth = depth(second); scnd_depth > 1; scnd_depth--)
		second = second->parent;

	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);
	else
		return (NULL);
}

/**
 * depth - Function measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 *
 * Return: If tree is NULL - (0),
 *			Otherwise the depth
 */

size_t depth(const binary_tree_t *tree)
{
	return ((tree->parent != NULL) ? 1 + depth(tree->parent) : 0);
}
