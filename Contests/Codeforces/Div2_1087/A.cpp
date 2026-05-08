#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        ll n,c,k;
        cin>>n>>c>>k;
        
        vector<ll> a(n);
 
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        sort(a.begin(),a.end());
        
        for(int i=0;i<n;i++){
            ll m=a[i];
            
            if(m>c){
                continue;
            }else{
                ll ex_poss=min(c-m,k);
                k-=ex_poss;
                m+=ex_poss;
                c+=m;
            }
        }
        
        cout<<c<<endl;

    }
}