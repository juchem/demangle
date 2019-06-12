#include <string>
#include <iostream>

#include <cstdlib>

#include <cxxabi.h>

void demangle(char const *symbol) {
	int status;
	auto name = abi::__cxa_demangle(symbol, 0, 0, &status);

  if (status) {
    std::cerr << "error: cannot demangle '" << symbol << '\'' << '\n';
  } else {
    std::cout << symbol << '\t' << name << std::endl;
  }

	std::free(name);
}

int main(int argc, char **argv) {
  for (int i = 1; i < argc; ++i) {
    demangle(argv[i]);
  }

  if (argc <= 1) {
    for (std::string s; std::cin >> s; ) {
      demangle(s.c_str());
    }
  }

  std::cerr.flush();

  return 0;
}
