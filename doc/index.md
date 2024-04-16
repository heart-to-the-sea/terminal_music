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
## 如何实现交互

一个能够交互的界面至少需要一个不断刷新的loop循环,我们创建屏幕时，需要创建交互式屏幕。交互式屏幕可以显示动态组件。

元素和组件之间的关系：
```c++
  Element document = hbox({
    text("left")|border,
    text("right")|border
  });
  Component component = Renderer([&]{
    return document;
  });
```
  Renderer是一个组件,hbox是一个元素，组件可以包裹一个或多个元素，此时被包裹的元素就变为了一个组件。元素就变成了动态的可渲染的组件

  Renderer：renderer可以将一个已经存在的元素复制一份，然后在复制品上添加一些我梦自己想要的东西，比如按钮上方显示文字和进度条，同时该方法可接受多个参数
  参数如下：
    child：renderer接收child的原因是为了在绘制用户界面时复用child的行为，新创建的组件，将事件传递给child的行为，保持了组件相同的行为，同时可以改变渲染界面的方式。可以把rendeer想象成一个画家，而child可以想象成一个模型。
  
Renderer是一个装饰器，通过对节点包装，不仅保留了节点的特性，使得我们可以动态更改节点行为，而不需要改变节点本身。

```cpp
Component input1 = Input(&first_name,[&]{});
Component input2 = Input(&first_name,[&]{});

// 通过container容器包含这些组件
auto component = Container::Vertical({
  input1,
  input2
});
// 此时renderer就会包含容器包含的所有组件，并且事件发生时，会将事件转化为响应的子组建
auto renderer = Renderer(component,[&]{

});
```