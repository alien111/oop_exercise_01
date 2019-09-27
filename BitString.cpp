#include "BitString.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

BitString::BitString() {

    firstHalf = 0;
    secondHalf = 0;

}


void BitString::Enter() {
    std::string str;

    std::cout << '\n' << "Enter string" << '\n';
    std::cin >> str;

    std::string sec(str.size(), '0');
    std::vector<int> v;

    while (str != sec) {
        int a = 0;
        for (int i = 0; i < str.size(); i++) {
            a *= 10;
            a += str[i] - '0';
            str[i] = char('0' + a / 2);
            a %= 2;
        }
        v.push_back(a);
    }



    unsigned long long shs = 1;

    for (int i = 0; i < 64 && i < v.size(); i++) {
        secondHalf += v[i] * shs;
        shs *= 2;
    }

    unsigned long long fhs = 1;

    for (int i = 64; i < v.size(); i++) {
        firstHalf += v[i] * fhs;
        fhs *= 2;
    }
}

BitString BitString::_not() {

    BitString bs;

    bs.firstHalf = ~(firstHalf);
    bs.secondHalf = ~(secondHalf);

    return bs;
}


BitString BitString::_and(const BitString &bs) {

    BitString bs1;
    bs1.firstHalf = firstHalf & bs.firstHalf;
    bs1.secondHalf = secondHalf & bs.secondHalf;

    return bs1;
    
}


BitString BitString::_or(const BitString &bs) {

    BitString bs1;
    bs1.firstHalf = firstHalf | bs.firstHalf;
    bs1.secondHalf = secondHalf | bs.secondHalf;

    return bs1;

}


BitString BitString::_xor(const BitString &bs) {

    BitString bs1;
    bs1.firstHalf = firstHalf ^ bs.firstHalf;
    bs1.secondHalf = secondHalf ^ bs.secondHalf;

    return bs1;

}

void BitString::shiftLeft(unsigned long long n) {
    
    unsigned long long pow63 = 1;
    for (int i = 0; i < 63; i++) {
        pow63 *= 2;
    }

    for (int i = 0; i < n; i++) {                                          //110100111 << 3 == 100111000
        firstHalf = firstHalf << 1;
        if (secondHalf >= pow63) {
            firstHalf += 1;
        }
        secondHalf = secondHalf << 1;
    }
}

void BitString::shiftRight(unsigned long long n) {                         //110100111 >> 3 == 000110100

    unsigned long long pow63 = 1;
    for (int i = 0; i < 63; i++) {
        pow63 *= 2;
    }
    for (int i = 0; i < n; i++) {
        secondHalf = secondHalf >> 1;
        if (firstHalf % 2 == 1) {
            secondHalf += pow63;
        }
        firstHalf = firstHalf >> 1;
    }


}

unsigned long long BitString::posBitNumber(){

    BitString bs1;
    bs1.firstHalf = firstHalf;
    bs1.secondHalf = secondHalf;

    unsigned long long number = 0;

    while (bs1.firstHalf != 0) {
        if (bs1.firstHalf % 2 == 1) number++;
        bs1.firstHalf /= 2;
    }

    while (bs1.secondHalf != 0) {
        if (bs1.secondHalf % 2 == 1) number++;
        bs1.secondHalf /= 2;
    }

    return number;

}

int BitString::compPosBitNumber(BitString &bs) {
    unsigned long long thisNumber = posBitNumber();
    unsigned long long bsNumber = bs.posBitNumber();

    if (thisNumber > bsNumber) return 0;
    if (thisNumber < bsNumber) return 1;
    else return 2;

}

void BitString::isArgInThis(const BitString &bs) {

    BitString lbs;
    lbs.firstHalf = firstHalf;
    lbs.secondHalf = secondHalf;
    BitString sbs;
    sbs.firstHalf = bs.firstHalf;
    sbs.secondHalf = bs.secondHalf;
    
    std::vector<int> vflbs;
    std::vector<int> vfsbs;

    std::vector<int> vslbs;
    std::vector<int> vssbs;
    

    while (lbs.firstHalf != 0) {
        vflbs.push_back(lbs.firstHalf % 2);
        lbs.firstHalf /= 2;
    }

    
    for (int i = vflbs.size(); i < 64 ; i++) {
        vflbs.push_back(0);
    }
    
    while (lbs.secondHalf != 0) {
        vslbs.push_back(lbs.secondHalf % 2);
        lbs.secondHalf /= 2;
    }
    for (int i = vslbs.size(); i < 64; i++) {
        vslbs.push_back(0);
    }
    





    while (sbs.firstHalf != 0) {
        vfsbs.push_back(sbs.firstHalf % 2);
        sbs.firstHalf /= 2;
    }

    for (int i = vfsbs.size(); i < 64 ; i++) {
        vfsbs.push_back(0);
    }


    while (sbs.secondHalf != 0) {
        vssbs.push_back(sbs.secondHalf % 2);
        sbs.secondHalf /= 2;
    }
    for (int i = vssbs.size(); i < 64; i++) {
        vssbs.push_back(0);
    }



    for (int i = 0; i < vfsbs.size() && i < vflbs.size(); i++) {
        
        if (vfsbs[i] == 1 && vflbs[i] != 1) {
            std::cout << "NO\n";
            return;
        }
    }



    for (int i = 0; i < vssbs.size() && i < vslbs.size(); i++) { 
        if (vssbs[i] == 1 && vslbs[i] != 1) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";

}

void BitString::print() {

    BitString bs1;
    bs1.firstHalf = firstHalf;
    bs1.secondHalf = secondHalf;

    std::vector<int> v;

    while (bs1.firstHalf != 0) {
        v.push_back(bs1.firstHalf % 2);
        bs1.firstHalf /= 2;
    }

    for (int i = 0; i < 64 - v.size(); i++) {
        std::cout << 0;
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        std::cout << v[i];
    }
    v.clear();

    std::cout << " ";

    while (bs1.secondHalf != 0) {
        v.push_back(bs1.secondHalf % 2);
        bs1.secondHalf /= 2;
    }
    for (int i = 0; i < 64 - v.size(); i++) {
        std::cout << 0;
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        std::cout << v[i];
    }
    std::cout << '\n';

}
