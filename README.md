# angdoom-cmake
Angdoom DOOM Level Generator

This is the Angdoom level generator from http://interreality.org/~tetron/technology/angdoom/, setup as a CMake project with some altered defines
to be MSVC compatible as well as removing the need for the GGI library. The plan is to eventually integrate this into Obsidian after working on
a standalone variant.

USAGE (from a GUI/file explorer)

Double-click angdoom or angdoom.exe

USAGE (from a terminal/command prompt)

> ./angdoom

or

> angdoom.exe

This will produce a file called output.wad in the same directory. At this time, there are no command-line options. Also, you will need to use a nodebuilder or 
a source port capable of generating its own nodes (The *ZDoom family, EDGE-Classic, EDGE and possibly others)

