#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans=0,n=arr.size();
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=i;j<n;j++){
                curr=(curr ^ arr[j]);
                if(curr==0){
                    ans=ans+j-i;
                }
            }
        }

        return ans;
    }
};