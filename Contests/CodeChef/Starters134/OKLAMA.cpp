#include <bits/stdc++.h>
#define ll long long
using namespace std;
void maintain_order(multiset<ll> &top,multiset<ll> &bot,ll &top_sum,ll &bot_sum){
    ll sz_total=top.size()+bot.size();
    
    while(top.size()>0 and bot.size()>0){
        ll a=*top.begin();
        ll b=*(--bot.end());
        
        if(b>a){
            top.erase(top.find(a));
            bot.erase(bot.find(b));
            top_sum-=a;
            bot_sum-=b;
            
            
            top.insert(b);
            bot.insert(a);
            
            top_sum+=b;
            bot_sum+=a;
            
        }else{
            break;
        }
    }
    
    while(top.size() > (sz_total+1)/2){
        ll a=*top.begin();
        top_sum-=a;
        bot_sum+=a;
        top.erase(top.find(a));
        bot.insert(a);
    }
    
    while(top.size()<(sz_total+1)/2){
        ll a=*(--bot.end());
        top_sum+=a;
        bot_sum-=a;
        bot.erase(bot.find(a));
        top.insert(a);
    }
    
    
}
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
	    ll n,q;
	    cin>>n>>q;
	    multiset<ll> top_set,bot_set;
	    
	    ll top_sum=0,bot_sum=0;
	    
	    vector<ll> a(n+1);
	    vector<vector<ll> >  query(q,vector<ll> (2));
	    for(ll i=1;i<=n;i++){
	        cin>>a[i];
	    }
	    
	    for(ll i=0;i<q;i++){
	        cin>>query[i][0];
	        query[i][1]=i;
	    }
	    
	    
	    sort(query.begin(),query.end());
	    vector<ll> sol(q);
	    
	    ll curr=1;
	    
	    for(ll i=0;i<q;i++){
	        while(curr<=query[i][0]){
	            top_sum+=a[curr];
	            top_set.insert(a[curr]);
	            curr++;
	        }
	        
	        maintain_order(top_set,bot_set,top_sum,bot_sum);
	        //cout<<curr<<" "<<top_sum<<" "<<bot_sum<<endl;
	        sol[query[i][1]]=top_sum-bot_sum;
	    }
	    
	    for(ll i=0;i<q;i++){
	        cout<<sol[i]<<" ";
	    }
	    
	    cout<<endl;
	}

}
