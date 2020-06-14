#ifndef _INTERPRETER_HPP_
#define _INTERPRETER_HPP_

#include "visitor.hpp"

class Interpreter : public ExprVisitor, StmtVisitor {
public:
  virtual Object visit(BinaryExpr *expr) { return std::monostate{}; }
  virtual Object visit(AssignExpr *expr) { return std::monostate{}; }
  virtual Object visit(CallExpr *expr) { return std::monostate{}; }
  virtual Object visit(GetExpr *expr) { return std::monostate{}; }
  virtual Object visit(GroupingExpr *expr) { return std::monostate{}; }
  virtual Object visit(LiteralExpr *expr) { return std::monostate{}; }
  virtual Object visit(LogicalExpr *expr) { return std::monostate{}; }
  virtual Object visit(SetExpr *expr) { return std::monostate{}; }
  virtual Object visit(SuperExpr *expr) { return std::monostate{}; }
  virtual Object visit(ThisExpr *expr) { return std::monostate{}; }
  virtual Object visit(UnaryExpr *expr) { return std::monostate{}; }
  virtual Object visit(VariableExpr *expr) { return std::monostate{}; }

  virtual void visit(PrintStmt *stmt) {}
  virtual void visit(ExprStmt *stmt) {}

private:
};

#endif // !_INTERPRETER_HPP_