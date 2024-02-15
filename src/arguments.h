#pragma once

namespace arguments {

struct Options {
  int port{17980};
} inline opts;

void Parse(int argc, char** argv);

}
