#include <iostream>
#include <vector>
float y_kannsuu(float x);
std::vector<float> x;
void daisuuhou();

int main()
{
    for (float i = 0; i < 3; i++)
    {
        x.push_back(y_kannsuu(i));
        //printf("%lf\n", x[i]);
    }
    daisuuhou();
    return 0;
}

float y_kannsuu(float x)
{
    return x * x * x * x - 2 * x * x * x + x * x - 3 * x + 1;
}

void daisuuhou()
{
    float num = 0;
    num = 1 / 2 * (x.back() + x[0]);
    for (int i = 1; i < x.size() - 1; i++)
    {
        num += x[i];
    }
    printf("%lf", num);
}