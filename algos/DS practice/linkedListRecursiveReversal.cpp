//Author - Shashank
//Program to reverse a linked list using recursion

#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

typedef struct Node{
  int data;
  Node *next;
};

Node *startNode;
Node *endNode;

void addNodeAtEnd(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(endNode!=NULL)
        endNode->next = newNode;
    else
        startNode=newNode;

    endNode = newNode;
}


//Returns the start of the new reversed list
Node* recursivelyReverseList(Node *start)
{
    //check if list is empty.
    //reverse of empty list is an empty list
    if(start==NULL)
        return NULL;

    //check if list contains only one element.
    //reverse of this is the element itself
    if(start->next==NULL)
        return start;

    Node* oldStartOfRightSubList = start->next;

    //We have to destroy the old link as it will cause program to fall in
    //infinite loop for the first two nodes (old first two) as their link
    //will remain unaltered.
    start->next=NULL;

    Node *startOfRightReversedSubList = recursivelyReverseList(oldStartOfRightSubList);

    oldStartOfRightSubList->next=start;

    return startOfRightReversedSubList;
}

void printList()
{
    Node *currentNode = startNode;
    while(currentNode!=NULL)
    {
        printf("%d->",currentNode->data);
        currentNode=currentNode->next;
    }
}

int main()
{
    //create 10 nodes in the list
    for(int i=0;i<10; i++)
    {
        addNodeAtEnd(i);
    }

    //print nodes
    printList();


    printf("\n");

    //Reversal
    startNode = recursivelyReverseList(startNode);
    printList();

}


