// Source : https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author : qingyuanxingsi
// Date   : 2016-02-25

/********************************************************************************** 
* 
* Given a binary tree, flatten it to a linked list in-place.
* 
* For example,
* Given
* 
*          1
*         / \
*        2   5
*       / \   \
*      3   4   6
* 
* The flattened tree should look like:
* 
*    1
*     \
*      2
*       \
*        3
*         \
*          4
*           \
*            5
*             \
*              6
* 
* 
* Hints:
* If you notice carefully in the flattened tree, each node's right child points to 
* the next node of a pre-order traversal.
*               
**********************************************************************************/

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
public:
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        if(root->left == NULL){
            flatten(root->right);
        }
        else{
            flatten(root->left);
            flatten(root->right);
            TreeNode* p = root->left;
            TreeNode* s = p;
            TreeNode* q = root->right;
            while(s->right!=NULL){
                s = s->right;
            }
            s->right = q;
            root->right = p;
            root->left = NULL;
        }
    }
};
