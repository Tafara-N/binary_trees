#include "binary_trees.h"

/**
 * binary_trees_ancestor - Function finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: If no common ancestors - NULL,
 *			Otherwise the common ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mother, *pop;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mother = first->parent, pop = second->parent;
	if (first == pop || !mother || (!mother->parent && pop))
		return (binary_trees_ancestor(first, pop));
	else if (mother == second || !pop || (!pop->parent && mother))
		return (binary_trees_ancestor(mother, second));
	return (binary_trees_ancestor(mother, pop));
}
