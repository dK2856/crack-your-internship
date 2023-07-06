class Solution {
public:
    // TC-O(1)  ||  SC-O(1)
    // Bit Manipulation is used
    // Simple property of AND is used
    
    bool isPowerOfTwo(int n) {
        
        if(n>0 && (n&(n-1))==0)
            return true;
        else
            return false;
    }
};