#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int x;
    struct Node* next;
}Node;
// insert an element to the end of the

void InsertEnd(Node** root, int value){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        exit(1);
    }
    new_node->next = NULL;
    new_node->x = value;
    
    Node* curr = *root;
    while (curr->next!=NULL)
    {
        curr= curr->next;
    }
    curr->next = new_node;

}
int main(int argc, char* argv[])
{   
    Node* root = malloc(sizeof(Node));
    if(root == NULL){

        exit(2);
    }
    root->x = 15;
    root->next = NULL;
/*   root.next = malloc(sizeof(Node));
    root.next->x = -2;
    root.next->next = malloc(sizeof(Node));
    root.next->next->x = 22;
    root.next->next->next = NULL;*/
     for (int i = 0; i < 6; i++)
     {
        InsertEnd(&root, 0);
     }
     
    Node* curr = root;
    while (curr!=NULL)
    {
        printf("%d\n",curr->x);
        
        curr= curr->next;
    }
    
    
    
    /* for(Node* curr = &root; curr!=NULL ;curr = curr->next)*/
    return 0;
}



