#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll check_valid(ll &cnt_a,ll &cnt_e,ll &cnt_i,ll &cnt_o,ll &cnt_u,ll &cnt_c,ll &k){
        return cnt_a>0 and cnt_e>0 and cnt_i>0 and cnt_o>0 and cnt_u>0 and cnt_c>=k;
    }
    ll get_cnt_k(string &word,ll k){
        ll j=0,n=word.size(),ans=0;

        ll cnt_a=0,cnt_e=0,cnt_i=0,cnt_o=0,cnt_u=0,cnt_c=0;

        for(int i=0;i<n;i++){
            if(word[i]=='a'){
                cnt_a++;
            }else if(word[i]=='e'){
                cnt_e++;
            }else if(word[i]=='i'){
                cnt_i++;
            }else if(word[i]=='o'){
                cnt_o++;
            }else if(word[i]=='u'){
                cnt_u++;
            }else{
                cnt_c++;
            }

            while(j<=i and check_valid(cnt_a,cnt_e,cnt_i,cnt_o,cnt_u,cnt_c,k)){
                
                if(word[j]=='a'){
                    cnt_a--;
                }else if(word[j]=='e'){
                    cnt_e--;
                }else if(word[j]=='i'){
                    cnt_i--;
                }else if(word[j]=='o'){
                    cnt_o--;
                }else if(word[j]=='u'){
                    cnt_u--;
                }else{
                    cnt_c--;
                }

                j++;

            }

            ans=ans+j;
        }

        return ans;
    }
    ll countOfSubstrings(string word, int k) {
        return get_cnt_k(word,k)-get_cnt_k(word,k+1);
    }
};