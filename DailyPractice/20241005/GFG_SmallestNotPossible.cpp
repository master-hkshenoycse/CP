#include<bits/stdc++.h>
using namespace std;
#define ll long long
//same as https://cses.fi/problemset/task/2183
long long findSmallest(vector<int> &arr) {
        // Your code goes here.
        ll sum=0,n=arr.size();
        sort(arr.begin(),arr.end());
        for(ll i=0;i<n;i++){
            if(arr[i]>sum+1){
                return sum+1;
            }
            sum=sum+arr[i];
        }
        
        return sum+1;
        
    }