#include <stdio.h>
#include <string.h>

int pq[100];
int size = 0;

void insert(int x)
{
    pq[size++] = x;
}

int findMinIndex()
{
    if(size == 0)
        return -1;

    int min = 0;

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[min])
            min = i;
    }

    return min;
}

void deletePQ()
{
    int index = findMinIndex();

    if(index == -1)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[index]);

    for(int i = index; i < size - 1; i++)
        pq[i] = pq[i + 1];

    size--;
}

void peek()
{
    int index = findMinIndex();

    if(index == -1)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[index]);
}

int main()
{
    int N;
    char op[10];
    int x;

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "delete") == 0)
        {
            deletePQ();
        }
        else if(strcmp(op, "peek") == 0)
        {
            peek();
        }
    }

    return 0;
}