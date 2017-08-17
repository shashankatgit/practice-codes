//Author - Shashank
//Program to reverse a linked list

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


void reverseList()
{
    Node *prev = NULL;
    Node *tempStart = startNode;
    Node *next = NULL;

    while(tempStart)
    {
        next = tempStart->next;
        tempStart->next = prev;
        prev=tempStart;
        tempStart = next;
    }

    startNode = prev;

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
    reverseList();
    printList();

}


