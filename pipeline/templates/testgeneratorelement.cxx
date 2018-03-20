#include "testgeneratorelement.hpp"
#include <string>
#include <packets.hpp>


TestGeneratorElement::TestGeneratorElement(std::string name, size_t upstreamSize, size_t downstreamSize)
    : PipelineElement("Generator-" + name, upstreamSize, downstreamSize)
{
}

void TestGeneratorElement::tick()
{
    AScanRawData asamples;

    for (int i = 0; i < 100; ++i) {
        asamples.push_back(i);
    }

    PacketData* dataPacket = new AScanRawPacket(asamples);

    Packet* packet = new Packet(PacketType::eAScanRawPacket, 0, dataPacket);
    while (!(_upstreamQueue.push(packet))) {
    }
}
