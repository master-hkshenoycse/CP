#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_diff(ll s,string &t){
        ll v1=s,v2=0;

        for(auto ch:t){
            v2=v2*10+(ch-'0');
        }

        return abs(v1-v2);
    }

    string add_one(string num){
        ll carry=1;
        ll n=num.size();

        string ret;
        for(ll i=n-1;i>=0;i--){
            ll v=(num[i]-'0'+carry)%10;
            carry=(num[i]-'0'+carry)/10;

            ret+=char('0'+v);
            
        }

        if(carry>0){
            ret+=char('0'+carry);
        }

        reverse(ret.begin(),ret.end());
        return ret;
    }



    string sub_one(string num){
        ll borrow=1,n=num.size();
        string ret;

        for(ll i=n-1;i>=0;i--){
            ll v=(num[i]-'0'-borrow);

            if(v<0){
                v+=10;
                borrow=1;
            }else{
                borrow=0;
            }

            ret+=char('0'+v);
        }

        reverse(ret.begin(),ret.end());
        return ret;

    }
    ll get_num(string o,ll ignore){
        string rev_part;
        ll sz=o.size();
        for(ll i=0;i<o.size()-ignore;i++){
            rev_part+=o[i];
        }

        string ret=o;
        reverse(rev_part.begin(),rev_part.end());
        ret+=rev_part;

        ll sol=0;
        for(auto o:ret){
            sol=sol*10+(o-'0');
        }

        return sol;
    }
    string nearestPalindromic(string n) {
        int sz=n.size();
        if(n=="1"){
            return "0";
        }

        string half_num=n.substr(0,(sz+1)/2);
        
        vector<ll> candidates={get_num(half_num,0)};
        candidates.push_back(get_num(half_num,1));
        
        candidates.push_back(get_num(add_one(half_num),0));
        candidates.push_back(get_num(add_one(half_num),1));


        candidates.push_back(get_num(sub_one(half_num),0));
        candidates.push_back(get_num(sub_one(half_num),1));

        ll tmp;
        for(ll i=0;i<sz-1;i++){
            tmp=tmp*10+9;
        }

        candidates.push_back(tmp);
        
        tmp=tmp*10+9;
        candidates.push_back(tmp);

        tmp=1;
        for(ll i=0;i<sz;i++){
            tmp=tmp*10+0;
        }

        tmp+=1;

        candidates.push_back(tmp);

        ll diff_req=9e18;
        ll ans=9e18;

        for(auto c:candidates){
            ll d=get_diff(c,n);
            if(d==0){
                continue;
            }

            cout<<c<<endl;
            if(d < diff_req){
                diff_req=d;
                ans=c;
            }else if(d==diff_req){
                ans=min(ans,c);
            }
        }

        return to_string(ans);

        
        
    }
};