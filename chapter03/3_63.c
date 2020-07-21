long switch_prob(long x, long n)
{
    long result = x;
    switch (n)
    {
    case 60:
    case 62:
        result *= 8;
        break;
    case 63:
        result >>= 3;
        break;
    case 64:
        result <<= 4;
        result -= x;
        x = result;
        x *= x;
        result = x + 0x4B;
        break;
    case 65:
        x *= x;
        result = x + 0x4B;
        break;
    default:
        result += 0x4B;
    }
    return result;
}