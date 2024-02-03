#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

void traverse(struct node* head);
struct node* create_list(struct node* head);
struct node* add_to_empty(struct node* head, int data);
struct node* insert_begin(struct node* head, int data);
struct node* insert_end(struct node* head, int data);
struct node* insert_given(struct node* head, int data, int position);
struct node* delete_begin(struct node* head);
struct node* delete_end(struct node* head);
struct node* delete_given(struct node* head, int position);

int main() {
    struct node* head = NULL;
    int option, data, position;

    do {
        printf("What operation do you want to perform? Select Option number. Enter 0 to exit.\n");
        printf("1. Create List\n");
        printf("2. Traverse List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Given Position\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete at Given Position\n");

        scanf("%d", &option);

        switch (option) {
            case 0:
                printf("Exiting the program.\n");
                break;
            case 1:
                head = create_list(head);
                break;
            case 2:
                traverse(head);
                break;
            case 3:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insert_begin(head, data);
                break;
            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insert_end(head, data);
                break;
            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                head = insert_given(head, data, position);
                break;
            case 6:
                head = delete_begin(head);
                break;
            case 7:
                head = delete_end(head);
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = delete_given(head, position);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

    } while (option != 0);

    return 0;
}

// (remaining functions unchanged)


void traverse(struct node* head)
{
    struct node* temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

struct node* create_list(struct node* head)
{
    int data,n;
    
    printf("enter number of node:");
    scanf("%d",&n);
    
    printf("enter data of node 1:");
    scanf("%d",&data);
    
    if(head==NULL)
    {   
        head = add_to_empty(head,data);
        // return head;
    }
    for(int i = 2;i<=n;i++)
    {
        printf("enter data of node %d:",i);
        scanf("%d",&data);
        
        head = insert_end(head,data);
    }
    return head;
}

struct node* add_to_empty(struct node* head,int data)
{
    struct node* current = (struct node*)malloc(sizeof(struct node));
    current->next = NULL;
    current->data = data;
    current->prev = NULL;
    head = current;
    return head;
}

struct node* insert_begin(struct node* head,int data)
{
    struct node* current = (struct node*)malloc(sizeof(struct node));
    current->data = data;
    current->prev = NULL;
    current->next = head;
    head->prev = current;
    head = current;
    return head;
}

struct node* insert_end(struct node* head,int data)
{
    struct node* current = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = current;
    current->prev = temp;
    current->data = data;
    current->next = NULL;
    return head;
}

struct node* insert_given(struct node* head,int data,int position)
{
    struct node* current = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    struct node* q = head->next;
    if(position==1)
    {
        head = insert_begin(head,data);
        return head;
    }
    
    
    int i = 1;
    while(i!=position-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    if(p->next==NULL)
    {
        head = insert_end(head,data);
        return head;
    }
    else{
    current->data = data;
    current->next = q;
    q->prev = current;
    p->next = current;
    current->prev = p;
    }
    
    return head;
}
    
struct node* delete_begin(struct node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
    } else {
        struct node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        printf("Deleted node from the beginning.\n");
    }
    return head;
}

struct node* delete_end(struct node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        if (temp->prev != NULL) {
            temp->prev->next = NULL;
        } else {
            head = NULL; // Only one node in the list
        }
        free(temp);
        printf("Deleted node from the end.\n");
    }
    return head;
}

struct node* delete_given(struct node* head, int position)
{
    if(position == 1)
    {
        head = delete_begin(head);
    }
    else
    {
        struct node* p = head;
        struct node* q = head->next;
        int i = 1;
        while(i!=position-1)
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next = q->next;
        q->next->prev = p;
        free(q);
    }
    return head;
}

