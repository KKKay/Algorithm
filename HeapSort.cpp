//
//  main.cpp
//  Heap
//
//  Created by cool kid on 2020/5/6.
//  Copyright © 2020 cool kid Wangyuhan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;


//通过引用调用的方式传递真实值，并没有将a，b拷贝到形参，而是直接进行传递。可节约时间。
void swap(int &a,int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void CreateHeap(int arr[],int index){
    int father;

    while(index!=0){
        father = (index-1)/2;
        if(arr[father]<arr[index]){
            swap(arr[father],arr[index]);
        }
        index = father;
    }

}

void TuneHeap(int arr[],int index,int size){
    int leftson = index*2+1;
    int rightson = leftson+1;

    if(index*2+2<=size-1){
        if(arr[rightson]>=arr[leftson]&&arr[rightson]>arr[index]){
            swap(arr[index],arr[rightson]);
        }
        else if(arr[leftson]>=arr[rightson]&&arr[leftson]>arr[index]){
            swap(arr[index],arr[leftson]);
        }
    }
    else if(index*2+1==size-1){
        if(arr[leftson]>arr[index]){
            swap(arr[index],arr[leftson]);
        }
    }

}

void HeapSort(int arr[],int size){

    //int size = sizeof(arr)/4;
    int count = size;

    if(size<=1) return;
    else{
        //cout << size << endl;
        for(int i=0;i<size;i++){
            CreateHeap(arr, i);
        }

        for(int j=0;j<count-1;j++){
            swap(arr[0],arr[size-1]);
            size--;
            for(int k=0;k<size;k++){
                TuneHeap(arr, k, size);
            }
        }
    }

}

int main(int argc, const char * argv[]) {
    int arr[] = {1,6,4,7,6,2,347,2,546,8,32,67,347};
    //cout << sizeof(arr)/4 << endl;
    int size = sizeof(arr)/4;

    HeapSort(arr,size);

    for(int i=0;i<size;i++){
        cout << arr[i] << endl;
    }

    return 0;
}
