//
//  main.cpp
//  Merge
//
//  Created by cool kid on 2020/5/7.
//  Copyright © 2020 cool kid Wangyuhan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;



void Merge(int arr[],int l,int m,int r){
    
    int length = r-l+1;
    int help[length];
    int p1 = l;
    int p2 = m+1;
    
    //cout << l << " " << m << " " << r << endl;
    
    for(int i=0;i<length;i++){
        if(p1<=m && p2<=r){
            int small = arr[p1]<=arr[p2]?p1:p2;
            help[i] = arr[small];

            if(small==p1) p1++;
            else if(small==p2) p2++;
        }
        else if( p2<=r){
            help[i] = arr[p2++];
        }
        else if(p1<=m ){
            help[i] = arr[p1++];
        }
    }
    
    
    for(int j=0;j<length;j++){
        arr[l+j] = help[j];
        //cout << help[j] << " ";
    }
    //cout << endl;
}

void Divide(int arr[],int l,int r){
    //cout << arr[l] << " " << arr[r] << endl;
    int m = l+(r-l)/2;
    //cout << l << " " << m << " " << r << endl;
    if(l==r) return;
    Divide(arr, l, m);
    Divide(arr, m+1, r);
    Merge(arr,l,m,r);
}

void MergeSort(int arr[],int length){
    
    //cout << length << endl;
    if(length==0||length==1) return;
    Divide(arr, 0, length-1);
}



int main(int argc, const char * argv[]) {
    int arr[] = {1,5,6,2,3,8,1,4,7,3,9,2};
    int length = sizeof(arr)/4;
    //cout << length;
    MergeSort(arr,length);
    
    for(int i=0;i<length;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}



