#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
} node;

class linkedList{
    private:
            node** head;

    public:

        linkedList(){
            *head = NULL;
        }
        node* getHead(){
            return *head;
        }
        void add(int d){
             node* t = new node;
             t->data = d;
             t->next = *head;
             *head = t;
        }

        void disp(){
            node* t = *head;
            while(t != NULL){
                cout << t->data << " ";
                t = t->next;
            }
            cout << endl;
        }

        void reverse(){
            node *pre,*cur,*nxt;
            pre = NULL;
            cur = *head;
            while(cur != NULL){
                nxt = cur->next;
                cur->next =pre;
                pre = cur;
                cur = nxt;
            }
            *head = pre;
        }

       static node* midOfList(linkedList ll){
            node *s,*f;
            f = s = *(ll.head);
            while(f != NULL && f->next != NULL){
                s = s->next;
                f = f->next->next;
            }
            return s;
        }
};

int main(){
    linkedList ll;
    ll.add(5);
    ll.add(10);
    ll.add(15);
    ll.add(20);
    ll.disp();
    ll.reverse();
    ll.disp();
    node **mid;
    *mid = linkedList::midOfList(ll);
    cout << "mid : " << (*mid)->data << endl;
    return 0;
}
