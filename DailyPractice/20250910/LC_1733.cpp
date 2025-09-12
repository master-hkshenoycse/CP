#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int> &a,vector<int> &b){
        for(int i=0;i<a.size();i++){
            if (is_present(b,a[i])) {
                return 1;
            }
        }
        return 0;
    }

    bool is_present(vector<int> &a,int v){
        auto it=lower_bound(a.begin(),a.end(),v);
        if(it != a.end() && (*it) == v){
            return 1;
        }
        return 0;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        int m = languages.size();
        for(auto &l:languages){
            sort(l.begin(),l.end());
        }
        vector<vector<int> > req;
        
        for(auto f:friendships){
            if(check(languages[f[0]-1],languages[f[1]-1])==0){
                req.push_back(f);
            }
        }

        int ans=INT_MAX;

        for(int i=1;i<=n;i++){

            vector<int> learnt(m+1,0);
            int cnt=0;
            for(auto r:req){
                int a=r[0],b=r[1];
                if(is_present(languages[a-1],i)){
                    learnt[a]=1;
                }

                if(is_present(languages[b-1],i)){
                    learnt[b]=1;
                }

                if(learnt[a]==0){
                    cnt++;
                    learnt[a]=1;
                }

                if(learnt[b]==0){
                    cnt++;
                    learnt[b]=1;
                }
            }


            ans=min(ans,cnt);
        }

        return ans;
    }
};