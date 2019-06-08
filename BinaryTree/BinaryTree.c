#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * 1. 如果是空樹，先建立一個指向 Node 的 pointer 稱為 Root Node Pointer
 * 2. 然後 Create 1 個 Node 為 Root Node
 * 3. 將 Root Node Pointer 指向 Root Node 
 */
typedef struct Node
{
    int data;
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
    return node;
}

void NodeAdd(int d)
{
    /* Tree is empty */
    if( root == NULL )
    {
        /* Create a Node as root */
        root        = malloc(sizeof(Node));
        root->data  = d;
        root->left  = NULL;
        root->right = NULL;
    }
    /* Tree is not empty */
    else
    {
        Node* parentNode    = NULL;        
        Node* currNode      = root;
        /* Save parentNode */
        while( currNode != NULL )
        {
            parentNode = currNode;
            if( d < currNode->data ){ currNode = currNode->left;  }
            else                    { currNode = currNode->right; }
        }
        
        /* Create New Node */
        currNode = malloc(sizeof(Node));
        currNode->data  = d;
        currNode->left  = NULL;
        currNode->right = NULL;
        
        /* Assign New Node to Parent Child */
        if( d < parentNode->data ){ parentNode->left    = currNode; }
        else                      { parentNode->right   = currNode; }
    }
}

void PreOrder(Node *node)
{
    if( node == NULL ) return;    
    Node* currNode      = node;
    printf("Node : %d\n", currNode->data);
    PreOrder(currNode->left);
    PreOrder(currNode->right);
}

void InOrder(Node *node)
{
    if( node == NULL ) return;    
    Node* currNode      = node;    
    InOrder(currNode->left);
    printf("Node : %d\n", currNode->data);
    InOrder(currNode->right);
}

void PostOrder(Node *node)
{
    if( node == NULL ) return;    
    Node* currNode      = node;        
    PostOrder(currNode->left);    
    PostOrder(currNode->right);
    printf("Node : %d\n", currNode->data);        
}

int main(int argc, char **argv)
{
	printf("Binary Tree !!!\n");
    NodeAdd(50);
    NodeAdd(40);
    NodeAdd(30);
    NodeAdd(45);
    NodeAdd(48);
    NodeAdd(60);
    NodeAdd(55);
    NodeAdd(70);    
    NodeAdd(80);    
    NodeAdd(65);    
    NodeAdd(66);
    NodeAdd(64);
    NodeAdd(63);
    //PreOrder(root);
    PostOrder(root);
    
    NodeDelete(root, 30);
    PreOrder(root);
    
    NodeDelete(root, 40);
    PreOrder(root);
    
    NodeDelete(root, 70);
    PreOrder(root);    
	return 0;
}
