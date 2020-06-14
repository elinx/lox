add_library(loxlib  INTERFACE)
target_include_directories(loxlib INTERFACE include)
target_sources(loxlib INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/include/expr.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/interpreter.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/lox.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/object.hpp
  )
