#include "cachelab.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <getopt.h>

typedef struct Node
{
    unsigned val;
    struct Node *previous;
    struct Node *next;
} Node;

typedef struct LRU
{
    Node *first;
    Node *last;
} LRU;

LRU *creatLRU()
{
    LRU *l = malloc(sizeof(LRU));
    if (l == NULL)
    {
        puts("create LRU failed.");
        exit(0);
    }
    else
    {
        l->first = NULL;
        l->last = NULL;
        return l;
    }
}

void display(LRU *l)
{
    Node *n = l->first;
    printf("lru: first:%p, last:%p\n", l->first, l->last);
    while (n)
    {
        printf("-> Node:%p val:%d, previous:%p, next:%p\n", n, n->val, n->previous, n->next);
        if (n->previous == n->next && n->next != NULL)
        {
            exit(0);
        }
        n = n->next;
    }
}

unsigned getLruNode(LRU *l)
{
    if (l->last == NULL)
    {
        return -1;
    }
    else
    {
        // printf("before get:");
        // display(l);
        Node *last = l->last;
        Node *first = l->first;
        if (first != last)
        {
            first->previous = last;

            last->previous->next = NULL;
            l->last = last->previous;

            last->previous = NULL;

            last->next = first;

            l->first = last;
        }
        // printf("after get:");
        // display(l);
        return last->val;
    }
}

/*
    add 时要放最后？
*/
void addLruNode(LRU *l, unsigned val)
{
    Node *n = malloc(sizeof(Node));
    if (n == NULL)
    {
        puts("create LRU Node failed.");
        exit(0);
    }
    else
    {
        // printf("before add:");
        // display(l);
        n->val = val;
        n->previous = NULL;
        n->next = l->first;
        if (l->first != NULL)
        {
            l->first->previous = n;
        }
        else
        {
            l->last = n;
        }
        l->first = n;
        // printf("after add:");
        // display(l);
    }
}

void setLruNode(LRU *l, unsigned val)
{
    Node *n = l->first;
    while (n != NULL)
    {
        if (n->val == val)
        {
            break;
        }
        else
        {
            n = n->next;
        }
    }
    if (n == NULL)
    {
        addLruNode(l, val);
    }
    else
    {
        if (n == l->first)
        {
            return;
        }
        // printf("get node:%p\n", n);
        // printf("before set:");
        // display(l);
        Node *previous = n->previous;
        Node *next = n->next;
        n->previous = NULL;
        n->next = l->first;
        if (previous != NULL)
        {
            previous->next = next;
        }
        l->first->previous = n;
        l->first = n;
        if (l->last == n)
        {
            l->last = previous;
        }
        // printf("after set:");
        // display(l);
    }
}

typedef enum
{
    HIT = 1,
    MISS,
    EVICTION
} STATES;

typedef struct
{
    unsigned s;
    unsigned t;
} CL;

int s = -1, S = -1, E = -1, b = -1, B = -1, v = 0;
FILE *fp = NULL;
char *filePath = NULL;

LRU **CL_LRU;
CL **CACHE;
unsigned bm, sm, tm;

int hits = 0, misses = 0, eviction = 0;

void vPrint(STATES states)
{
    if (v)
    {
        switch (states)
        {
        case HIT:
            printf("hit ");
            break;
        case MISS:
            printf("miss ");
            break;
        case EVICTION:
            printf("eviction ");
            break;
        }
    }
}

void init(int argc, char **argv)
{
    int opt = 0;
    while ((opt = getopt(argc, argv, "vs:E:b:t:")) != -1)
    {
        switch (opt)
        {
        case 'v':
            v = 1;
            break;
        case 's':
            s = atoi(optarg);
            S = pow(2, s);
            break;
        case 'E':
            E = atoi(optarg);
            break;
        case 'b':
            b = atoi(optarg);
            B = pow(2, b);
            break;
        case 't':
            filePath = optarg;
            fp = fopen(filePath, "r");
            break;
        }
    }

    if (S == -1 || E == -1 || B == -1 || filePath == NULL)
    {
        puts("Missing required command line argument");
    }

    bm = ~(-1 << b);
    sm = ~(-1 << (s + b)) ^ bm;
    tm = ~(0 | bm | sm);

    CL_LRU = malloc(sizeof(LRU *) * S);
    if (CL_LRU == NULL)
    {
        puts("create CL_LRU failed");
        exit(0);
    }

    CACHE = malloc(sizeof(CL *) * S);
    if (CL_LRU == NULL)
    {
        puts("create CACHE failed");
        exit(0);
    }

    for (int i = 0; i < S; i++)
    {
        CACHE[i] = malloc(sizeof(CL) * E);
        if (CL_LRU == NULL)
        {
            printf("create CHCHE[%d] failed", i);
            exit(0);
        }

        CL_LRU[i] = creatLRU();
        for (int j = 0; j < E; j++)
        {
            CACHE[i][j].s = 0;
            CACHE[i][j].t = 0;
        }
    }
}

void _L(unsigned address, unsigned size)
{
    int ss = (address & sm) >> b;
    // int bs = address & bm;
    int ts = (address & tm) >> (s + b);
    int es = -1, fr = -1;
    // printf("\n->ss:%d ts:%d\n", ss, ts);
    for (int i = 0; i < E; i++)
    {
        if (CACHE[ss][i].s != 0)
        {
            if (CACHE[ss][i].t == ts)
            {
                es = i;
                break;
            }
        }
        else
        {
            fr = fr == -1 ? i : fr;
        }
    }
    // printf("->es:%d fr:%d\n", es, fr);
    if (es == -1)
    {
        misses += 1;
        vPrint(MISS);
        if (fr != -1)
        {
            // if (ss == 0)
            // {
            //     display(CL_LRU[ss]);
            // }
            setLruNode(CL_LRU[ss], fr);
            // if (ss == 0)
            // {
            //     display(CL_LRU[ss]);
            // }
            CACHE[ss][fr].s = 1;
            CACHE[ss][fr].t = ts;
            // printf("%8x empty -> ss:%d, es:%d\n", address, ss, fr);
        }
        else
        {
            eviction += 1;
            vPrint(EVICTION);
            // if (ss == 0)
            // {
            //     display(CL_LRU[ss]);
            // }
            unsigned ae = getLruNode(CL_LRU[ss]);
            // if (ss == 0)
            // {
            //     display(CL_LRU[ss]);
            // }
            // printf("->ae:%d\n", ae);
            CACHE[ss][ae].s = 1;
            CACHE[ss][ae].t = ts;
            // printf("%8x eviction -> ss:%d, es:%d\n", address, ss, ae);
        }
    }
    else
    {
        hits += 1;
        // if (ss == 0)
        // {
        //     display(CL_LRU[ss]);
        // }
        setLruNode(CL_LRU[ss], es);
        // if (ss == 0)
        // {
        //     display(CL_LRU[ss]);
        // }
        vPrint(HIT);

        // printf("%8x hit -> ss:%d, es:%d\n", address, ss, es);
    }
}

void run()
{
    char buffer[50];
    while (fgets(buffer, 50, fp) != NULL)
    {
        if (buffer[0] == ' ')
        {
            unsigned address, size;
            sscanf(buffer + 2, " %x, %d", &address, &size);
            printf("%c %x,%d ", buffer[1], address, size);
            switch (buffer[1])
            {
            case 'L':
                _L(address, size);
                break;
            case 'M':
                _L(address, size);
                _L(address, size);
                break;
            case 'S':
                _L(address, size);
                break;
            }
            if (v)
            {
                puts("");
            }
        }
    }
}

int main(int argc, char **argv)
{
    init(argc, argv);
    run();
    printSummary(hits, misses, eviction);
    return 0;
}
