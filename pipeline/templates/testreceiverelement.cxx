#include "testreceiverelement.hpp"

TestReceiverElement::TestReceiverElement(std::string name, size_t upstreamSize, size_t downstreamSize)
    : PipelineElement("Receiver-" + name, upstreamSize, downstreamSize)
{
}

void TestReceiverElement::tick()
{
    for (auto& element : _downstreamElements) {
        UpstreamPacket* packet = nullptr;
        if (element->recvUpstream(packet)) {
            assert(packet);
            debugPrint(packet->toString());
            // packet->debugPrint();
            // std::cout << "New packet:" <<
        }
    }
}
