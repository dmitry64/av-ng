#ifndef PACKETS_HPP
#define PACKETS_HPP

#include <iostream>
#include <vector>
#include <array>
#include <types.hpp>

class DownstreamPacket
{
    PacketCounterType _count;

public:
    DownstreamPacket(PacketCounterType count)
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
    PacketCounterType _count;

public:
    UpstreamPacket(PacketCounterType count)
        : _count(count)
    {
    }
    std::string toString()
    {
        return std::string("P:") + std::to_string(_count);
    }
    ~UpstreamPacket() {}
    PacketCounterType count() const
    {
        return _count;
    }
    void setCount(const PacketCounterType& count)
    {
        _count = count;
    }
};

class AScanRawPacket : public UpstreamPacket
{
    std::vector<AmplitudeType> _samples;

public:
    AScanRawPacket(const std::vector<AmplitudeType>& samples, PacketCounterType count)
        : UpstreamPacket(count)
        , _samples(samples)
    {
    }
    std::vector<AmplitudeType> samples() const
    {
        return _samples;
    }
};

#endif  // PACKETS_HPP
