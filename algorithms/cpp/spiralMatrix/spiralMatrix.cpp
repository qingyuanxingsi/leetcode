// Source : https://oj.leetcode.com/problems/spiral-matrix/
// Author : qingyuanxingsi
// Date   : 2016-02-25

/********************************************************************************** 
* 
* Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
* 
* For example,
* Given the following matrix:
* 
* [
*  [ 1, 2, 3 ],
*  [ 4, 5, 6 ],
*  [ 7, 8, 9 ]
* ]
* 
* You should return [1,2,3,6,9,8,7,4,5].
* 
*               
**********************************************************************************/

class Solution {
private:
    vector<int> result;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        auto M = matrix.size();
        if(M == 0){
            return result;
        }
        auto N = matrix[0].size();
        visit(matrix,0,0,M-1,N-1);
        return result;
    }
    
    void visit(vector<vector<int>>& matrix,int x1,int y1,int x2,int y2){
        if(x1 > x2 || y1 > y2){
            return;
        }
        // right
        for(int i=y1;i<=y2;i++){
            result.push_back(matrix[x1][i]);
        }
        // down
        for(int i=x1+1;i<=x2;i++){
            result.push_back(matrix[i][y2]);
        }
        // left when x2 > x1
        if(x2 > x1){
            for(int i=y2-1;i>=y1;i--){
                result.push_back(matrix[x2][i]);
            }
        }
        // up when y2 > y1
        if(y2 > y1){
            for(int i=x2-1;i>x1;i--){
                result.push_back(matrix[i][y1]);
            }
        }
        visit(matrix,x1+1,y1+1,x2-1,y2-1);
    }
};
