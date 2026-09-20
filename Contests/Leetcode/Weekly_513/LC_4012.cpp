#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        ll n=tasks.size();
        vector<ll> csum(n,0);
        for(ll i=0;i<n;i++){
            csum[i]=tasks[i];
            if(i-1>=0)
                csum[i]+=csum[i-1];
        }

        vector<int> ret;
        ll d=0;

        for(int t:shifts){
            if(d+t>=csum.back()){
                ret.push_back(0);
                d=0;
            }else{
                d+=t;
                auto it = upper_bound(csum.begin(),csum.end(),d);
                ret.push_back(n-distance(csum.begin(),it));
            }
        }

        return ret;
    }
};