
void fun()
{
    /*
        生成如下形式汇编指令，然后计算便宜替换到hex中即可。
    */
    __asm__(
        "mov $0x59b997fa, %rdi\n\t"
        "callq 0x004017ec\n\t");
}

int main(){
    return 0;
}