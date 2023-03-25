#include <stdlib.h>
#include "queue.h"

/* Add an item to the rear of the dynamically-allocated queue.
 * Returns:  pointer to the item if successful, NULL if not 
 */

ItemType *enqueue(Queue *queuePtr, ItemType *newItem, int queueEnd) {
    ListNode *newNode = (ListNode*) malloc(sizeof (ListNode));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->dataPtr = newItem; // add data pointer to node

    // need to update the next pointer of whatever is already in the last
    if (queuePtr->rear == NULL && queuePtr->front == NULL) {
        queuePtr->rear = newNode;
        queuePtr->front = newNode;
        newNode->next = NULL; // set next pointer to null
        newNode->rear = NULL;
    } else {
        if (queueEnd == REAR) {
            queuePtr->rear->next = newNode;
            newNode->rear = queuePtr->rear;
            queuePtr->rear = newNode; // update the queue's rear pointer 
            newNode->next = NULL; // set next pointer to null
        } else if (queueEnd == FRONT) {
            newNode->next = queuePtr->front;
            queuePtr->front->rear = newNode;
            newNode->rear = NULL;
            queuePtr->front = newNode;
        } else {
            return NULL;
        }
    }
    //(queuePtr->size)++;
    return newNode->dataPtr;
}

/* Removes an item from the front of the queue.
 * Returns:  pointer to the item if successful, NULL if empty */
ItemType *dequeue(Queue *queuePtr, int queueEnd) {
    if (queuePtr->front == NULL && queuePtr->rear == NULL) {
        return NULL;
    }
    ListNode *nodeToDelete;
    if (queueEnd == FRONT) {
        nodeToDelete = queuePtr->front;
        queuePtr->front = nodeToDelete->next;
        if (queuePtr->front == NULL) {
            queuePtr->rear = NULL;
        }
        if(nodeToDelete->next != NULL){
            nodeToDelete->next->rear = NULL;
        }
    } else if (queueEnd == REAR) {
        nodeToDelete = queuePtr->rear;
        queuePtr->rear = nodeToDelete->rear;
        if (queuePtr->rear == NULL) {
            queuePtr->front = NULL;
        }
        if(nodeToDelete->rear != NULL){
            nodeToDelete->rear->next = NULL;
        }
    } else {
        return EXIT_FAILURE;
    }
    return nodeToDelete->dataPtr;
}

/* Returns:  number of items in the queue */
int queueSize(const Queue queue) {
    int nItem = 0;
    ListNode *currentNode = queue.front;
    while (currentNode != NULL) {
        nItem++;
        currentNode = currentNode->next;
    }
    return nItem;
}

/* Print the contents of the queue to the specified stream */
void printQueue(const Queue queue, FILE *stream) {
    ListNode *currentNode = queue.front;
    while (currentNode != NULL) {
        fprintf(stream, ITEM_FORMAT "\n", *(currentNode->dataPtr));
        currentNode = currentNode->next;
    }
}