#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int> > merge_interval(vector<vector<int> >&curr){
        sort(curr.begin(),curr.end());
        vector<vector<int> > ret;

        int l=-1,r=-1;
        for(auto it:curr){
            if(it[0]>r){
                if(r!=-1)
                    ret.push_back({l,r});
                l=it[0];
                r=it[1];
            }else{
                r=max(r,it[1]);
            }
        }

        if(l!=-1)
            ret.push_back({l,r});

        return ret;
    }
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {

        vector<vector<int> > target=merge_interval(targetIntervals);
        priority_queue<int> pq;
        sort(availableIntervals.begin(),availableIntervals.end());

        int ans=0,j=0,i=0,r_end=-1;       
        while(j<target.size()){

            while(i<availableIntervals.size() && availableIntervals[i][0]<=max(r_end,target[j][0])){
                pq.push(availableIntervals[i][1]);
                i++;
            }

            if(r_end < target[j][1]){
                if(pq.size()==0)
                    return -1;
                ans++;
                r_end=pq.top();
                pq.pop();
            }else{
                j++;
            }
        }

        return ans;
        

        
    }
};