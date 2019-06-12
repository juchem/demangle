cmake_minimum_required(VERSION 2.8)
add_executable(demangle src/demangle.cpp)
target_compile_features(demangle PRIVATE cxx_std_11)
target_compile_options(
  demangle
    PRIVATE
      -Werror
      -Wall
      -Wextra
)
target_link_libraries(demangle -static)

install(
  TARGETS
    demangle
  RUNTIME
  DESTINATION
    bin
)
