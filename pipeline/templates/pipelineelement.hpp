#ifndef PIPELINEELEMENT_HPP
#define PIPELINEELEMENT_HPP

#include <boost/lockfree/queue.hpp>

template <class UpstreamType, class DownstreamType>
class PipelineElement
{
    boost::lockfree::queue<UpstreamType> _upstreamQueue;
    boost::lockfree::queue<DownstreamType> _downstreamQueue;

public:
    PipelineElement(int upstreamSize, int downstreamSize)
        : _upstreamQueue(upstreamSize)
        , _downstreamQueue(downstreamSize){

          };
    bool sendDownstream(const DownstreamType& packet)
    {
        return _downstreamQueue.push(packet);
    }
    bool recvUpstream(UpstreamType& packet)
    {
        return _upstreamQueue.pop(packet);
    }
};

#endif  // PIPELINEELEMENT_HPP
