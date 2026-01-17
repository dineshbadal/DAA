//  https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
class Solution {
  public:
  bool Memo(vector<int>& arr, int sum,int node,vector<vector<int>>&t){
      //   node*sum  with node is 0 then sum is also zero 
      //    ans vice versa 
     if(t[node][sum]!=-1){
            return t[node][sum];
        }
      int n= arr.size();
        if(sum==0){
            return true;
        }
        if(n==node || sum<0){
            return false ;
        }
        if(sum>=arr[node]){
            return   t[node][sum]=((Memo(arr,sum-arr[node],node+1,t)) ||
            Memo(arr,sum,node+1,t));
        }
        else return  t[node][sum]=Memo(arr,sum,node+1,t);
      
  }
  bool Recursion(vector<int>& arr, int sum,int node){
        int n= arr.size();
        if(sum==0){
            return true;
        }
        if(n==node || sum<0){
            return false ;
        }
        if(sum>=arr[node]){
            return( Recursion(arr,sum-arr[node],node+1) ||
            Recursion(arr,sum,node+1));
        }
        else Recursion(arr,sum,node+1);
  }
    bool topDown(vector<int>& arr, int sum,vector<vector<bool>>&t){
        int row=arr.size();
        int col=sum+1;
          for (int i = 0; i <= row; i++) {
            t[i][0] = true;
        }
        for(int i=1; i<=row;i++){
            for(int j=1; j<=col ; j++){
                if(j>=arr[i-1]){
                t[i][j]=((t[i-1][j-arr[i-1]]) || t[i-1][j]
                                                     );
                }
                else
                 t[i][j]=t[i-1][j];
            }
        }
        return t[row][sum];
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n= arr.size();
        if(n==0) return 0;
        vector<vector<int >>t(n+1,vector<int>(sum+1,-1));
        vector<vector<bool >>td(n+1,vector<bool>(sum+1,0));
        // return Memo()
        return topDown(arr,sum,td);}
};
