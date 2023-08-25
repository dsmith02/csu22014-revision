// deque.h
// Diarmuid Smith, August 2023

struct deque
{
    struct node *head;
    struct node *tail;
};

struct node
{
    struct node *next;
    struct node *prev;
    char *val;
};

// create a new empty deque
struct deque *
new_deque();

// push a string to the front of the deque
void push_front_deque(struct deque *this, char *str);

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

// returns 1 if the deque is empty, returns 0 otherwise
int is_nulldeque(struct deque *this);

void init_head(struct deque *this);

void init_tail(struct deque *this);

struct node *create_node(char *val);