#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static char *strList[] = {
    ".", "..", "one", "two", "three", "four", "five"};
void draww(WINDOW *, int, int);
int main(int argc, char const *argv[])
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, true);
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *menuWindow = newwin(yMax - 1, xMax - 1, 0, 1);
    scrollok(menuWindow, true);
    box(menuWindow, 0, 0);
    draww(menuWindow, 0, yMax);
    sleep(1);
    char ch;
    int i = 1;
    do
    {
        switch (ch)
        {
        case 'a':
            i--;
            i = i < 0 ? 0 : i;
            break;
        case 'd':
            i++;
            i = i > yMax ? yMax : i;
            break;
        }
        draww(menuWindow, i, yMax);
    } while ((ch = getch()) && ch != 'q');
    endwin();
    return 0;
}
/**
 * 渲染目录，
 * 1. 根据传入的start去截取渲染的数据
 * 2. 如果传入的数据截取长度小于渲染的最大长度则触发清屏操作
 * */
void draww(WINDOW *win, int start, int size)
{
    wclear(win);
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    int len = 60 - start + size;
    len = len < yMax - 1 ? len : yMax - 1;
    for (int i = 0; i <= len; i++)
    {
        // strList[i];
        box(win, 0, 0);
        // mvwaddwstr(win, i, 2, L"asdfasdf");
        // wprintw(win, " %s %d\n", "1313231", i+start);
        mvwprintw(win, i + 1, 2, "%s %d \n", "  ---- -->", i + start - 1);
        wrefresh(win);
    }
    refresh();
}