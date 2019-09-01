#ifndef _LOX_HPP_
#define _LOX_HPP_

#include <algorithm>
#include <fstream>
#include <iostream>

#include "scanner.hpp"

class Lox {
private:
public:
  Lox() = default;
  ~Lox() = default;

  static void runFile(std::string path) {
    std::string input;
    std::ifstream ifs(path, std::ios::binary);
    ifs >> input;
    run(input);
  }

  static void runPrompt() {
    for (;;) {
      std::cout << "> ";
      std::string input;
      std::getline(std::cin, input);
      run(input);
    }
  }

  static void run(std::string &source) {
    Scanner scanner(source);
    std::list<Token> tokens = scanner.scanTokens();
    for (auto token : tokens) {
      std::cout << token << std::endl;
    }
  }

  static void error(size_t line, std::string message) {
    report(line, "", message);
  }

  static void report(size_t line, std::string where, std::string message) {
    std::cout << "[line " + std::to_string(line) + "] Error" + where + ": " +
                     message
              << "\n";
  }
};

#endif