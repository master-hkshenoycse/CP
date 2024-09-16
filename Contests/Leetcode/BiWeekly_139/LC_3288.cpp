#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        vector<int> req=coordinates[k];
        sort(coordinates.begin(),coordinates.end());
        int n=coordinates.size();


        vector<int> mark_n(n,1e9+5);
        vector<int> dp_prefix(n,0),dp_suffix(n,0);
        int i=0;
        while(i<n){
            int j=i;

            while(j<n and coordinates[i][0]==coordinates[j][0]){
                int c=coordinates[j][1];
                int ind=upper_bound(mark_n.begin(),mark_n.end(),c)-mark_n.begin();
                if(ind>0 and mark_n[ind-1]==c){
                    ind--;
                }

                dp_prefix[j]=ind+1;
                j++;
            }

            for(int o=i;o<j;o++){
                mark_n[dp_prefix[o]-1]=min(mark_n[dp_prefix[o]-1],coordinates[o][1]);
            }

            i=j;
        }

        for(int i=0;i<n;i++){
            mark_n[i]=1e9;
        }

        i=n-1;
        while(i>=0){
            int j=i;

            while(j>=0 and coordinates[i][0]==coordinates[j][0]){
                int c=-1*coordinates[j][1];
                int ind=upper_bound(mark_n.begin(),mark_n.end(),c)-mark_n.begin();
                if(ind>0 and mark_n[ind-1]==c){
                    ind--;
                }

                dp_suffix[j]=ind+1;
                j--;
            }

            for(int o=i;o>j;o--){
                mark_n[dp_suffix[o]-1]=min(mark_n[dp_suffix[o]-1],-coordinates[o][1]);
            }

            i=j;
        }

        for(int i=0;i<n;i++){
            if(coordinates[i]==req){
                return dp_prefix[i]+dp_suffix[i]-1;
            }
        }


        return 0;
        
    }
};