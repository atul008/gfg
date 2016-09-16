#include "ll.h"
void addNodeBeg(node** head,int item){

		node* n = new node;
		n->data = item;
		n->next = *head;
		*head = n;
}

void display(node** head){
	node* temp = *head;
	while(temp){

		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;

}
void reverseList(node** head){
	node *curr ,*prev,*nxt;
	if(*head ==NULL)
		return ;
		
	prev = NULL;
	curr = *head;
	nxt = curr->next;
	
	while(curr != NULL){
		curr->next = prev;
		
		prev = curr ;
		curr = nxt;
		if(nxt != NULL) 
			nxt = nxt->next;
	}
	*head = prev;
}

