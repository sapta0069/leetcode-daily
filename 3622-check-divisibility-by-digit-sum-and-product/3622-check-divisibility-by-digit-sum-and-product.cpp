class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int s = 0;
        int m = 1;
        while(temp>0){
            int dig = temp%10;
            s+=dig;
            m*=dig;
            temp /= 10 ;

        }

        int tot = s+m;
        if (n % tot== 0)
    return true;
else
    return false;
    }
};