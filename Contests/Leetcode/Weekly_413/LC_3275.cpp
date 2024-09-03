#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        vector<int> sol;
        for(auto q:queries){
            pq.push(abs(q[0])+abs(q[1]));
            if(pq.size()>k){
                pq.pop();
            }
            if(pq.size() == k){
                sol.push_back(pq.top());
            }else{
                sol.push_back(-1);
            }
        }
        
        return sol;
    }
};