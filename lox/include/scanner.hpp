#ifndef _SCANNER_HPP_
#define _SCANNER_HPP_

#include "token.hpp"
#include <list>
#include <string>

class Scanner {
private:
  std::string _source;
  std::list<Token> _tokens;
  size_t _start;
  size_t _current;
  size_t _line;

public:
  Scanner(std::string source)
      : _source(source), _start(0), _current(0), _line(1) {}
  ~Scanner() {}

  std::list<Token> scanTokens() {
    while (!isAtEnd()) {
      _start = _current;
      scanToken();
    }

    _tokens.push_back(Token(TK_EOF, "", nullptr, _line));
    return _tokens;
  }

private:
  bool isAtEnd() { return _current >= _source.length(); }
  void scanToken() {
    char c = advance();
    switch (c) {
      case '(': addToken(TK_LEFT_PAREN); break;
      case ')': addToken(TK_RIGHT_PAREN); break;
      case '{': addToken(TK_LEFT_BRACE); break;
      case '}': addToken(TK_RIGHT_BRACE); break;
      case ',': addToken(TK_COMMA); break;
      case '.': addToken(TK_DOT); break;
      case '-': addToken(TK_MINUS); break;
      case '+': addToken(TK_PLUS); break;
      case ';': addToken(TK_SEMICOLON); break;
      case '*': addToken(TK_STAR); break;
      default:

      break;
    }
  }

  char advance() {
    _current++;
    return _source.at(_current - 1);
  }

  void addToken(TokenType type) {
    addToken(type, nullptr);
  }

  void addToken(TokenType type, Object *literal) {
    std::string text = _source.substr(_start, _current - _start);
    _tokens.push_back(Token{type, text, literal, _line});
  }
};

#endif // !_SCANNER_HPP_