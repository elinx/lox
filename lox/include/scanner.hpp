#ifndef _SCANNER_HPP_
#define _SCANNER_HPP_

#include "lox.hpp"
#include "token.hpp"
#include <algorithm>
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

    _tokens.push_back(Token(TK_EOF, "", {}, _line, _current, 0));
    return _tokens;
  }

private:
  bool isAtEnd() { return _current >= _source.length(); }
  void scanToken() {
    char c = advance();
    switch (c) {
    case '(':
      addToken(TK_LEFT_PAREN);
      break;
    case ')':
      addToken(TK_RIGHT_PAREN);
      break;
    case '{':
      addToken(TK_LEFT_BRACE);
      break;
    case '}':
      addToken(TK_RIGHT_BRACE);
      break;
    case ',':
      addToken(TK_COMMA);
      break;
    case '.':
      addToken(TK_DOT);
      break;
    case '-':
      addToken(TK_MINUS);
      break;
    case '+':
      addToken(TK_PLUS);
      break;
    case ';':
      addToken(TK_SEMICOLON);
      break;
    case '*':
      addToken(TK_STAR);
      break;
    case '!':
      addToken(match('=') ? TK_BANG_EQUAL : TK_BANG);
      break;
    case '=':
      addToken(match('=') ? TK_EQUAL_EQUAL : TK_EQUAL);
      break;
    case '<':
      addToken(match('=') ? TK_LESS_EQUAL : TK_LESS);
      break;
    case '>':
      addToken(match('=') ? TK_GREATER_EQUAL : TK_GREATER);
      break;
    case '/':
      if (match('/')) {
        while (peek() != '\n' && !isAtEnd())
          advance();
      } else {
        addToken(TK_SLASH);
      }
      break;
    case ' ':
    case '\r':
    case '\t':
      // Ignore whitespace.
      break;
    case '\n':
      _line++;
      break;
    case '"':
      str();
      break;
    default:
      if (isdigit(c)) {
        num();
      } else if (isalpha(c)) {
        identifier();
      } else {
        // Lox::error(_line, "Unexpected character.");
      }
      break;
    }
  }

  char advance() {
    _current++;
    return _source.at(_current - 1);
  }

  void addToken(TokenType type) { addToken(type, {}); }

  void addToken(TokenType type, Object literal) {
    std::string text = _source.substr(_start, _current - _start);
    _tokens.push_back(
        Token{type, text, literal, _line, _start, _current - _start});
  }

  bool match(char expected) {
    if (isAtEnd()) {
      return false;
    }
    if (_source.at(_current) != expected) {
      return false;
    }
    ++_current;
    return true;
  }

  char peek() {
    if (isAtEnd()) {
      return '\0';
    }
    return _source.at(_current);
  }

  void str() {
    while (peek() != '"' && !isAtEnd()) {
      if (peek() == '\n') {
        ++_line;
      }
      advance();
    }
    // unterminated string
    if (isAtEnd()) {
      // Lox.error(_line, "Unterminated string");
      return;
    }
    // the closing "
    advance();
    // trim the surrounding quotes
    std::string value = _source.substr(_start + 1, _current - 1 - _start - 1);
    addToken(TK_STRING, value);
  }

  void num() {
    while (isdigit(peek())) {
      advance();
    }
    // look for a fractional part
    if (peek() == '.' && isdigit(peekNext())) {
      advance();
      while (isdigit(peek())) {
        advance();
      }
    }
    addToken(TK_NUMBER, std::stof(_source.substr(_start, _current - _start)));
  }

  char peekNext() {
    if (_current + 1 >= _source.length()) {
      return '\0';
    }
    return _source.at(_current + 1);
  }

  void identifier() {
    while (isalnum(peek())) {
      advance();
    }
    std::string text = _source.substr(_start, _current - _start);
    auto type = keywordsTokenTypeLookup(text);
    if (type > TK_EOF) {
      type = TK_IDENTIFIER;
    }
    addToken(type);
  }
};

#endif // !_SCANNER_HPP_