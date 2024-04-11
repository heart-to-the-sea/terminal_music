#include <ncurses.h>

int main() {
    initscr(); // 初始化ncurses
    cbreak(); // 禁用行缓冲（即禁用回车键缓冲）
    noecho(); // 禁止回显输入字符
    keypad(stdscr, TRUE); // 启用键盘输入

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x); // 获取屏幕大小

    WINDOW *win = newwin(max_y - 2, max_x - 2, 1, 1); // 创建一个窗口
    scrollok(win, TRUE); // 启用窗口滚动功能

    // 向窗口中输出一些内容，填充窗口
    for (int i = 0; i < 100; i++) {
        wprintw(win, "Line %d\n", i);
    }

    wrefresh(win); // 刷新窗口

    int ch;
    int scroll = 0; // 记录当前的滚动位置

    // 循环等待用户输入，响应上下键进行滚动
    while ((ch = getch()) != 'q') { // 输入'q'退出循环
        switch (ch) {
            case KEY_UP: // 上键
                if (scroll > 0) {
                    scroll--; // 向上滚动
                    wscrl(win, -1); // 向上滚动一个行
                    wrefresh(win); // 刷新窗口
                }
                break;
            case KEY_DOWN: // 下键
                if (scroll < 100 - max_y + 2) {
                    scroll++; // 向下滚动
                    wscrl(win, 1); // 向下滚动一个行
                    wrefresh(win); // 刷新窗口
                }
                break;
            default:
                break;
        }
    }

    endwin(); // 结束ncurses
    return 0;
}