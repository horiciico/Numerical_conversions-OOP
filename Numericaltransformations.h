#ifndef NUMERICALTRANSFORMATIONS_H
#define NUMERICALTRANSFORMATIONS_H

#include <string>
#include <algorithm>
#include <stdexcept>

using std::string;

static string DecToBin(int);
static int BinToDec(string);
static string C2(string);
static string signExtension_4(char, string);
static string signExtension_3(char, string);
static string BinToHex(string);
static string BinToOct(string);





class DecNumber
{
    int DecValue;
    bool isNeg;
    char signBit;
    string unsignedBin;
    
    
public:
    DecNumber(int);
    string toBin();
    string toHex();
    string toOct();
    
};


class BinNumber
{
    string BinValue;
    bool isNeg;
    bool BinCheck(string);
    char signBit;


public:
    BinNumber(string);
    string toDec();
    string toHex();
    string toOct();
};


class HexNumber
{
    string HexValue;
    bool isNegfunction();
    bool isNeg;
    bool HexCheck(string);
    


public:
    HexNumber(string);
    string toBin();
    string toDec();
    string toOct();
};


class OctNumber
{
    string OctValue;
    bool isNeg;
    bool OctCheck(string);

public:
    string toDec();
    string toBin();
    string toHex();
    OctNumber(string);
};



#endif