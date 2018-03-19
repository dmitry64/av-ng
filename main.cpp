#include <iostream>
#include <pipelineelement.hpp>
#include <testgeneratorelement.hpp>
#include <testreceiverelement.hpp>
#include <syncelement.hpp>

int main()
{
    TestGeneratorElement* generator1(new TestGeneratorElement("G1", 8, 8));
    TestGeneratorElement* generator2(new TestGeneratorElement("G2", 8, 8));
    SyncElement* sync1(new SyncElement("S1", 8, 8));
    TestReceiverElement* receiver(new TestReceiverElement("R1", 8, 8));


    receiver->addDownstreamElement(sync1);

    sync1->addDownstreamElement(generator1);
    sync1->addDownstreamElement(generator2);

    generator1->startThread();
    generator2->startThread();
    sync1->startThread();
    receiver->startThread();
    sleep(10);

    // DownstreamPacket* a(new DownstreamPacket(123));

    // element.sendDownstream(a);
    std::cout << "Hello World!" << std::endl;
    generator1->stopThread();
    generator1->waitThread();

    generator2->stopThread();
    generator2->waitThread();

    sync1->stopThread();
    sync1->waitThread();

    receiver->stopThread();
    receiver->waitThread();
    return 0;
}
