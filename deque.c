#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "deque.h"

// create a new empty deque
struct deque *new_deque()
{
    struct deque *new_que = malloc(sizeof(struct deque));
    return new_que;
}

// push a string to the front of the deque
void push_front_deque(struct deque *this, char *str)
{
    if (is_nulldeque(this) == 1)
    {
        init_head(this);
        this->head->val = str;
        return;
    }
}

// pop a string from the front of the deque
char *pop_front_deque(struct deque *this);

// push a string to the back of the deque
void push_back_deque(struct deque *this, char *str);

// pop a value from the back of the deque
char *pop_back_deque(struct deque *this);

// free the memory being used by a deque
void free_deque(struct deque *this);

// return a string from the deque at position “index”, where the item at
// the front of the deque has index 0, and subsequent items are number
// successively. if there are fewer than index+1 items in the deque,
// return a string containing the value “ERROR”
char *item_at_deque(struct deque *this, int index);

int is_nulldeque(struct deque *this)
{
    if (this->head == NULL && this->tail == NULL)
    {
        return 1;
    }

    return 0;
}

void init_head(struct deque *this)
{
    this->head = malloc(sizeof(struct node));
}

void init_tail(struct deque *this)
{
    this->head = malloc(sizeof(struct node));
}
