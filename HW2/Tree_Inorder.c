#include <stdio.h>
#include <stdlib.h>

struct node {
   int data; 
	
   struct node *leftChild;
   struct node *rightChild;
};

struct node *root = NULL;

void insert(int data) {
   struct node *tempNode = (struct node *) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;

      while(1) { 
         parent = current;
          
         if(data < parent->data) {
            current = current->leftChild;                
            
            
            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }  
         else {
            current = current->rightChild;
            
            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }            
   }
}

struct node* search(int data) {
   struct node *current = root;
   printf("Visiting elements: ");

   while(current->data != data) {
      if(current != NULL)
         printf("%d ",current->data); 

      if(current->data > data) {
         current = current->leftChild;
      }
      
      else {                
         current = current->rightChild;
      }
      
      if(current == NULL) {
         return NULL;
      }
   }
   
   return current;
}

void inorder(struct node* root) {
   if(root != NULL) {
      inorder(root->leftChild);
      printf("%d ",root->data);          
      inorder(root->rightChild);
   }
}


int main() {
   int i;
   int array[6] = { 1, 4, 16, 25, 20, 15};

   for(i = 0; i < 6; i++)
      insert(array[i]);

   i = 31;
   struct node * temp = search(i);

   if(temp != NULL) {
      printf("[%d] Element found.", temp->data);
      printf("\n");
   }else {
      printf("[ x ] Element not found (%d).\n", i);
   }

   i = 15;
   temp = search(i);

   if(temp != NULL) {
      printf("[%d] Element found.", temp->data);
      printf("\n");
   }else {
      printf("[ x ] Element not found (%d).\n", i);
   }            

   printf("\nInorder : ");
   inorder(root);
      
   return 0;
}
