#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> cnt(26,0);

        for(auto t:tasks){
            cnt[t-'A']++;
        }

        for(int i=0;i<26;i++){
            if(cnt[i]>0){
                pq.push(cnt[i]);
            }
        }

        int ans=0;

        while(pq.size()>0){
            vector<int> remain;
            int cycle=n+1;
            while(cycle>0 and pq.size()>0){
                int max_freq=pq.top();//puck the tasks which have highest units remaining
                pq.pop();

                if(max_freq>1){
                    remain.push_back(max_freq-1);
                }
                ans++;
                cycle--;
            }

            for(auto e:remain){
                pq.push(e);
            }

            //all tasks done
            if(pq.size()==0){
                break;
            }

            ans+=cycle;//add the idle time
        }

        return ans;

    }
};