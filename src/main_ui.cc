#include "main_ui.h"

#include <ftxui/component/event.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>
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
          ) | border
      ) | flex,

      window(
          text("Problem Info") | bold,
          vbox(
          )
      ) | size(WIDTH, GREATER_THAN, 20)
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

  x = event.cursor_x();
  y = event.cursor_y();
  return out;
}

bool MainComponent::OnCharEvent(Event event) {
  auto out{false};

  return out;
}
