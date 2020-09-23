#pragma once
#include <iostream>

namespace Internal
{
  template <typename... Args>
  void log(const char *fileName, int line, Args &&... args)
  {
    std::cout << fileName << ":" << line << ":";
    ((std::cout << " " << std::forward<Args>(args)), ...);
    std::cout << std::endl;
  }
} // namespace Internal

#define LOG(...) ::Internal::log(__FILE__, __LINE__, __VA_ARGS__)
