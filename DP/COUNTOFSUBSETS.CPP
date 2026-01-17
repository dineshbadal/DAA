//https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
class Solution {
          public:
          int     Recursion(vector<int>&arr, int target , int node , int ans){
              if( target == 0  &&  node==arr.size()){
                  return 1;
              }
              if(target>0 &&  node==arr.size()){
                  return 0;
              }
              if(target>=arr[node]){
                ans+=  Recursion(arr,target-arr[node],node+1,ans)+
                  Recursion(arr,target,node+1,ans);
              }
              else ans+=  Recursion(arr,target,node+1,ans);
              return ans;
          }
            int Memoization(vector<int>&arr,int target ,int node,vector<vector<int>>&t){
                if(t[node][target]!=-1){
                    return t[node][target];
                }
                      if( target == 0  &&  node==arr.size()){
                  return 1;
              }
              if(target>0 &&  node==arr.size()){
                  return 0;
              }
              if(target>=arr[node]){
                t[node][target]= Memoization(arr,target-arr[node],node+1,t)+
                  Memoization(arr,target,node+1,t);
              }
              else t[node][target]=  Memoization(arr,target,node+1,t);
              return t[node][target];  
            }
            int BottomUp(vector<int>& arr, int target){
                 int n=arr.size();
                vector<vector<int>>t(n+1,vector<int>(target+1,0));
                for(int i=0 ; i<=n;i++){
                    t[i][0]=1;
            } t[0][0]=1;
                for(int i=1; i<=n ;i++){
                    for(int j=0;j<=target;j++){
                        if(j>=arr[i-1]){
                            t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
                        }
                        else t[i][j]=t[i-1][j];
                    }
                }
                return t[n][target];
            }
            int perfectSum(vector<int>& arr, int target) {
                // code here
                int n=arr.size();
                int ans=0 ;
                vector<vector<int>>t(n+1,vector<int>(target+1,-1));
        
                // return Recursion(arr,target,0,ans);
                // return Memoization(arr,target,0, t);
                   return BottomUp(arr,target);
                
            }
        };
