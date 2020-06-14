add_library(loxlib  INTERFACE)
target_include_directories(loxlib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(loxlib INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/lox/ast_visitor.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/lox/expr.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/lox/interpreter.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/lox/lox.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/lox/object.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/lox/parser.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/lox/scanner.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/lox/stmt.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/lox/token.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/lox/visitor.hpp
)

