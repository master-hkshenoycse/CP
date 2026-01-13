#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int minOperations(string s, int k) {
        ll n=s.size(),c0=0,c1=0;
        for(auto ch:s){
            c0+=(ch=='0');
            c1+=(ch=='1');
        }

        if(k==n){
            if(c0==n)return 1;
            if(c1==n)return 0;
            return -1;
        }
        
        for(int i=0;i<=n+1;i++){
           ll flips = i*k;
           ll min_req_flips = c0;
           ll max_poss_flips = 0;
           if(i%2==1){
                max_poss_flips = c0*i+(i-1)*c1;
           }else{
                max_poss_flips = c0*(i-1)+c1*i;
           }

           cout<<i<<" "<<flips<<" "<<min_req_flips<<" "<<max_poss_flips<<endl;

           if((flips%2)!=(c0%2)){
            continue;
           }

           if(flips>=min_req_flips && flips<=max_poss_flips){
            return i;
           }
        }

        return -1;
    }
};