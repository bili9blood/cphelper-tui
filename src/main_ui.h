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
};
