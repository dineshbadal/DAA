// This is on the geekforgeek 
class Solution {
  public:
    int topdown(string &s1, string&s2){
        int n=s1.size();
        int m=s2.size();
                int ans=0;
        vector<vector<int>>t(n+1,vector<int>(m+1,0));
        for( int i=1 ; i<=n ;i++){
            for( int j=1 ; j<=m ; j++){
                  if(s1[i-1]==s2[j-1]){
                      t[i][j]=1+ t[i-1][j-1];
                      
                  }
               ans = max(ans,t[i][j]);
            }
        }
        return ans;
    }
    int Recursion(string &s1, string&s2,int n , int m , int cnt){
        if(n<0 || m<0){
            return cnt ;
        }
       int currcount=cnt;
        if(s1[n]==s2[m]){
          currcount= Recursion(s1,s2,n-1,m-1,cnt+1);
        }
      
         int c1 = Recursion(s1,s2,n-1,m,0);
         int c2 = Recursion(s1,s2,n,m-1,0);
        return max({currcount,c1,c2});
    }
    int longCommSubstr(string& s1, string& s2) {
        // your code here
        // return Recursion(s1,s2,s1.size()-1,s2.size()-1,0);
        return topdown(s1,s2);
    }
};
