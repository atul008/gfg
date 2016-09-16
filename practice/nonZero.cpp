#include<stdio.h>
int main(){
    int n,a,count=0,max=-1,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        if(a==0){
            max = (max<count)?count:max;
            count=0;
        } else {
            count++;
        }
    }
    max = (max<count)?count:max;
    printf("%d\n",max);
return 0;
}
