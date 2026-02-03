#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll n,k;
    cin>>n>>k;

    vector<vector<ll> > ind_req(k,vector<ll> (3));
    vector<ll> cnt_m_req(n+1,0);

    for(ll i=0;i<k;i++){
        cin>>ind_req[i][0]>>ind_req[i][1]>>ind_req[i][2];
        cnt_m_req[ind_req[i][0]]++;
    }
    
    ll ma_poss=-1,ma_ways=0;

    for(ll mask=0;mask<(1ll<<n);mask++){
        ll curr_score=0;

        for(auto ind:ind_req){
            if((mask & (1ll<<(ind[0]-1)))==0){
                if(mask & (1ll<<(ind[1]-1))){
                    if(mask & (1ll<<(ind[2]-1))){
                        curr_score++;
                    }
                }
            }
        }

        


        if(curr_score>ma_poss){
            ma_poss=curr_score;
            ma_ways=1;
        }else  if(curr_score==ma_poss){
            ma_ways++;
        }
    }

    cout<<ma_poss<<" "<<ma_ways<<endl;
}