#include <iostream>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

// 自定义按钮组件
class CustomButton : public ComponentBase {
public:
    CustomButton(std::wstring label, std::function<void()> onclick)
        : label_(std::move(label)), onclick_(std::move(onclick)) {}
    
    Element Render() override {
        // 渲染按钮
        return hbox({
            text(L"[ "),
            text(label_) | size(WIDTH, EQUAL, label_.size() + 2),
            text(L" ]"),
        });
    }

    bool OnEvent(Event event) override {
        // 处理点击事件
        if (event == Event::Return) {
            onclick_();
            return true;
        }
        return false;
    }

private:
    std::wstring label_;
    std::function<void()> onclick_;
};

int main() {
    // 创建 ScreenInteractive 对象
    auto screen = ScreenInteractive::Fullscreen();
    // 自定义按钮点击事件
    auto onclick = [] {
        std::wcout << L"Button clicked!" << std::endl;
    };

    // 创建自定义按钮组件
    auto button = std::make_shared<CustomButton>(L"My Button", onclick);

    // 将按钮添加到屏幕
    screen.Loop(button);

    return 0;
}
