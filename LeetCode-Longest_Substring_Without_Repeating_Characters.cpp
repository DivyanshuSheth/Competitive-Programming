class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0, current_sum = 0;
        unordered_map <char, int> charcount;
        for (int j = 0; )
        for (char c : s) {
            if (charcount[c] != 0) {
                answer = max(answer, current_sum);
                charcount.clear();
                charcount[c]++;
                current_sum = 1;
                answer = max(answer, current_sum);
            }
            else {
                charcount[c]++;
                current_sum++;
                answer = max(answer, current_sum);
            }
        }
        return answer;
    }
};
