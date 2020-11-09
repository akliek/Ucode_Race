#include <stdio.h>
#include <unistd.h>
void mx_printchar(char c);

static void top(int n) {
    int length = 2 * n;
    int height = n / 2;
    int str = length;
    for(int y = 1; y <= height; y++) {
        for(int x = 1; x <= length; x++) {
            if(y <= height && x == n - y + 1)
                mx_printchar('/');
            else if((y <= height && x == n + y - 1) || (y <= height && x == n + 2 * y - 1))
              mx_printchar('\\');
            else if(y <= n / 2 && x > n + y * 2 - 1)
                length = n / 2 + y;
            else
                mx_printchar(' ');
        }
        length = str;
        mx_printchar('\n');
    }
}
static void bottom(int n) {
    int length = 2 * n;
    int height = n / 2;
    for(int y = 1; y <= height; y++) {
        for(int x = 1; x <= length; x++){
                if(x > 1 && x <= length - 2 && y == height)
                    mx_printchar('_');
                else if(x == length && y >= 1 && y <= height)
                    mx_printchar('|');
                else if(y <= height && x == n/2 - y + 1)
                    mx_printchar('/');
                else if(y <= height && x == n/2 + y + n - 1)
                    mx_printchar('\\');
                else
                    mx_printchar(' ');
        }
        mx_printchar('\n');
    }
}

void mx_pyramid(int n) {
    if(n % 2 != 0 && n < 0)
        return;
    top(n);
    bottom(n);
}
// int main() {
//     mx_pyramid(-5);
// }