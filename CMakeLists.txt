# Same version line copied from Obsidian...if needs be I'm sure this can be adjusted quite a bit downward
cmake_minimum_required(VERSION 3.12..3.20)

project(
  angdoom
  LANGUAGES C
  VERSION 0.1.0
)

add_executable(
  angdoom
  main.c 
  generate.c
  misc.c
  vectorize.c
  )

# Copies executable to local install directory after build
add_custom_command(
  TARGET angdoom
  POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E copy "$<TARGET_FILE:angdoom>"
          "${CMAKE_CURRENT_LIST_DIR}"
)