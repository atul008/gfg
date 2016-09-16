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
    struct node* left;
    struct node* right;
 } node;

 node* newNode(int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
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



 int main(){
    node* root;
    root = newNode(5);
    root->left = newNode(8);
    root->right = newNode(2);
    root->right->left = newNode(20);
    root->right->left->right = newNode(24);
    root->left->left = newNode(3);
    root->left->right = newNode(10);
    root->left->left->left = newNode(15);
    root->left->left->right = newNode(11);
    root->left->right->left = newNode(25);

    inorder(root); cout << endl;
 //   preorder(root); cout << endl;
  //  postorder(root); cout << endl;

 return 0;
 }
