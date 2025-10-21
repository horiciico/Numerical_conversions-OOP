#include "Numericaltransformations.h"
#include <cmath>



string DecToBin(int dec)
{
    string bin="";
    if(dec==0) return "0";
    while(dec!=0)
    {
        if(dec%2==0) bin+='0';
        else bin+='1';

        dec/=2;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}


int BinToDec(string bin)
{
    int decimal=0;
    for(int i=0, j=bin.length()-1; i<bin.length(); i++,j--)
    {
        if(bin[i]=='1') decimal+=pow(2,j);
    }
    return decimal;
}


string C2(string bin)
{
    string C2="";
    int _last_1_bit;

    for(int i=0; i<bin.length(); i++)
    {
        if(bin[i]=='1') _last_1_bit=i;
    }

    for(int i=0; i<bin.length(); i++)
    {
        if(i<_last_1_bit)
        {
            if(bin[i]=='1') C2+='0';
            else C2+='1';
        }
        else C2+=bin[i];
    }

    return C2; 
}



string signExtension_4(char signBit, string bin)
{
    
    while(bin.length()%4!=0)
    {
        bin=signBit+bin;
    }
    return bin;
}


string signExtension_3(char signBit, string bin)
{
    while(bin.length()%3!=0)
    {
        bin=signBit+bin;
    }
    return bin;
}


string BinToHex(string bin)
{
    string Hex="";
    for(int i=0; i<bin.length(); i+=4)
    {
        string group=bin.substr(i,4);
        int hex_int=BinToDec(group);

        if(hex_int<=9) Hex+=hex_int+ '0';
        else Hex+=hex_int +'7';
    }
    return Hex;
}


string BinToOct(string bin)
{
    string Oct="";
    for(int  i=0; i<bin.length(); i+=3)
    {
        int oct_int= BinToDec(bin.substr(i,3));
        Oct+=oct_int + '0';
    }
    return Oct;

}















string DecNumber::toBin()
{
    int decimal=this->DecValue;

    if(decimal>0)
        return this->signBit+this->unsignedBin;

    if(decimal<=0)
        return '1' +C2(unsignedBin);


    if(decimal==0)
        return "0";
    
    return "0";
}


string DecNumber::toHex()
{
    string bin;
    if(this->DecValue==0) return "0";
    else
    {
        if(this->isNeg)
        {
            bin='1'+C2(this->unsignedBin);
            bin=signExtension_4(this->signBit, bin);
        }
        else bin=signExtension_4(this->signBit, this->unsignedBin);
    }
    string Hex=BinToHex(bin);
    return Hex;
}


string DecNumber::toOct()
{
    string bin;
    
    if(this->DecValue==0)
        return "0";
    else
    {
        if(this->isNeg)
        {
            bin='1'+C2(this->unsignedBin);
            bin=signExtension_3(this->signBit, bin);
        }
        else
            bin=signExtension_3(this->signBit, this->unsignedBin);
    }
    
    string Oct=BinToOct(bin);
    return Oct;
}


DecNumber::DecNumber(int value)
{
    this->DecValue=value;
    this->unsignedBin=DecToBin(this->DecValue);

    if(value>=0)
    {
        this->signBit='0';
        this->isNeg=false;
    }
    else
    {
        this->signBit='1';
        this->isNeg=true;
    }
}











bool BinNumber::BinCheck(string vall)
{
    for(int i=0; i<vall.length(); i++)
    {
        if(vall[i]!='1' && vall[i]!='0') return false;
    }
    return true;
}


BinNumber::BinNumber(string value)
{
    if (value.empty())
            throw std::invalid_argument("BinNumber: EMPTY STRING!");
    if(!BinCheck(value))
            throw std::invalid_argument("BinNumber: INVALID BINARY NUMBER");
    
    this->BinValue=value;

    if(BinValue[0]=='1') 
        this->isNeg=true;
    else
        this->isNeg=false;

    signBit=this->BinValue[0];
}


string BinNumber::toDec()
{
    int dec;
    if(this->BinValue=="0") return "0";
    else
    {
        if(!this->isNeg)
            dec=BinToDec(this->BinValue);

        if(this->isNeg)
        {
            string bin=C2(this->BinValue);
            dec=-BinToDec(bin);
        }
    }
    string Bin=std::to_string(dec);
    return Bin;   
}


string BinNumber::toHex()
{
    string Hex;

    if(this->BinValue=="0") return "0";
    else
    {
        Hex=signExtension_4(this->signBit, this->BinValue);
        Hex=BinToHex(Hex);
    }
    return Hex;
}


string BinNumber::toOct()
{
    string Oct;

    if(this->BinValue=="0") return "0";
    else
    {
        Oct=signExtension_3(this->signBit, this->BinValue);
        Oct=BinToOct(Oct);
    }
    return Oct;
}











bool HexNumber::HexCheck(string value)
{
    for (int i = 0; i < value.length(); i++)
    {
        char c = value[i];
        bool isNumber = (c >= '0' && c <= '9');
        bool isLetter = (c >= 'a' && c <= 'f');
        bool isCapsLetter = (c >= 'A' && c <= 'F');

        if (!isNumber && !isLetter && !isCapsLetter)
            return false;
    }
    return true;
}


bool HexNumber::isNegfunction()
{
   if(this->HexValue[0]>='0' && this->HexValue[0]<='7') return false;
   else return true;
}


HexNumber::HexNumber(string value)
{
    if (value.empty())
            throw std::invalid_argument("HexNumber: EMPTY STRING!");
    if(!HexCheck(value))
            throw std::invalid_argument("HexNumber: INVALID HEXADECIMAL NUMBER");

    this->HexValue=value;
    this->isNeg= this->isNegfunction();
}


string HexNumber::toBin()
{
    int hex_letter;
    string Bin="";
    for (int i = 0; i < this->HexValue.length(); i++)
    {
         char c = this->HexValue[i];
            if (c >= '0' && c <= '9')
                hex_letter = c - '0';
            else if (c >= 'A' && c <= 'F')
                hex_letter = c - 'A' + 10;
            else if (c >= 'a' && c <= 'f')
                hex_letter = c - 'a' + 10;

        Bin+=signExtension_4('0',DecToBin(hex_letter));
    }

    return Bin;
}

string HexNumber::toOct()
{
    string Oct;
    string bin_number=HexNumber::toBin();

    if(this->isNeg)
        Oct=signExtension_3('1', bin_number);
    else
        Oct=signExtension_3('0', bin_number);

    Oct=BinToOct(Oct);
    return Oct;
}


string HexNumber::toDec()
{
    string bin_number=HexNumber::toBin();
    string dec_number;

    if(!this->isNeg)
    {
        dec_number=std::to_string(BinToDec(bin_number));
    }
    else
    {
        bin_number=C2(bin_number);
        dec_number="-"+std::to_string(BinToDec(bin_number));
    }

    return dec_number;

}




bool OctNumber::OctCheck(string oct)
{
    for(int i=0; i<oct.length(); i++)
    {
        if(oct[i]>'7' || oct[i]<'0') return false;
    }
    return true;
}

OctNumber::OctNumber(string value)
{
    if (value.empty())
            throw std::invalid_argument("OctNumber: EMPTY  STRING!");
    if(!OctCheck(value))
            throw std::invalid_argument("OctNumber: INVALID  OCTAL  NUMBER");

    
    this->OctValue=value;

    char firs_oct=OctValue[0];

    if(firs_oct=='7' || firs_oct=='6' || firs_oct=='5' || firs_oct=='4') this->isNeg=1;
    else this->isNeg=0;
}


string OctNumber::toBin()
{
    string Bin="";
    for(int i=0; i<this->OctValue.length(); i++)
    {
        int oct_int=OctValue[i]-'0';
        Bin+=signExtension_3('0', DecToBin(oct_int));
    }
    return Bin;
}


string OctNumber::toHex()
{
    string Hex;
    if(this->isNeg)
    {
        Hex=signExtension_4('1', this->toBin());
        Hex=BinToHex(Hex);
    }
    else
    {
        Hex=signExtension_4('0', this->toBin());
        Hex=BinToHex(Hex);
    }
    return Hex;
}


string OctNumber::toDec()
{
    string bin=OctNumber::toBin();
    string Dec;

    if(this->isNeg)
    {
        Dec='-'+ std::to_string(BinToDec(C2(bin)));
    }
    else Dec=std::to_string(BinToDec(bin));

    return Dec;
}



