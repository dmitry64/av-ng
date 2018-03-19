#include "syncelement.hpp"

SyncElement::SyncElement(std::string name, size_t upstreamSize, size_t downstreamSize)
    : PipelineElement("Sync-" + name, upstreamSize, downstreamSize)
    , _upstreamCounter(0)
{
}

void SyncElement::tick()
{
    for (auto& element : _downstreamElements) {
        UpstreamPacket* packet = nullptr;
        if (element->recvUpstream(packet)) {
            assert(packet);
            packet->setCount(_upstreamCounter);
            ++_upstreamCounter;
            _upstreamQueue.push(packet);
            // packet->debugPrint();
            // std::cout << "New packet:" <<
        }
    }
}
