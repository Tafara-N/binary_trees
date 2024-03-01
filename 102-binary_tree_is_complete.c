#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Function creates a new levelorder_queue_t node
 * @node: Binary tree node for the new node to contain
 *
 * Return: On errors - NULL,
 *			Otherwise, a pointer to the new node
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
 * push - Function pushes a node to the back of a levelorder_queue_t queue
 * @node: The binary tree node to print and push
 * @head: Double pointer to the head of the queue
 * @tail: Double pointer to the tail of the queue
 *
 * Description: Upon malloc failure, exits with a status code of 1
 */

void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *curr;

	curr = create_node(node);
	if (curr == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = curr;
	*tail = curr;
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
 * binary_tree_is_complete - Function checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to traverse
 *
 * Return: If the tree is NULL or not complete - (0),
 *			Otherwise - (1)
 *
 * Description: On malloc failure, exits with a status code of 1
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flg = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flg == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flg = 1;
		if (head->node->right != NULL)
		{
			if (flg == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flg = 1;
		pop(&head);
	}
	return (1);
}
