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

// Node constructor.
Node* new_node(Key key, Value value, Node* parent, Node* left, Node* right);

// These functions check if a node is able to perform
// a certain rotation.
bool can_rotate_up(Node* node);
bool can_zig_zig(Node* node);
bool can_zig_zag(Node* node);

// Rotates 'node' and 'node's parent either left or right;
// whichever will move 'node' up.
void rotate_up(Node* node);

// Performs 'zig-zig' rotation on 'node', its parent, and
// its grandparent.
void zig_zig(Node* node);

// Performs 'zig-zag' rotation on 'node', its parent, and
// its grandparent.
void zig_zag(Node* node);


// Inserts a key-value pair into the tree.
void set(const Key key, const Value value, Node* root);

// Removes a key-value pair from the tree.
void remove(const Key key, Node* root);

// Returns a mutable pointer to the object stored at 'key'.
// If 'key' is not in the tree, returns NULL.
Value get(const Key key, Node* root);


//// Helper Functions ////

// Recursively finds the node but doesn't splay it to
// the root.
Node* _locate(const Key key, Node* root);

// Repeatedly rotates the node up until it is the
// root of the tree.
void _splay(Node* node, Node* root);

