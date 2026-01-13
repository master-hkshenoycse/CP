#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> target = nums2;

        if(nums1==nums2) return 0;

        queue<vector<int> > q;
        set<vector<int> > vis;

        q.push(nums1);
        vis.insert(nums1);
        int steps=0;

        while(q.size()>0){
            int sz=q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();

                if(curr==target) return steps;

                for(int l=0;l<n;l++){
                    for(int r=l;r<n;r++){
                        vector<int> rem (curr.begin()+l,curr.begin()+r+1);
                        vector<int> new_list;
                        new_list.insert(new_list.end(), curr.begin(), curr.begin()+l);
                        new_list.insert(new_list.end(),curr.begin()+r+1,curr.end());

                        int rem_sz=new_list.size();

                        for(int idx=0;idx<=rem_sz;idx++){
                            vector<int> final_new_list=new_list;
                            final_new_list.insert(final_new_list.begin()+idx,rem.begin(), rem.end());
                            if(!vis.count(final_new_list)){
                                vis.insert(final_new_list);
                                q.push(final_new_list);
                            }
                        }
                    }
                }
            }
            steps++;
        }

        return -1;

    }
};