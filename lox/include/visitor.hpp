#ifndef _VISITOR_HPP_
#define _VISITOR_HPP_

#include <any>

class BinaryExpr;
class AssignExpr;
class CallExpr;
class GetExpr;
class GroupingExpr;
class LiteralExpr;
class LogicalExpr;
class SetExpr;
class SuperExpr;
class ThisExpr;
class UnaryExpr;
class VariableExpr;

class ExprVisitor {
public:
  virtual std::any visit(BinaryExpr *expr) = 0;
  virtual std::any visit(AssignExpr *expr) = 0;
  virtual std::any visit(CallExpr *expr) = 0;
  virtual std::any visit(GetExpr *expr) = 0;
  virtual std::any visit(GroupingExpr *expr) = 0;
  virtual std::any visit(LiteralExpr *expr) = 0;
  virtual std::any visit(LogicalExpr *expr) = 0;
  virtual std::any visit(SetExpr *expr) = 0;
  virtual std::any visit(SuperExpr *expr) = 0;
  virtual std::any visit(ThisExpr *expr) = 0;
  virtual std::any visit(UnaryExpr *expr) = 0;
  virtual std::any visit(VariableExpr *expr) = 0;
};

class PrintStmt;
class ExprStmt;

class StmtVisitor {
public:
  virtual void visit(PrintStmt *stmt) = 0;
  virtual void visit(ExprStmt *stmt) = 0;
};

#endif