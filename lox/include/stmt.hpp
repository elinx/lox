#ifndef _STMT_HPP_
#define _STMT_HPP_

#include "expr.hpp"

class Stmt {

};

class PrintStmt : public Stmt {
public:
  PrintStmt(Expr *value) : _value{value} {}
private:
  Expr *_value;
};

class ExprStmt : public Stmt {
public:
  ExprStmt(Expr *expr) : _expr(expr) {}
private:
  Expr *_expr;
};

#endif