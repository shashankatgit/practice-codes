//Program to delete a node in linked list without using if block

#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

typedef struct Node{

  int data;
  Node *next;
};

Node *startNode;

void addNodeAtEnd(int data, Node **endNode)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*endNode!=NULL)
        (*endNode)->next = newNode;
    else
        startNode=newNode;

    *endNode = newNode;
}

void delMatchedNodeWithIf(int data)
{
    Node *temp;
    temp = start;
    while (temp->data != data)
    {

    }
}

int main()
{

    Node *endNode=NULL;

    //create 10 nodes in the list
    for(int i=0;i<10; i++)
    {
        addNodeAtEnd(i, &endNode);
    }

    //print nodes
    Node *currentNode = startNode;
    while(currentNode!=NULL)
    {
        printf("%d->",currentNode->data);
        currentNode=currentNode->next;
    }

}


