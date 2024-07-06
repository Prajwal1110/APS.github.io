#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>

using namespace std;

// Function to calculate SHA-256 hash
string sha256(const string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

// MerkleNode class definition
class MerkleNode {
public:
    MerkleNode* left;
    MerkleNode* right;
    string data;
    bool is_leaf;
    string hash;

    // Constructor
    MerkleNode(MerkleNode* left, MerkleNode* right, string data, bool is_leaf=false) 
        : left(left), right(right), data(data), is_leaf(is_leaf) {
        this->hash = calculate_hash();
    }

    // Calculate hash
    string calculate_hash() {
        if (is_leaf) {
            return sha256(data);
        } else {
            string left_hash = left ? left->hash : "";
            string right_hash = right ? right->hash : "";
            return sha256(left_hash + right_hash);
        }
    }
};

// MerkleTree class definition
class MerkleTree {
public:
    MerkleNode* root;
    vector<MerkleNode*> leaves;

    // Constructor
    MerkleTree(vector<string>& data_list) {
        for (const string& data : data_list) {
            leaves.push_back(new MerkleNode(nullptr, nullptr, data, true));
        }
        root = build_tree(leaves);
    }

    // Build tree
    MerkleNode* build_tree(vector<MerkleNode*>& nodes) {
        if (nodes.size() == 1) {
            return nodes[0];
        }
        vector<MerkleNode*> new_level;
        for (size_t i = 0; i < nodes.size(); i += 2) {
            MerkleNode* left = nodes[i];
            MerkleNode* right = (i + 1 < nodes.size()) ? nodes[i + 1] : nullptr;
            new_level.push_back(new MerkleNode(left, right, ""));
        }
        return build_tree(new_level);
    }
};

// Example usage
int main() {
    vector<string> transactions = {"Transaction1", "Transaction2", "Transaction3", "Transaction4"};
    MerkleTree merkle_tree(transactions);
    cout << "Merkle Root: " << merkle_tree.root->hash << endl;
    return 0;
}
