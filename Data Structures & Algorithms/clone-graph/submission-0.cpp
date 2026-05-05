class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {
        if (!node) return nullptr;

        // If already cloned, return it
        if (mp.count(node)) return mp[node];

        // Create clone
        Node* clone = new Node(node->val);
        mp[node] = clone;

        // Clone neighbors
        for (auto nei : node->neighbors) {
            clone->neighbors.push_back(dfs(nei));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};