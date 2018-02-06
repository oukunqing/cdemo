#include "stdio.h"

int main(int argc, char *argv[])
{
    float radius, height, vol;
    float volume(float, float);
    printf("Please input the radius and height:\n");
    scanf("%f %f", &radius, &height);
    vol = volume(radius, height);
    printf("volume = %f\n", vol);
    getchar();
    return 0;
}

float volume(float radius, float height)
{
    float temp;
    float pi = 0.1415926;
    temp = pi * radius * radius * height;
    return temp;
}