#include "testgeneratorelement.hpp"

TestGeneratorElement::TestGeneratorElement(std::string name, size_t upstreamSize, size_t downstreamSize)
    : PipelineElement("Generator-" + name, upstreamSize, downstreamSize)
{
}

void TestGeneratorElement::tick()
{
    std::vector<unsigned char> samples;

    for (int i = 0; i < 100; ++i) {
        samples.push_back(i);
    }

    AScanRawPacket* packet = new AScanRawPacket(samples, 123);
    if (_upstreamQueue.push(packet)) {
        // std::cout << "Added packet to queue" << std::endl;
    }
}
