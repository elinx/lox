#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include <list>
#include "token.hpp"
#include "expr.hpp"

class Parser {
public:
  Parser(std::list<Token> tokens) : _tokens(tokens) {}
private:
  std::list<Token> _tokens;
  size_t _current;
};

#endif