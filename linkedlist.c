#include <stdio.h>
#include <stdlib.h>

/* struct node */
typedef struct _Node{
    int value;
    struct _Node* next;
}Node;

/* struct linkedlist */
typedef struct _List{
    int listNum;
    Node* head;
}List;

void insert(List* linkedlist, int value, int position);
void delete(List* linkedlist, int position);
void init(List* linkedlist);
Node* search(List* linkedlist, int value);
void print_list(List* lptr);

void insert(List* linkedlist, int value, int position){
    //check the position of the node if it's out of bound
    if(position < 1 || position > linkedlist->listNum+1){
        printf("position out of bound\n");
        exit(1);
    }
    //creating new node
    Node* nNode = (Node*) malloc(sizeof(Node*));
    nNode->value = value;
    //when the node is added in the front (position starts from 1)
    if(position == 1){
        nNode->next = linkedlist->head->next;
        linkedlist->head = nNode;
    }
    //when the node is not added in the front
    else{
        int i;
        Node* tmp = linkedlist->head;
        //position = position - 1
        for(i = 0; i < position-1; i++){
            tmp = tmp->next;
        }
        //position = position
        nNode->next = tmp->next;
        tmp->next = nNode;
    }
    linkedlist->listNum++;
}

/* initiate linkedlist */
void init(List* linkedlist){
    linkedlist->listNum = 0;
    linkedlist->head = NULL;
}

void delete(List* linkedlist, int position){
    if(position < 1 || position > linkedlist->listNum+1){
        printf("position out of bound\n");
        exit(1);
    }
    
    Node* tmp = linkedlist->head;
    /* when position equals to 1 */
    if(position == 1){
        linkedlist->head = tmp->next;
        free(tmp);
    }
    /* position other than 1 */
    else{
        int i;
        for(i = 0; i < position-1; i++){
            tmp = tmp->next;
        }
        Node* tmp2 = tmp->next;
        tmp->next = tmp2->next;
        tmp2->next = NULL;
        free(tmp2);
    }
    linkedlist->listNum--;
}

Node* search(List* linkedlist, int value){
    Node* tmp = linkedlist->head;
    /* iterates till second last of the node in the list */
    while(tmp->next != NULL){
        if(tmp->value == value){
            return tmp;
        }
        else {
            tmp = tmp->next;
        }
    }
    /* check the last node in the list */
    tmp = tmp->next;
    if(tmp->value == value){
        return tmp;
    }
    else{
        printf("cannot find this value in this linked list \n");
        return NULL;
    }
}
void print_list(List* lptr){
	Node* tmp = lptr->head;
	printf("List value: ");
	while(tmp != NULL){
		printf("%d ",tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
	printf("Total: %d value(s)\n",lptr->listNum);
}

int main(){
    List* mylist = (List*)malloc(sizeof(List));
	init(mylist);

	insert(mylist,3,1);
	insert(mylist,4,2);
	insert(mylist,5,3);
	insert(mylist,6,4);
	insert(mylist,7,5);
	insert(mylist,8,6);
	insert(mylist,9,7);
	insert(mylist,3,3);
	print_list(mylist);
    
    return 0;
}