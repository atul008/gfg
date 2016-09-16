 #include<iostream>
 #include<algorithm>
 #include<vector>
 #include<cstring>
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
 #define SIZE 20
 char* mulStringUtil(string s1,char c,char s3[]){
    int l1 = s1.length();

    rep(l1/2,i) swap(s1[i],s1[l1-1-i]);

//    cout << s1 << endl << s2 << endl;
    int carry = 0,temp = 0;
    int k =0;
    rep(l1,i) {
            temp = static_cast<int>((s1[i]-'0') * (c-'0')) + carry;
            carry = temp/10;
            temp = temp%10;
            s3[k++] = static_cast<char>('0' + temp);
    }
    while(carry > 0 ){
        s3[k++] = static_cast<char>('0'+ carry%10);
        carry /=10;
    }

    s3[k] = '\0';
    int l3 = strlen(s3);
    rep(l3/2,i) swap(s3[i],s3[l3-1-i]);

  return s3;
 }

 void add(char s1[],char s2[]){
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    rep(l1/2,i) swap(s1[i],s1[l1-1-i]);
    rep(l2/2,i) swap(s2[i],s2[l2-1-i]);
    int carry = 0,temp = 0;
  //  cout << "l1,l2 : " << l1 << ","<<l2 << endl;
    int len = max(l1,l2);
    rep(len,i){
            if(i < l1 && i < l2){
                temp = static_cast<int>( (s1[i]-'0') + (s2[i]-'0') + carry);
              //  cout << 1 << endl;
            } else if (i >= l1 && i < l2){
                temp = static_cast<int>(s2[i]-'0' + carry);
                //cout << 2 <<" " << temp;
            } else if(i>=l2 && i<l1){
                temp = static_cast<int>(s1[i]-'0' + carry);
                //cout << 3 << endl;
            }
            carry = temp/10;
            temp %= 10;
            s1[i] = static_cast<char>(temp + '0');

       //     cout <<" s1 " <<  s1[i] << endl;
    }
    if(carry > 0){
        s1[len++] = static_cast<char>(carry + '0');
    }

    rep(len/2,i) swap(s1[i],s1[len-1-i]);
    s1[len] = '\0';
    //rep(len,i) cout << s1[i] << " ";
  //  cout << s1 << endl ;
 }

 void mulString(string s1, string s2, char s3[]){
        int l2 = s2.length();
        rep(l2/2,i) swap(s2[i],s2[l2-1-i]);
        char temp[SIZE];
        int pass = 0;
        rep(l2,i) {
            mulStringUtil(s1,s2[i],temp);
          //  cout << "temp : " << temp << endl;
            int len = strlen(temp);

            rep1(pass+1,j) {
                temp[len-1+j] = '0';
            }
            temp[len+pass] = '\0';
           // cout << "temp : " << temp << endl;
            add(s3,temp);
         //   cout << "s3 : " << s3 << endl;
            pass++;
        }

 }

 int main(){
    string s1("999999"),s2("999999");
   // char s4[3] = {'1','0','0'};
   // char s5[3] = {'2','0','0'};;
   // add(s4,s5);
   // cout << s4 << endl;
    char s3[SIZE];
    s3[0] = '\0';
    mulString(s1,s2,s3);
    cout << s3 << endl;

 return 0;
 }

