// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
#include <memory> // for shared_ptr, allocator, __shared_ptr_access
#include <iostream>
#include "ftxui/component/captured_mouse.hpp"     // for ftxui
#include "ftxui/component/component.hpp"          // for Renderer, ResizableSplitBottom, ResizableSplitLeft, ResizableSplitRight, ResizableSplitTop
#include "ftxui/component/component_base.hpp"     // for ComponentBase
#include "ftxui/component/screen_interactive.hpp" // for ScreenInteractive
#include "ftxui/dom/elements.hpp"                 // for Element, operator|, text, center, border
using namespace ftxui;

ButtonOption Style()
{
  auto option = ButtonOption::Animated();
  option.transform = [](const EntryState &s)
  {
    auto element = text(s.label);
    return element;
  };
  return option;
}
Component Inner(std::vector<Component> children)
{
  Component vlist = Container::Vertical(std::move(children));
  return Renderer(vlist, [vlist]
                  { return hbox({
                        text(" "),
                        vlist->Render(),
                    }); });
}
Component Empty()
{
  return std::make_shared<ComponentBase>();
}
int main()
{
  auto screen = ScreenInteractive::Fullscreen();
  std::string sot = "⏸︎";
  std::string sot2 = "⏹︎";

  auto middle = Renderer([]
                         { return text("歌词") | center; });
  auto left = Renderer([&]
                       { return yframe(vbox({
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                             text("青花瓷"),
                         })); });
  auto right = Renderer([]
                        { return text("right") | center; });
  auto top = Renderer([]
                      { return text("终端音乐") | center; });
  auto btn_dec_10 = Button(
      sot, [&]
      {
        std::cout<<"111"<<std::endl;
         sot = "123"; },
      Style());

  auto bottom = Renderer([&]
                         { return hbox({text("◀"),
                                        text(" "),
                                        (btn_dec_10)->Render(),
                                        text(" "),
                                        text(" "),
                                        text("▶")}) |
                                  center; });

  int left_size = 40;
  int right_size = 0;
  int top_size = 1;
  int bottom_size = 1;

  auto container = middle;
  container = ResizableSplitLeft(left, container, &left_size);
  container = ResizableSplitRight(right, container, &right_size);
  container = ResizableSplitTop(top, container, &top_size);
  container = ResizableSplitBottom(bottom, container, &bottom_size);

  auto renderer =
      Renderer(container, [&]
               { return container->Render() | border; });

  screen.Loop(renderer);
}
