#include<bits/stdc++.h>
using namespace std;

vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // your code here
        int n=arr.size();
        deque<int> dq;
        vector<int> sol;
        for(int i=0;i<n;i++){
            while(dq.size()>0 and i-dq.front()>=k){
                dq.pop_front();
            }
            
            while(dq.size()>0 and arr[dq.back()]<=arr[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if(i>=k-1){
                sol.push_back(arr[dq.front()]);
            }
        }
        
        return sol;
    }