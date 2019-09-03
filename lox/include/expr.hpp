#ifndef _EXPR_HPP_
#define _EXPR_HPP_

#include "token.hpp"
#include <list>

class Expr {};

class Binary : public Expr {
public:
  Binary(Expr left, Token op, Expr right)
      : _left(left), _operator(op), _right(right) {}

private:
  Expr _left;
  Token _operator;
  Expr _right;
};

class Assign : public Expr {
public:
  Assign(Token name, Expr value) : _name(name), _value(value) {}

private:
  Token _name;
  Expr _value;
};

class Call : public Expr {
public:
  Call(Expr callee, Token paren, std::list<Expr> arguments)
      : _callee(callee), _paren(paren), _arguments(arguments) {}

private:
  Expr _callee;
  Token _paren;
  std::list<Expr> _arguments;
};

class Get : public Expr {
public:
  Get(Expr object, Token name) : _object(object), _name(name) {}

private:
  Expr _object;
  Token _name;
};

class Grouping : public Expr {
public:
  Grouping(Expr expression) : _expression(expression) {}

private:
  Expr _expression;
};

class Literal : public Expr {
public:
  Literal(Object value) : _value(value) {}

private:
  Object _value;
};

class Logical : public Expr {
public:
  Logical(Expr left, Token op, Expr right)
      : _left(left), _operator(op), _right(right) {}

private:
  Expr _left;
  Token _operator;
  Expr _right;
};

class Set : public Expr {
public:
  Set(Expr object, Token name, Expr value)
      : _object(object), _name(name), _value(value) {}

private:
  Expr _object;
  Token _name;
  Expr _value;
};

class Super : public Expr {
public:
  Super(Token keyword, Token method) : _keyword(keyword), _method(method) {}

private:
  Token _keyword;
  Token _method;
};

class This : public Expr {
public:
  This(Token keyword) : _keyword(keyword) {}

private:
  Token _keyword;
};

class Unary : public Expr {
public:
  Unary(Token op, Expr right) : _operator(op), _right(right) {}

private:
  Token _operator;
  Expr _right;
};

class Variable : public Expr {
public:
  Variable(Token name) : _name(name) {}

private:
  Token _name;
};

#endif