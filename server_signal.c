#include <stdio.h>
#include <signal.h>
#include <unistd.h>

unsigned char X = 0; // принимаемое сообщение (хоть abc хоть большой текст)

int length = 0; // длина передаваемого сообщения

void sighandler_1(int signum)
{

    //printf("USR1\n"); // принтф для того, чтобы увидеть, что сигнал в нашу программу действительно приходит.

    X = X >> 1; // сдвиг на 1
    length++;

 if (length >= 8)
        {
            printf("******%x %c\n", X,X);

            length = 0;

            X=0;

        }

}

void sighandler_2(int signum)
{

    //printf("USR2\n"); // принтф для того, чтобы увидеть, что сигнал в нашу программу действительно приходит.

    X = (X >> 1) + 128; // сдвиг на 1 и добавление 1 в младший разряд (128(10-ая = 10000000-2-ая) - это код, который вставляет единицу в самый старший разряд)
    length++;

    if (length >= 8)
        {
            printf("******%x %c\n", X,X);

            length = 0;

            X=0;

        }


}

int main(int argc, char *argv[])
{

    signal(SIGUSR1, sighandler_1);

    signal(SIGUSR2, sighandler_2);

    while (1)
    {
        sleep(1);

    }

        return 0;
}