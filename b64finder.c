#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

inline static bool isbase64(const unsigned char c) {
    if(c <= 'Z') {
        if(c <= '9') {
            if(c >= '/') return true;
            if(c == '+') return true;
            return false;
        } else if(c >= 'A') {
            return true;
        }
        return false;
    } else if(c >= 'a' && c <= 'z') {
        return true;
    }
    return false;
}

#define BUFSIZE 4*1024
#define TRIGGER 50
int main() {
    int consec = 0;
    unsigned char buf[BUFSIZE];
    ssize_t left = 0;

    while(true) {
        for(int i = 0; i < left; i++) {
            if(isbase64(buf[i]))
                consec++;
            else
                consec = 0;

            if(consec == TRIGGER)
                return 0;
        }
        left = read(0, buf, BUFSIZE);
        if(left == -1) {
            fprintf(stderr, "error reading data");
            return 1;
        }
        if(left == 0) {
            return 1;
        }
    }
}
