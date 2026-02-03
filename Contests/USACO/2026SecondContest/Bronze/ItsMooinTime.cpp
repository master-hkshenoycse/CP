#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll t,k;
    cin>>t>>k;

    while(t--){

        ll n;
        cin>>n;

        string s;
        cin>>s;

        string ret;
        ll c=0;
        
        for(ll i=n-1;i>=0;i--){
            if(c==0){
                if(s[i] == 'M'){
                    ret+="M";
                }else{
                    ret+="O";
                    c=1-c;
                }
            }else{
                if(s[i]=='M'){
                    ret+='O';
                    c=1-c;
                }else{
                    ret+='M';
                }
            }
        }

        reverse(ret.begin(),ret.end());
        cout<<"YES"<<endl;
        if(k==1)cout<<ret<<endl;
    }
}