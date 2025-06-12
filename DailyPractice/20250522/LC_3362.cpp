#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
            int n=nums.size();
            vector<int> start[n];
            int used=0;
            for(auto q:queries){
                start[q[0]].push_back(q[1]);
            }
            priority_queue<int> pq;
            vector<int> ex(n+2,0);
            int cs=0;
            for(int i=0;i<n;i++){
                cs=cs+ex[i];
                while(start[i].size()>0){
                    pq.push(start[i].back());
                    start[i].pop_back();
                }
    
                while(pq.size()>0 and cs<nums[i]){
                    if(pq.top()<i){
                        break;
                    }
                    cs++;
                    ex[pq.top()+1]--;
                    used++;
                    pq.pop();
                }
    
                if(cs<nums[i]){
                    return -1;
                }
            }
    
            return queries.size()-used;
        }
    };