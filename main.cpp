#include <iostream>
#include <pipelineelement.hpp>
#include <testgeneratorelement.hpp>
#include <testreceiverelement.hpp>

int main()
{
    TestGeneratorElement* generator(new TestGeneratorElement("G1", 8, 8));
    TestReceiverElement* receiver(new TestReceiverElement("R1", 8, 8));

    receiver->addDownstreamElement(generator);

    generator->startThread();
    receiver->startThread();
    sleep(10);

    // DownstreamPacket* a(new DownstreamPacket(123));

    // element.sendDownstream(a);
    std::cout << "Hello World!" << std::endl;
    generator->stopThread();
    generator->waitThread();
    receiver->stopThread();
    receiver->waitThread();
    return 0;
}
