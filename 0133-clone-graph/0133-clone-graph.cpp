class Solution {
public:
    unordered_map<Node*, Node*> cloned;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // If already cloned, return the clone
        if (cloned.find(node) != cloned.end())
            return cloned[node];

        // Clone current node
        Node* clone = new Node(node->val);
        cloned[node] = clone;

        // Recursively clone all neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};
