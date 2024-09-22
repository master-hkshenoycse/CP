
#include<bits/stdc++.h>
using namespace std;
void sort012(vector<int>& arr) {
        // code here
        int lo=0,mid=0,hi=arr.size()-1;
        while(mid<=hi){
            if(arr[mid]==0){
                swap(arr[mid],arr[lo]);
                lo++;
                mid++;
            }else if(arr[mid]==1){
                mid++;
            }else{
                swap(arr[mid],arr[hi]);
                hi--;
            }
        }
    }