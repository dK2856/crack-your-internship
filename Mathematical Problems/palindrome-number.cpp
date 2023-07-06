class Solution {
public:
    bool isPalindrome(int x) {
        int temp=x;
        long long int rev=0;
        while(temp>0)
        {
            int d=temp%10;
            rev=rev*10+d;
            temp=temp/10;
        }
        if(x==rev && x>=0)
            return true;
        else
            return false;
    }
};