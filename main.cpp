#include <iostream>
#include <pipelineelement.hpp>

class Data
{
};

int main()
{
    PipelineElement<Data, Data> element(3, 3);
    Data a;
    element.sendDownstream(a);
    std::cout << "Hello World!" << std::endl;
    return 0;
}
