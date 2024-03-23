#include<bits/stdc++.h>
using namespace std;

bool isMaxHeap(vector<int> arr, int n){
    // Your code goes here
    for(int i=0;i<n;i++){
        int left=2*i+1;
        int right=2*i+2;
        if(left<n and arr[i]<arr[left]){
            return 0;
        }
        if(right<n and arr[i]<arr[right]){
            return 0;
        }
    }
    
    return 1;
}

int main(){
    cout<<isMaxHeap({90, 15, 10, 7, 12, 2},6)<<endl;
    cout<<isMaxHeap({9, 15, 10, 7, 12, 11},6)<<endl;
}