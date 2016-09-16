#include "ll.h"
void addNodeBeg(node** head,int item){

		node *n = new node;
		n->data = item;
		n->next = *head;
		*head = n;
}
void addNodeEnd(node** head ,int item){
		node *n = new node;
		n->data = item;
		n->next = NULL;
		
		
		if(*head == NULL){
		   *head = n;
		   return ;
		}
		node *temp = *head;
		while(temp->next){
			temp = temp->next;
		}
		temp->next = n;
		
}
void addNodeDown(node** head ,int item){
		node *n = new node;
		n->data = item;
		n->down = NULL;
		
		node *temp = *head;
		while(temp->down){
			temp = temp->down;
		}
		temp->down = n;
		
}

void display(node** head){
	node* temp = *head;
	while(temp){
	cout << temp->data << " ";
		temp = temp->next;
	}
}

void displayAll(node** head){
	node* temp = *head;
	while(temp){
		displayDown(&temp);
		temp = temp->next;
	}
}

void displayDown(node** head){
	node* temp = *head;
	if(temp == NULL){
	  return;
	  }
	cout << "Parent Node :" << temp->data << endl;
	temp = temp->down;
	while(temp){

		cout << temp->data << endl;
		temp = temp->down;
	}


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

void mergeList(node **head1 ,node **head2){
	node *head3 = NULL,*temp1 ,*temp2;
	
	temp1 = *head1;
	temp2 = *head2;
	addNodeEnd(&head3,0);
	if(temp1 == NULL && temp2 == NULL)
		return ;
		
	while(temp1 !=NULL && temp2 != NULL){
		//cout << "Case 1\n";
		if(temp1->data <= temp2->data){
			addNodeDown(&head3,temp1->data);
			temp1 = temp1->down; 
		} else {
			addNodeDown(&head3,temp2->data);
			temp2 = temp2->down;
		}
	} 
	
	if(temp1 !=NULL){
		//cout << "Case 2 \n";
		while(temp1 !=NULL){
			addNodeDown(&head3,temp1->data);
			temp1 = temp1->down; 
		}
	}
	
	if(temp2 !=NULL){
		//cout << "Case 3 \n";
		while(temp2 !=NULL){
			addNodeDown(&head3,temp2->data);
			temp2 = temp2->down; 
		}
	}
	head3 = head3->down;
	*head1 = head3;
	(*head1)->next = (*head2)->next;  

}



