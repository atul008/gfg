#include "ll.h"
int main(){

	node *head1=NULL;
	cout << "LL created \n";
	addNodeEnd(&head1,1);
	addNodeEnd(&head1,2);
	addNodeEnd(&head1,3);
	
	cout << "Node added\n";
	
	
	addNodeDown(&head1,3);
	addNodeDown(&head1,5);
	addNodeDown(&head1,7);
	
	addNodeDown(&(head1->next),4);
	addNodeDown(&(head1->next),6);
	addNodeDown(&(head1->next),8);
	
	addNodeDown(&(head1->next->next),11);
	addNodeDown(&(head1->next->next),14);
	addNodeDown(&(head1->next->next),19);
	
	cout << "Node added Down\n";
	displayAll(&head1);
	cout << "Flattened List\n";
	while(head1->next != NULL){
		mergeList(&head1,&(head1->next));
	}

	displayAll(&head1);
	return 0;
}
