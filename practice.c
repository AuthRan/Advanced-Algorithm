#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}
struct node *insertNode(struct node *root, int value) {
    if(root == NULL) {
        return createNode(value);
    }
    if(value < root->data) {
        root->left = insertNode(root->left, value);
    }
    if(value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void inorder(struct node *root) {
    if(root){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 55);
    insertNode(root, 15);
    insertNode(root, 75);
    insertNode(root, 65);
    insertNode(root, 5);
    insertNode(root, 58);
    inorder(root);
    return 0;
}

/*
t = (t*d + (txt[i] - '0'))%q
if(t==p){
}
t = (d * (t - (txt[i] - '0)*h) + (txt[i+m] - '0' )) % q
*/