#include "ftxui/dom/elements.hpp"                 // for Element, operator|, text, center, border
using namespace ftxui;

auto main() -> int {
  Element document = hbox({
    text("left")|border,
    text("right")|border
  });
  auto screen = Screen::Create(
    Dimension::Full(),
    Dimension::Full()
  );

  Render(screen,document);
  screen.Print();
}
