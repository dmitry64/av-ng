enable_language(CXX)
set (CMAKE_CXX_STANDARD 14)
set(SOURCES
   templates/pipelineelement.cxx
   templates/testgeneratorelement.cxx
   templates/testreceiverelement.cxx
   templates/syncelement.cxx
   templates/packethandler.cxx
   templates/packets.cxx
    )
set(HEADERS
   templates/pipelineelement.hpp
   templates/testgeneratorelement.hpp
   templates/testreceiverelement.hpp
   templates/packets.hpp
   templates/syncelement.hpp
   templates/types.hpp
   templates/packethandler.hpp
    )

include_directories(templates)

add_library(pipeline ${SOURCES} ${HEADERS})



