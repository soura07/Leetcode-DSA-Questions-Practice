class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int>sortedNodes;
        inOrderDfs(root,sortedNodes);
        int minDifference = INT_MAX;
        for (int i = 1; i < sortedNodes.size(); i++){
            minDifference = min(minDifference, sortedNodes[i] - sortedNodes[i - 1]);
        }
        return minDifference;
    }
    void inOrderDfs(TreeNode*root, vector<int>& sortedNodes){
        if (root == nullptr) return;
        inOrderDfs(root->left, sortedNodes);
        sortedNodes.push_back(root->val);
        inOrderDfs(root->right, sortedNodes);
    }
};
