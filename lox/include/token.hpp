#ifndef _TOKEN_HPP_
#define _TOKEN_HPP_

#include <array>
#include <ostream>
#include <string>
#include <unordered_map>

#include "object.hpp"

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

std::string tokenName(TokenType type) {
  static std::array<std::string,
                    static_cast<size_t>(TK_EOF - TK_LEFT_PAREN + 1)>
      TokenStr{{// Single-character tokens.
                "TK_LEFT_PAREN", "TK_RIGHT_PAREN", "TK_LEFT_BRACE",
                "TK_RIGHT_BRACE", "TK_COMMA", "TK_DOT", "TK_MINUS", "TK_PLUS",
                "TK_SEMICOLON", "TK_SLASH", "TK_STAR",

                // One or two character tokens.
                "TK_BANG", "TK_BANG_EQUAL", "TK_EQUAL", "TK_EQUAL_EQUAL",
                "TK_GREATER", "TK_GREATER_EQUAL", "TK_LESS", "TK_LESS_EQUAL",

                // Literals.
                "TK_IDENTIFIER", "TK_STRING", "TK_NUMBER",

                // Keywords.
                "TK_AND", "TK_CLASS", "TK_ELSE", "TK_FALSE", "TK_FUN", "TK_FOR",
                "TK_IF", "TK_NIL", "TK_OR", "TK_PRINT", "TK_RETURN", "TK_SUPER",
                "TK_THIS", "TK_TRUE", "TK_VAR", "TK_WHILE",

                "TK_EOF"}};
  return TokenStr[type];
}

using KeywordsTokenMap = std::unordered_map<std::string, TokenType>;
KeywordsTokenMap &keywordsMap() {
  static KeywordsTokenMap keywords{
      {"and", TK_AND},     {"class", TK_CLASS},   {"else", TK_ELSE},
      {"false", TK_FALSE}, {"for", TK_FOR},       {"fun", TK_FUN},
      {"if", TK_IF},       {"nil", TK_NIL},       {"or", TK_OR},
      {"print", TK_PRINT}, {"return", TK_RETURN}, {"super", TK_SUPER},
      {"this", TK_THIS},   {"true", TK_TRUE},     {"var", TK_VAR},
      {"while", TK_WHILE},
  };
  return keywords;
};

TokenType keywordsTokenTypeLookup(std::string keywords) {
  return keywordsMap()[keywords];
}

class Token {
public:
  Token(TokenType type, std::string lexeme, Object literal, size_t line,
        size_t start, size_t len)
      : _type(type), _lexeme(lexeme), _literal(literal), _line(line),
        _start(start), _len(len) {}

  TokenType type() { return _type; }
  Object literal() { return _literal; }
  std::string lexme() { return _lexeme; }

  friend std::ostream &operator<<(std::ostream &os, const Token &token);

private:
  TokenType _type;
  std::string _lexeme;
  Object _literal;
  size_t _line;
  size_t _start;
  size_t _len;
};

std::ostream &operator<<(std::ostream &os, const Token &token) {
  os << " [line:" << token._line << ", " << token._start << ":" << token._len
     << "] ";
  os << tokenName(token._type) << " " << token._lexeme << " ";
  os << object::toString(token._literal);
  return os;
}

#endif