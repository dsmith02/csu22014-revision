//   mystring.c
//   David Gregg
//   December 2022

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "mystring.h"

// (a) create a new empty list string
struct mystring *new_empty_mystring()
{
	struct mystring *new_string = malloc(sizeof(struct mystring));
	struct ls_node *node = malloc(sizeof(struct ls_node));
	new_string->head = node;
	return new_string;
}

// (b) create a new list string with the same contents as a normal
// NULL-terminated C string
struct mystring *new_array2mystring(char *text)
{
	// String must not be null.
	if (text == NULL)
	{
		fprintf(stderr, "ERROR");
		return NULL;
	}

	// Create a mystring with a head containing the first character.
	struct mystring *s = new_empty_mystring();
	struct ls_node *head = create_node(*text);
	s->head = head;

	char current = *text;
	struct ls_node *node = head;

	// Iterates over the string until it hits a null terminator. Each character it
	for (int i = 1; (current = *(text + i)) != '\0'; i++)
	{
		struct ls_node *next_node = create_node(current);
		node->next = next_node;
		node = next_node;
	}
	return s;
}

// (c) create a new mystring that is a copy of str
struct mystring *mystring_copy(struct mystring *str)
{
	if (str == NULL)
	{
		fprintf(stderr, "ERROR: STRING MUST NOT BE NULL");
		return NULL;
	}

	struct mystring *new_string = new_empty_mystring();
	new_string->head = create_node(str->head->c);

	struct ls_node *old_node = str->head;
	struct ls_node *new_node = new_string->head;

	while ((old_node = old_node->next) != NULL)
	{
		new_node->next = create_node(old_node->c);
		new_node = new_node->next;
	}

	return new_string;
}

// (d) create a new mystring that is the concatenation of two
// mystrings
struct mystring *mystring_concatenate(struct mystring *str1,
									  struct mystring *str2)
{
	struct mystring *concat_string = mystring_copy(str1);

	// MISSING FIRST CHARACTER OF SECOND STR
	struct ls_node *new_node = get_tail(concat_string);
	new_node->next = create_node(get_tail(str2)->c);
	struct ls_node *old_node = str2->head;

	while ((old_node = old_node->next) != NULL)
	{
		new_node->next = create_node(old_node->c);
		new_node = new_node->next;
	}

	return concat_string;
}

// (e) create a new mystring containing the same characters as str,
// but in reverse order
struct mystring *mystring_reverse(struct mystring *str)
{
}

// is there a match starting at this point in the text
int match_substring(struct ls_node *text, struct ls_node *str)
{
}

// (f) return 1 if str is a substring of text; 0 otherwise
int mystring_substring(struct mystring *text, struct mystring *str)
{
}

// (g) free the memory used by the mystring
void mystring_free(struct mystring *str)
{
	if (str == NULL)
	{
		fprintf(stderr, "ERROR: STR MUST NOT BE NULL");
	}

	struct ls_node *current = str->head;
	do
	{
		struct ls_node *next = current->next;
		free(current);
		current = next;
	} while (current != NULL);

	return;
}

struct ls_node *create_node(char c)
{
	struct ls_node *node = malloc(sizeof(struct ls_node));
	node->c = c;
	node->next = NULL;
	return node;
}

struct ls_node *get_tail(struct mystring *str)
{
	if (str == NULL)
	{
		return NULL;
	}

	struct ls_node *current = str->head;
	struct ls_node *previous;
	while (current != NULL)
	{
		previous = current;
		current = current->next;
	}

	return previous;
}
