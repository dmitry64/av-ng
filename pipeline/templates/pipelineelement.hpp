#ifndef PIPELINEELEMENT_HPP
#define PIPELINEELEMENT_HPP

#include <boost/lockfree/queue.hpp>
#include <boost/thread.hpp>
#include <vector>
#include <memory>
#include <cassert>
#include <iostream>
#include <packets.hpp>

class PipelineElement
{
protected:
    std::unique_ptr<boost::thread> _elementThread;
    boost::lockfree::queue<UpstreamPacket*> _upstreamQueue;
    boost::lockfree::queue<DownstreamPacket*> _downstreamQueue;
    std::vector<PipelineElement*> _downstreamElements;
    std::atomic_bool _isRunning;
    std::atomic_bool _runSwitch;
    std::string _elementName;

public:
    PipelineElement(std::string name, size_t upstreamSize, size_t downstreamSize)
        : _elementThread(nullptr)
        , _upstreamQueue(upstreamSize)
        , _downstreamQueue(downstreamSize)
        , _isRunning(false)
        , _runSwitch(false)
        , _elementName(name)
    {
        std::cout << "Created element: " << name << std::endl;
    }
    virtual ~PipelineElement() {}
    bool sendDownstream(DownstreamPacket* packetPtr)
    {
        assert(packetPtr);
        return _downstreamQueue.push(packetPtr);
    }
    bool recvUpstream(UpstreamPacket*& packetPtr)
    {
        return _upstreamQueue.pop(packetPtr);
    }
    void addDownstreamElement(PipelineElement* element)
    {
        assert(!_isRunning.load());
        _downstreamElements.push_back(element);
    }
    void startThread()
    {
        debugPrint("Starting thread...");
        _runSwitch.store(true);
        _elementThread = std::unique_ptr<boost::thread>(new boost::thread(boost::bind(&PipelineElement::run, this)));
        debugPrint("Thread started!");
    }
    void stopThread()
    {
        debugPrint("Stopping thread...");
        _runSwitch.store(false);
    }
    void waitThread()
    {
        debugPrint("Waiting thread...");
        _elementThread.get()->join();
        debugPrint("Thread joined!");
    }

protected:
    void debugPrint(std::string text)
    {
        std::cout << "[" << _elementName << "]: " << text << std::endl;
    }
    void run()
    {
        _isRunning.store(true);
        while (_runSwitch.load()) {
            tick();
        }
        _isRunning.store(false);
    }
    virtual void tick()
    {
        std::cout << "tick" << std::endl;
    }
};

#endif  // PIPELINEELEMENT_HPP
