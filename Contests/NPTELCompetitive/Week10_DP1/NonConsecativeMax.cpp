#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;


float round(float var)
{
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}
int main(){
    ll t;
    cin>>t;



    while(t--){
        ll n;
        cin>>n;
        vector<ll> a(n+1),dp(n+1,0);
        ll tot=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            tot+=a[i];
        }

        for(ll i=1;i<=n;i++){
            dp[i]=dp[i-1];
            ll ex=0;
            if(i-2>=0){
                ex=dp[i-2];
            }
            dp[i]=max(dp[i],ex+a[i]);
        }


        dd ans=(dp[n]*1.00)/(tot*1.00);
        
        ans=ans*100.00;
        cout << setprecision (2) << fixed<<ans;
        cout<<"%"<<endl;
    }
    
}