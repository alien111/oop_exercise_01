#include "BitString.h"

int main(int argc, char** argv) {

    BitString bs;

    bs.Enter();

    BitString bs1;

    bs1.Enter();

    bs.print();
    bs1.print();

    BitString bsTest = bs._not();

    std::cout << "not first number:\n";

    bsTest.print();

    bsTest = bs._and(bs1);

    std::cout << "first and second:\n";

    bsTest.print();

    bsTest = bs._or(bs1);

    std::cout << "first or second:\n";

    bsTest.print();
    
    bsTest = bs._xor(bs1);

    std::cout << "first xor second:\n";

    bsTest.print();

    std::cout << "Positive Bit Number of First is " << bs.posBitNumber() << '\n';

    if (bs.compPosBitNumber(bs1) == 0) {
        std::cout << "Bit Comparence of first and second shows that first is larger\n";
    } else if (bs.compPosBitNumber(bs1) == 1) {
        std::cout << "Bit Comparence of first and second shows that second is larger\n";
    } else {
        std::cout << "Bit Comparence of first and second shows that they are equal\n";
    }

    std::cout << "Is second in first? : ";
    bs.isArgInThis(bs1);

    int shift;

    std::cout << "Enter number of bits to shift first number left and second right : ";
    std::cin >> shift;

    bs.shiftLeft(shift);

    std::cout << "Shifted first left : \n";
    bs.print();

    bs1.shiftRight(shift);

    std::cout << "Shifted second right : \n";
    bs1.print();




    return 0;
}