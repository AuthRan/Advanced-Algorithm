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
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct node *insert (struct node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if(value < root->data) {
        root->left = insert(root->left, value);
    }
    else if(value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inorder(struct node *root){
    if (root != NULL) {
        inorder(root->left);
        printf("6%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder Traversal: \n");
    inorder(root);
    return 0;
}