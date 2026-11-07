#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define min_heap priority_queue<vector<ll>,vector<vector<ll> >,greater<vector<ll> > >
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        min_heap busy_servers,free_servers;
        int n=servers.size(),m=tasks.size();

        for(int i=0;i<n;i++)
            free_servers.push({servers[i],i});

        vector<int> ret;
        ll i=0,wall_time=0;

        while(i<m){
            if(wall_time<i)
                wall_time=i;
            
            while(busy_servers.size()>0){
                auto early = busy_servers.top();
                if(early[0]<=wall_time){
                    busy_servers.pop();
                    free_servers.push({servers[early[1]],early[1]});
                }else{
                    break;
                }
            }

            if(free_servers.size()==0){
                wall_time=busy_servers.top()[0];
                continue;
            }

            auto first = free_servers.top();
            free_servers.pop();
            ret.push_back(first[1]);
            busy_servers.push({wall_time+tasks[i],first[1]});
            i++;
        }

        return ret;
    }
};