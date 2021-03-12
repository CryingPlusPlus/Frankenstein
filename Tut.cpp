#include <iostream>

int main()
{
    float* bigArr1 = new float[16384];
    float* bigArr2 = new float[16384];
    float* bigArr3 = new float[16384];

    for( int i = 0; i < 16384; ++i )
    {
        bigArr1[i] = 20;
        bigArr2[i] = 50;
        bigArr3[i] = 0;
    }

    for( int i = 0; i < 16384; ++i )
        bigArr3[i] = bigArr2[i] + bigArr1[i];


    delete[] bigArr1;
    delete[] bigArr2;
    delete[] bigArr3;

    return 0;
}
