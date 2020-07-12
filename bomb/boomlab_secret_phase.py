class T:
    def __init__(self, l, r, v):
        self.v = v
        self.l = l
        self.r = r


def fun(t, v):
    if t == None:
        return -1
    elif v < t.v:
        return 2 * fun(t.l, v)
    elif v == t.v:
        return 0
    else:
        return 2 * fun(t.r, v) + 1


if __name__ == "__main__":
    n1 = T(None, None, 1)
    n7 = T(None, None, 7)
    n20 = T(None, None, 20)
    n35 = T(None, None, 35)
    n40 = T(None, None, 40)
    n47 = T(None, None, 47)
    n99 = T(None, None, 99)
    n1001 = T(None, None, 1001)

    n6 = T(n1, n7, 6)
    n22 = T(n20, n35, 22)
    n45 = T(n40, n47, 45)
    n107 = T(n99, n1001, 107)

    n8 = T(n6, n22, 8)
    n50 = T(n45, n107, 50)

    n36 = T(n8, n50, 36)

    for i in range(0, 0x3e9):
        if fun(n36, i) == 2:
            print(i, fun(n36, i))
