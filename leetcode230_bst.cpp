#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        to_out.clear();
        inorder(root, k);
        return to_out[k-1];
    }
    void inorder(TreeNode* root, int k)
    {

        if(root == nullptr)
        {
            return;
        }
        if(flag)
            return;;
        inorder(root->left, k);
        if(flag)
            return;
        to_out.push_back(root->val);
        //cout << root->val << "\n";
        if(to_out.size()==k)
        {
            //cout << to_out[k-1];
            flag = true;
            return;
        }
        if(flag)
            return;
        inorder(root->right, k);
    }


    vector<int> to_out;
    bool flag = false;

};
}
