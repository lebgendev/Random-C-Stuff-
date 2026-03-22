#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

int main(){
    time_t rawTime = 0;
    struct tm *pTime = NULL;
    bool isRun = true;
    while (isRun){
        time(&rawTime);
        pTime = localtime(&rawTime);
        printf("\r%d:%d:%d", pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
        Sleep(1000);
    }
    






    return 0;
}