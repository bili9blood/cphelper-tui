#include <cstdio>

#include "arguments.h"

int main(int argc, char **argv) {
  arguments::Parse(argc, argv);

  printf("port: %d\n", arguments::opts.port);
}
