#include <ncurses.h>
// document https://www.gnu.org/software/guile-ncurses/manual/
// build gcc main.c -lncurses
int main(int argc, char const *argv[])
{
  initscr(); // 获取终端特征如大小等，并设置终端支持的curses环境
  cbreak(); // 禁用缓冲区,并设置curses每次只接受一个字符
  noecho(); // 告诉curses不要把输入回显到屏幕上
  clear(); // 清空当前屏幕
  int scrLine, scrCol;
  getmaxyx(stdscr, scrLine, scrCol);
  printf("%d %d \n",scrLine,scrCol);
  mvaddstr(scrLine-1,0,"hello world");

  getch(); // 等待用户输入
  endwin(); // 返回控制台
  
  return 0;
}
