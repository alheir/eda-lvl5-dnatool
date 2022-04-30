#ifndef GENDATA_H
#define GENDATA_H

#include <cstdint>
#include <string>
#include <vector>

class GenData
{
private:
    unsigned long len = 0;

public:
    GenData(std::string& str);
    ~GenData();

    uint8_t get(unsigned long index);
    void set(uint8_t val, unsigned long index);
    std::vector<uint8_t> data;

    void toString(std::string& strOut);

    unsigned long length();
};


#endif