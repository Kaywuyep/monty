#include "monty.h"
/**
 * _isdigit - Checks for a digit 0 through 9
 * @str: variable
 * Return: 0 or 1
 */
int _isdigit(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);  /*Not a valid integer if the string is empty or NULL*/

	while (*str)
	{
		if (!isdigit(*str) && (*str != '-' && *str != '+'))
			return (0);  /* Not a digit or a valid sign character*/
		str++;
	}

	return (1);  /*All characters are valid digits or signs*/
}

/**
 * initialize_instructions - funcion to initialize the instruction_t array
 * Return: opcode
 */
instruction_t *initialize_instructions(void)
{
	instruction_t *op = malloc(sizeof(instruction_t) * 16);
	instruction_t push = {"push", _push};
	instruction_t pall = {"pall", _pall};
	instruction_t pint = {"pint", _pint};
	instruction_t pop = {"pop", _pop};
	instruction_t swap = {"swap", _swap};
	instruction_t add = {"add", _add};
	instruction_t nop = {"nop", _nop};
	instruction_t sub = {"sub", _sub};
	instruction_t div = {"div", _div};
	instruction_t mul = {"mul", _mul};
	instruction_t mod = {"mod", _mod};
	instruction_t pchar = {"pchar", _pchar};
	instruction_t pstr = {"pstr", _pstr};
	instruction_t rotl = {"rotl", _rotl};
	instruction_t rotr = {"rotr", _rotr};
	instruction_t terminator = {NULL, NULL};

	if (!op)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	op[0] = push;
	op[1] = pall;
	op[2] = pint;
	op[3] = pop;
	op[4] = swap;
	op[5] = add;
	op[6] = nop;
	op[7] = sub;
	op[8] = div;
	op[9] = mul;
	op[10] = mod;
	op[11] = pchar;
	op[12] = pstr;
	op[13] = rotl;
	op[14] = rotr;
	op[15] = terminator;
	return (op);
}
/**
 * free_instructions - function to free initialized the instruction_t array
 * @op: opcode
 */
void free_instructions(instruction_t *op)
{
	free(op);
}
