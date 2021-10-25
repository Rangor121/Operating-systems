#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main()
{


  int pid = 2371;               // постоянно меняется. надо проверять pf -A
  char *msg = "Hello world!\0"; // указатель на массив символов
  unsigned char ch;             // текущий символ строки

  int y = 0; // Индекс строки



  while ((ch = msg[y++]) != 0)
  {

    for (int i = 0; i < 8; ++i)
    {
      if (ch % 2 == 0)
      {
        kill(pid, SIGUSR1);
      } // посылаем SIGUSR1
      else
      {
        kill(pid, SIGUSR2);
      } // посылаем SIGUSR2
      ch = ch / 2;

      usleep(1000);
    }
  }

  return 0;
}

// мы сказали, что на sigint надо реагировать вызовом sighandler. Сигнал sigint возникает в тот момент, когда мы пытаемся прервать выполнение команды.

// вместо того, чтобы прерваться команда печатает abc
