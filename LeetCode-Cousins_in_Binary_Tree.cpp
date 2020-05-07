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
class Solution {
public:
    bool same_parent_check(TreeNode * root, int x, int y) {
        int x_order = 0, y_order = 0, found = ((root -> val == x) ? 1 : 0);
        queue <TreeNode *> order_x;
        order_x.push(root); 
        while (!found) {
            if (order_x.front() == NULL) { order_x.pop();    x_order++;    continue; }
            else if (order_x.front() -> val == x) { found = 1; }
            order_x.push(order_x.front() -> left);
            order_x.push(order_x.front() -> right);
            order_x.pop();
            x_order++;
        }
        found = root -> val == y ? 1 : 0;
        queue <TreeNode *> order_y;
        order_y.push(root);
        while (!found) {
            if (order_y.front() == NULL) { order_y.pop();    y_order++;    continue; }
            else if (order_y.front() -> val == y) { found = 1; }
            order_y.push(order_y.front() -> left);
            order_y.push(order_y.front() -> right);
            order_y.pop();
            y_order++;
        }
        if (x_order / 2 == y_order / 2) {
            return 1;
        }
        else return 0;
    }
    int node_depth(TreeNode * root, int x) {
        if (root -> val == x) {
            return 0;
        }
        else if (root -> left == NULL || root -> right == NULL) {
            if (root -> left == NULL && root -> right == NULL) return INT_MAX - 10001;
            else if (root -> left == NULL) return 1 + node_depth(root -> right, x);
            else return 1 + node_depth(root -> left, x);
        }
        else {
            return 1 + min(node_depth(root -> left, x), node_depth(root -> right, x));
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int x_depth = node_depth(root, x);
        int y_depth = node_depth(root, y);
        if (x_depth == y_depth && !same_parent_check(root, x, y)) return 1;
        else return 0;
    }
};
