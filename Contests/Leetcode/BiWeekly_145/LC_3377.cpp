#include<bits/stdc++.h>
using namespace std;
int isp[100005];
int prec=-1;
class Solution {
public:

    int string_to_int(string &s){
        int ret=0;
        for(auto ch:s){
            ret=ret*10 + (ch-'0');
        }
        return ret;
    }
    void pre_compute(){
        isp[1]=1;
        for(int i=2;i<=10000;i++){
            if(isp[i]==0){
                for(int j=i*i;j<=10000;j+=i){
                    isp[j]=1;
                }
            }
        }
    }
    int minOperations(int n, int m) {
        if(prec==-1){
            pre_compute();
            prec=1;
        }

        map<int,int> dp;
        set<pair<int,int> >s;

        if(isp[n]){
            s.insert({n,n});
            dp[n]=n;
        }

        while(s.size()>0){
            auto it=*s.begin();
            int val=it.second;
            int d=it.first;
            s.erase(it);
            
            
            string num=to_string(val);
            vector<int> poss;

            for(int i=0;i<num.size();i++){

                if(num[i]<'9'){
                    num[i]++;
                    int new_val=string_to_int(num);
                    if(isp[new_val])poss.push_back(new_val);
                    num[i]--;
                }


                if(num[i]>'0'){
                    num[i]--;
                    int new_val=string_to_int(num);
                    if(isp[new_val])poss.push_back(new_val);
                    num[i]++;
                }

            }

            for(auto p:poss){
                if(dp.find(p) == dp.end() or dp[p] > d+p){
                    dp[p]=d+p;
                    s.insert({dp[p],p});
                }
            }


        }

        if(dp.find(m) == dp.end()){
            dp[m]=-1;
        }

        return dp[m];
    }
};