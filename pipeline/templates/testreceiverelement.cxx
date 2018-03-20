#include "testreceiverelement.hpp"

TestReceiverElement::TestReceiverElement(std::string name, size_t upstreamSize, size_t downstreamSize)
    : PipelineElement("Receiver-" + name, upstreamSize, downstreamSize)
{
}

void TestReceiverElement::tick()
{
    for (PipelineElement* element : _downstreamElements) {
        Packet* packet = nullptr;
        if (element->recvUpstream(packet)) {
            assert(packet);
            debugPrint(packet->toString());
            delete packet;
            usleep(10000);
            // packet->debugPrint();
            // std::cout << "New packet:" <<
        }
    }
}
