## ftxui模块组成

ftxui由3个模块组成

1. screen 定义 ftxui::screen 和由 ftxui::Pixel 组成的网格
2. dom 这是一个主模块，定义了一个层次化的ftxui::Element集合，一个远足在ftxui::Screen上绘制一些东西，它受容器的大小影响
3. component 如果程序需要响应用户输入，则需要使用这个模块，它定义了一组ftxui::Component. 这些组件可以使用箭头或光标进行导航，有几个内置组件，如复选框，输入框等进行交互

## 固定一侧，并拖拽另一侧

```
ResizableSplitLeft
ResizableSplitRight
ResizableSplitTop
ResizableSplitBottom
```
