#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> cnt(26,0);
        int n=target.size();

        for(auto ch:s)
            cnt[ch-'a']++;

        int cnt_od=0;
        string ret;
        char od_char;

        if(n==1){
            if(s>target)
                return s;
            else
                return ret;
        }
        for(int i=0;i<26;i++){

            if(cnt[i]%2){
                cnt_od++;
                od_char=char('a'+i);
            }

            if(cnt_od>1){
                return ret;
            }
        }

        if(cnt_od==1){
            cnt[od_char-'a']--;
        }

        
        string curr=s;
        for(int i=0;i<n/2;i++){
            char ch=target[i];
            
            for(int j=ch-'a';j<26;j++){
                if(cnt[j]==0){
                    continue;
                }
                string tmp=curr;
                tmp[i]=char('a'+j);
                tmp[n-i-1]=char('a'+j);
                vector<int> tmp_cnt=cnt;
                tmp_cnt[j]-=2;

                int k=i+1,l=n-i-2;
                while(k<l){
                    for(int o=0;o<26;o++){
                        if(tmp_cnt[o]>1){
                            tmp[k]=char('a'+o);
                            tmp[l]=char('a'+o);
                            tmp_cnt[o]-=2;
                            k++;
                            l--;

                            break;
                        }
                    }
                }

                
                if(n%2){                  
                    tmp[(n)/2]=od_char;
                }
                


                if(tmp>target){
                    if(ret.size()==0){
                        ret=tmp;
                    }else{
                        ret=min(ret,tmp);
                    }
                }
            }
            
            
            if(cnt[ch-'a']<2){
                break;
            }

            curr[i]=ch;
            curr[n-i-1]=ch;
            cnt[ch-'a']-=2;

        }


        return ret;
    }
};