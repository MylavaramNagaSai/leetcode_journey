#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for (int i = 0; i < 32; ++i) {
            result <<= 1;            // Left-shift result to make room
            result |= (n & 1);       // Add the least significant bit of n
            n >>= 1;                 // Right-shift n to process the next bit
        }

        return result;
    }
};
