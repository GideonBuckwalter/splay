#include <stdbool.h>
#include "splay.c"

/*
 *  Author: Gideon Buckwalter
 *  Creation Date: May 17, 2017
 *  Github: GideonBuckwalter
 *
 *  Description:
 *  Specification file for the Splay Tree data structure implementation.
 *  Could be used for database lookup tables (?).
 */

// These might be changed later.
typedef void* Key;
typedef void* Value;

// Define the Node structure.
typedef struct
{
    Key key;
    Value value;
    Node* parent;
    Node* left;
    Node* right;
} Node;

typedef struct
{
    Node* root;
} SplayTree;

// Frees memory used by splay tree.
void destroy_splay_tree(SplayTree* tree);

// Inserts a key-value pair into the tree.
void set(const Key key, const Value value, SplayTree* tree);

// Removes a key-value pair from the tree.
void remove(const Key key, SplayTree* tree);

// Returns a mutable pointer to the object stored at 'key'.
// If 'key' is not in the tree, returns NULL.
Value get(const Key key, SplayTree* tree);
