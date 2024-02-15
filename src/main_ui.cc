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
          vbox(
              text("input"),
              text("output")
          ) | border,
          text("AC") | center | color(Color::GreenLight) | bold | inverted | border
      ) | flex,
      text("info") | border

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

  return out;
}
