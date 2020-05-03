class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        unordered_map <char, int> jewelcheck;
        for (char c : J) {
            jewelcheck[c] = 1;
        }
        for (char c : S) {
            if (jewelcheck[c] == 1) {
                count++;
            }
        }
        return count;
    }
};
