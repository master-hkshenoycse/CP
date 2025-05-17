#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int uniqueXorTriplets(vector<int>& nums) {
            int n=nums.size();
    
            unordered_set<int> doubles,singles,triples;
            
    
            for(auto e:nums){
    
                triples.insert(e);
    
                for(auto s:doubles){
                    triples.insert(s^e);
                }
    
                for(auto s:singles){
                    triples.insert(s);
                }
    
    
                for(auto s:singles){
                    doubles.insert(s^e);
                }
                doubles.insert(0);
                singles.insert(e);
    
            }
    
            return triples.size();
        }
    };