//1143 ->leetcode
class Solution {
public:                    
    int Recursion( string &s1 , string &s2 , int n ,int m){
        // Base Case 
        if(m<0 || n<0){
            return 0 ;
        }
        // Problem Tree or Recursion Tree 
        if(s1[n]==s2[m]){
            return 1 + Recursion(s1,s2,n-1,m-1);
        }
        else {
            return max(Recursion(s1 ,s2 , n-1 , m),Recursion(s1,s2,n,m-1));
        }
        
    }
     int BottomUp( string &s1 , string &s2 , int n ,int m , vector<vector<int>>&t){
        // Base Case 
        if(m<0 || n<0){
            return 0 ;
        }
        if(t[n][m]!=-1){
            return t[n][m];
        }
        // Problem Tree or Recursion Tree 
        if(s1[n]==s2[m]){
            return  t[n][m] =1 + BottomUp(s1,s2,n-1,m-1,t);
        }
        else {
            return t[n][m] =max(BottomUp(s1 ,s2 , n-1 , m,t),BottomUp(s1,s2,n,m-1,t));
        }
        
    }
    int TopDowm(string s1 , string s2 , int n, int m){
        vector<vector<int>>t(n+1,vector<int>(m+1,0));
        for( int i=1 ; i<n+1 ;i++){
            for( int j=1; j<m+1 ;j++){
             
           if(s1[i-1]==s2[j-1]){
               t[i][j] =1 + t[i-1][j-1];
        }
        else {
              t[i][j] =max(t[i-1][j],t[i][j-1]);
        }

            }
        }
        return t[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // return Recursion( text1 , text2 , n-1, m -1);
        // vector<vector<int>>t(n+1,vector<int>(m+1,-1));
        // return BottomUp(text1 , text2 , n-1 , m-1 , t );
        return TopDowm(text1,text2,n,m);
    }
};
