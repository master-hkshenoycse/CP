#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        // Your code here
        vector<int> sol;
        
        for(int i=0;i<n+2;i++){
            int index=abs(arr[i]);
            if(arr[index]<0){
                sol.push_back(index);        //means number is already visisted
            }else{
                arr[index]*=-1;
            }
        }
        
        return sol;
    }
};