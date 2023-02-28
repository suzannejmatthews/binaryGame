#include "level_9.h"
#include "level_admin.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void level9(char * user_string){
    struct averageCadet {
        int freetime;
        int hours_drill_week;
        int tours_left;
        char name[64];
        char bio[64];
    };
    struct averageCadet chad;
    chad.freetime = 0;
    chad.hours_drill_week = 20;
    chad.tours_left = 100;
    strcpy(chad.name, "Chad");
    strcpy(chad.name, "Chad has no free time because of the firstie");
    int result = compare_strings(user_string, chad.name);
    if (result != 0)
        you_lose(9);
    else 
        pass_level();
    return;

  }
