#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct struct_type
{
    int deg;
    int k;
}struct_type;
void read_matr(int* pa[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &pa[i][j]);
}

void print_matr(int* pa[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", pa[i][j]);
        printf("\n");
    }
}

int search(int d, struct_type* mas, int n)
{
    int i = 0;
    while (i < n && mas[i].deg != d)
        i++;

    if (i == n)
        i = EOF;
    return i;
}
struct_type* create_struct(int* pa[], int i, int n, int* l)
{
    struct_type* mas = (struct_type*)calloc(n, sizeof(struct_type));
    int m = 0;
    for (int j = 0; j < n; j++)
    {
        int s = search(pa[i][j], mas, m);
        if (s == EOF)
        {
            mas[m].k = 1;
            mas[m].deg = pa[i][j];
            m++;
        }
        else
            mas[s].k++;
    }
    *l = m;
    mas = (struct_type*)realloc(mas, (*l) * sizeof(struct_type));
    return mas;
}
int search_el(int d, int* b, int n)
{
    int i = 0;

    while (i < n && b[i] != d)
        i++;

    if (i == n)
        i = EOF;
    return i;
}
void write_el(struct_type* ptr, int l)
{
    int i;
    for (i = 0; i < l; i++)
    {
        if (ptr[i].k == 1)
            printf("%d ", ptr[i].deg);
    }
}
void print_mass(int* a, size_t m)
{
    int i;
    for (i = 0; i < m; i++)
    {
        printf("%d ", a[i]);
    }
}


int main()
{
    int n;
    int l;
    int k = 0;
    struct_type* ptr;
    setlocale(LC_ALL, "RUS");
    printf("введите размер матрицы, ");
    printf("Привет");
    scanf("%d", &n);
    int** a = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++)
        a[i] = (int*)calloc(n, sizeof(int));
    printf("Введите элементы матрицы А размера %d x %d\n", n, n);
    read_matr(a, n);
    printf("Исходная матрица:\n");
    print_matr(a, n);
    printf("Результат программы:\n");
    for (int i = 0; i < n; i++)
    {
        ptr = create_struct(a, i, n, &l);
        printf("Элементы различающиеся один раз %d строке:", i);
        write_el(ptr, l);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
}
