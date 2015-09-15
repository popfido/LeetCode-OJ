/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if (!node) return NULL;
        
        unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*> copied;
        clone(node, copied);
        return copied[node];
    }
    
    UndirectedGraphNode* clone(const UndirectedGraphNode* node, unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*> &copied){
        if (copied.find(node)!=copied.end()) return copied[node];
        
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        copied[node] = new_node;
        for (auto nbr: node->neighbors)
            new_node->neighbors.push_back(clone(nbr,copied));
        return new_node;
    }
};
