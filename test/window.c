#include <ncurses.h>

int main() {
    // 初始化 ncurses 模式
    initscr();
    // 禁用键盘输入缓冲
    cbreak();
    // 不显示输入字符
    noecho();

    // 获取屏幕的大小
    int height, width;
    getmaxyx(stdscr, height, width);

    // 计算窗口的大小
    int win_height = height - 4; // 减去边框和边距
    int win_width = width - 4;   // 减去边框和边距

    // 创建一个新的窗口
    WINDOW *win = newwin(win_height, win_width, 2, 2); // 从(2, 2)开始显示窗口

    // 使用自定义边框字符绘制边框
    wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');

    // 在窗口内写入一些内容
    mvwprintw(win, 1, 1, "This is a sample window");

    // 刷新窗口
    wrefresh(win);

    // 刷新整个屏幕
    refresh();

    // 等待用户按下任意键
    getch();

    // 结束 ncurses 模式
    endwin();

    return 0;
}