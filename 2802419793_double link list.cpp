#include <stdio.h>
#include <stdlib.h>

struct tnode 
{
    int x;
    struct tnode *next, *prev;
} *head, *tail;

void push_front(int value) 
{
    struct tnode *node = (struct tnode *)malloc(sizeof(struct tnode));
    node->x = value;
    node->prev = NULL;
    node->next = head;
    if (head != NULL) 
	{
        head->prev = node;
    } 
	else 
	{
        tail = node;
    }
    head = node;
}

void push_back(int value) 
{
    struct tnode *node = (struct tnode *)malloc(sizeof(struct tnode));
    node->x = value;
    node->next = NULL;
    node->prev = tail;
    if (tail != NULL) 
	{
        tail->next = node;
    } 
	else 
	{
        head = node;
    }
    tail = node;
}

void delete_back() 
{
    if (tail == NULL) 
	{
        printf("List is empty\n");
        return;
    }
    struct tnode *del = tail;
    if (head == tail) 
	{
        head = tail = NULL;
    } 
	else 
	{
        tail = tail->prev;
        tail->next = NULL;
    }
    free(del);
}

void delete_mid(int value) 
{
    struct tnode *curr = head;
    while (curr != NULL && curr->x != value) 
	{
        curr = curr->next;
    }
    if (curr == NULL) 
	{
        printf("Value %d not found in the list\n", value);
        return;
    }
    if (curr == head) 
	{
        head = head->next;
        if (head) head->prev = NULL;
    } 
	else if (curr == tail) 
	{
        delete_back();
        return;
    } 
	else 
	{
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    free(curr);
}

void printList() 
{
    struct tnode *curr = head;
    while (curr != NULL) 
	{
        printf("%d ", curr->x);
        curr = curr->next;
    }
    printf("\n");
}

int main() 
{
    push_back(10);
    push_back(20);
    push_back(30);
    push_front(5);
    printList();
    delete_back();
    printList();
    delete_mid(20);
    printList();
    return 0;
}

