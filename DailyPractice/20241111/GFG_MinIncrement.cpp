#include<bits/stdc++.h>
using namespace std;
/*operation is increase by 1*/
int minIncrements(vector<int> arr) {
        // Code here
        sort(arr.begin(),arr.end());
        int max_val=0,ans=0,n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]<=arr[i-1]){
                ans=ans+(arr[i-1]-arr[i]+1);
                arr[i]=arr[i-1]+1;
            }
        }
        return ans;
    }