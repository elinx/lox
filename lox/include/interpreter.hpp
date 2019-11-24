#ifndef _INTERPRETER_HPP_
#define _INTERPRETER_HPP_

#include "visitor.hpp"
#include <any>

class Interpreter : public ExprVisitor, StmtVisitor {
public:
  virtual std::any visit(BinaryExpr *expr) { return std::any{}; }
  virtual std::any visit(AssignExpr *expr) { return std::any{}; }
  virtual std::any visit(CallExpr *expr) { return std::any{}; }
  virtual std::any visit(GetExpr *expr) { return std::any{}; }
  virtual std::any visit(GroupingExpr *expr) { return std::any{}; }
  virtual std::any visit(LiteralExpr *expr) { return std::any{}; }
  virtual std::any visit(LogicalExpr *expr) { return std::any{}; }
  virtual std::any visit(SetExpr *expr) { return std::any{}; }
  virtual std::any visit(SuperExpr *expr) { return std::any{}; }
  virtual std::any visit(ThisExpr *expr) { return std::any{}; }
  virtual std::any visit(UnaryExpr *expr) { return std::any{}; }
  virtual std::any visit(VariableExpr *expr) { return std::any{}; }

  virtual void visit(PrintStmt *stmt) {}
  virtual void visit(ExprStmt *stmt) {}

private:
};

#endif // !_INTERPRETER_HPP_