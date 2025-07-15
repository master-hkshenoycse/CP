#include<bits/stdc++.h>
using namespace std;
class FindSumPairs {
    public:
        map<int,int> help;
        int n,m;
        vector<int> a,b;
        FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
            a=nums1;
            b=nums2;
            n=a.size();
            m=b.size();
            help.clear();
            
            for(int i=0;i<m;i++){
                help[b[i]]++;
            }
        }
        
        void add(int index, int val) {
            int c=b[index];
            help[c]--;
            help[c+val]++;
            b[index]+=val;
        }
        
        int count(int tot) {
            int ans=0;
            for(int i=0;i<n;i++){
                ans+=help[tot-a[i]];
            }
            return ans;
        }
    };
    
    /**
     * Your FindSumPairs object will be instantiated and called as such:
     * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
     * obj->add(index,val);
     * int param_2 = obj->count(tot);
     */