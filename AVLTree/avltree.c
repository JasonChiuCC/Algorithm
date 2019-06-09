#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
}Node;
Node *root = NULL;


Node* FindMinNode(Node* node)
{    
    Node* currNode  = node;
    if( currNode->left != NULL ){
        return FindMinNode(currNode->left);
    }else{
        return currNode;    
    }    
}

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

int NodeHeight(Node *node) 
{ 
    if (node == NULL) 
        return 0; 
    return node->height; 
} 

struct Node* newNode(int d) 
{ 
    Node* node      = malloc(sizeof(Node)); 
    node->data      = d;
    node->left      = NULL;
    node->right     = NULL;
    node->height    = 1;
    return(node); 
}

Node* rightRotate(Node* node)
{
    Node* tmpNode   = node->left;
    node->left      = tmpNode->right;
    tmpNode->right  = node;
    
    /* Update Node hight */
    tmpNode->height = 1 + max( NodeHeight(tmpNode->left), NodeHeight(tmpNode->right));
    node->height    = 1 + max( NodeHeight(node->left), NodeHeight(node->right));        
    return tmpNode;    
}

Node* leftRotate(Node* node)
{
    Node* tmpNode   = node->right;
    node->right     = tmpNode->left;
    tmpNode->left   = node;
    
    /* Update Node hight */
    tmpNode->height = 1 + max( NodeHeight(tmpNode->left), NodeHeight(tmpNode->right));
    node->height    = 1 + max( NodeHeight(node->left), NodeHeight(node->right));        
    return tmpNode;    
}
  
Node* NodeDelete(Node* node, int d)
{
    if( node == NULL ) return;
    
    if( d < node->data ) {
        node->left  = NodeDelete( node->left,  d);
    } else  if( d >  node->data ) {
        node->right = NodeDelete( node->right, d);
    } else {
        printf("node data = %d\n",node->data);
        /* Case1 : Del Node has NO child 
         * 直接刪除 Node
         */
        if( node->left  == NULL && 
            node->right == NULL)
        {
            printf("This Node has NO child C(%d) !!!\n", node->data, node->data);
            free(node);
            node = NULL;
            return node;
        }
        
        /* Case2 : Del Node has ONE child 
         * 把刪除的 Node 替換為 child Node
         */
        if( node->right != NULL && node->left  == NULL)
        {
            printf("This Node has One child C(%d)!!!\n", node->data);
            Node* tmpNode = node;
            node = node->right;
            free(tmpNode);
            tmpNode = NULL;
            return node;        
        }
        if( node->left  != NULL && node->right == NULL)
        {
            printf("This Node has One child C(%d)!!!\n", node->data);
            Node* tmpNode = node;
            node = node->left;
            free(tmpNode);
            tmpNode = NULL;
            return node;
        }
        /* Case3 : Del Node has TWO child 
         * 有 2 種方法
         * 1. 找 Node 右子樹中最小的 Node 代替
         * 2. 找 Node 左子樹中最大的 Node 代替
         */
        if( node->left  != NULL && 
            node->right != NULL)
        {
            printf("This Node has Two child C(%d)!!!\n", node->data);
            Node * nodeMin = FindMinNode(node->left);
            printf("FindMinNode C(%d)!!!\n", nodeMin->data);
            node->data = nodeMin->data;
            NodeDelete(node->left, nodeMin->data);            
        }         
    }
    
    /* Update Node hight */
    node->height = 1 + max( NodeHeight(node->left), NodeHeight(node->right));
        
    int balance = getBalance(node);
    printf("Node : %2d Balance : %d\n", node->data, balance);
    
    // 4 種需要旋轉的 Case
    // (1) LL 
    if (balance >= 2    && d < node->left->data) 
    {
        node = rightRotate(node);
    }  
    // (2) RR 
    if (balance <= -2   && d > node->right->data) 
    {
        node = leftRotate(node); 
    }
    // (3) LR 
    if (balance >= 2    && d > node->left->data) 
    { 
        node->left = leftRotate(node->left);
        node = rightRotate(node);
    }   
    // (4) RL 
    if (balance <= -2   && d < node->right->data) 
    { 
        node->left = rightRotate(node->left);
        node = leftRotate(node);
    }     
    return node;
}

int getBalance(Node *node) 
{ 
    if (node == NULL) 
        return 0; 
    return NodeHeight(node->left) - NodeHeight(node->right); 
} 
  
Node* NodeAdd(Node* node, int d)
{
    
    /* Tree is empty */
    if( node == NULL ){ return newNode(d); }
    
    /* Tree is not empty */
    Node * currNode = node;
    if( d < currNode->data )
    {
        currNode->left  = NodeAdd(currNode->left,   d);
    }
    else if( d > currNode->data )
    {
        currNode->right = NodeAdd(currNode->right,  d);
    }
    
    /* Update Node hight */
    node->height = 1 + max( NodeHeight(node->left), NodeHeight(node->right));
        
    int balance = getBalance(node);
    printf("Node : %2d Balance : %d\n", node->data, balance);
    
    // 4 種需要旋轉的 Case
    // (1) LL 
    if (balance >= 2    && d < node->left->data) 
    {
        node = rightRotate(node);
    }  
    // (2) RR 
    if (balance <= -2   && d > node->right->data) 
    {
        node = leftRotate(node); 
    }
    // (3) LR 
    if (balance >= 2    && d > node->left->data) 
    { 
        node->left = leftRotate(node->left);
        node = rightRotate(node);
    }   
    // (4) RL 
    if (balance <= -2   && d < node->right->data) 
    { 
        node->left = rightRotate(node->left);
        node = leftRotate(node);
    } 
    return node;
}

void PreOrder(Node *node)
{
    if( node == NULL ) return;    
    Node* currNode      = node;
    printf("Node : %2d Hight : %2d\n", currNode->data, currNode->height);
    PreOrder(currNode->left);
    PreOrder(currNode->right);
}

void InOrder(Node *node)
{
    if( node == NULL ) return;    
    Node* currNode      = node;    
    InOrder(currNode->left);
    printf("Node : %2d Hight : %2d\n", currNode->data, currNode->height);
    InOrder(currNode->right);
}

void PostOrder(Node *node)
{
    if( node == NULL ) return;    
    Node* currNode      = node;        
    PostOrder(currNode->left);    
    PostOrder(currNode->right);
    printf("Node : %2d Hight : %2d\n", currNode->data, currNode->height);
}

int main(int argc, char **argv)
{
	printf("AVL Tree !!!\n");

    
    /* Constructing tree given in the above figure */
    root = NodeAdd(root, 20);
    //PreOrder(root);
    NodeAdd(root, 10); 
    //PreOrder(root);
    NodeAdd(root, 30);
    //printf("root L : %d R : %d !!!\n",root->left->data,root->right->data); 
    //PreOrder(root);
    NodeAdd(root, 8);
    NodeAdd(root, 9);
    PreOrder(root);
    //NodeAdd(root, 30);     
	return 0;
}
