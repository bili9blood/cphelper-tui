#pragma once
#include <ftxui/component/screen_interactive.hpp>

namespace global {
inline ftxui::ScreenInteractive* screen() {
  static ftxui::ScreenInteractive _screen = ftxui::ScreenInteractive::Fullscreen();
  return &_screen;
}
}  // namespace global
