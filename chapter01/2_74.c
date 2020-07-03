#include <stdio.h>
#include <assert.h>
#include <limits.h>

/*
    正数减正数无溢出。
    正数减负数:a - (-b) = a + b 存在正溢出。
    负数减负数:(TMIN - TMIN) = 0。
    负数减正数:-a - b = -a + (-b) 存在负溢出。
*/
int tsub_ok(int x, int y)
{
    int res = x - y;
    int x_sign = !(x & INT_MIN);
    int y_sign = !(y & INT_MIN);
    int res_sign = !(res & INT_MIN);
    // x,y 符号不同且 res 符号与 y 相同时减法溢出。
    // x == TMIN，结果为 0 时减法溢出(补码加法运算中 TMIN 的逆元是 TMIN)。
    int over_flow = ((x_sign != y_sign) && (res_sign == y_sign)) || (x == INT_MIN && res == 0); 
    
    return !over_flow;
}

int main(int argc, char *argv[])
{
    assert(!tsub_ok(0x00, INT_MIN));
    assert(tsub_ok(0x00, 0x00));
    return 0;
}