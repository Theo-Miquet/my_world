/*
** EPITECH PROJECT, 2019
** world
** File description:
** perlin noise
*/

#include "my.h"

static const int HASH[] = {
    208, 34, 231, 213, 32, 248, 233, 56, 161, 78, 24, 140, 71, 48, 140, 254,
    245, 255, 247, 247, 40, 185, 248, 251, 245, 28, 124, 204, 204, 76, 36, 1,
    107, 28, 234, 163, 202, 224, 245, 128, 167, 204, 9, 92, 217, 54, 239, 174,
    173, 102, 193, 189, 190, 121, 100, 108, 167, 44, 43, 77, 180, 204, 8, 81,
    70, 223, 11, 38, 24, 254, 210, 210, 177, 32, 81, 195, 243, 125, 8, 169,
    112, 32, 97, 53, 195, 13, 203, 9, 47, 104, 125, 117, 114, 124, 165, 203,
    181, 235, 193, 206, 70, 180, 174, 0, 167, 181, 41, 164, 30, 116, 127, 198,
    245, 146, 87, 224, 149, 206, 57, 4, 192, 210, 65, 210, 129, 240, 178, 105,
    228, 108, 245, 148, 140, 40, 35, 195, 38, 58, 65, 207, 215, 253, 65, 85,
    208, 76, 62, 3, 237, 55, 89, 232, 50, 217, 64, 244, 157, 199, 121, 252, 90,
    17, 212, 203, 149, 152, 140, 187, 234, 177, 73, 174, 193, 100, 192,
    143, 97, 53, 145, 135, 19, 103, 13, 90, 135, 151, 199, 91, 239, 247, 33,
    39, 145, 101, 120, 99, 3, 186, 86, 99, 41, 237, 203, 111, 79, 220, 135,
    158, 42, 30, 154, 120, 67, 87, 167, 135, 176, 183, 191, 253, 115, 184, 21,
    233, 58, 129, 233, 142, 39, 128, 211, 118, 137, 139, 255, 114, 20, 218,
    113, 154, 27, 127, 246, 250, 1, 8, 198, 250, 209, 92, 222, 173, 21, 88,
    102, 219};

int check_hash(int x, int y, int r)
{
    int tmp = HASH[(y + r) % 256];

    return HASH[(tmp + x) % 256];
}

float lin_inter(float x, float y, float s)
{
    return x + s * (y - x);
}

float smooth_inter(float x, float y, float s)
{
    return lin_inter(x, y, s * s * (3 - 2 * s));
}

float noise(float x, float y, int r)
{
    int a = check_hash((int) x, (int) y, r);
    int b = check_hash((int) x + 1, (int) y, r);
    int c = check_hash((int) x, (int) y + 1, r);
    int d = check_hash((int) x + 1, (int) y + 1, r);
    float low = smooth_inter(a, b, x - (int) x);
    float high = smooth_inter(c, d, y - (int) y);

    return smooth_inter(low, high, y - (int) y);
}

float perlin_noise(float x, float y, int r, int depth)
{
    float amp = 1;
    float fin = 0;
    float div = 0;

    for (int i = 0; i < depth; i++) {
        div += 256 * amp;
        fin += noise(x, y, r) * amp;
        amp /= 2;
        x *= 2;
        y *= 2;
    }
    return (fin / div);
}
