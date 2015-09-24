/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        unordered_set<DirectedGraphNode*> unique;
        stack<DirectedGraphNode*> st;
        topSortGlobal(graph, unique, st);
        
        vector<DirectedGraphNode*> ret;
        while(!st.empty()){
            ret.push_back(st.top());
            st.pop();
        }
        return ret;
    }
    
private:
    void topSortGlobal(vector<DirectedGraphNode*> graph, unordered_set<DirectedGraphNode*> &unique, stack<DirectedGraphNode*> &st){
        for (const auto &node: graph){
            if(unique.count(node) == 0){
                unique.insert(node);
                topSortUtil(node, unique, st);
            }
        }
    }
    
    void topSortUtil(DirectedGraphNode* node, unordered_set<DirectedGraphNode*> &unique, stack<DirectedGraphNode*> &st){
        for (const auto &neighbor: node->neighbors){
            if(unique.count(neighbor) == 0){
                unique.insert(neighbor);
                topSortUtil(neighbor, unique, st);
            }
        }
        st.push(node);
    }
};
