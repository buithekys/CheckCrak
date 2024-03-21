#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int maxCount = 0, maxLength = 0, resPos = -1;
    for (int i = 0; i < num_pwds; ++i)
    {
        int count = 0;
        for (int j = 0; j < num_pwds; ++j)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                count++;
            }
        }
        int len = strlen(arr_pwds[i]);
        if (count > maxCount || (count == maxCount && len > maxLength))
        {
            maxCount = count;
            maxLength = len;
            resPos = i;
        }
    }
    return resPos;
}

int main()
{
    const char *arr_pwds[] = {"pink123", "xxxx@xxxx", "123xyz", "pink#pink", "pink#pink",
                              "pink123"};

    cout << findCorrectPassword(arr_pwds, 6);
    return 0;
}