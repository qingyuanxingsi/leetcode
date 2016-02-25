// Source : https://oj.leetcode.com/problems/spiral-matrix-ii/
// Author : qingyuanxingsi
// Date   : 2016-02-25

/********************************************************************************** 
* 
* Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
* 
* For example,
* Given n = 3,
* 
* You should return the following matrix:
* 
* [
*  [ 1, 2, 3 ],
*  [ 8, 9, 4 ],
*  [ 7, 6, 5 ]
* ]
* 
*               
**********************************************************************************/

class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> generateMatrix(int n) {
        result.resize(n);
        for(int i=0;i!=n;i++){
            result[i].resize(n);
        }
        fillMatrix(0,0,n-1,n-1,1);
        return result;
    }
    
    void fillMatrix(int x1, int y1, int x2, int y2, int start){
        if(x1>x2 || y1>y2) return;
        // right
        for(int i=y1;i<=y2;i++){
            result[x1][i] = start;
            start++;
        }
        // down
        for(int i=x1+1;i<=x2;i++){
            result[i][y2] = start;
            start++;
        }
        // left
        if(x2 > x1){
            for(int i=y2-1;i>=y1;i--){
                result[x2][i] = start;
                start++;
            }
        }
        // up
        if(y2 > y1){
            for(int i=x2-1;i>x1;i--){
                result[i][y1] = start;
                start++;
            }
        }
        fillMatrix(x1+1,y1+1,x2-1,y2-1,start);
    }
};
