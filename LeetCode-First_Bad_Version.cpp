// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 1)
            return 1;
        if (n == 2) {
            return isBadVersion(1) ? 1 : 2;
        }
        long long int low = 1, high = n;
        long long int mid;
        if (high == INT_MAX){
            mid = high / 2;
        }
        else{
            mid = (n + 1) / 2;
        }
        while(!(isBadVersion(mid) == 1 && isBadVersion(mid + 1) == 1 && isBadVersion(mid - 1) == 0)) {
            if (isBadVersion(mid) == 1)
                high = mid - 1;
            else
                low = mid + 1;
            mid = (low + high) / 2;
            if (mid == high) {
                if (isBadVersion(mid) == 1 && isBadVersion(mid - 1) == 0){
                    break;
                }
            }
            if (mid == low && mid != high) {
                if (isBadVersion(mid) == 1 && isBadVersion(mid + 1) == 1){
                    break;
                }
            }
        }
        return mid;
    }
};
