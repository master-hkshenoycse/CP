#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size(),m=station.size();
        vector<int> matching_ind_prefix(n),matching_ind_suffix(n);

        int match_ind=0;
        for(int i=0;i<n;i++){
            while(skill[i]!=station[match_ind])
                match_ind++;
            matching_ind_prefix[i]=match_ind;
            match_ind++;
        }
        match_ind=m-1;
        for(int i=n-1;i>=0;i--){
            while(skill[i] != station[match_ind])
                match_ind--;
            matching_ind_suffix[i]=match_ind;
            match_ind--;
        }


        int ans=0;
        for(int i=0;i+1<n;i++)
            ans=max(ans,matching_ind_suffix[i+1]-matching_ind_prefix[i]);
        return ans;

    }
};