class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        
        int n=word.size();
        
        for(int j=0;j<patterns.size();j++){
            string y=patterns[j];
            int m=y.size();
            int f=0;
            for(int i=0;i<n-m+1;i++){
                
                if(word.substr(i,m)==y){
                    f=1;
                    break;
                }
            }
            ans=ans+f;
        }
        
        
        return ans;
    }
};