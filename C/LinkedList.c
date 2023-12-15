#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int val;
        struct Node *next;
}  Node;
typedef struct LinkedList{
	Node *head;
}  LinkedList; 

void insert(LinkedList *LL, int val){
	Node *temp = (Node *)(malloc(sizeof(Node)));
	temp->val  = val;
	temp->next = LL->head;
	LL->head   = temp;
}
void insertAtEnd(LinkedList *ll, int val){
	Node *temp = (Node *)(malloc(sizeof(Node)));
	temp->val = val;
	Node *temp1 = ll->head;
	while(temp1->next!=NULL){
		temp1=temp1->next;
	}
	
}
	
void print(LinkedList *ll){
	Node *temp = ll->head;
	while(temp->next!=NULL){
		printf("%d ",temp->val);
		temp = temp->next;
	}
}

int main(){
	LinkedList ll;
	insert(&ll,1);
	insert(&ll,2);
	insert(&ll,3);
	insert(&ll,4);
	insert(&ll,5);
	insert(&ll,6);
	print(&ll);
}



