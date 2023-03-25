/* Header file for a simple queue data structure.
 * To be implemented using dynamic allocation.
 *
 * Dale Shpak June 23, 2015
 */

#ifndef QUEUE_H
#define	QUEUE_H
#include <stdio.h>

// The following 3 lines must all be in agreement
typedef int ItemType;
#define ITEM_PROMPT "an integer"
#define ITEM_FORMAT "%d"
#define FRONT 0
#define REAR 1

// A node for a singly-linked list
typedef struct listNode {
    struct listNode *next;
    struct listNode *rear;
    ItemType *dataPtr;
} ListNode;

// A queue data structure
typedef struct {
    ListNode *front;
    ListNode *rear;
    int size; // Number of items currently in the queue
} Queue;

/* Add an item to the rear of the dynamically-allocated queue.
 * queueEnd is used to pick which side of the queue to add from
 * Returns:  pointer to the item if successful, NULL if not */
ItemType *enqueue (Queue *queuePtr, ItemType *newItem, int queueEnd);

/* Removes an item from the front of the queue.
 * queueEnd is used to pick which side of the queue to remove from
 * Returns:  pointer to the item if successful, NULL if empty */
ItemType *dequeue (Queue *queuePtr, int queueEnd);

/* Returns:  number of items in the queue */
int queueSize (const Queue queue);

/* Print the contents of the queue to the specified stream */
void printQueue (const Queue queue, FILE *stream);

#endif	/* QUEUE_H */

