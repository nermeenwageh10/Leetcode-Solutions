/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        return to_string(root->val) + "(" + serialize(root->left) + ")" + "|" 
            + "(" + serialize(root->right) + ")"; 
    }
    bool isDigit(char c){
        return c == '-' || (c >= '0' && c <= '9');
    }
    TreeNode* build(string s, int left, int right){

        if (left >= right) return nullptr;
        if (left + 1 == right) return nullptr;
        int val = 0;
        bool hasValue = 0, negative = 0;
        while (left <= right && isDigit(s[left])){
            hasValue = 1;
            if (s[left] != '-')
                val = val * 10 + s[left] - '0';
            else 
                negative = 1;
            left++;
        }
        if (!hasValue) return nullptr;
        if (negative) val *= -1;
        TreeNode* root = new TreeNode(val);
        int cnt = 0;
        int leftPart = left;
        while (leftPart <= right){
            if (s[leftPart] == '(') cnt++;
            if (s[leftPart] == ')') cnt--;
            if (cnt == 0) break;
            leftPart++;
        }
        root->left = build(s, left + 1, leftPart);
        root->right = build(s, leftPart + 3, right);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return build(data, 0, data.size()-1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;