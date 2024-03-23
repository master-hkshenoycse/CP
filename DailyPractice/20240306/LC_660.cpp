/*https://leetcode.ca/all/660.html*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solution(ll n){
    vector<ll> dig={0,1,2,3,4,5,6,7,8};

    vector<ll> sol;

    while(n>0){
        sol.push_back(dig[n%9]);
        n/=9;
    }

    reverse(sol.begin(),sol.end());
    ll ans=0;
    for(auto e:sol){
        ans=ans*10+e;
    }

    return ans;
}

int main(){
    cout<<solution(9)<<endl;
    cout<<solution(19)<<endl;
    cout<<solution(25)<<endl;
}