#include <stdlib.h>
#include "queue.h"
/* Add an item to the rear of the dynamically-allocated queue.
 * Returns:  pointer to the item if successful, NULL if not 
 */

ItemType *enqueue (Queue *queuePtr, ItemType *newItem){
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    if(newNode == NULL){
        return NULL;
    }
    newNode->dataPtr=newItem; // add data pointer to node
    
    // need to update the next pointer of whatever is already in the last
    if(queuePtr->rear == NULL && queuePtr->front == NULL){
        queuePtr->rear = newNode;
        queuePtr->front = newNode;
    }
    else{
        queuePtr->rear->next= newNode;
        queuePtr->rear = newNode; // update the queue's rear pointer 
    }
    newNode->next = NULL; // set next pointer to null
    //(queuePtr->size)++;
    return newNode->dataPtr;
}

/* Removes an item from the front of the queue.
 * Returns:  pointer to the item if successful, NULL if empty */
ItemType *dequeue (Queue *queuePtr){
    if(queuePtr->front == NULL){
        return NULL;
    }
    ListNode *nodeToDelete = queuePtr->front;
    if(nodeToDelete == NULL){
        return NULL;
    }
    queuePtr->front = nodeToDelete->next;
    if(queuePtr->front == NULL){
        queuePtr->rear = NULL;
    }
    return nodeToDelete->dataPtr;
}

/* Returns:  number of items in the queue */
int queueSize (const Queue queue){
    int nItem = 0;
    ListNode *currentNode = queue.front;
    while(currentNode != NULL){
        nItem++;
        currentNode = currentNode->next;
    }
    return nItem;
}

/* Print the contents of the queue to the specified stream */
void printQueue (const Queue queue, FILE *stream){
    ListNode *currentNode = queue.front;
    while(currentNode != NULL){
        fprintf(stream, ITEM_FORMAT "\n", *(currentNode->dataPtr));
        currentNode = currentNode->next;
    }
}