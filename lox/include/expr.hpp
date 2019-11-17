#ifndef _EXPR_HPP_
#define _EXPR_HPP_

#include "token.hpp"
#include "visitor.hpp"
#include <list>

class Expr {
public:
  virtual void accept(ExprVisitor &visitor) = 0;
};

class BinaryExpr : public Expr {
public:
  BinaryExpr(Expr *left, Token op, Expr *right)
      : _left(left), _operator(op), _right(right) {}

  virtual void accept(ExprVisitor &visitor) override { visitor.visit(this); }

  Expr *left() { return _left; }
  std::string op() { return _operator.lexme(); }
  Expr *right() { return _right; }

private:
  Expr *_left;
  Token _operator;
  Expr *_right;
};

class AssignExpr : public Expr {
public:
  AssignExpr(Token name, Expr *value) : _name(name), _value(value) {}

  virtual void accept(ExprVisitor &visitor) override { visitor.visit(this); }
  std::string name() { return _name.lexme(); }
  Expr *value() { return _value; }
private:
  Token _name;
  Expr *_value;
};

class CallExpr : public Expr {
public:
  CallExpr(Expr *callee, Token paren, std::list<Expr *> arguments)
      : _callee(callee), _paren(paren), _arguments(arguments) {}

  virtual void accept(ExprVisitor &visitor) override { visitor.visit(this); }

private:
  Expr *_callee;
  Token _paren;
  std::list<Expr *> _arguments;
};

class GetExpr : public Expr {
public:
  GetExpr(Expr *object, Token name) : _object(object), _name(name) {}

  virtual void accept(ExprVisitor &visitor) override { visitor.visit(this); }

private:
  Expr *_object;
  Token _name;
};

class GroupingExpr : public Expr {
public:
  GroupingExpr(Expr *expression) : _expression(expression) {}

  virtual void accept(ExprVisitor &visitor) override { visitor.visit(this); }
  Expr *expression() { return _expression; }
private:
  Expr *_expression;
};

class LiteralExpr : public Expr {
public:
  LiteralExpr(Object value) : _value(value) {}

  virtual void accept(ExprVisitor &visitor) override { visitor.visit(this); }

  std::string toString() { return object::toString(_value); }

private:
  Object _value;
};

class LogicalExpr : public Expr {
public:
  LogicalExpr(Expr *left, Token op, Expr *right)
      : _left(left), _operator(op), _right(right) {}

  virtual void accept(ExprVisitor &visitor) override { visitor.visit(this); }

private:
  Expr *_left;
  Token _operator;
  Expr *_right;
};

class SetExpr : public Expr {
public:
  SetExpr(Expr *object, Token name, Expr *value)
      : _object(object), _name(name), _value(value) {}

  virtual void accept(ExprVisitor &visitor) override { visitor.visit(this); }

private:
  Expr *_object;
  Token _name;
  Expr *_value;
};

class SuperExpr : public Expr {
public:
  SuperExpr(Token keyword, Token method) : _keyword(keyword), _method(method) {}

  virtual void accept(ExprVisitor &visitor) override { visitor.visit(this); }

private:
  Token _keyword;
  Token _method;
};

class ThisExpr : public Expr {
public:
  ThisExpr(Token keyword) : _keyword(keyword) {}

  virtual void accept(ExprVisitor &visitor) override { visitor.visit(this); }

private:
  Token _keyword;
};

class UnaryExpr : public Expr {
public:
  UnaryExpr(Token op, Expr *right) : _operator(op), _right(right) {}

  virtual void accept(ExprVisitor &visitor) override { visitor.visit(this); }

  std::string op() { return _operator.lexme(); }
  Expr *right() { return _right; }

private:
  Token _operator;
  Expr *_right;
};

class VariableExpr : public Expr {
public:
  VariableExpr(Token name) : _name(name) {}

  virtual void accept(ExprVisitor &visitor) override { visitor.visit(this); }

private:
  Token _name;
};

#endif