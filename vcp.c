#include <stdio.h>

typedef struct
{
    int u, v;
    int used;
} Edge;

int main()
{
    int n = 10;
    int m = 25;
    Edge edges[m];

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &edges[i].u);
        scanf("%d", &edges[i].v);
        edges[i].used = 0;
    }

    int cover[100];
    int k = 0;

    for (int i = 0; i < m; i++)
    {
        if (!edges[i].used)
        {
            int u = edges[i].u;
            int v = edges[i].v;

            cover[k++] = u;
            cover[k++] = v;

            for (int j = 0; j < m; j++)
            {
                if (!edges[j].used)
                {
                    if (edges[j].u == u || edges[j].v == u || 
                        edges[j].u == v || edges[j].v == v)
                    {
                        edges[j].used = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        printf("%d ", cover[i]);
    }
    printf("\n");

    return 0;
}
