#include <stdio.h>

#include <stdlib.h>

/* Definition for singly-linked list */
typedef struct listint {
	int data;
	struct listint* next;
} listint_t;

/* Function to check if there is a cycle in the linked list */
int check_cycle(listint_t *list) {
	listint_t *slow = list, *fast = list;
	
	while (slow != NULL && fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

        /* If there is a cycle, the fast pointer will eventually meet the slow pointer */
        if (slow == fast) {
            return 1;  /* Cycle detected */
        }
    }

    return 0;  
}

/* Example usage */
int main() {

    return 0;
}
