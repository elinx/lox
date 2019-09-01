#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_

#include <variant>

using Object = std::variant<std::monostate, float, std::string>;

#endif // !_OBJECT_HPP_