/*https://www.geeksforgeeks.org/gray-to-binary-and-binary-to-gray-conversion/*/
int grayToBinary(int n)
    {
        
        // Your code here
        int ans=n;
        for(int b=n>>1;b!=0;b>>=1){
            ans^=(b);
        }
        return ans;
        
    }