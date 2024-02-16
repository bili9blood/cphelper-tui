#include "components.h"

#include <ftxui/component/component.hpp>

using namespace ftxui;
using namespace components;

Element components::field(const std::string& label, const Color& label_color, const Element& value) {
  return hbox(
      text(" " + label + " ") | bgcolor(label_color) | bold,
      separatorEmpty(),
      value
  );
}
