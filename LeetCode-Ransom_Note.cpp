class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char, int> charmap;
        for (char c : magazine) {
            charmap[c]++;
        }
        for (char c : ransomNote) {
            --charmap[c];
            if (charmap[c] < 0) 
                return 0;
        }
        return 1;
    }
};
