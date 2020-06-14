#ifndef _EXPR_HPP_
#define _EXPR_HPP_

#include <list>

#include <lox/token.hpp>
#include <lox/visitor.hpp>

class Expr {
public:
  virtual Object accept(ExprVisitor &visitor) = 0;
};

class BinaryExpr : public Expr {
public:
  BinaryExpr(Expr *left, Token op, Expr *right)
      : _left(left), _operator(op), _right(right) {}

  virtual Object accept(ExprVisitor& visitor) override { return visitor.visit(*this); }

  Expr *left() const { return _left; }
  std::string op() const { return _operator.lexme(); }
  Expr *right() const { return _right; }

private:
  Expr *_left;
  Token _operator;
  Expr *_right;
};

class AssignExpr : public Expr {
public:
  AssignExpr(Token name, Expr *value) : _name(name), _value(value) {}

  virtual Object accept(ExprVisitor &visitor) override { return visitor.visit(*this); }
  std::string name() const { return _name.lexme(); }
  Expr *value() const { return _value; }
private:
  Token _name;
  Expr *_value;
};

class CallExpr : public Expr {
public:
  CallExpr(Expr *callee, Token paren, std::list<Expr *> arguments)
      : _callee(callee), _paren(paren), _arguments(arguments) {}

  virtual Object accept(ExprVisitor &visitor) override { return visitor.visit(*this); }
  Expr *callee() { return _callee; }
  std::list<Expr *> arguments() { return _arguments; }
private:
  Expr *_callee;
  Token _paren;
  std::list<Expr *> _arguments;
};

class GetExpr : public Expr {
public:
  GetExpr(Expr *object, Token name) : _object(object), _name(name) {}

  virtual Object accept(ExprVisitor &visitor) override { return visitor.visit(*this); }

private:
  Expr *_object;
  Token _name;
};

class GroupingExpr : public Expr {
public:
  GroupingExpr(Expr *expression) : _expression(expression) {}

  virtual Object accept(ExprVisitor &visitor) override { return visitor.visit(*this); }
  Expr *expression() const { return _expression; }
private:
  Expr *_expression;
};

class LiteralExpr : public Expr {
public:
  LiteralExpr(Object value) : _value(value) {}

  virtual Object accept(ExprVisitor &visitor) override { return visitor.visit(*this); }

  std::string toString() const { return object::toString(_value); }

private:
  Object _value;
};

class LogicalExpr : public Expr {
public:
  LogicalExpr(Expr *left, Token op, Expr *right)
      : _left(left), _operator(op), _right(right) {}

  virtual Object accept(ExprVisitor &visitor) override { return visitor.visit(*this); }
  std::string name() const {return _operator.lexme(); }
  Expr *left() const { return _left; }
  Expr *right() const { return _right; }
private:
  Expr *_left;
  Token _operator;
  Expr *_right;
};

class SetExpr : public Expr {
public:
  SetExpr(Expr *object, Token name, Expr *value)
      : _object(object), _name(name), _value(value) {}

  virtual Object accept(ExprVisitor &visitor) override { return visitor.visit(*this); }

private:
  Expr *_object;
  Token _name;
  Expr *_value;
};

class SuperExpr : public Expr {
public:
  SuperExpr(Token keyword, Token method) : _keyword(keyword), _method(method) {}

  virtual Object accept(ExprVisitor &visitor) override { return visitor.visit(*this); }
  std::string method() { return _method.lexme(); }
private:
  Token _keyword;
  Token _method;
};

class ThisExpr : public Expr {
public:
  ThisExpr(Token keyword) : _keyword(keyword) {}

  virtual Object accept(ExprVisitor &visitor) override { return visitor.visit(*this); }

private:
  Token _keyword;
};

class UnaryExpr : public Expr {
public:
  UnaryExpr(Token op, Expr *right) : _operator(op), _right(right) {}

  virtual Object accept(ExprVisitor &visitor) override { return visitor.visit(*this); }

  std::string op() const { return _operator.lexme(); }
  Expr *right() const { return _right; }

private:
  Token _operator;
  Expr *_right;
};

class VariableExpr : public Expr {
public:
  VariableExpr(Token name) : _name(name) {}

  virtual Object accept(ExprVisitor &visitor) override { return visitor.visit(*this); }

private:
  Token _name;
};

#endif