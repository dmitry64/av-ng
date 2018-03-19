#ifndef TESTRECEIVERELEMENT_HPP
#define TESTRECEIVERELEMENT_HPP

#include "pipelineelement.hpp"

class TestReceiverElement : public PipelineElement
{
public:
    TestReceiverElement(std::string name, size_t upstreamSize, size_t downstreamSize);

protected:
    void tick();
};

#endif  // TESTRECEIVERELEMENT_HPP
