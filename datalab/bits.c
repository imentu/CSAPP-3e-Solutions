/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
  /*
    a ^ b = (a & ~b) | (~a & b);
    a | b = ~a & ~b;
  */
  return ~(~(x & ~y) & ~(~x & y));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
  /*
    仅符号位为 1 的二进制表示 tmin。
  */
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
  /*
    ~tmax = tmin;
    tmin - 1 = tmax;
    用 x == (~x - 1) 来确定是否是 tmax，-1 会有同样的结果，使用 -1 + 1 = 0 来排除 x = -1。
    因不允许使用 - ， 使用 -x = ~x + 1 代替减法运算。
  */
  return !(x ^ (~x + (~1 + 1))) & !!(x + 1);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
  /*
    生成奇数位全为 1 的掩码 mask，再测试 mask 与 x 后再比较是否等于 mask。
  */
  int m1 = 0XAA;
  int m2 = (m1 << 8) | m1;
  int m3 = (m2 << 8) | m1;
  int m4 = (m3 << 8) | m1;
  return !((x & m4) ^ m4);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
  /*
    -x = ~x + 1;
  */
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
  /*
    先测试是否是 0x30 - 0x3F 之间的数，再通过 9 加任何大于 6 的数会进位测试 x 是否是 0x30 - 0x39 之间的数字。
  */
  return !((x & ~0xF) ^ 0x30) & !(((x + 6) & ~0xF) ^ 0x30);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
  /*
    只能使用位运算，就要要构造一个表达式产生 y | 0 或 0 | z 作为返回值。
    利用 ! 运算符结果只有 1 和 0，以及 0 - 1 = -1， 1 - 1 = 0 的性质，可构造出如下表达式。
    题目中禁止使用 -，所以利用 -x = ~x + 1 构造减法。
  */
  return ((!!x + (~1 + 1)) & z) | ((!x + (~1 + 1)) & y);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
  int sign = 1 << 31;                       // 用作测试符号位
  int x_sign = !(x & sign);                 // 获取 x 的符号位，x 为正数时为 1，x 为负数时为 0
  int y_sign = !(y & sign);                 // 获取 y 的符号位，y 为正数时为 1，y 为负数时为 0
  int se = x_sign ^ y_sign;                 // x,y 的符号相等时为 0，符号不相等时为 1
  int y_minus_x = y + (~x + 1);             // y - x
  int y_minus_x_sign = !(y_minus_x & sign); // 获取 y - x 的符号位，y - x 为正数时为 1，y - x 为负数时为 0
  int y_is_zero = !y_minus_x;               // y - x == 0 时为 1，y - x != 0 时为 0
  /*
    使用类似 conditional 的方式返回计算结果
    x_sign == y_sign ? ((y - x > 0) || (y - x == 0)) : y > 0;
    符号相同时 y - x 大于 0，或 y - x == 0。
    符号不同时 y >= 0。
  */
  return ((se + (~1 + 1)) & (y_minus_x_sign | y_is_zero)) | ((!se + (~1 + 1)) & y_sign);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x)
{
  /*
    利用二分法(参照 ../chapter01/2_65.c)将各个位与 B0 进行或运算，只要二进制表示中有 1 个 1，B0 就等于 1。取反后再 & 1 即可实现逻辑非。
  */
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  return ~x & 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
  /*
    x 为正数时，只需找到最高位的 1 的位置，再加 1 位符号位即可。
    x 为负数时，只需找到最高位的 0 的位置，再加 1 位符号位即可。
  */
  int sign = x >> 31;
  int b_16, b_8, b_4, b_2, b_1, b_0;
  x = (!sign + (~1 + 1)) ^ x; // x 为正数时不变，为负数时取反(方便找最高位 0)。

  // 二分找 1
  b_16 = !!(x >> 16) << 4;
  x >>= b_16;
  b_8 = !!(x >> 8) << 3;
  x >>= b_8;
  b_4 = !!(x >> 4) << 2;
  x >>= b_4;
  b_2 = !!(x >> 2) << 1;
  x >>= b_2;
  b_1 = !!(x >> 1) << 0;
  x >>= b_1;
  b_0 = x & 1;

  return b_16 + b_8 + b_4 + b_2 + b_1 + b_0 + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf)
{
  /*
    float V = (-1)^s * M * 2^E
    对于规格化值，仅需将 exp + 1 即可实现乘二（注意处理溢出）。
    对于非规格化值，将小数部分左移一位即可实现乘二。
  */
  int sign = uf >> 31;
  int exp = uf >> 23 & 0xFF;
  int frac = uf & 0x7FFFFF;
  if (exp == 0xFF) // uf == ±∞ || uf == NaN => return uf;
  {
    return uf;
  }
  if (exp == 0)
  {
    frac <<= 1;
  }
  else if (exp == 254)
  {
    exp = 0xFF;
    frac = 0;
  }
  else
  {
    exp += 1;
  }
  return sign << 31 | exp << 23 | frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf)
{
  int sign = uf >> 31;
  int exp = uf >> 23 & 0xFF;
  int frac = uf & 0x7FFFFF;
  int num = 0;
  int pow, has_half, has_other, round;
  if (exp < 127) // 小于 0 的数。
  {
  }
  else if (exp > 158) // 绝对值超出 2^31 的数。
  {
    num = 1 << 31;
  }
  else
  {
    /*
      只剩处理规格化的值。
      取得 exp 后对 num 移位即可，因 2^0 = 1，所以 num 可以直接取 1。
    */
    pow = exp - 127;
    num = 1;
    if (pow > 0)
    {
      num <<= pow;
    }
    /*
      处理舍入，若小数部分大于 0.5， round = 1。

      不对呀，这就过了？  
      凭啥？
    */
    has_half = !!(frac & 0x400000);
    has_other = !!(frac & ~0x400000);
    round = has_half && has_other;
    num += round;
    if (sign)
    {
      num = ~num + 1;
    }
  }
  return num;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x)
{
  /*
    float 可以很容易的表示 [2^-149,2^127] 之间的整数。
    当 x < 2^-149 时，返回 0。
    当 2^-149 <= x < 2^-126 时，使用非规格化表示。
    当 2^-126 <= x < 2^-128 时，使用规格化表示。
    当 x >= 2^-128 时，返回 +∞。
  */
  unsigned sign = 0, exp = 0, frac = 0;
  if (x < -149)
  {
  }
  else if (x < -126)
  {
    frac >>= (-126 - x);
  }
  else if (x <= 127)
  {
    exp = x + 127;
  }
  else
  {
    exp = 0xFF;
  }
  return sign << 31 | exp << 23 | frac;
}
