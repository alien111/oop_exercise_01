
#include <iostream>
#include <string>

class BitString
{
public:

    BitString();
    BitString(unsigned long long first, unsigned long long second);

    BitString* _not();
    BitString* _and(BitString *bs);
    BitString* _or(BitString *bs);
    BitString* _xor(BitString *bs);
 
    void shiftLeft(unsigned long long n);
    void shiftRight(unsigned long long n);

    unsigned long long posBitNumber();
    int compPosBitNumber(BitString *bs);

    void isArgInThis(BitString *bs);

    void print();

private:
    unsigned long long firstHalf;
    unsigned long long secondHalf;
    
    
};

