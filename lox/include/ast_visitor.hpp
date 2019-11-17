#ifndef _AST_VISITOR_HPP_
#define _AST_VISITOR_HPP_

#include "visitor.hpp"
#include <string>

class AstPrintVisitor : public ExprVisitor {
public:
  std::string print(Expr *expr) {
    expr->accept(*this);
    return result();
  }
  virtual void visit(BinaryExpr *expr) {
    parenthesize(expr->op(), expr->left(), expr->right());
  }
  virtual void visit(AssignExpr *expr) {
    parenthesize2("=", expr->name(), expr->value());
  }
  virtual void visit(CallExpr *expr) {}
  virtual void visit(GetExpr *expr) {}
  virtual void visit(GroupingExpr *expr) {
    parenthesize("group", expr->expression());
  }
  virtual void visit(LiteralExpr *expr) { _result += expr->toString(); }
  virtual void visit(LogicalExpr *expr) {}
  virtual void visit(SetExpr *expr) {}
  virtual void visit(SuperExpr *expr) {}
  virtual void visit(ThisExpr *expr) {}
  virtual void visit(UnaryExpr *expr) {
    parenthesize(expr->op(), expr->right());
  }
  virtual void visit(VariableExpr *expr) {}

  std::string result() { return _result; }

private:
  void parenthesize(const std::string& name, std::initializer_list<Expr *> exprs) {
    _result += "(" + name;
    for (auto expr : exprs) {
      _result += " ";
      AstPrintVisitor vis;
      expr->accept(vis);
      _result += vis.result();
    }
    _result += ")";
  }

  template <typename... Ts>
  void parenthesize(std::string name, Ts &&... exprs) {
    parenthesize(name, {std::forward<Ts>(exprs)...});
  }

  void parenthesize2(const std::string& op, const std::string& name, Expr* value) {
    _result += "(" + op + " " + name;
      AstPrintVisitor vis;
      _result += vis.print(value);
    _result += ")";
  }

private:
  std::string _result;
};

#endif