class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        map<string,int> help;
        for(int i=0;i<n;i++){
            help[nums[i]]=1;
        }
        
        for(int i=0;i<(1<<n);i++){
            string y;
            for(int j=0;j<n;j++){
                if(i &(1<<j))y+='1';
                else y+='0';
            }
            if(help.find(y) == help.end()){
                return y;
            }
        }
        return "1";
    }
};