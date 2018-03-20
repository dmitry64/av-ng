#include "syncelement.hpp"

SyncElement::SyncElement(std::string name, size_t upstreamSize, size_t downstreamSize)
    : PipelineElement("Sync-" + name, upstreamSize, downstreamSize)
    , _upstreamCounter(0)
{
}

void SyncElement::tick()
{
    for (PipelineElement* element : _downstreamElements) {
        Packet* packet = nullptr;
        if (element->recvUpstream(packet)) {
            assert(packet);
            packet->setCounter(_upstreamCounter);
            ++_upstreamCounter;
            while (!_upstreamQueue.push(packet)) {
            }
            // packet->debugPrint();
            // std::cout << "New packet:" <<
        }
    }
}
