class Solution {
public:
    int firstUniqChar(string s) {
        if (s.length() == 0)
            return -1;
        vector <int> vect(26, 0);
        int i = 0;
        for (char c : s) {
            vect[c - 'a']++;
        }
        for (char c : s) {
            if (vect[c - 'a'] == 1) {
                break; 
            } 
            i++;
        }
        if (i == s.length()) {
            return -1;
        }
        return i;
    }
};
