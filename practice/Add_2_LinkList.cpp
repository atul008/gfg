#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node* next;

} node;

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
void addList(node*,node*,node*,int);
void appendList(node* head3,node* curr,int carry){
//	cout << "Append List\n";
	int sum,new_carry;
//	if(curr == NULL && carry != 0)
//		addList(NULL,NULL,head3,carry);
	 if( curr == NULL && carry == 0){
	//	cout << "Returning from append \n";
		return ;
	}	
	node *n = new node;
	if(curr != NULL)
		sum = curr->data + carry;
	else
		sum = carry; 
		
	new_carry = sum/10; 
	cout << "sum :" << sum << endl;
	cout << "carry :" << new_carry << endl;
	sum = sum % 10;
	n->data = sum;
	n->next = NULL;
	head3->next = n;
	head3 = n;
	if(curr != NULL)
		appendList(head3,curr->next,new_carry);
	else
		appendList(head3,curr,new_carry);
}

void addList(node* head1,node* head2,node* head3,int carry){
	
	int sum,new_carry ;
	if(head1 == NULL && head2 == NULL && carry == 0){
		cout << "Case1 :\n";
		return;
	}
	else if(head1 == NULL && head2 == NULL){
		cout << "Case2 :\n";
		node *n = new node;
		sum = carry;
		sum = sum % 10;
		n->data = sum;
		n->next = NULL;
		head3->next = n;
		head3 = n;
		return ;
	}  else if(head1 == NULL){
		cout << "Case3 :\n";
		appendList(head3,head2,carry);
	
	}   else if(head2 == NULL){
		cout << "Case4 :\n";
		appendList(head3,head1,carry);
	
	}else{
		cout << "Case5 :\n";
		node *n = new node;
		sum = head1->data + head2->data + carry;
		cout << "sum :" << sum << endl;
		new_carry = sum/10;
		cout << "carry :" << new_carry << endl;
		sum = sum % 10;
		n->data = sum;
		n->next = NULL;
		head3->next = n;
		head3 = n;
		addList(head1->next,head2->next,head3,new_carry);	
	}


}

int main(){

	node* head1=NULL,*head2=NULL,*head3 = NULL ;
	cout << "LL created \n";
	addNodeBeg(&head1,1);
	addNodeBeg(&head1,2);
	addNodeBeg(&head1,3);
	cout << "Node added\n";
	display(&head1);


	cout << "LL created \n";
	addNodeBeg(&head2,7);
	addNodeBeg(&head2,8);
	addNodeBeg(&head2,9);
	addNodeBeg(&head2,9);
	addNodeBeg(&head2,9);
	cout << "Node added\n";
	display(&head2);

	reverseList(&head2);
	reverseList(&head1);
	cout << "Reversed Lists :\n";
	display(&head2);
	display(&head1);
	
	addNodeBeg(&head3,0);
	addList(head1,head2,head3,0);
	head3 = head3->next;
	reverseList(&head3);
	cout << "Added list: \n";
	display(&head3);
	return 0;
}
