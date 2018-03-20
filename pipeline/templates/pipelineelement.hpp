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
    boost::lockfree::queue<Packet*, boost::lockfree::fixed_sized<true>> _upstreamQueue;
    boost::lockfree::queue<Packet*, boost::lockfree::fixed_sized<true>> _downstreamQueue;
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
        std::cout << "Upstream lockfree:" << _upstreamQueue.is_lock_free() << " Downstream lockfree:" << _downstreamQueue.is_lock_free() << std::endl;
    }
    virtual ~PipelineElement() {}
    bool sendDownstream(Packet* packetPtr)
    {
        assert(packetPtr);
        return _downstreamQueue.push(packetPtr);
    }
    bool recvUpstream(Packet*& packetPtr)
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
        _elementThread.reset(new boost::thread(boost::bind(&PipelineElement::run, this)));
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
