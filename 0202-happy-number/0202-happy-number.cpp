class Solution {
public:
    int getNextNumber(int n) {
        int sum = 0;
        while(n > 0){
            int digit = n % 10;
            n = n / 10;
            sum += digit * digit;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = getNextNumber(n);
        while(fast != 1 && fast != slow){
            slow = getNextNumber(slow);
            fast = getNextNumber(getNextNumber(fast));
        }
        return fast == 1;
    }
};