#ifndef _TOKEN_HPP_
#define _TOKEN_HPP_

#include "object.hpp"
#include <string>
#include <ostream>
#include <array>

enum TokenType {
  // Single-character tokens.
  TK_LEFT_PAREN = 0,
  TK_RIGHT_PAREN,
  TK_LEFT_BRACE,
  TK_RIGHT_BRACE,
  TK_COMMA,
  TK_DOT,
  TK_MINUS,
  TK_PLUS,
  TK_SEMICOLON,
  TK_SLASH,
  TK_STAR,

  // One or two character tokens.
  TK_BANG,
  TK_BANG_EQUAL,
  TK_EQUAL,
  TK_EQUAL_EQUAL,
  TK_GREATER,
  TK_GREATER_EQUAL,
  TK_LESS,
  TK_LESS_EQUAL,

  // Literals.
  TK_IDENTIFIER,
  TK_STRING,
  TK_NUMBER,

  // Keywords.
  TK_AND,
  TK_CLASS,
  TK_ELSE,
  TK_FALSE,
  TK_FUN,
  TK_FOR,
  TK_IF,
  TK_NIL,
  TK_OR,
  TK_PRINT,
  TK_RETURN,
  TK_SUPER,
  TK_THIS,
  TK_TRUE,
  TK_VAR,
  TK_WHILE,

  TK_EOF
};

std::array<std::string, static_cast<size_t>(TK_EOF - TK_LEFT_PAREN + 1)> TokenStr{ {
  // Single-character tokens.
  "TK_LEFT_PAREN",
  "TK_RIGHT_PAREN",
  "TK_LEFT_BRACE",
  "TK_RIGHT_BRACE",
  "TK_COMMA",
  "TK_DOT",
  "TK_MINUS",
  "TK_PLUS",
  "TK_SEMICOLON",
  "TK_SLASH",
  "TK_STAR",

  // One or two character tokens.
  "TK_BANG",
  "TK_BANG_EQUAL",
  "TK_EQUAL",
  "TK_EQUAL_EQUAL",
  "TK_GREATER",
  "TK_GREATER_EQUAL",
  "TK_LESS",
  "TK_LESS_EQUAL",

  // Literals.
  "TK_IDENTIFIER",
  "TK_STRING",
  "TK_NUMBER",

  // Keywords.
  "TK_AND",
  "TK_CLASS",
  "TK_ELSE",
  "TK_FALSE",
  "TK_FUN",
  "TK_FOR",
  "TK_IF",
  "TK_NIL",
  "TK_OR",
  "TK_PRINT",
  "TK_RETURN",
  "TK_SUPER",
  "TK_THIS",
  "TK_TRUE",
  "TK_VAR",
  "TK_WHILE",

  "TK_EOF"
}};

std::string tokenName(TokenType type) {
  return TokenStr[type];
}

class Token {
public:
  Token(TokenType type, std::string lexeme, Object *literal, size_t line)
      : _type(type), _lexeme(lexeme), _literal(literal), _line(line) {}

  friend std::ostream& operator<< (std::ostream& os, const Token& token);
private:
  TokenType _type;
  std::string _lexeme;
  Object *_literal;
  size_t _line;
};

std::ostream& operator<< (std::ostream& os, const Token& token) {
  os << tokenName(token._type)  << " " << token._lexeme << " " << token._line;
  return os;
}
#endif