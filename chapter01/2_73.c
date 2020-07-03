#include <stdio.h>
#include <assert.h>
#include <limits.h>

/*
    x > 0, y > 0, sum <= 0; 正溢出
    x < 0, y < 0, sum >= 0; 负溢出
*/
int saturating_add(int x, int y)
{
    int sum = x + y;
    int x_sign = !(x & INT_MIN);
    int y_sign = !(y & INT_MIN);
    int sum_sign = !(sum & INT_MIN);

    int over_flow = (x_sign == y_sign) && (sum_sign != x_sign || sum == 0); // x,y 符号相等且 sum 符号与 x 符号不相等或 sum == 0 时，加法溢出。

    over_flow && (x_sign && (sum = INT_MAX)); // 利用逻辑运算短路计算的特性，若正溢出 sum = INT_MAX。
    over_flow && (!x_sign && (sum = INT_MIN)); // 利用逻辑运算短路计算的特性，若负溢出 sum = INT_MIN。

    return sum;
}

int main(int argc, char *argv[])
{
    assert(INT_MAX == saturating_add(INT_MAX, 0x1234));
    assert(INT_MIN == saturating_add(INT_MIN, -0x1234));
    assert(0x11 + 0x22 == saturating_add(0x11, 0x22));
    return 0;
}