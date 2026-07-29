#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll ncr(ll n,ll r,ll max_val){
        if(r>n){
            return 0;
        }

        r=min(r,n-r);

        ll ret=1;
        for(ll i=1;i<=r;i++){
            ret = (ret * (n-r+i))/i;
            if(ret >= max_val){
                return max_val;
            }
        }

        return ret;
    }
    ll countPerms(vector<ll> &counts,int pos,ll max_val){
        ll perms=1;
        ll remains = pos;
        for(auto cnt:counts){
            ll ways = ncr(remains,cnt,max_val);
            perms = perms * ways;

            if( perms >= max_val){
                return max_val;
            }

            remains = remains-cnt;
        }
        return perms;
    }
    string smallestPalindrome(string s, int k) {
        ll max_perms_need = k+1;
        vector<ll> cnt(26,0);
        for(auto ch:s){
            cnt[ch-'a']++;
        }

        string middle = "";
        vector<ll> half_cnt(26,0);
        ll half_len=0;
        for(ll i=0;i<26;i++){
            if(cnt[i]%2==1){
                middle+=char('a'+i);
            }
            half_cnt[i]=cnt[i]/2;
            half_len+=half_cnt[i];
        }

        ll total_palindromes = countPerms(half_cnt,half_len,max_perms_need);

        if(k>total_palindromes){
            return "";
        }

        string first_half="";
        for(int pos=0;pos<half_len;pos++){
            for(int c=0;c<26;c++){
                if(half_cnt[c]==0){
                    continue;
                }

                half_cnt[c]--;

                ll palindromes_with_prefix = countPerms(half_cnt,half_len-pos-1,max_perms_need);

                if(k>palindromes_with_prefix){
                    k-=palindromes_with_prefix;
                    half_cnt[c]++;
                }else{
                    first_half+=('a'+c);
                    break;
                }
            }
        }

        string result = first_half + middle;
        reverse(first_half.begin(),first_half.end());
        result+=first_half;

        return result;




    }
};