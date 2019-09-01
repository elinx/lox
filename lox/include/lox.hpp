#ifndef _LOX_HPP_
#define _LOX_HPP_

#include <fstream>
#include <iostream>
#include <string>

class Lox {
private:
public:
  Lox() = default;
  ~Lox() = default;

  void runFile(std::string path) {
    std::string input;
    std::ifstream ifs(path, std::ios::binary);
    ifs >> input;
    run(input);
  }

  void runPrompt() {
    for (;;) {
      std::cout << "> ";
      std::string input;
      std::getline(std::cin, input);
      run(input);
    }
  }

  void run(std::string &input) {}
};

#endif