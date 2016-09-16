#include <iostream>
#include <list>

using namespace std;

typedef struct node {
	int data;
	struct node* left,*right;	
} node ;


void display(list<int>& ll){
	list<int>::iterator it;

	for(it = ll.begin(); it != ll.end() ;it++){
		cout << *it << " " ;
	
	}
	cout << endl;
}

node* makeBst(list<int>& ll, int size,int offset){
	list<int>::iterator it;
	int mid,l,r,count = 0 ;
	if(size == 0)
		return NULL;
		
	if(size % 2 == 0){
		mid = offset + size/2 -1;
		l = size/2-1;
		r = l+1;
	 } else {
	 
 		mid = offset + size/2;	 		
	 	l = size/2;
	 	r = l;
	 }
	
	for(it = ll.begin();it != ll.end() && count < mid;it++)
		count++;
	 
	node *n = new node;
	n->data = *it;
	n->left = makeBst(ll,l,offset);
	n->right = makeBst(ll,r,offset + l + 1);

	return n;
} 

void inorder(node *root){

	if(root == NULL)
		return ;
		
	inorder(root->left);
	cout << root->data << " \n";
	inorder(root->right);

}

void postorder(node *root){
	if(root == NULL)
		return ;
		
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " \n";
	
}

int main(){
	
	list<int> ll;
	list<int>::iterator it;
	ll.push_back(10);
	ll.push_back(20);
	ll.push_back(30);
	ll.push_back(40);
	ll.push_back(50);
	
	
	display(ll);
	
	node *root = NULL;
	root = makeBst(ll,ll.size(),0);
	cout << "Inorder Traversal \n";
	inorder(root);
	cout << "Postorder Traversal \n";
	postorder(root);
	cout << endl;	
return 0;
}

