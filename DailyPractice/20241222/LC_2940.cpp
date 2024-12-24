#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bSearch(int value,vector<pair<int,int> > &st){
        int lo=0,hi=st.size()-1,ans=-1;

        while(hi>=lo){
            int mid=(hi+lo)/2;
            if(st[mid].first > value){
                ans=max(ans,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }


        if(ans==-1){
            return -1;
        }

        return st[ans].second;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size(),m=queries.size();
        vector<int> sol(m,-1);


        vector<pair<int,int> >st;
        vector<vector<pair<int,int> > > qBank(n);


        for(int i=0;i<m;i++){
            int a=queries[i][0];
            int b=queries[i][1];

            if(a>b){
                swap(a,b);
            }

            if(heights[b]>heights[a] or a==b){
                sol[i]=b;
            }else{
                qBank[b].push_back({heights[a],i});
            }
        }

        for(int i=n-1;i>=0;i--){
            for(auto q:qBank[i]){
                int index=q.second;
                int value=q.first;
                sol[index]=bSearch(value,st);
            }

            while(st.size()>0 and st.back().first<=heights[i]){
                st.pop_back();
            }
            st.push_back({heights[i],i});
        }



        return sol;

    }
};