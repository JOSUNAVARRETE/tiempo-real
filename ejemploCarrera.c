
#include <stdio.h>
#include <pthread.h>

int turno;

void* imprime_A(void* arg)
{
    while (1)
    {
        if (turno == 0)
        {
            printf("A");
            turno = 1;
        }
    }
}

void* imprime_B(void* arg)
{
    while (1)
    {
        if (turno == 1)
        {
            printf("B");
            turno = 0;
        }
    }
}

int main()
{
    pthread_t thread_id1, thread_id2;
    turno = 0;
    pthread_create(&thread_id1, NULL, imprime_A, NULL);
    pthread_create(&thread_id2, NULL, imprime_B, NULL);
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    return 0;
}