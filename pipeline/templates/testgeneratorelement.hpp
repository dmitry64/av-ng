#ifndef TESTGENERATORELEMENT_HPP
#define TESTGENERATORELEMENT_HPP

#include "pipelineelement.hpp"

class TestGeneratorElement : public PipelineElement
{
public:
    TestGeneratorElement(std::string name, size_t upstreamSize, size_t downstreamSize);

protected:
    void tick();
};

#endif  // TESTGENERATORELEMENT_HPP
