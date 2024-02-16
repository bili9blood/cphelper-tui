#pragma once

#include <ftxui/component/component_base.hpp>
#include <nlohmann/json.hpp>

class MainComponent final : public ftxui::ComponentBase {
 public:
  MainComponent();

 private:
  ftxui::Element Render() final;
  bool           OnEvent(ftxui::Event event) final;
  bool           OnCharEvent(ftxui::Event event);
  void           HandleProblemInfo(const nlohmann::json& info);

  std::string    problem_name_;
  std::string    problem_group_;

  int            info_window_width_{20};
  int            verdict_window_height_{1};

  bool           show_detail_info_{false};
};
