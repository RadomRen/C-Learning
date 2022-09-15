#define _CRT_SECURE_NO_WARNINGS
struct A
{
    int _a : 2;
    int _b : 5;
    int _c : 10;
    int _d : 30;
};
int main()
{
    printf("%d\n", sizeof(struct A));//8
    return 0;
}