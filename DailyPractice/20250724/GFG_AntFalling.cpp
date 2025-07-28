class Solution {
    public:
      int getLastMoment(int n, vector<int>& left, vector<int>& right) {
          // code here
          int answer=0;
          for(auto l:left){
              answer=max(answer,l);
          }
          
          for(auto r:right){
              answer=max(answer,n-r);
          }
          
          return answer;
      }
  };