#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    string fractionAddition(string expression) {
        vector<ll> deno_;
        vector<ll> nume_;
        ll i=0,n=expression.size();

        while(i<n){
            int sign=1;
            if(expression[i]=='-'){
                sign=-1;
                i++;
            }else if(i>0){
                i++;
            }


            ll value=0;
            while(i<n and expression[i]>='0' and expression[i]<='9'){
                value=value*10+(expression[i]-'0');
                i++;
            }
            nume_.push_back(value*sign);
            i++;//for fraction (/) sign

            value=0;
            while(i<n and expression[i]>='0' and expression[i]<='9'){
                value=value*10+(expression[i]-'0');
                i++;
            }
            deno_.push_back(value);
        }

        ll lcm=1;
        for(auto d:deno_){
            lcm=(lcm * d)/__gcd(lcm,d);
        }

        ll sz=nume_.size();
        ll tot=0;
        for(ll i=0;i<sz;i++){
            cout<<nume_[i]<<" "<<deno_[i]<<" "<<lcm<<endl;
            tot=tot+(nume_[i]*lcm)/deno_[i];
        }

        ll gcd=__gcd(abs(tot),abs(lcm));
        tot/=gcd;
        lcm/=gcd;

        string sol=to_string(tot);
        sol+='/';
        sol+=to_string(lcm);

        return sol;





        
    }
};