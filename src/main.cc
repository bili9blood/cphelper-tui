#include <cstdio>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/screen/screen.hpp>

#include "arguments.h"
#include "main_ui.h"

int main(int argc, char **argv) {
  using namespace ftxui;

  arguments::Parse(argc, argv);

  auto       screen         = ScreenInteractive::Fullscreen();
  auto       main_component = (std::shared_ptr<ComponentBase>)Make<MainComponent>();

  const auto HandleQuit     = [&](const Event &event) {
    if (event == Event::Character('q')) {
      screen.ExitLoopClosure()();
      return true;
    }
    return false;
  };

  main_component |= CatchEvent(HandleQuit);

  screen.Loop(main_component);

  return 0;
}
