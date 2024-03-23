#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int> arr, int k) {
        map<int,int> help;
        for(auto e:arr){
            help[e]++;
        }
        vector<int> freq;
        for(auto it:help){
            freq.push_back(it.second);
        }
        sort(freq.begin(),freq.end());
        for(int i=0;i<freq.size();i++){
            int del=min(freq[i],k);
            freq[i]-=del;
            k-=del;
        }
        int ans=0;
        for(int i=0;i<freq.size();i++){
            if(freq[i]>0){
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    cout<<sol.findLeastNumOfUniqueInts({5,5,4},1)<<endl;
    cout<<sol.findLeastNumOfUniqueInts({4,3,1,1,3,3,2},3)<<endl;
}

/*https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description
Greedy- remove elements with least frequnecy
*/