#ifndef _INTERPRETER_HPP_
#define _INTERPRETER_HPP_

#include "visitor.hpp"

class Interpreter : public Visitor {
public:
  void print(Expr *expr) { expr->accept(*this); }
  virtual void visit(Binary &expr) {
  }
  virtual void visit(Assign &expr) {}
  virtual void visit(Call &expr) {}
  virtual void visit(Get &expr) {}
  virtual void visit(Grouping &expr) {}
  virtual void visit(Literal &expr) {
  }
  virtual void visit(Logical &expr) {}
  virtual void visit(Set &expr) {}
  virtual void visit(Super &expr) {}
  virtual void visit(This &expr) {}
  virtual void visit(Unary &expr) {}
  virtual void visit(Variable &expr) {}

private:
};

#endif // !_INTERPRETER_HPP_