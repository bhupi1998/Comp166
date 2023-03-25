#include <stdlib.h>
#include "queue.h"
/* Add an item to the rear of the dynamically-allocated queue.
 * Returns:  pointer to the item if successful, NULL if not 
 * typedef struct {
    ListNode *front;
    ListNode *rear;
    int size; // Number of items currently in the queue
} Queue;

 * typedef struct listNode {
    struct listNode *next;
    ItemType *dataPtr;
} ListNode;
 */

ItemType *enqueue (Queue *queuePtr, ItemType *newItem){
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->dataPtr=newItem; // add data pointer to node
    
    // need to update the next pointer of whatever is already in the last
    if(queuePtr->rear != NULL){
        (queuePtr->rear)->next = newNode;
    }
    queuePtr->rear = newNode; // update the queue's rear pointer 
    newNode->next=NULL; // set next pointer to null
    return newNode;
}

/* Removes an item from the front of the queue.
 * Returns:  pointer to the item if successful, NULL if empty */
ItemType *dequeue (Queue *queuePtr){
}

/* Returns:  number of items in the queue */
int queueSize (const Queue queue){
}

/* Print the contents of the queue to the specified stream */
void printQueue (const Queue queue, FILE *stream){
}