#include "ll.h"
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

	
	return 0;
}
