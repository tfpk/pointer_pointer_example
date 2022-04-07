#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void print_list(struct node *head) {
    if (head == NULL) {
        printf("X\n");
        return;
    }
    printf("%d -> ", head->data);
    print_list(head->next);
}


void free_list(struct node *head) {
    if (head == NULL) {
        return;
    }
    free_list(head->next);
    free(head);
}

// Use pointer pointers to insert negative one into a list
void insert_negative_one_at(struct node **linked_list_pointer, int insert_at) {
    int i = 0;
    while (i < insert_at && *linked_list_pointer == NULL) {
        // This gets the pointer to the head of the list, gets it's next field, and gets a pointer to that field.
        struct node *linked_list_node = *linked_list_pointer;

        // linked_list_pointer is now a pointer to the pointer to the next node.
        linked_list_pointer = &(linked_list_node->next);
        i++;
    }

    // Create a node to insert.
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = -1;

    // First, we will make the `new_node`'s next pointer point at the actual node that our pointer points to.
    new_node->next = *linked_list_pointer;

    // Now, we must make the "next" pointer we are pointing at point at `new_node`
    *linked_list_pointer = new_node;

}

#define SIZE 10

int main(void) {

    // Create a linked list with these elements
    int data[SIZE] = {1,2,3,4,5,6,7,8,9,10};

    struct node *linked_list = NULL;

    int data_i = 0;
    while (data_i < SIZE) {
        struct node *tmp = malloc(sizeof(struct node));
        tmp->data = data[data_i];
        tmp->next = linked_list;
        linked_list = tmp;
        data_i++;
    }
    print_list(linked_list);

    // Find out where the user wants to insert the element at.
    int insert_at = 0;
    printf("Which element do you want to insert -1 at: ");
    scanf("%d", &insert_at);

    insert_negative_one_at(&linked_list, insert_at);

    print_list(linked_list);

    free_list(linked_list);

    return 0;
}
