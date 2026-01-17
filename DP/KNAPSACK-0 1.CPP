class Solution {
  public:
  // recursion is included in the memo. method
  //  memoziation should be done here 
  //  int W, vector<int> &val, vector<int> &wt
  //  vector<vector<int>>&t;
    int TopDown(int W, vector<int> &val, vector<int> &wt,vector<vector<int>>&t){
       int n=val.size();
        for(int i=1 ; i<=n;i++){// rows
            for(int j=1 ; j<=W;j++){// cols
                if(wt[i-1]<=j){
                    t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
                }
                else t[i][j]=t[i-1][j];
            }
        }
        return t[n][W];
    }
    // int findwight(int W, vector<int> &val, vector<int> &wt,int node , vector<vector<int>>&t ){
    //      if(W==0  || node==val.size()){
    //       return 0;
    //      }
    //         if(t[W][node]!=-1){
    //              return t[W][node];
    //          }
         
    //     if(W>=wt[node]){
    //          return t[W][node]=max(val[node]+findwight(W-wt[node],val,wt,node+1,t),
    //         findwight(W,val,wt,node+1,t));}
        
    //     else return t[W][node]=findwight(W,val,wt,node+1,t);
        
    
    // }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        // here we have two cases we ca
        int n=val.size();
        vector<vector<int>>t(n+1,vector<int>(W+1,0));
        // return findwight(W,val,wt,0,t);
       
        int ans = TopDown(W,val,wt,t);
        return ans;
    }
   
};
