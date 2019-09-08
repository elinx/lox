#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include "expr.hpp"
#include "token.hpp"
#include <list>

/** Parser of lox
 *
 * Grammer:
 * expression     → equality ;
 * equality       → comparison ( ( "!=" | "==" ) comparison )* ;
 * comparison     → addition ( ( ">" | ">=" | "<" | "<=" ) addition )* ;
 * addition       → multiplication ( ( "-" | "+" ) multiplication )* ;
 * multiplication → unary ( ( "/" | "*" ) unary )* ;
 * unary          → ( "!" | "-" ) unary
 *                | primary ;
 * primary        → NUMBER | STRING | "false" | "true" | "nil"
 *                | "(" expression ")" ;
 */
class Parser {
public:
  Parser(std::list<Token> tokens) : _tokens(tokens), _current(0) {}
  Expr *parse() { return expression(); }
private:
  Expr *expression() { return equality(); }

  Expr *equality() {
    Expr *expr = comparison();
    while (match({TK_BANG_EQUAL, TK_EQUAL_EQUAL})) {
      Token op = previous();
      Expr *right = comparison();
      expr = new Binary(expr, op, right);
    }
    return expr;
  }

  bool match(std::initializer_list<TokenType> types) {
    for (auto type : types) {
      if (check(type)) {
        advance();
        return true;
      }
    }
    return false;
  }

  bool check(TokenType type) {
    if (isAtEnd()) {
      return false;
    }
    return peek().type() == type;
  }

  Token advance() {
    if (!isAtEnd()) {
      ++_current;
    }
    return previous();
  }

  bool isAtEnd() { return peek().type() == TK_EOF; }

  Token peek() { return *std::next(std::begin(_tokens), _current); }

  Token previous() { return *std::next(std::begin(_tokens), _current - 1); }

  Expr *comparison() {
    Expr *expr = addition();
    while (match({TK_GREATER, TK_GREATER_EQUAL, TK_LESS, TK_LESS_EQUAL})) {
      Token op = previous();
      Expr *right = addition();
      expr = new Binary(expr, op, right);
    }
    return expr;
  }

  Expr *addition() {
    Expr *expr = multiplication();

    while (match({TK_MINUS, TK_PLUS})) {
      Token op = previous();
      Expr *right = multiplication();
      expr = new Binary(expr, op, right);
    }

    return expr;
  }

  Expr *multiplication() {
    Expr *expr = unary();

    while (match({TK_SLASH, TK_STAR})) {
      Token op = previous();
      Expr *right = unary();
      expr = new Binary(expr, op, right);
    }

    return expr;
  }

  Expr *unary() {
    if (match({TK_BANG, TK_MINUS})) {
      Token op = previous();
      Expr *right = unary();
      return new Unary(op, right);
    }

    return primary();
  }

  Expr *primary() {
    if (match({TK_FALSE}))
      return new Literal(false);
    if (match({TK_TRUE}))
      return new Literal(true);
    if (match({TK_NIL}))
      return new Literal({});

    if (match({TK_NUMBER, TK_STRING})) {
      return new Literal(previous().literal());
    }

    if (match({TK_LEFT_PAREN})) {
      Expr *expr = expression();
      consume(TK_RIGHT_PAREN, "Expect ')' after expression.");
      return new Grouping(expr);
    }
    return nullptr;
  }

  Token consume(TokenType type, std::string str) {
    if (check(type)) { return advance(); }
    std::cout << "parse error\n";
    exit(1);
  }

private:
  std::list<Token> _tokens;
  size_t _current;
};

#endif