#include <iostream>
#include <bitset>

int main() {
    int number = 204536; // ตัวเลขที่ต้องการแปลง
    std::bitset<32> binaryRepresentation(number); // แปลงเป็นไบนารี่ 32 บิต

    std::cout << binaryRepresentation << std::endl; // แสดงผล

    return 0;
}
