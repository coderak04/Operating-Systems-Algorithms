#include<stdio.h>

int main() 
{
    int fr[20], p[50], c = 0, c1, d, f, i, j, k = 0, n, r, t, b[20], c2[20];
    printf("Enter no of pages:");
    scanf("%d", & n);
    printf("Enter the reference string:");
    for (i = 0; i < n; i++)
        scanf("%d", & p[i]);
    printf("Enter no of frames:");
    scanf("%d", & f);
    fr[k] = p[k];
    printf("\tpage frames");
    printf("\n\t%d\n", fr[k]);
    c++;
    k++;
    for (i = 1; i < n; i++) 
    {
        c1 = 0;
        for (j = 0; j < f; j++) 
        {
            if (p[i] != fr[j])
                c1++;
        }
        if (c1 == f) 
        {
            c++;
            if (k < f) 
            {
                fr[k] = p[i];
                k++;
                for (j = 0; j < k; j++)
                    printf("\t%d", fr[j]);
                printf("\n");
            } 
            else 
            {
                for (r = 0; r < f; r++) 
                {
                    c2[r] = 0;
                    for (j = i - 1; j < n; j--) 
                    {
                        if (fr[r] != p[j])
                            c2[r]++;
                        else
                            break;
                    }
                }
                for (r = 0; r < f; r++)
                    b[r] = c2[r];
                for (r = 0; r < f; r++) {
                    for (j = r; j < f; j++) 
                    {
                        if (b[r] < b[j]) 
                        {
                            t = b[r];
                            b[r] = b[j];
                            b[j] = t;
                        }
                    }
                }
                for (r = 0; r < f; r++) 
                {
                    if (c2[r] == b[0])
                        fr[r] = p[i];
                    printf("\t%d", fr[r]);
                }
                printf("\n");
            }
        }
    }
    printf("\nThe no of page faults is %d", c);
    printf("\nThe no of page hits is %d", n - c);
}