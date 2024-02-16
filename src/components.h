#pragma once

#include <memory>
namespace ftxui {
class Node;
class Color;
}  // namespace ftxui

namespace components {
using Element = std::shared_ptr<ftxui::Node>;

Element field(const std::string& label, const ftxui::Color& label_color, const Element& value);
}  // namespace components
