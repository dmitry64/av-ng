#ifndef TYPES_HPP
#define TYPES_HPP

#include <vector>
#include <chrono>

enum PacketType
{
    eEmptyPacket = 0,
    eAScanRawPacket = 1,
    eBScanRawPacket = 2,
    eConfigPacket = 3
};

using PacketCounterType = unsigned long int;
using PacketInitTime = std::chrono::steady_clock::time_point;

using DelayType = unsigned short;
using AmplitudeType = unsigned char;
using AScanRawData = std::vector<AmplitudeType>;

struct BScanSample
{
    DelayType _begin;
    DelayType _end;
};

using BScanRawData = std::vector<BScanSample>;


#endif  // TYPES_HPP
