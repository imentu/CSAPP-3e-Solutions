#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int data_t;

typedef struct
{
    long len;
    data_t *data;
} vec_rec, *vec_ptr;

vec_ptr new_vec(long len)
{
    vec_ptr result = (vec_ptr)malloc(sizeof(vec_rec));
    if (!result)
        return result;

    result->len = len;
    data_t *data = NULL;
    if (len > 0)
    {
        data = (data_t *)calloc(len, sizeof(data_t));
        if (!data)
        {
            free((void *)result);
            return NULL;
        }
    }
    result->data = data;
    return result;
}

int get_vec_element(vec_ptr v, long index, data_t *dest)
{
    if (index < 0 || index >= v->len)
    {
        return 0;
    }
    *dest = v->data[index];
    return 1;
}

long vec_length(vec_ptr v)
{
    return v->len;
}

data_t *get_vec_start(vec_ptr v)
{
    return v->data;
}

void set_vec_start(vec_ptr v, data_t *data)
{
    v->data = data;
}

#define LEN 24

void inner4(vec_ptr u, vec_ptr v, data_t *dest)
{
    long i;
    long length = vec_length(u);
    data_t *udata = get_vec_start(u);
    data_t *vdata = get_vec_start(v);
    data_t sum = (data_t)0;
    for (i = 0; i < length - 6; i += 6)
    {
        sum = sum + udata[i] * vdata[i] + udata[i + 1] * vdata[i + 1] + udata[i + 2] * vdata[i + 2] + udata[i + 3] * vdata[i + 3] + udata[i + 4] * vdata[i + 4] + udata[i + 5] * vdata[i + 5];
    }
    for (; i < length; i++)
    {
        sum = sum + udata[i] * vdata[i];
    }
    *dest = sum;
}

int main(int argc, char *argv[])
{
    vec_ptr u = new_vec(LEN);
    vec_ptr v = new_vec(LEN);

    data_t *arr = (data_t *)malloc(sizeof(data_t) * LEN);
    memset(arr, 0, sizeof(data_t) * LEN);
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;

    set_vec_start(u, arr);
    set_vec_start(v, arr);

    data_t res;
    inner4(u, v, &res);

    assert(res == 1 + 4 + 9);
    return 0;
}