#ifndef PACKETS_HPP
#define PACKETS_HPP

#include <iostream>
#include <vector>
#include <array>
#include <memory>
#include <types.hpp>
#include <packethandler.hpp>
#include <cassert>

class PacketData
{
public:
    PacketData();
    virtual ~PacketData(){

    };
};

class Packet
{
    PacketType _type;
    PacketCounterType _counter;
    PacketInitTime _time;
    PacketData* _data;

public:
    Packet(PacketType type, PacketCounterType counter, PacketData* data)
        : _type(type)
        , _counter(counter)
        , _data(data)
    {
        assert(_data);
        _time = std::chrono::steady_clock::now();
    }
    Packet() = delete;
    Packet(const Packet& packet) = delete;
    ~Packet()
    {
        assert(_data);
        delete _data;
    }
    PacketType type() const
    {
        return _type;
    }
    PacketCounterType counter() const
    {
        return _counter;
    }
    void setCounter(const PacketCounterType& counter)
    {
        _counter = counter;
    }
    std::string toString()
    {
        return std::string("Packet:") + std::to_string(_counter);
    }
};

class AScanRawPacket : public PacketData
{
    AScanRawData _data;

    int mark;
    int test_payload[1000];

public:
    AScanRawPacket(const AScanRawData& data);
    ~AScanRawPacket();
};

class BScanRawPacket : public PacketData
{
    BScanRawData _data;

public:
};

#endif  // PACKETS_HPP
