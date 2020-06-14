#include <iostream>

#include <lox/lox.hpp>

using lox::Lox;

int main(int argc, char **argv) {
  Lox lox;
  if (argc > 1) {
    std::cout << "Usage: jlox [script]\n";
  } else if (argc == 2) {
    lox.runFile(argv[1]);
  } else {
    lox.runPrompt();
  }
  return 0;
}