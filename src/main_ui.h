#pragma once

#include <ftxui/component/component_base.hpp>
#include <mutex>

class MainComponent final : public ftxui::ComponentBase {
 public:
  MainComponent();

  void SetProblemName(const std::string& name);

 private:
  ftxui::Element Render() final;
  bool           OnEvent(ftxui::Event event) final;
  bool           OnMouseEvent(ftxui::Event event);
  bool           OnCharEvent(ftxui::Event event);
  void           HandleProblemInfo(const std::string& info);

  std::string    problem_name_;
  std::string    problem_group_;

  int            info_window_width_{20};
  int            verdict_window_height_{1};

  bool           show_detail_info_{false};
};
