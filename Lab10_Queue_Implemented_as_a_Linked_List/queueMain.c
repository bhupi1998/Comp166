/* Tests for Queue library.
 *
 * Dale Shpak
 * March 25, 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef enum {QUIT=-1, ENQUEUE, DEQUEUE, PRINT, N_CHOICES} Choice;

int main(int ac, char *av[]) {
    Queue queue = {NULL, NULL, 0};

    int done = 0;
    while (!done) {
        Choice choice;
	int nValid;
        do {
            printf("Enter %d to add to queue, %d to remove, or %d to print contents "
		   "(%d to quit): ", ENQUEUE, DEQUEUE, PRINT, QUIT);
            nValid = scanf("%d", &choice);
	    while (getchar() != '\n') { } // Get rid of rest of line
        } while (nValid != 1 || choice < QUIT || choice >= N_CHOICES);


        switch (choice) {
	case DEQUEUE: {
	    ItemType *itemPtr;
	    if ((itemPtr = dequeue(&queue)) != NULL) {
		printf("Removed " ITEM_FORMAT "\n", *itemPtr);
		free (itemPtr);
	    } else {
		printf("Queue is empty\n");
	    }
	    break;
	}

	case ENQUEUE: {
	    ItemType *itemPtr = (ItemType *) malloc (sizeof(ItemType));
	    if (itemPtr == NULL) {
		fprintf(stderr, "%s: Error allocating memory for item.\n", av[0]);
		return EXIT_FAILURE;
	    }

	    printf ("Enter " ITEM_PROMPT ": ");
	    if (scanf(ITEM_FORMAT, itemPtr) != 1) {
		fprintf(stderr, "Unable to read " ITEM_PROMPT "\n");
		break;
	    }

	    if ((itemPtr = enqueue(&queue, itemPtr)) != NULL) {
		printf("Added " ITEM_FORMAT "\n", *itemPtr);
	    } else {
		fprintf(stderr, "%s: Error allocating memory to queue.\n", basename(av[0]));
		return EXIT_FAILURE;
	    }
	    break;
	}
	    
	case PRINT: {
	    printf ("%d Items currently in the queue:\n", queueSize(queue));
	    printQueue (queue, stdout);
	    break;
	}
	    
	case QUIT: {
	    done = 1;
	    break;
	}


	default: {
	    fprintf(stderr, "Invalid choice entered");
	    break;
	}
        }
    }

    printf ("%d Items remaining in the queue:\n", queueSize(queue));
    printQueue (queue, stdout);


    return EXIT_SUCCESS;
}

