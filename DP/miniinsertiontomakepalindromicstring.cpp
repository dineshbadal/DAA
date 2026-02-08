class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
         string s2 = s;
         reverse( s2.begin(), s2.end());
         vector<vector<int>>t(n+1 , vector<int>(n+1,0));
         for(int i=1 ; i<n+1 ; i++){
              for(int j=1 ;j<n+1 ; j++){
                if( s[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else {
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
              }
         }
         int lenghtofLCS=t[n][n];
         return n-lenghtofLCS;
    }
};
