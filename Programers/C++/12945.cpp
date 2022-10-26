int solution(int n)
{
    int ret = 0;
    int num1 = 1;
    int num2 = 1;

    // case 0, 1, 2 리턴
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;

    // 피보나치 수열은 47번째부터 int 범위를 벗어남
    // 두 수 x, y의 합을 z로 나눈 나머지는
    // x, y 각각을 z로 나눈 나머지의 합을 z로 나눈 나머지와 같음
    // (x + y) % z == ((x % z) + (y % z)) % z
    // (4 + 11) % 3 == 0
    // (1 + 2) % 3 == 0
    for (int i = 3; i <= n; i++)
    {
        ret = (num1 + num2) % 1234567;
        num1 = num2;
        num2 = ret;
    }
    return ret;
}
