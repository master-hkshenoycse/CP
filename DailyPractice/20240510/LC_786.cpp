#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    class Compare {
        public:
        bool operator()(pair<int,int> &a,pair<int,int> &b){
            return a.first*b.second<=b.first*a.second;
        }
    };
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        int n=arr.size();
        priority_queue<pair<int,int> ,vector<pair<int,int> >,Compare> pq;    

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pq.push({arr[i],arr[j]});
                if(pq.size()>k){
                    pq.pop();
                }

            }
        }

        vector<int> sol(2);
        sol[0]=pq.top().first;
        sol[1]=pq.top().second;
        return sol;
    }
};