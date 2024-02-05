#include <stdio.h>
#include <stdlib.h>
struct node {
 int data;
 struct node* left;
 struct node* right;
};
struct node* insert(struct node* node, int data); 
struct node* newNode (int data);
void inorder(struct node* node);
void postorder (struct node* node);
void preorder (struct node* node);
void main(){
 struct node* root = NULL;
 int n, i = 0 ,j;
 printf("Enter the number of nodes: \n"); 
 scanf("%d",&n); 
 printf("Enter items for %d nodes: \n",n); 
 scanf("%d",&j); 
 root=insert(root, j);
 while( i < n - 1){
 scanf("%d",&j);
 root = insert(root, j);
 i++;
 }
 printf("Inorder: ");
 inorder(root);
 printf("\nPostorder: ");
 postorder(root);
 printf("\nPreorder: ");
 preorder(root);
}
struct node* newNode (int data){
 struct node* node;
 node = (struct node*)malloc(sizeof(struct node));
 node->data = data;
 node->left = NULL; 
 node->right = NULL ;
 return node;
}
struct node* insert(struct node* node, int data){
 if (node == NULL)
 return newNode(data); 
 if (data < node->data) 
 node->left = insert(node->left, data); 
 else if (data > node->data) 
 node->right = insert(node->right, data); 
 return node;
}
void inorder(struct node* node){
 if (node != NULL){ 
 inorder (node->left); 
 printf("%d ", node->data); 
 inorder (node->right);
 }
}
void postorder (struct node* node){
 if (node != NULL) { 
 postorder (node->left); 
 postorder (node->right); 
 printf("%d ", node->data);
 }
}
void preorder (struct node* node){
 if(node != NULL) { 
 printf("%d ", node->data);
 preorder (node->left); 
 preorder (node->right);
 }
}