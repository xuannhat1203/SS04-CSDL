#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;
Node* createNode(int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}
void inseartToStart(Node** head, int value){
	Node* newNode = createNode(value);
	if(value == 0){
	 	printf("Danh sach trong \n");
	}else{
		newNode->data = value;
		newNode->next = *head;
		*head = newNode;
	}
}
void printList(Node* head){
	Node *temp = head;
	while(temp != NULL){
		printf(" %d -> ", temp->data);
		temp = temp->next;
	}
	printf(" NULL");
}
int main(){
	int n;
	printf("Nhap so luong phan tu: ");
	scanf("%d",&n);
	int num;
	Node* head = NULL;
	for(int i=0;i<n;i++){
		printf("Nhap gia tri thu %d: ",i+1);
		scanf("%d",&num);
		inseartToStart(&head,num);
	}
	printList(head);
}

