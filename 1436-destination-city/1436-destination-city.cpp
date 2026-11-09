
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> start;

        for (auto &p : paths) {
            start.insert(p[0]);
        }

        for (auto &p : paths) {
            if (start.find(p[1]) == start.end()) {
                return p[1];
            }
        }

        return "";
    }
};
