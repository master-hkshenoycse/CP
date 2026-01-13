/*https://usaco.org/index.php?page=viewproblem2&cpid=1445*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<string> poss;
void gen_poss(){

    for(char ch1='a';ch1<='z';ch1++){
        for(char ch2='a';ch2<='z';ch2++){
            if(ch2==ch1) continue;
            string s="";
            s.push_back(ch1);
            s.push_back(ch2);
            s.push_back(ch2);
            poss.push_back(s);
        }
    }

}
int main(){

    ll n,f;
    cin>>n>>f;

    string s;
    cin>>s;

    gen_poss();
    vector<string> sol;


    for(auto str:poss){
        vector<ll> prefix_cnt(n,0);
        vector<ll> suffix_cnt(n,0);
        
        for(ll i=0;i+2<n;i++){
            if(s[i]==str[0] and s[i+1]==str[1] and s[i+2]==str[2]){
                prefix_cnt[i+2]++;
            }   
            prefix_cnt[i] += (i>0 ? prefix_cnt[i-1] : 0);
        }

        for(ll i=n-1;i>=0;i--){
            if(i+2<n and s[i]==str[0] and s[i+1]==str[1] and s[i+2]==str[2]){
                suffix_cnt[i]++;
            }
            suffix_cnt[i] += (i+1<n ? suffix_cnt[i+1] : 0);
        }

        ll max_cnt=prefix_cnt[n-1]; 


        for(ll i=0;i+2<n;i++){
            ll n_eq=0;
            n_eq=(str[0]!=s[i])+(str[1]!=s[i+1])+(str[2]!=s[i+2]);

            if(n_eq<=1){
                ll curr_cnt=0;
                if(i-1>=0){
                    curr_cnt+=prefix_cnt[i-1];
                }

                if(i+3<n){
                    curr_cnt+=suffix_cnt[i+3];
                }

                max_cnt=max(max_cnt,curr_cnt+1);
            }


        }
        if(max_cnt>=f){
            sol.push_back(str);
        }

    }   


    cout<<sol.size()<<endl;
    for(auto str:sol){
        cout<<str<<endl;
    }
}