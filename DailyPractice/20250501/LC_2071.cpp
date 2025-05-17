#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int n,m;
        bool check(vector<int> &tasks,vector<int>&workers,int k,int pills,int strength){
            deque<int> q;
            int t_idx=0;
            for(int i=m-k;i<m;i++){
            
                while(t_idx<k && tasks[t_idx]<=workers[i]+strength){
                    q.push_back(tasks[t_idx]);
                    t_idx++;
                }
    
                if(q.empty()){
                    return 0;
                }
    
                if(q.front()<=workers[i]){
                    q.pop_front();
                }else{
                    if(pills==0){
                        return 0;
                    }
                    pills--;
                    q.pop_back();
                }
            }
    
            return 1;
        }
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            n=tasks.size();
            m=workers.size();
    
            sort(tasks.begin(),tasks.end());
            sort(workers.begin(),workers.end());
            
    
            int ret=0,lo=0,hi=min(n,m);
    
            while(hi>=lo){
                int mid=(hi+lo)/2;
                if(check(tasks,workers,mid,pills,strength)){
                    ret=max(ret,mid);
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }
    
            return ret;
        }
    };