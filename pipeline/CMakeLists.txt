enable_language(CXX)
set (CMAKE_CXX_STANDARD 14)
set(SOURCES
   templates/pipelineelement.cxx
    )
set(HEADERS
   templates/pipelineelement.hpp
    )

include_directories(templates)

add_library(pipeline ${SOURCES} ${HEADERS})



