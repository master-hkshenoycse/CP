#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here.
         int sum=0,n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(arr[i]>sum+1){
                return sum+1;
            }
            sum=sum+arr[i];
        }
        
        return sum+1;
    }
};