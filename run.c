#include <stdio.h>
#include <stdlib.h>

// Constants 
#define CAPACITY 4
#define true 1
#define false 0

// Data Structure Queue 
typedef struct
{
    int elements[CAPACITY]; 
    int head; 
    int length; 
}queue; 

// define bool 
typedef int bool; 

// Method(s) prototype
bool dequeue(queue* head, int* element);
bool enqueue(queue* head, int element);
bool isEmpty(queue* head);
int length(queue* head);

int main(int argc,char ** argv)
{ 
    // Sanity check 
    if (argc != 1)
    {
        printf("Usage: ./run\n");
        return 1;
    }
    // Attrbutes 
    int opition;
    int value;
    queue test; 
    
    test.length = 0; 
    test.head = 0;
    
    // program main loop 
    do
    {
        // Prompt the user for an opition
        printf("0. Exit\n");
        printf("1. Enqueue an element.\n");
        printf("2. Dequeue an element.\n");
        
        // take user opition
        scanf("%d", &opition);
        
        switch(opition)
        {
            // Enqueue an Element
            case 1: 
                printf("Value: ");
                scanf("%d", &value);
                if (enqueue(&test, value))
                {
                    printf("Success\n");
                }
                else 
                {
                    printf("Fail\n");
                }
                break;
                
            // Dequeue an element
            case 2:
                if (dequeue(&test, &value))
                {
                    printf("Success.\n");
                    printf("Return %d\n", value);
                }
                else
                {
                    printf("Fail\n");
                }
                break;
        }
        
    }while(opition != 0);
    
    return 0;
}

/*
* dequeue() - remove an element from the queue 
* 
* @param queue* head - the queue i want to manipulate 
* @param int* element - the element that will be dequeued 
* @return bool - true if removal is a success 
*/ 
bool dequeue(queue* head, int* element)
{
    if (head->length > 0)
    {
        head->length--; 
        *element = head->elements[head->head];
        head->head++;
        return true;
    }
    else
    {
        return false;
    }
}

/*
* enqueue() - add an element to the queue
* 
* @param queue* head - the queue i want to manipulate 
* @param int element - the element that will be enqueued 
* @return bool - true if the operation is a success
*/
bool enqueue(queue* head, int element)
{
    if (head->length < CAPACITY)
    {
        head->length++;
        head->elements[(head->head + head->length) % CAPACITY] = element; 
        
        return true; 
    }
    else 
    {
        return false;
    }
}

/*
* isEmpty() - Check if the queue is empty or not
*
* @param queue* head - the queue i want to check if it's empty or not
* @return bool - true if the queue is empty
*/ 
bool isEmpty(queue* head)
{
    return length == 0; 
}

/* 
* length()- get the length of the queue 
*
* @param queue* head - the queue to be checked 
* return int - the length of the queue
*/ 
int length(queue* head)
{
    return head->length;
}

