cmake_minimum_required(VERSION 3.12..3.20)

project(
  angwolf
  LANGUAGES C
  VERSION 0.1.0
)

add_executable(
  angwolf
  main.c 
  generate.c
  misc.c
  vectorize.c
  )

# Copies executable to local install directory after build
add_custom_command(
  TARGET angwolf
  POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E copy "$<TARGET_FILE:angwolf>"
          "${CMAKE_CURRENT_LIST_DIR}"
)