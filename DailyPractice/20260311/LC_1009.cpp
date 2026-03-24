class Solution {
public:
    int bitwiseComplement(int n) {
        int ans=0;
        
        int i=0;
        
        if(n==0){
            return 1;
        }
        
        while(n){
            int o=(n%2);
            
            if(o)ans=ans;
            else ans=ans+(1<<i);
            
            n/=2;
            i++;
        }
        
        return ans;
    }
};