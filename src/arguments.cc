#include "arguments.h"

#include <CLI11.hpp>

#include "constants.h"

void arguments::Parse(int argc, char **argv) {
  using arguments::opts;

  CLI::App app{constants::kProgDesc};

  /* ---------------------------------------------------------------- */
  /*                              Options                             */
  /* ---------------------------------------------------------------- */
  app.add_option("-P,--port", opts.port, "Port to listen on");

  /* ---------------------------------------------------------------- */
  /*                               Parse                              */
  /* ---------------------------------------------------------------- */
  try {
    app.parse(argc, argv);
  } catch (const CLI ::ParseError &e) {
    exit(app.exit(e));  // NOLINT
  }
}
