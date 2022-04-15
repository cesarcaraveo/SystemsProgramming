//
//  main.cpp
//  Class7
//
//  Created by Cesar Caraveo on 1/24/18.
//  Copyright © 2018 Cesar Caraveo. All rights reserved.
//

#include <iostream>
#include <cstring>

void replace(char keyword[], char pre, char post) {
    for (int i = 0; i < strlen(keyword); i++) { // i < str[i] != '\0'; or int i = 0, e = strlen(str) i != e
        if (keyword[i] == pre) {
            keyword[i] = post;
        }
    }
}

void del(char keyword[], char remove) {
    for (int i = 0; i < strlen(keyword); i++) {
        if (keyword[i] == remove) {
            keyword[i] = ' ';
        }
    }
}

char * char_kill(char *str, char kill) {
    char *ret = new char [strlen(str) + 1]; // +1 for \0
    int len = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != kill) {
            ret[len] = str[i];
            len++;
        }
    }
    
    ret[len] = '\0'; // null terminator
    
    return ret;
}

int main(int argc, const char * argv[]) {
    char *str = new char[10];
    char src[10] = {'h', 'e', 'l', 'l', 'o', ' ', 'b', 'a', 'l', 'l'};
    char *src_p = src;
    
//    std::cout << strlen(str) << "\n";
//    strcpy(str, src_p);
//    std::cout << strlen(str) << "\n";
//    std::cout << str << "\n";
//
    std::cout << strlen(str) << "\n";
    strncpy(str, src_p, 10);
    std::cout << strlen(str) << "\n";
    std::cout << str << "\n";
    
    replace(src, 'l', 'b');
    std::cout << src << "\n";
    
    del(src, 'b');
    std::cout << src << "\n";
    return 0;
}
