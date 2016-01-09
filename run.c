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
}Queue; 

// define bool 
typedef int bool; 

// Method(s) prototype
bool dequeue(queue* head, int* element);
bool enqueue(queue* head, int element);
bool isEmpty(queue* head);
int length(queue* head);

int main(int argc,char ** argv)
{ 
    // TODO Write test program
    
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
        elements[(head->head + head->length) % CAPACITY] = element; 
        
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

