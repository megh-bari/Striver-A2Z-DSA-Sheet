/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

 class Solution {
    public:
        vector<vector<int>> treeTraversal(TreeNode* root) {
            vector<int> pre, in, post;
            if (root == NULL) return {pre, in, post};
    
            stack<pair<TreeNode*, int>> st;
            st.push({root, 1});
    
            while (!st.empty()) {
                auto it = st.top();
                st.pop();
    
                  // State 1 means this node needs to be processed for preorder
                if (it.second == 1) {
                    pre.push_back(it.first->data);
                    it.second++;
                    st.push(it);
    
                    if (it.first->left != NULL) {
                        st.push({it.first->left, 1});
                    }
                }
           // State 2 means this node needs to be processed for inorder
                else if (it.second == 2) {
                    in.push_back(it.first->data);
                    it.second++;
                    st.push(it);
    
                    if (it.first->right != NULL) {
                        st.push({it.first->right, 1});
                    }
                }
                // Postorder
                else {
                    post.push_back(it.first->data);
                }
            }
    
            return {pre, in, post};
        }
    };
    
    