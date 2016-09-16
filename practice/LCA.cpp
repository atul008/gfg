 #include<iostream>
 #include<algorithm>
 #include<vector>
 using namespace std;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 #define sz(a) int((a).size())
 #define pb push_back
 #define all(c) (c).begin(),(c).end()
 #define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
 #define present(c,x) ((c).find(x) != (c).end())
 #define cpresent(c,x) (find(all(c),x) != (c).end())
 #define rep(a,i) for(int i =0; i<a; i++)
 #define rep1(a,i) for(int i=1; i<a ;i++)
 #define repA2B(a,b,i) for(int i=a; i<=b; i++)

typedef struct node {
    int data;
    node* left;
    node* right;
 } node;

 node* newNode(int data){
    node* n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
 }

 void inorder(node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
 }

 void preorder(node* root){
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
 }

 void postorder(node* root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
 }


bool findPath(node* root ,vi& path , int k){
    if(root == NULL) return false;

    path.push_back(root->data);

    if( (root->left && findPath(root->left,path,k) ) || (root->right && findPath(root->right,path,k))) return true;

    path.pop_back();
    return false;
}

//Finding  LCA ,Assuming that both node are present in the tree.

node* lca(node* root,int n1,int n2){

    if(root == NULL) return NULL;

    if((root->data == n1) || (root->data == n2) ) return root;

    node *left_lca,*right_lca;

    left_lca = lca(root->left,n1,n2);
    right_lca = lca(root->right,n1,n2);

    if(left_lca && right_lca) return root;

    return (left_lca != NULL)?left_lca : right_lca;
}


 int main(){
    node* root;
    root = newNode(5);
    root->left = newNode(8);
    root->right = newNode(2);
    root->right->left = newNode(20);
    root->left->left = newNode(3);
    root->left->right = newNode(10);
    root->left->left->left = newNode(15);
    root->left->left->right = newNode(11);
    root->left->right->left = newNode(25);
    inorder(root); cout << endl;
   // preorder(root); cout << endl;
    //postorder(root); cout << endl;
    node* LCA = lca(root,11,25);
    cout << "LCA :  "<< LCA->data << endl;
 return 0;
 }
