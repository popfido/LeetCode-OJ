class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        queue<string> current, next;
        unordered_set<string> visited;
        int level = 0;
        bool found = false;
        
        auto state_is_target = [&](const string &s) {return s == end;};
        auto state_extended = [&](const string &s){
            vector<string> result;
            
            for (size_t i=0; i<s.size(); i++){
                string new_word(s);
                for (char c='a'; c<= 'z';c++){
                    if (c==new_word[i]) continue;
                    
                    swap(c, new_word[i]);
                    if((dict.count(new_word) > 0 || new_word == end) && !visited.count(new_word)) {
                        result.push_back(new_word);
                        visited.insert(new_word);
                    }
                    swap(c, new_word[i]);
                }
            }
            return result;
        };
        
        current.push(start);
        while(!current.empty() && !found){
            ++level;
            while((!current.empty()&&!found)) {
                const string str = current.front();
                current.pop();
                const auto& new_state = state_extended(str);
                for (const auto& state : new_state) {
                    next.push(state);
                    if(state_is_target(state)){
                        found = true;
                        break;
                    }
                }
            }
            swap(next,current);
        }
        if(found) return level + 1;
        else return 0;
    }
};
