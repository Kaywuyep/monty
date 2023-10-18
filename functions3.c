#include "monty.h"
/**
 * _div - function div two number
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line_number);
		clean_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		clean_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	_pop(stack, line_number);
}
/**
 * _mul - function that multiplies two number
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line_number);
		clean_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _mod - function that gives modulo of two number
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", line_number);
		clean_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		clean_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _pchar - function that prints the char at the top of the stack
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)/*ensure there is atleast one element in the stack*/
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number);
		clean_stack(*stack);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	if (value < 0 || value > 127)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", line_number);
		clean_stack(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}

/**
 * _pstr - function that prints the string starting at the top of the stack
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *value = *stack;

	(void)line_number;

	while (value && value->n != 0 && (value->n >= 0 && value->n <= 127))
	{
		putchar(value->n);
		value = value->next;
	}

	putchar('\n');
}
