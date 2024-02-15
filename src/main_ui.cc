#include "main_ui.h"

#include <ftxui/component/event.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/terminal.hpp>
#include <string>

#include "arguments.h"
using namespace ftxui;

MainComponent::MainComponent() = default;

Element MainComponent::Render() {
  return hbox(
      vbox(
          window(
              text("Input") | bold,
              hbox(

              )
          ) | flex,

          window(
              text("Output") | bold,
              hbox(

              )
          ) | flex,

          hbox(
              text(" AC ") | center | bgcolor(Color::GreenLight) | bold,
              separatorEmpty(),
              text("Congratulations!") | flex
          ) | size(HEIGHT, EQUAL, verdict_window_height_) |
              border
      ) | flex,

      window(
          text("Info") | bold,
          vbox(
              hbox(
                  text(" NAME ") | bgcolor(Color::DarkOrange) | bold,
                  separatorEmpty(),
                  text(problem_name_)
              ),

              show_detail_info_
                  ? (vbox(
                        separator(),
                        hbox(
                            text(" PORT ") | bgcolor(Color::BlueViolet) | bold,
                            separatorEmpty(),
                            text(std::to_string(arguments::port))
                        )
                    ))
                  : vbox()
          )
      ) | size(WIDTH, EQUAL, info_window_width_)
  );
}

bool MainComponent::OnEvent(Event event) {
  auto out{false};

  if (event.is_mouse())
    out |= OnMouseEvent(std::move(event));
  else if (event.is_character())
    out |= OnCharEvent(std::move(event));

  return out;
}

bool MainComponent::OnMouseEvent(Event event) {
  auto out{false};

  return out;
}

bool MainComponent::OnCharEvent(Event event) {
  auto out{false};

  if (event.character() == "[") {
    info_window_width_ = std::min(info_window_width_ + 4, Terminal::Size().dimx);
    out                = true;
  } else if (event.character() == "]") {
    info_window_width_ = std::max(info_window_width_ - 4, 18);
    out                = true;
  } else if (event.character() == "'") {
    verdict_window_height_ = std::min(verdict_window_height_ + 1, Terminal::Size().dimy - 2);  // top border & bot border
    out                    = true;
  } else if (event.character() == ";") {
    verdict_window_height_ = std::max(verdict_window_height_ - 1, 1);
    out                    = true;
  } else if (event.character() == "d") {
    show_detail_info_ = !show_detail_info_;
    out               = true;
  }

  return out;
}
