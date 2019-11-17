#ifndef _VISITOR_HPP_
#define _VISITOR_HPP_

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
  virtual void visit(BinaryExpr *expr) = 0;
  virtual void visit(AssignExpr *expr) = 0;
  virtual void visit(CallExpr *expr) = 0;
  virtual void visit(GetExpr *expr) = 0;
  virtual void visit(GroupingExpr *expr) = 0;
  virtual void visit(LiteralExpr *expr) = 0;
  virtual void visit(LogicalExpr *expr) = 0;
  virtual void visit(SetExpr *expr) = 0;
  virtual void visit(SuperExpr *expr) = 0;
  virtual void visit(ThisExpr *expr) = 0;
  virtual void visit(UnaryExpr *expr) = 0;
  virtual void visit(VariableExpr *expr) = 0;
};

#endif