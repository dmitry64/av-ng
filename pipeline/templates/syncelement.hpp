#ifndef SYNCELEMENT_HPP
#define SYNCELEMENT_HPP

#include <pipelineelement.hpp>

class SyncElement : public PipelineElement
{
    PacketCounterType _upstreamCounter;

public:
    SyncElement(std::string name, size_t upstreamSize, size_t downstreamSize);

protected:
    void tick();
};

#endif  // SYNCELEMENT_HPP
