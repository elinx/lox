#ifndef _AST_VISITOR_HPP_
#define _AST_VISITOR_HPP_

#include "visitor.hpp"
#include <string>

class AstPrintVisitor : public Visitor {
public:
  std::string print(Expr *expr) {
    expr->accept(*this);
    return result();
  }
  virtual void visit(Binary &expr) {
    parenthesize(expr.op(), expr.left(), expr.right());
  }
  virtual void visit(Assign &expr) {
    // parenthesize2("=", expr.name(), expr.value());
  }
  virtual void visit(Call &expr) {}
  virtual void visit(Get &expr) {}
  virtual void visit(Grouping &expr) {
    parenthesize("group", expr.expression());
  }
  virtual void visit(Literal &expr) { _result += expr.toString(); }
  virtual void visit(Logical &expr) {}
  virtual void visit(Set &expr) {}
  virtual void visit(Super &expr) {}
  virtual void visit(This &expr) {}
  virtual void visit(Unary &expr) {
    parenthesize(expr.op(), expr.right());
  }
  virtual void visit(Variable &expr) {}

  std::string result() { return _result; }

private:
  void parenthesize(std::string name, std::initializer_list<Expr *> exprs) {
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

private:
  std::string _result;
};

#endif