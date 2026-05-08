#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n=damage.size();
        vector<ll> c_damage(n,0);
        for(int i=0;i<n;i++){
            c_damage[i]=damage[i];
            if(i-1>=0)
                c_damage[i]+=c_damage[i-1];
        }

        vector<int> cum_score(n,0);

        for(int i=0;i<n;i++){
            int lo=0,hi=i,ret=i+1;
            while(hi>=lo){
                int mid=(hi+lo)/2;
                int tot_damage=c_damage[i];
                if(mid-1>=0)
                    tot_damage-=c_damage[mid-1];
                
                if(hp-tot_damage>=requirement[i]){
                    ret=min(ret,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }

            if(ret<=i){
                cum_score[i]++;
                if(ret-1>=0)
                    cum_score[ret-1]--;
            }
        }

        ll ans=0,cs=0;

        for(int i=n-1;i>=0;i--){
            cs=cs+cum_score[i]*1ll;
            ans=ans+cs;
        }

        return ans;

    }
};