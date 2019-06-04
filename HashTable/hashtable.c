#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 *   +-----+
 * 0 |     |
 *   +-----+
 * 1 |     |--> BB --> CC
 *   +-----+
 * 2 |     |
 *   +-----+
 * 3 |     |
 *   +-----+
 * 4 |     |--> AA
 *   +-----+
 * 5 |     |
 *   +-----+
 * 6 |     |
 *   +-----+
 * 7 |     |
 *   +-----+  
 * 8 |     |
 *   +-----+
 * 9 |     |
 *   +-----+
 * 
 */
typedef struct element
{
    char name[256];
    struct element *next;
}node;
node *hashTable[10];
#define HASH_TABLE_SIZE 10
int strToKey(char name[])
{
    int asciiSum = 0;
    for(int i=0; i<strlen(name); i++)
    {
        //printf("%c = %d\n",name[i], name[i]);
        asciiSum += name[i];
    }
    return (asciiSum%HASH_TABLE_SIZE);
}

void addNode(char name[])
{
    node *element = malloc(sizeof(node));
    node *tmpNode;
    element->next = NULL;
    strcpy(element->name,name);
    int key = strToKey(name);
    
    if( hashTable[key] == NULL )
    {
        hashTable[key] = element;
    }
    else
    {
        for(tmpNode = hashTable[key]; tmpNode->next != NULL; tmpNode = tmpNode->next);
        tmpNode->next = element;
    }
}

int searchNode(char name[], int *mkey, int *midx)
{
    int key = strToKey(name);
    int idx = 0;
    node *tmpNode;
    
    if( hashTable[key] == NULL )
    {
        //printf("Find ERROR\n");
        return -1;
    }
   
    tmpNode = hashTable[key];        
    for(;;tmpNode = tmpNode->next)
    {
        if( strcmp(tmpNode->name, name) == 0 )
        {
            *mkey = key;
            *midx = idx;
            //printf("Find OK\n");
            return 0;            
        }
        if( tmpNode->next == NULL) break;
        idx++;
        //printf("Find Next\n");
    }
    return -1;
}

void deleteNode(char name[])
{
    int key = strToKey(name);
    int idx = 0;
    node *tmpNode;
    node *preNode; 
    if( hashTable[key] == NULL )
    {
        printf("Find ERROR\n");
        return -1;
    }
    
    tmpNode = hashTable[key];
    preNode = tmpNode;
    for(;;tmpNode = tmpNode->next)
    {
        if( strcmp(tmpNode->name, name) == 0 )
        {
            if( tmpNode->next != NULL)
            {
                hashTable[key] = tmpNode->next;
                free(tmpNode);
                printf("Del OK-1\n");
                return;
            }
            else
            {
                preNode->next = NULL;
                free(tmpNode);
                tmpNode = NULL;                
                printf("Del OK-2\n");
                return;                
            }        
        }
        if( tmpNode->next == NULL) break;
        printf("Find Next\n");
        preNode = tmpNode;
    } 
}

void printHashTable()
{
    node *tmpNode;
    for(int idx = 0; idx < HASH_TABLE_SIZE; idx++)    
    {
        if( hashTable[idx] != NULL )
        {
            tmpNode = hashTable[idx];
            printf("hashTable[%d] = ",idx);            
            for(;;tmpNode = tmpNode->next)
            {
                printf("%s -> ", tmpNode->name);            
                if( tmpNode->next == NULL) break;
            }
            printf("\n");
        }
        else
        {
            printf("hashTable[%d] = NULL\n",idx);
        }
    }
}

int main(int argc, char **argv)
{
    int key = 0;
    int idx = 0;
    // Init HashTable to NULL
    for(int i = 0; i< HASH_TABLE_SIZE; i++){ hashTable[i] = NULL; }    
    
    addNode("AAA");
    addNode("BBB");
    addNode("CCC");
    addNode("ABC");
    addNode("DEF");
    addNode("Jason");
    addNode("Sharon");    
    addNode("XYZ");        
    addNode("Dog");            
    printHashTable();

    searchNode("XYZ",&key, &idx);
    printf("Find XYZ key = %d idx = %d\n", key, idx);
    
    deleteNode("DEF");
    printHashTable();    
    
    deleteNode("XYZ");
    printHashTable();        
	return 0;
}
