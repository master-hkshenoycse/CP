#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void zigZag(int n, vector<int> &arr) {
        // code here
        int f=0,l=0,r=1;
        while(l<n and r<n){
            if(f==0){
                if(arr[l]>arr[r]){
                    swap(arr[l],arr[r]);
                }
                
            }else{
                if(arr[l]<arr[r]){
                    swap(arr[l],arr[r]);
                }
            }
            f=1-f;
            l++;
            r++;
        }
        
    }
};
