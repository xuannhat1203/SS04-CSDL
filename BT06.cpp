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
void deleteRandom(Node** head, int position) {
    if (*head == NULL) {
        printf("Danh sách r?ng, không th? xóa\n");
        return;
    }
    if (position == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        return;
    }
    Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Vi tri xoa khong hop le\n");
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
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
	int number;
	int position;
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
	printf("\nNhap vi tri muon xoa: ");
	scanf("%d",&position);
	deleteRandom(&head,position);
	printf("\nSau khi xoa\n");
	printList(head);
}

