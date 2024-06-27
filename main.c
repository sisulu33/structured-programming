//
//  main.c
//  meats.c
//
//  Created by User One on 27/06/2024.
//

#include <stdio.h>

int main(void) {
    
    char *meats[5] = {"beef", "mutton", "pork", "chicken", "fish"};
    for (int i = 0; i < 5; i++){
        if (meats[i] == "mutton"){
            printf("i hate mutton\n");
            break;
        }else{
            printf("i eat %s\n", meats[i]);
        }
    }
    for(int i = 0; i < 5; i++){
        if(meats[i] == "pork"){
            printf("i love pork\n");
            continue;
        }else{
            printf("i eat %s\n", meats[i]);
        }
    }
    return 0;
}
