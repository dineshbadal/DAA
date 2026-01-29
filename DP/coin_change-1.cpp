// leetcode - 322 
// with the recursion and bottom up approach 
class Solution {
public:
    int Recursion(vector<int>& coins, int amount, int node) {
        // amount ==0 return 1 ;
        // amount <0 then 0 ;
        // node ==0  return 0  -->this mistake that i done and getting the ans as 0 for every case 
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX - 10000;  // to prevent the int overflow 
        if (node < 0)
            return INT_MAX - 10000;
        if (amount >= coins[node]) {
            return min((1 + Recursion(coins, amount - coins[node], node)),
                       Recursion(coins, amount, node - 1));
        } else
            return Recursion(coins, amount, node - 1);
    }
    int BottomUp(vector<int>& coins, int amount, int node,
                 vector<vector<int>>& t) {

        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX - 10000;
        if (node < 0)
            return INT_MAX - 10000;
        if (t[node][amount] != -1) {
            return t[node][amount];
        }
        if (amount >= coins[node]) {
            return t[node][amount] =
                       min((1 + BottomUp(coins, amount - coins[node], node, t)),
                           BottomUp(coins, amount, node - 1, t));
        } else
            return t[node][amount] = BottomUp(coins, amount, node - 1, t);
    }
    int coinChange(vector<int>& coins, int amount) {
        //  if(amount ==0 ) return 0;
        // if(coins.size()==1 && amount%coins[0]==0) return amount/coins[0];
        if (coins.size() == 1 && amount % coins[0] != 0)
            return -1;
        // return Recursion(coins , amount , coins.size()-1);
        vector<vector<int>> t(coins.size() + 1, vector<int>(amount + 1, -1));
        int ans = BottomUp(coins, amount, coins.size() - 1, t);
        if (ans >= INT_MAX - 10000)
        return -1;
        return ans;
    }
};
