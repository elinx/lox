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
  virtual ~ExprVisitor() = default;
  virtual Object visit(const BinaryExpr& expr) = 0;
  virtual Object visit(const AssignExpr& expr) = 0;
  virtual Object visit(const CallExpr& expr) = 0;
  virtual Object visit(const GetExpr& expr) = 0;
  virtual Object visit(const GroupingExpr& expr) = 0;
  virtual Object visit(const LiteralExpr& expr) = 0;
  virtual Object visit(const LogicalExpr& expr) = 0;
  virtual Object visit(const SetExpr& expr) = 0;
  virtual Object visit(const SuperExpr& expr) = 0;
  virtual Object visit(const ThisExpr& expr) = 0;
  virtual Object visit(const UnaryExpr& expr) = 0;
  virtual Object visit(const VariableExpr& expr) = 0;
};

class PrintStmt;
class ExprStmt;

class StmtVisitor {
public:
  virtual void visit(const PrintStmt& stmt) = 0;
  virtual void visit(const ExprStmt& stmt) = 0;
};

#endif