#ifndef _AST_VISITOR_HPP_
#define _AST_VISITOR_HPP_

#include "visitor.hpp"
#include <string>

class AstPrintVisitor : public ExprVisitor {
public:
  virtual Object visit(const BinaryExpr &expr) {
    return parenthesize(expr.op(), expr.left(), expr.right());
  }
  virtual Object visit(const AssignExpr &expr) {
    return parenthesize2("=", expr.name(), expr.value());
  }
  virtual Object visit(const CallExpr &expr) { return {}; }
  virtual Object visit(const GetExpr &expr) { return {}; }
  virtual Object visit(const GroupingExpr &expr) {
    return parenthesize("group", expr.expression());
  }
  virtual Object visit(const LiteralExpr &expr) { return expr.toString(); }
  virtual Object visit(const LogicalExpr &expr) {
    return parenthesize(expr.name(), expr.left(), expr.right());
  }
  virtual Object visit(const SetExpr &expr) { return {}; }
  virtual Object visit(const SuperExpr &expr) { return {}; }
  virtual Object visit(const ThisExpr &expr) { return std::string{"this"}; }
  virtual Object visit(const UnaryExpr &expr) {
    return parenthesize(expr.op(), expr.right());
  }
  virtual Object visit(const VariableExpr &expr) { return {}; }

private:
  std::string parenthesize(const std::string &name,
                           std::initializer_list<Expr *> exprs) {
    std::string res{"(" + name};
    for (auto expr : exprs) {
      res += " ";
      res += object::toString(expr->accept(*this));
    }
    res += ")";
    return res;
  }

  template <typename... Ts>
  std::string parenthesize(std::string name, Ts &&... exprs) {
    return parenthesize(name, {std::forward<Ts>(exprs)...});
  }

  std::string parenthesize2(const std::string &op, const std::string &name,
                            Expr *value) {
    std::string res{"(" + op + " " + name};
    res += object::toString(value->accept(*this));
    res += ")";
    return res;
  }
};

#endif