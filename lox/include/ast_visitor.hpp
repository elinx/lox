#ifndef _AST_VISITOR_HPP_
#define _AST_VISITOR_HPP_

#include "visitor.hpp"
#include <string>

class AstPrintVisitor : public ExprVisitor {
public:
  virtual std::any visit(BinaryExpr *expr) {
    return parenthesize(expr->op(), expr->left(), expr->right());
  }
  virtual std::any visit(AssignExpr *expr) {
    return parenthesize2("=", expr->name(), expr->value());
  }
  virtual std::any visit(CallExpr *expr) { return std::any{}; }
  virtual std::any visit(GetExpr *expr) { return std::any{}; }
  virtual std::any visit(GroupingExpr *expr) {
    return parenthesize("group", expr->expression());
  }
  virtual std::any visit(LiteralExpr *expr) { return expr->toString(); }
  virtual std::any visit(LogicalExpr *expr) { return std::any{}; }
  virtual std::any visit(SetExpr *expr) { return std::any{}; }
  virtual std::any visit(SuperExpr *expr) { return std::any{}; }
  virtual std::any visit(ThisExpr *expr) { return std::any{}; }
  virtual std::any visit(UnaryExpr *expr) {
    return parenthesize(expr->op(), expr->right());
  }
  virtual std::any visit(VariableExpr *expr) { return std::any{}; }

private:
  std::string parenthesize(const std::string& name, std::initializer_list<Expr *> exprs) {
    std::string res{"(" + name};
    for (auto expr : exprs) {
      res += " ";
      res += std::any_cast<std::string>(expr->accept(*this));
    }
    res += ")";
    return res;
  }

  template <typename... Ts>
  std::string parenthesize(std::string name, Ts &&... exprs) {
    return parenthesize(name, {std::forward<Ts>(exprs)...});
  }

  std::string parenthesize2(const std::string& op, const std::string& name, Expr* value) {
    std::string res{"(" + op + " " + name};
    res += std::any_cast<std::string>(value->accept(*this));
    res += ")";
    return res;
  }
};

#endif