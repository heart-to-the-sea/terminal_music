#include <curses.h>
#include <ncurses.h>
#include <wchar.h>
#include<locale.h>

int main() {
    setlocale(LC_ALL, ""); // 设置本地化环境，以支持宽字符

    initscr(); // 初始化ncurses
    cbreak(); // 禁用行缓冲（即禁用回车键缓冲）
    noecho(); // 禁止回显输入字符
    keypad(stdscr, TRUE); // 启用键盘输入

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x); // 获取屏幕大小

    WINDOW *win = newwin(max_y - 2, max_x - 2, 1, 1); // 创建一个窗口
    scrollok(win, TRUE); // 启用窗口滚动功能
    box(win, 0, 0);
    // 向窗口中输出一些内容，填充窗口
    for (int i = 0; i < 100; i++) {
        mvwprintw(win, i, 0, "Line %d", i);
    }

    // 在指定位置输出中文字符
    mvwaddwstr(win, 5, 10, L"你好");

    wrefresh(win); // 刷新窗口

    // 等待用户输入
    getch();

    endwin(); // 结束ncurses
    return 0;
}