#ifndef PACKETS_HPP
#define PACKETS_HPP

#include <iostream>
#include <vector>
#include <array>

class DownstreamPacket
{
    unsigned long int _count;

public:
    DownstreamPacket(unsigned long int count)
        : _count(count)
    {
    }
    std::string toString()
    {
        return std::string("P:") + std::to_string(_count);
    }
    ~DownstreamPacket() {}
};
class UpstreamPacket
{
    unsigned long int _count;

public:
    UpstreamPacket(unsigned long int count)
        : _count(count)
    {
    }
    std::string toString()
    {
        return std::string("P:") + std::to_string(_count);
    }
    ~UpstreamPacket() {}
};

class AScanRawPacket : public UpstreamPacket
{
    std::vector<unsigned char> _samples;

public:
    AScanRawPacket(const std::vector<unsigned char>& samples, unsigned long int count)
        : UpstreamPacket(count)
        , _samples(samples)
    {
    }
    std::vector<unsigned char> samples() const
    {
        return _samples;
    }
};

#endif  // PACKETS_HPP
