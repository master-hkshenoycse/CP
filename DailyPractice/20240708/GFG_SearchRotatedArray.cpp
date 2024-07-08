#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int lo=0,hi=arr.size()-1;
        int key_big=(key >= arr[0]);
        
        while(hi>=lo){
            
            int mid=(hi+lo)/2;
            
            
            if(arr[mid]==key){
                return mid;
            }
            
            int mid_big=(arr[mid] >= arr[0]);
            
            if(mid_big==key_big){
                if(arr[mid]>key){
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }else{
                if(key_big){
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
        }
        
        return -1;
    }
};