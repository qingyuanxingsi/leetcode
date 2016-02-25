// Source : https://leetcode.com/problems/coin-change/
// Author : qingyuanxingsi
// Date   : 2016-02-25

/*************************************************************************************** 
 *
 * You are given coins of different denominations and a total amount of money amount. 
 * Write a function to compute the fewest number of coins that you need to make up that
 * amount. If that amount of money cannot be made up by any combination of the coins,
 * return -1.
 * 
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 * 
 * Example 2:
 * coins = [2], amount = 3
 * return -1.
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test 
 * cases.
 * 
 ***************************************************************************************/
 /* 
 * Solution 1 - O(N * amount)
 * =========
 *
 * This problem can be solved using dynamic programming, thus building the optimal
 * solution from previous smaller ones. For every coin of value t and every sum of money
 * i the sum can be traced back to a previous sum i - t that was already computed and uses
 * the smallest number of coins possible. This way we can construct every sum i as the
 * minimum of all these previous sums for every coin value. To be sure we'll find a minimum
 * we can populate the solution vector with an amount bigger than the maximum possible, 
 * which is amount + 1(when the sum is made up of only coins of value 1). The only exception
 * is sol[0] which is 0 as we need 0 coins to have a sum of 0. In the end we need to look
 * if the program found a solution in sol[amount] or it remained the same, in which case we
 * can return -1.
 * 
 */
#include <limits.h>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> min_coins(amount+1,INT_MAX);
        for(int i=0;i!=coins.size();i++){
            int coin = coins[i];
            if(coin <= amount){
                min_coins[coins[i]] = 1;
            }
        }
        min_coins[0] = 0;
        for(int i=1;i!=amount+1;i++){
            if(min_coins[i]!=INT_MAX){
                for(int j=0;j!=coins.size();j++){
                    int next = i+coins[j];
                    if(next <= amount){
                        if(min_coins[i]+1 < min_coins[next]){
                            min_coins[next] = min_coins[i]+1;
                        }
                    }
                }
            }
        }
        return min_coins[amount] == INT_MAX ? -1:min_coins[amount];
    }
};
