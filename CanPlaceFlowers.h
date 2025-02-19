#include <stdbool.h>
//*___* __* _____*
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0) {
            if (i==0 && flowerbedSize == 1
                || i==0 && flowerbedSize>1 && flowerbed[i+1] == 0
                || i== flowerbedSize -1 && i != 0 && flowerbed[i - 1] == 0
                || i != flowerbedSize - 1 && i != 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0
                )
            {
                n--;
                flowerbed[i] = 1;
            }
        }
    }

    if (n <= 0) return true;
    else return false;
}
