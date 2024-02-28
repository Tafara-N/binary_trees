#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - Function creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs - NULL,
 *         Otherwise, a pointer to the new node
 */

levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *curr;

	curr = malloc(sizeof(levelorder_queue_t));
	if (curr == NULL)
		return (NULL);

	curr->node = node;
	curr->next = NULL;

	return (curr);
}

/**
 * free_queue - Function frees a levelorder_queue_t queue
 * @head: Pointer to the head of the queue
 */

void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * pint_push - Runs a function on a given binary tree node and pushes
 *				its children into a levelorder_queue_t queue.
 * @node: Binary tree node to print and push
 * @head: Double pointer to the head of the queue
 * @tail: Double pointer to the tail of the queue
 * @func: Pointer to the function to call on @node
 *
 * Description: On malloc failure, exits with a status code of 1
 */

void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *curr;

	func(node->n);
	if (node->left != NULL)
	{
		curr = create_node(node->left);
		if (curr == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = curr;
		*tail = curr;
	}
	if (node->right != NULL)
	{
		curr = create_node(node->right);
		if (curr == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = curr;
		*tail = curr;
	}
}

/**
 * pop - Function pops the head of a levelorder_queue_t queue
 * @head: Double pointer to the head of the queue
 */

void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_levelorder - Function traverses a binary tree using the
 *							level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}
