#include <string>
#include <sstream>
#include <vector>

class Codec {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::string res;
        serializeHelper(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const std::string& data) {
        std::stringstream ss(data);
        return deserializeHelper(ss);
    }

private:
    void serializeHelper(TreeNode* root, std::string& res) {
        if (root == nullptr) {
            res += "N,";
            return;
        }
        res += std::to_string(root->val) + ",";
        serializeHelper(root->left, res);
        serializeHelper(root->right, res);
    }

    TreeNode* deserializeHelper(std::stringstream& ss) {
        std::string val;
        if (!std::getline(ss, val, ',')) {
            return nullptr;
        }
        if (val == "N" || val.empty()) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(std::stoi(val));
        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);
        return node;
    }
};
