#include <cstdint>

int getSum(int a, int b) {
    while (b != 0) {
        uint32_t carry = static_cast<uint32_t>(a & b) << 1;
        a = a ^ b;
        b = static_cast<int>(carry);
    }
    return a;
}
