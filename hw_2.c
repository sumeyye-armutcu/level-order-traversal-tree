#include <stdio.h>
#include <stdlib.h>
//A binary tree node has data, pointer to left and right child
struct treeNode
{
int data;
struct treeNode* leftptr;
struct treeNode* rightptr;
};
//Function prototypes
void reverseLevelOrder(struct treeNode* root);
struct treeNode* newNode(int data);



//Function to print reverse level order traversal a binary tree
void reverseLevelOrder(struct treeNode* root)
{
 // Creating an empty queue
    
    struct treeNode* queue[10];
    int front=0 , rear = 0;
 // Creating an empty stack
    struct treeNode* stack[10];
    int top = -1;

    // Adding(Enqueue) the root node to the queues rear
    queue[rear] = root;
    rear++;

    // Until the queue is empty stay in the for loop
    for(;front != rear;front++)
    {
        // Taking(Dequeue) a node from the queue and Adding(push) it to the stack
        struct treeNode* node = queue[front];
        
        stack[++top] = node;
        
		// Adding(Enqueue) the right children to the queue
		if (node->rightptr)
        {
            queue[rear] = node->rightptr;
            rear++;
        }
        
        // Adding(Enqueue) the left children to the queue
        if (node->leftptr)
        {
            queue[rear] = node->leftptr;
            rear++;
        }
        
    }

    // Print all nodes from stack 
    for (;top >= 0;top--)
    {
        printf("%d ", stack[top]->data);
     
    }
    
    

 
}

//Insert new node to the binary tree
struct treeNode* newNode(int data)
{
struct treeNode* treeNode = (struct treeNode*) malloc(sizeof(struct
treeNode));
treeNode->data = data;
treeNode->leftptr = NULL;
treeNode->rightptr = NULL;
return(treeNode);
}
int main()
{
struct treeNode *root = newNode(9);
root->leftptr = newNode(12);
root->rightptr = newNode(21);
root->leftptr->leftptr = newNode(15);
root->leftptr->rightptr = newNode(8);
root->rightptr->leftptr = newNode(7);
root->rightptr->rightptr = newNode(11);
printf("Level Order traversal of binary tree is \n");
reverseLevelOrder(root);
return 0;
}

/*
REFERENCES
1-https://www.techiedelight.com/reverse-level-order-traversal-binary-tree/
2-https://www.youtube.com/watch?v=L7rbBGo7Mo8


*/
