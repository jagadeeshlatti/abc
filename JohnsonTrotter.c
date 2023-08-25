#include <stdio.h>
#include <stdbool.h>

bool LR = true;
bool RL = false;

int search(int a[], int n, int mobile)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mobile)
        {
            return i + 1;
        }
    }
}

int getMobile(int a[], bool dir[], int n)
{
    int i;
    int prev = 0, mobile = 0;

    for (i = 0; i < n; i++)
    {
        if (dir[a[i] - 1] == RL && i != 0)
        {
            if (a[i] > a[i - 1] && a[i] > prev)
            {
                mobile = a[i];
                prev = mobile;
            }
        }

        if (dir[a[i] - 1] == LR && i != n - 1)
        {
            if (a[i] > a[i + 1] && a[i] > prev)
            {
                mobile = a[i];
                prev = mobile;
            }
        }
    }

    if (mobile == 0 && prev == 0)
        return 0;
    else
        return mobile;
}

int Perm(int a[], bool dir[], int n)
{
    int temp;
    int mobile = getMobile(a, dir, n);
    int pos = search(a, n, mobile);

    if (dir[a[pos - 1] - 1] == RL)
    {
        temp = a[pos - 1];
        a[pos - 1] = a[pos - 2];
        a[pos - 2] = temp;
    }
    else if (dir[a[pos - 1] - 1] == LR)
    {
        temp = a[pos];
        a[pos] = a[pos - 1];
        a[pos - 1] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] > mobile)
        {
            if (dir[a[i] - 1] == LR)
                dir[a[i] - 1] = RL;
            else if (dir[a[i] - 1] == RL)
                dir[a[i] - 1] = LR;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    printf(" ");
}

int fact(int n)
{
    int fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

void perms(int n)
{
    int a[n];
    bool dir[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        printf("%d", a[i]);
    }
    printf(" ");

    for (int i = 0; i < n; i++)
        dir[i] = RL;

    for (int i = 1; i < fact(n); i++)
        Perm(a, dir, n);
}

int main(void)
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    perms(n);
}