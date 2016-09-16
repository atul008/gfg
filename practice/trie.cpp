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

typedef struct vertex{
    char data;
    int words,prefixes;
   struct vertex* edges[26];
}vertex;

class Trie{

    public:
        vertex* root;
        Trie(){
            root = initialize('@');
        }
        vertex* initialize(char);
        void addWord(vertex*,string,int);
        int countWords(vertex*,string,int);
        int countPrefixes(vertex*,string,int);
};

 vertex* Trie::initialize(char c){
    vertex* v = new vertex;
    v->data = c;
    v->words = 0;
    v->prefixes = 0;
    rep(26,i)  v->edges[i] = NULL;
    return v;
}

void Trie::addWord(vertex* root,string word,int index){
    if(root == NULL)
        return;
    else if(index == word.length()){
        root->words++;
        return;
    }else{
        root->prefixes++;
        char c = word[index];
        if(root->edges[c-'a'] == NULL){
            root->edges[c-'a'] = initialize(c);
        }
   //     cout<< "adding : " << word[index] << endl;;
        addWord(root->edges[c-'a'],word,++index);
    }
}

int Trie::countWords(vertex* v,string word,int index){
   if(v == NULL)
        return 0;
    else if(index == word.length())
        return v->words;
    else{
        char c = word[index];
        return countWords(v->edges[c-'a'],word,++index);
    }
}

int Trie::countPrefixes(vertex* v,string word,int index){
    if(v == NULL)
        return 0;
    else if(index == word.length()-1)
        return v->prefixes;
    else {
      char c = word[index];
      return countPrefixes(v->edges[c-'a'],word,++index);
    }
}


 int main(){
    Trie t;
    string s("dog"),str("doggy");
    t.addWord(t.root,s,0);
  // cout << t.countPrefixes(t.root,s,0) << endl;
   // cout << t.countWords(t.root,s,0) << endl;
    t.addWord(t.root,str,0);

    cout << t.countPrefixes(t.root,str,0) << endl;
    cout << t.countWords(t.root,str,0) << endl;
 return 0;
 }

