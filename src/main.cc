#include <unistd.h>

#include <cstdio>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/screen/screen.hpp>

#include "arguments.h"
#include "main_ui.h"
#include "screen.h"
#include "server.h"

static bool HandleQuit(const ftxui::Event& event) {
  if (event == ftxui::Event::Character('q')) {
    global::screen()->ExitLoopClosure()();
    return true;
  }
  return false;
}

int main(int argc, char** argv) {
  arguments::Parse(argc, argv);

  ftxui::Component main_component = std::make_shared<MainComponent>();

  main_component |= CatchEvent(HandleQuit);

  Server::StartServer();

  global::screen()->Loop(main_component);

  return 0;
}
