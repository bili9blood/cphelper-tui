#include "arguments.h"

#include <CLI11.hpp>

#include "constants.h"

void ParseArguments(int argc, char **argv) {
  CLI::App app{constants::kProgDesc};

  // TODO: add options

  try {
    app.parse(argc, argv);
  } catch (const CLI ::ParseError &e) {
    exit(app.exit(e));  // NOLINT
  }
}
