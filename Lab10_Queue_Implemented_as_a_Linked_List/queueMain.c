/* Tests for Queue library.
 *
 * Dale Shpak
 * March 25, 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include "queue.h"

typedef enum {
    QUIT = -1, ENQUEUE_FRONT, ENQUEUE_REAR, DEQUEUE_FRONT, DEQUEUE_REAR, PRINT, N_CHOICES
} Choice;

int main(int ac, char *av[]) {
    Queue queue = {NULL, NULL, 0};

    int done = 0;
    while (!done) {
        Choice choice;
        int nValid;
        do {
            printf("Enter \n\t%d to add to front of queue,\n"
                    "\t%d to add to rear of queue\n"
                    "\t%d to remove from front of queue,\n"
                    "\t%d to remove from rear of queue or\n"
                    "\t%d to print contents "
                    "\t(%d to quit): ", ENQUEUE_FRONT, ENQUEUE_REAR, DEQUEUE_FRONT, DEQUEUE_REAR, PRINT, QUIT);
            nValid = scanf("%d", &choice);
            while (getchar() != '\n') {
            } // Get rid of rest of line
        } while (nValid != 1 || choice < QUIT || choice >= N_CHOICES);


        switch (choice) {
            case DEQUEUE_FRONT:
            {
                ItemType *itemPtr;
                if ((itemPtr = dequeue(&queue, FRONT)) != NULL) {
                    printf("Removed " ITEM_FORMAT "\n", *itemPtr);
                    free(itemPtr);
                } else {
                    printf("Queue is empty\n");
                }
                break;
            }
            case DEQUEUE_REAR:
            {
                ItemType *itemPtr;
                if ((itemPtr = dequeue(&queue, REAR)) != NULL) {
                    printf("Removed " ITEM_FORMAT "\n", *itemPtr);
                    free(itemPtr);
                } else {
                    printf("Queue is empty\n");
                }
                break;
            }

            case ENQUEUE_FRONT:
            {
                ItemType *itemPtr = (ItemType *) malloc(sizeof (ItemType));
                if (itemPtr == NULL) {
                    fprintf(stderr, "%s: Error allocating memory for item.\n", av[0]);
                    return EXIT_FAILURE;
                }

                printf("Enter " ITEM_PROMPT ": ");
                if (scanf(ITEM_FORMAT, itemPtr) != 1) {
                    fprintf(stderr, "Unable to read " ITEM_PROMPT "\n");
                    break;
                }

                if ((itemPtr = enqueue(&queue, itemPtr, FRONT)) != NULL) {
                    printf("Added " ITEM_FORMAT "\n", *itemPtr);
                } else {
                    fprintf(stderr, "%s: Error allocating memory to queue.\n", basename(av[0]));
                    return EXIT_FAILURE;
                }
                break;
            }
            case ENQUEUE_REAR:
            {
                ItemType *itemPtr = (ItemType *) malloc(sizeof (ItemType));
                if (itemPtr == NULL) {
                    fprintf(stderr, "%s: Error allocating memory for item.\n", av[0]);
                    return EXIT_FAILURE;
                }

                printf("Enter " ITEM_PROMPT ": ");
                if (scanf(ITEM_FORMAT, itemPtr) != 1) {
                    fprintf(stderr, "Unable to read " ITEM_PROMPT "\n");
                    break;
                }

                if ((itemPtr = enqueue(&queue, itemPtr, REAR)) != NULL) {
                    printf("Added " ITEM_FORMAT "\n", *itemPtr);
                } else {
                    fprintf(stderr, "%s: Error allocating memory to queue.\n", basename(av[0]));
                    return EXIT_FAILURE;
                }
                break;
            }
            case PRINT:
            {
                printf("%d Items currently in the queue:\n", queueSize(queue));
                printQueue(queue, stdout);
                break;
            }

            case QUIT:
            {
                done = 1;
                break;
            }


            default:
            {
                fprintf(stderr, "Invalid choice entered");
                break;
            }
        }
    }

    printf("%d Items remaining in the queue:\n", queueSize(queue));
    printQueue(queue, stdout);


    return EXIT_SUCCESS;
}

