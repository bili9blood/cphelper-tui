#include "main_ui.h"

#include <fstream>
#include <ftxui/component/event.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/terminal.hpp>
#include <nlohmann/json.hpp>
#include <string>

#include "arguments.h"
#include "components.h"

using namespace components;
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

          field(
              "AC", Color::GreenLight, text("Congratulations!") | flex
          ) | size(HEIGHT, EQUAL, verdict_window_height_) |
              border
      ) | flex,

      window(
          text("Info") | bold,
          vbox(
              field("NAME", Color::DarkOrange, text(problem_name_)),

              filler(),
              show_detail_info_
                  ? (vbox(
                        separator(),
                        field("PORT", Color::BlueViolet, text(std::to_string(arguments::port)))
                    ))
                  : vbox()
          )
      ) | size(WIDTH, EQUAL, info_window_width_)
  );
}

void MainComponent::SetProblemName(const std::string& name) {
  problem_name_ = name;
}

bool MainComponent::OnEvent(Event event) {
  auto out{false};

  if (event.is_character())
    out |= OnCharEvent(std::move(event));
  else if (nlohmann::json::accept(event.input())) {
    HandleProblemInfo(event.input());
    const Event _e = std::move(event);
    out            = true;
  }

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

void MainComponent::HandleProblemInfo(const std::string& info) {
  try {
    const auto json = nlohmann::json::parse(info);
    problem_name_   = json["name"];
    problem_group_  = json["group"];
  } catch (const nlohmann::json::exception& e) {
    return;
  }
}
