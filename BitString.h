
#include <iostream>
#include <string>

class BitString
{
public:

    BitString();
    
    void Enter();

    BitString _not();
    BitString _and(const BitString &bs);
    BitString _or(const BitString &bs);
    BitString _xor(const BitString &bs);
 
    void shiftLeft(unsigned long long n);
    void shiftRight(unsigned long long n);

    unsigned long long posBitNumber();
    int compPosBitNumber(BitString &bs);

    void isArgInThis(const BitString &bs);

    void print();

private:
    unsigned long long firstHalf;
    unsigned long long secondHalf;
    
    
};

