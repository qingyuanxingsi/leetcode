// Source : https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Author : qingyuanxingsi
// Date   : 2016-02-24

/********************************************************************************** 
* 
* Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        auto elemLen = inorder.size();
        if(elemLen == 0){
            return NULL;
        }
        for(int i=0;i!=elemLen;i++){
            posMap.insert(pair<int,int>(inorder[i],i));
        }
        return recoverTree(inorder,0,elemLen-1,postorder,0,elemLen-1);
    }
    
    TreeNode* recoverTree(vector<int>& inorder,int inStart,int inEnd,vector<int>& postorder,int postStart,int postEnd){
        int rootVal = postorder[postEnd];
        if(inStart > inEnd || postStart > postEnd){
            return NULL;
        }
        TreeNode* head = new TreeNode(rootVal);
        int rootIndex = posMap[rootVal];
        head->left = recoverTree(inorder,inStart,rootIndex-1,postorder,postStart,postStart+rootIndex-inStart-1);
        head->right = recoverTree(inorder,rootIndex+1,inEnd,postorder,postEnd-(inEnd-rootIndex),postEnd-1);
        return head;
    }
};
