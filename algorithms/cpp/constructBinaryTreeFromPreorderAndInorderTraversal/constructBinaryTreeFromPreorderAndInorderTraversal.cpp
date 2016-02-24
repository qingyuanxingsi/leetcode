// Source : https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author : qingyuanxingsi
// Date   : 2016-02-24

/********************************************************************************** 
* 
* Given preorder and inorder traversal of a tree, construct the binary tree.
* 
* Note:
* You may assume that duplicates do not exist in the tree.
* 
*               
**********************************************************************************/

#include <map>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    map<int,int> posMap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        auto vec_num = inorder.size();
        for(int i=0;i!=vec_num;i++){
            posMap[inorder[i]] = i;
        }
        return helper(preorder,0,vec_num-1,inorder,0,vec_num-1);
    }
    
    TreeNode* helper(vector<int>& preorder,int start1,int end1,vector<int>& inorder,int start2,int end2){
        if(start1 > end1 || start2 > end2){
            return NULL;
        }
        int rootVal = preorder[start1];
        TreeNode* head = new TreeNode(rootVal);
        int rootIndex = posMap[rootVal];
        head->left = helper(preorder,start1+1,start1+rootIndex-start2,inorder,start2,rootIndex-1);
        head->right = helper(preorder,end1-end2+rootIndex+1,end1,inorder,rootIndex+1,end2);
        return head;
    }
};
