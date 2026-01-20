class Solution {
public:
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
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        
        int range =0 ;
        for(int i=0 ; i< n ; i++ ){
            range+=nums[i];
        }
      // EDGES CASES
      // NOW s1+s2=range ;
      // s2-s1=target;
      // add s1=(range+target)/2;
      // now s1 never be the decimal so (range+target)%2!=0 it never be the odd so ans subset never form 
          // nums = [1,2,3]
          // range = 6
          // target = 1
          
          // range + target = 7 (odd)
          // s1 = 3.5 ❌
          // Answer = 0 ✅

        if (abs(target) > range) return 0;
        if((target+range)%2!=0)  return 0;
        int subarrsum=(target+range)/2;
        // apply the count of the subarray with the sum k 
        return BottomUp(nums,subarrsum);
    }
};
