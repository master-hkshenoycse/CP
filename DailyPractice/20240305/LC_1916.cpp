#include<bits/stdc++.h>
using namespace std;
/*The problems basically boils down to finding number of toplogical orderings of the directed tree. The problem can be solved this way, let's say the node 'r' has children 'ch1', 'ch2' and 'ch3' and let's say their sizes are n1, n2, n3. We compute topological orderings of each subtree first.

Then topological ordering of node 'r' can computed as:
Top(r) = (#ordering of nodes in subtree rooted at r) * Top(ch1) * Top(ch2) * Top(ch3)
#ordering of nodes = fact(n1 + n2 + n3) / (fact[n1] * fact[n2] * fact[n3])

Therefore for an arbitrary node r and children marked as ch_i where

sz[ch_i] represents size of subtree rooted at ith children i.e. ch_i
Σ sz(r) represents size of subtree rooted at r. We are subtracting 1 because root r will always come first as we don't have a choice here, after that we have choices
∏ factorial(sz(ch_i)) represents product of factorial of sizes of each subtree*/
#define ll long long
/*
n! / (cnt_0 * cnt_1 * .. * cnt_n-1)
Where cnt_i is the number of nodes in the subtree with the root node i
*/
class Solution {
public:
    ll mod=1e9+7;
    vector<ll> fact,inv_fact;

    ll modpow(ll a,ll n){
        ll res=1;
        while(n>0){
            if(n%2){
                res=(res*a)%mod;
            }
            n/=2;
            a=(a*a)%mod;
        }
        return res;
    }
    
    void pre(ll n){
        for(ll i=1;i<=n;i++){
            fact[i]=(fact[i-1]*i)%mod;
            inv_fact[i]=modpow(fact[i],mod-2);
        }
    }

    void dfs(ll v,ll p,vector<vector<ll> >&adj,vector<ll> &subtree_size,vector<ll> &sol){
        subtree_size[v]=1;
        ll ans=1;
        ll den=1,num=1;

        for(auto to:adj[v]){
            if(to==p){
                continue;
            }
            dfs(to,v,adj,subtree_size,sol);

            subtree_size[v]+=subtree_size[to];
            ans=(ans * sol[to])%mod;
            den=(den * inv_fact[subtree_size[to]])%mod;

        }

        num=fact[subtree_size[v]-1];
        ans=(ans * num)%mod;
        ans=(ans * den)%mod;
        sol[v]=ans;

    }
    int waysToBuildRooms(vector<int>& prevRoom) {
        ll n=prevRoom.size();
        vector<ll> subtree_size(n+1,0);
        vector<vector<ll> > adj(n+1);
        fact.resize(n+1,1),inv_fact.resize(n+1,1);
        pre(n);
        for(int i=1;i<n;i++){
            adj[prevRoom[i]].push_back(i);
            adj[i].push_back(prevRoom[i]);
        }       

        vector<ll> sol(n+1,1);
        dfs(0,-1,adj,subtree_size,sol);
        return sol[0];
    }
};