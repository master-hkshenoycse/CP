#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        ll n=s.size(),n_eq=0,cnt_10=0,cnt_01=0;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                n_eq++;
                if(s[i]=='0')
                    cnt_01++;
                else
                    cnt_10++;
            }
        }   

        //cout<<n_eq<<" "<<cnt_01<<" "<<cnt_10<<endl;

        ll ret=flipCost*n_eq;
        ll diff=abs(cnt_01-cnt_10);
        ll ex=0;
        if(diff%2){
            ex=flipCost;
            diff--;
        }

        ret=min(ret,ex+(diff/2)*crossCost+((cnt_10+cnt_01)/2)*swapCost);
        ret=min(ret,ex+diff*flipCost+((cnt_10+cnt_01-diff)/2)*swapCost);
        return ret;
    }
};