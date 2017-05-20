#include <stdio.h>
#include <stdlib.h>

void destroy_splay_tree(SplayTree* tree)
{
    if (tree->root)
        destroy_children(tree->root);
}



//// Helper Functions ////

// Node constructor.
static Node*
new_node(Key key, Value value, Node* parent, Node* left, Node* right)
{
    Node* node = malloc(sizeof *node);

    node->key = key;
    node->value = value;
    node->parent = parent;
    node->left = left;
    node->right = right;

    return node;
}


// These functions check if a node is able to perform
// a certain rotation.
static bool can_rotate_up(Node* node);
static bool can_zig_zig(Node* node);
static bool can_zig_zag(Node* node);

// Rotates 'node' and 'node's parent either left or right;
// whichever will move 'node' up.
static void rotate_up(Node* node);

// Performs 'zig-zig' rotation on 'node', its parent, and
// its grandparent.
static void zig_zig(Node* node);

// Performs 'zig-zag' rotation on 'node', its parent, and
// its grandparent.
static void zig_zag(Node* node);

// Frees 'node' and all it's decendents.
static void destroy_children(Node* node)
{
    if (node->left)
        destroy_children(node->left);
    if (node->right)
        destroy_children(node->right);
    free(node);
}

// Recursively finds the node but doesn't splay it to
// the root.
static Node* locate(const Key key, Node* root);

// Repeatedly rotates the node up until it is the
// root of the tree.
static void splay(Node* node, Node* root);
