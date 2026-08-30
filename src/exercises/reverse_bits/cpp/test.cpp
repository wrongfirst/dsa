#include <cstdint>

uint32_t reverseBits(uint32_t n);

int main() {
    Tests.equal_check("Example 1", (uint32_t)2818572288u, reverseBits(0b00000000000000000000000000010101));
    return 0;
}
