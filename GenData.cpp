#include "GenData.h"

/**
 * @brief Construct a new Gen Data:: Gen Data object
 * 
 * @param str DNA sequence with "acgt" characters
 */
GenData::GenData(std::string& str)
{
    data.clear();
    len = 0;

    uint8_t block=0; // block containing 4 "acgt" characters (2 bits per char)
    for(auto c : str)
    {
        c = tolower(c);
        uint8_t genChar = 0; // "acgt" 2-bit character
        switch (c)
        {
        case 'a':
            genChar = 0;
            break;
        case 'c':
            genChar = 1;            
            break;
        case 'g':
            genChar = 2;
            break;
        case 't':
            genChar = 3;
            break;
        default:
            genChar = 255; // error
            break;
        }

        if(genChar != 255)
        {
            block |= genChar << 2 * (len % 4);

            len++;

            if((len % 4) == 0) // the block is complete (4 chars)
            {
                data.push_back(block);
                block = 0;
            }
        }

    }
}

GenData::~GenData(){}

unsigned long GenData::length()
{
    return len;
}

uint8_t GenData::get(unsigned long index)
{
    uint8_t block = data.at(index / 4);
    uint8_t mask = 0x3 << index % 4;
    return (block & mask) >> index % 4;
}

void GenData::set(uint8_t val, unsigned long index)
{
    // WIP
}