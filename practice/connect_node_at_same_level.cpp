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
    node* next;
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
 node* findNext(node* root){
    if(root == NULL) return NULL;
    if(root->left) return root->left;
    else if(root->right) return root->right;
    else if(root->next)
         findNext(root->next);
 }

 void connectNodes(node* root){
    if(root == NULL) return;

    if(root->left && root->right){
        root->left->next = root->right;
        root->right->next = findNext(root->next);
        connectNodes(root->left);
        connectNodes(root->right);
    }
    if(root->left && root->right == NULL){
        root->left->next = findNext(root->next);
        connectNodes(root->left);
    }

    if(root->left == NULL && root->right){
        root->right->next = findNext(root->next);
        connectNodes(root->right);
    }

 }
void printEachLevel(node* root){
    if(root == NULL) return ;

    int level = 0;
    node* temp;
    while(root != NULL){
        cout << "level : " << level << endl;
        temp = root;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        root = root->left;
        level++;
    }
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
    root->next = NULL;
    connectNodes(root);
    printEachLevel(root);
 return 0;
 }
