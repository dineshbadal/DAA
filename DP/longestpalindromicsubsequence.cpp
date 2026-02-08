// leetcode 516 easy level after solving the LCS 
class Solution {
public:
  int topdown( string s , string s2 , int n , int m ){
    vector<vector<int>>t(n+1 , vector<int>(m+1,0));
    for( int i=1 ; i<=n ;i++){
        for( int j=1; j<=m ; j++){
            if( s[i-1]==s2[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else {
                t[i][j]=max(t[i][j-1],t[i-1][j]);
            }
        }
    }
    return t[n][m];
  }
    int longestPalindromeSubseq(string s) {
         string s2 =  s;
         reverse(s2.begin(),s2.end());
         int n= s.size();
         return topdown(s,s2,n,n);
    }
};
