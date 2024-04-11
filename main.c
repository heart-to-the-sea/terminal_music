#include <ncurses.h>
// document https://www.gnu.org/software/guile-ncurses/manual/
// build gcc main.c -lncurses
int main(int argc, char const *argv[])
{
  int ch;
  initscr(); // 获取终端特征如大小等，并设置终端支持的curses环境
  raw();
  cbreak(); // 禁用缓冲区,并设置curses每次只接受一个字符
  noecho(); // 告诉curses不要把输入回显到屏幕上
  clear(); // 清空当前屏幕

  /////////////////////////////////
  

  /////////////////////////////////
  refresh();
  getch();
  endwin(); // 返回控制台
  
  return 0;
}
