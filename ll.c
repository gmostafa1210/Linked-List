
#include<stdio.h>
#include<stdlib.h>


/*Node*/
struct Node{
    int data;
    struct Node *next;
}*node;

/*Head*/
struct Head{
    int count;
    struct Node *p;
}*head;

/*Create Head*/
void create_head(){
    head = (struct Head*)malloc(sizeof(struct Head));
    head->count = 0;
    head->p = NULL;
}

/*Create Node*/
void create_node(){
    node = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Data: ");
    scanf("%d",&node->data);
    node->next = NULL;
}

/*Display*/
void display(){
    struct Node *temp;
    temp = head->p;
    printf("\nDisplay:\n");
    printf("-------\n");
    while(temp != NULL){
        printf("Data: %d\n", temp->data);
        temp = temp->next;
    }
    printf("-------\n");
}

/*Insert First*/
void insert_first(){
    create_node();
    node->next = head->p;
    head->p = node;
    head->count++;
    display();
}

/*insert Last*/
void insert_last(){
    struct Node *temp;
    if(head->count==0){
        insert_first();
    }
    else{
        create_node();
        temp = head->p;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = node;
        head->count++;
        display();
    }
}

/*Insert Any*/
void insert_any(){
    if(head->count==0){
        insert_first();
    }
    /*else if(head->count==1){
        insert_first();
    }*/
    else{
        struct Node *temp;
        int n, flag = 0;
        printf("The number after which I want to insert data: ");
        scanf("%d",&n);
        temp = head->p;
        while(temp != NULL){
            if(temp->data == n){
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if(flag == 1){
            create_node();
            node->next = temp->next;
            temp->next = node;
            head->count++;
        }
        else{
            printf("\nInvalid Input!\n");
        }
        display();
    }
}

/*Delete First*/
void delete_first(){
    if(head->count == 0){
        printf("\nNo data for delete.\n");
    }
    else{
        struct Node *temp;
        temp = head->p;
        head->p = temp->next;
        free(temp);
        head->count--;
    }
    display();
}

/*Delete Last*/
void delete_last(){
    if(head->count == 0){
        printf("\nNo data for delete.\n");
    }
    else if(head->count == 1){
        delete_first();
    }
    else{
        struct Node *temp;
        int c = 1;
        temp = head->p;
        while(c < head->count - 1){
            temp = temp->next;
            c++;
        }
        free(temp->next);
        temp->next = NULL;
        head->count--;
    }
    display();
}

/*Delete Any*/
void delete_any(){
    struct Node *temp;
    struct Node *temp1;
    temp = head->p;
    int n, flag = 0;
    printf("\nData I want to delete: ");
    scanf("%d",&n);
    if (temp->data == n){
        delete_first();
    }
    else{
        while(temp->next != NULL){
            if(temp->next->data == n){
                temp1 = temp->next;
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if(flag == 1){
            temp->next = temp->next->next;
            free(temp1);
            head->count--;
        }
        else if(flag == 0){
            printf("\nData not found!\n");
        }
    }
    display();
}

/*Search*/
void search(){
    struct Node *temp;
    int n,c = 1, flag = 0;
    printf("The data I want to search: ");
    scanf("%d",&n);
    temp = head->p;
    while(temp != NULL){
        if(temp->data == n){
            flag = 1;
            break;
        }
        temp = temp->next;
        c++;
    }
    if(flag == 1){
        display();
        printf("\nPosition of the data is: %d\n", c);
    }
    else{
        display();
        printf("\nThe data is not here.\n");
    }
}

int main(){
    printf("Linked List\n");
    create_head();
    while(1){
        int m, i, d;
        printf("\n");
        printf("Press 1 for insert.\n");
        printf("Press 2 for delete.\n");
        printf("Press 3 for search.\n");
        printf("Press 0 for close program.\n");
        printf("Your option: ");
        scanf("%d",&m);
        if(m == 0){
            printf("Thank You!\n");
            break;
        }
        else if(m == 1){
            printf("Press 1 for insert first.\n");
            printf("Press 2 for insert any.\n");
            printf("Press 3 for insert last.\n");
            printf("Your option: ");
            scanf("%d",&i);
            if(i == 1){
                insert_first();
            }
            else if(i == 2){
                insert_any();
            }
            else if(i == 3){
                insert_last();
            }
        }
        else if(m == 2){
            printf("Press 1 for delete first.\n");
            printf("Press 2 for delete any.\n");
            printf("Press 3 for delete last.\n");
            printf("Your option: ");
            scanf("%d",&d);
            if(d == 1){
                delete_first();
            }
            else if(d == 2){
                delete_any();
            }
            else if(d == 3){
                delete_last();
            }
        }
            else if(m == 3){
                search();
            }
            else{
                printf("Invalid input!.\n");
                scanf("%d",&m);
            }
        }
    return 0;
}
