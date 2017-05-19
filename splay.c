#include <stdio.h>
#include <stdlib.h>


Node* new_node(Key key, Value value, Node* parent, Node* left, Node* right)
{
    Node* node = malloc(sizeof *node);

    node->key = key;
    node->value = value;
    node->parent = parent;
    node->left = left;
    node->right = right;

    return node;
}
