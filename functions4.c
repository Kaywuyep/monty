#include "monty.h"
/**
 * _rotl - Rotates the stack to the top.
 * @stack: Stack or queue
 * @line_number: Line number
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	if (!stack || !*stack || !(*stack)->next)
		return;

	temp = *stack;
	last = *stack;

	while (last->next)
		last = last->next;

	*stack = temp->next;
	temp->next = NULL;
	last->next = temp;

	(void)line_number;
}

/**
 * _rotr - Rotates the stack to the bottom.
 * @stack: Stack or queue
 * @line_number: Line number
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}
