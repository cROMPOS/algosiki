/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

bool rec (TreeNode* r1, TreeNode* r2) {
    cout << "l: " << r1->val << " r: " << r2->val <<endl;

    if ( (r1->left != nullptr && r2->right == nullptr) || (r1->left == nullptr && r2->right != nullptr) || (r1->right != nullptr && r2->left == nullptr) || (r1->right == nullptr && r2->left != nullptr) ) {
        return false;
    } 

    if (r1->val != r2->val) {
        return false;
    }

    if (r1->left != nullptr && r1->right != nullptr && r2->left != nullptr && r2->right != nullptr) {
        if ((r1->left->val != r2->right->val) || (r1->right->val != r2->left->val)) {
                return false;
            }
    }
    
    
    if (r1->right != nullptr) {
        if (rec(r1->right, r2->left) == false) {
            return false;
        }
    }

    if (r1->left != nullptr) {
        if (rec(r1->left, r2->right) == false) {
            return false;
        }
    }

    return true;
}


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root!=NULL && root->left == nullptr && root->right == nullptr) {
            return true;
        }
        else if (root!= NULL && root->left != nullptr && root->right!=nullptr && root->left->val == root->right->val) {
            cout << "l: "<<endl;
            return rec(root->left, root->right);
        }
        else {
            return false;
        }
    }
};