#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;

typedef struct Box{
    int h,w,d;
}Box;

int compare(const void *a, const void *b){
    return  ( ( (*(Box *)b).w  * (*(Box *)b).d )- ( (*(Box *)a).w * (*(Box *)a).d) );
}

int stackBoxes(Box *box,int n){
    Box boxes[n*3];
    int index =  0;

    for(int i=0;i<n;i++){

        boxes[index] = box[i];
        index++;
        boxes[index].h = box[i].w;
        boxes[index].w = min(box[i].h , box[i].d);
        boxes[index].d = max(box[i].h ,box[i].d);
        index++;

        boxes[index].h = box[i].d;
        boxes[index].w = min(box[i].h , box[i].w);
        boxes[index].d = max(box[i].h ,box[i].w);

        index++;
    }
    n = n*3;
    qsort(boxes,n,sizeof(boxes[0]),compare);

    int msh[n];

    for(int i =0 ;i<n;i++){
     msh[i] = boxes[i].h;
    }

    for(int i =1 ;i<n;i++){
        for(int j = 0;j<i;j++){
            if(boxes[i].w < boxes[j].w && boxes[i].d < boxes[j].d &&  msh[i] < msh[j] + boxes[i].h )
                msh[i] = msh[j] + boxes[i].h;
        }
    }

    int max = -1;
    for(int i = 0 ;i <n;i++)
        if(max < msh[i])
            max = msh[i];

    return max;
}

int main(){

    Box box[] = {{4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32}};
    int n = sizeof(box)/sizeof(box[0]);
    cout << "Max height : " << stackBoxes(box,n) << endl ;
    return 0;

}

