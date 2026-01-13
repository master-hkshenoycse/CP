#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n=arrivals.size();
        map<int,queue<int> >arrival_counter;
        int ans=0;
        for(int i=1;i<=n;i++){
            int curr_ele=arrivals[i-1];
            if (arrival_counter[curr_ele].size()==m){
                ans++;
            }else{
                arrival_counter[curr_ele].push(i);
            }

            int start=max(1,i-w+1);
            if(i>=w && start-1>=0){
                if(arrival_counter[arrivals[start-1]].size()>0){
                    if(arrival_counter[arrivals[start-1]].front()==start){
                        arrival_counter[arrivals[start-1]].pop();
                    }
                }
            }
        }

        return ans;
    }
};