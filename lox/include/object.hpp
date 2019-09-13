#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_

#include <iostream>
#include <string>
#include <variant>

using Object = std::variant<std::monostate, float, std::string>;

template <class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template <class... Ts> overloaded(Ts...)->overloaded<Ts...>;

namespace object {

std::string toString(Object obj) {
  std::string res;
  std::visit(
      overloaded{
          [&res](auto arg) { res = ">_<"; },
          [&res](float arg) { res = std::to_string(arg); },
          [&res](std::string arg) { res = arg; },
      },
      obj);
  return res;
}

} // namespace object
#endif // !_OBJECT_HPP_