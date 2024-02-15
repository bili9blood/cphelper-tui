#pragma once

#include <ftxui/component/component_base.hpp>

class MainComponent final : public ftxui::ComponentBase {
 public:
  MainComponent();

 private:
  ftxui::Element Render() final;
  bool           OnEvent(ftxui::Event event) final;
  bool           OnMouseEvent(ftxui::Event event);
  bool           OnCharEvent(ftxui::Event event);

  std::string    problem_name_;

  int            info_window_width_{20};
  int            verdict_window_height_{1};

  bool           show_detail_info_{false};
};
