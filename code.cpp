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
class FindElements {
public:
    set<int>A;
    void change (TreeNode* root)
    {
        if(root!=NULL)
        {
            if(root->left!=NULL)
            {
                root->left->val=root->val*2+1;
                A.insert(root->left->val);
            }
            if(root->right!=NULL)
            {
                root->right->val=root->val*2+2;
                A.insert(root->right->val);
            }
            change(root->left);
            change(root->right);
        }
    }
    FindElements(TreeNode* root) {
        root->val=0;
        A.insert(root->val);
        change(root);
    }
    
    bool find(int target) {
   //     auto s=A.find(target);
        if(A.find(target)!=A.end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
