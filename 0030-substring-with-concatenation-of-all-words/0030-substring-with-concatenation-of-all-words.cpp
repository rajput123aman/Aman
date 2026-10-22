
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        if (words.empty() || s.empty()) return ans;

        int n = s.size();
        int len = words[0].size();
        int k = words.size();

        if (n < len * k) return ans;

        unordered_map<string, int> mp;

        for (const string& word : words) {
            mp[word]++;
        }

        for (int start = 0; start < len; start++) {
            int left = start;
            int count = 0;

            unordered_map<string, int> seen;

            for (int right = start; right + len <= n; right += len) {
                string word = s.substr(right, len);

                if (mp.find(word) == mp.end()) {
                    seen.clear();
                    count = 0;
                    left = right + len;
                    continue;
                }

                seen[word]++;
                count++;

                while (seen[word] > mp[word]) {
                    string leftWord = s.substr(left, len);
                    seen[leftWord]--;
                    count--;
                    left += len;
                }

                if (count == k) {
                    ans.push_back(left);

                    string leftWord = s.substr(left, len);
                    seen[leftWord]--;
                    count--;
                    left += len;
                }
            }
        }

        return ans;
    }
};
