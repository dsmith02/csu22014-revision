#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

void print_node(struct ls_node *n);
void print_first(struct mystring *s);
void print_string(struct mystring *s);
void ln();

int main()
{
    char *first = "This is a test of copy string.";
    struct mystring *first_string = new_array2mystring(first);
    print_string(first_string);

    ln();

    struct mystring *copy_string = mystring_copy(first_string);
    print_string(copy_string);

    ln();

    char *c1 = "This is the opening ";
    char *c2 = "and this is the closing!";
    struct mystring *concat1 = new_array2mystring(c1);
    struct mystring *concat2 = new_array2mystring(c2);
    struct mystring *concat_end = mystring_concatenate(concat1, concat2);
    print_string(concat_end);
}

void ln()
{
    printf("\n");
}

void print_node(struct ls_node *n)
{
    printf("%c", n->c);
}

void print_first(struct mystring *s)
{
    printf("%c\n", s->head->c);
}

void print_string(struct mystring *s)
{
    struct ls_node *current = malloc(sizeof(struct ls_node));
    current->next = s->head;

    while ((current = current->next) != NULL)
    {
        print_node(current);
    }
}