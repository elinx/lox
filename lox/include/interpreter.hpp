#ifndef _INTERPRETER_HPP_
#define _INTERPRETER_HPP_

#include "visitor.hpp"
class Interpreter : public ExprVisitor, StmtVisitor {
public:
  void print(Expr *expr) { expr->accept(*this); }

  virtual void visit(BinaryExpr *expr) {}
  virtual void visit(AssignExpr *expr) {}
  virtual void visit(CallExpr *expr) {}
  virtual void visit(GetExpr *expr) {}
  virtual void visit(GroupingExpr *expr) {}
  virtual void visit(LiteralExpr *expr) {}
  virtual void visit(LogicalExpr *expr) {}
  virtual void visit(SetExpr *expr) {}
  virtual void visit(SuperExpr *expr) {}
  virtual void visit(ThisExpr *expr) {}
  virtual void visit(UnaryExpr *expr) {}
  virtual void visit(VariableExpr *expr) {}

  virtual void visit(PrintStmt *stmt) {}
  virtual void visit(ExprStmt *stmt) {}

private:
};

#endif // !_INTERPRETER_HPP_