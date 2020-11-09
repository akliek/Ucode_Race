#include <stdio.h>
#include <unistd.h>
void mx_printchar(char c);
static void top(int n) {
    int length = (n * 5) / 2 + 3;
    int height =  n / 2 + 2;
    for(int y = 1; y <= height; y++) {
        for(int x = 1; x <= length; x++) {
            if((x == n / 2 + 2 && y == 1) || (x == length && y == 1)
            || ( x == 1 && y == n / 2 + 2) || (x == n * 2 + 2 && y == n / 2 + 2))
                mx_printchar('+');
            else if((y == 1 && x > n / 2 + 2) 
            || (y == n / 2 + 2 && x > 1 && x < n * 2 + 2))
                mx_printchar('-');
            else if(y < n + 2 && x == length)
                mx_printchar('|');
            else if((x == n / 2 + 2 - y + 1) || (x == length + 1 - y && y < n / 2 + 2))
                mx_printchar('/');
            else
                mx_printchar(' ');
        }
        mx_printchar('\n');
    }
}
static void bottom(int n) {
    int length = (n * 5) / 2 + 3;
    int height = n + 1;
    for(int y = 1; y <= height; y++) {
        for(int x = 1; x <= length; x++) {
            if((x == 1 && y == height) || (x == 2 * n + 2 && y == height)
            || (x == length && y == height - n / 2 - 1))
                mx_printchar('+');
            else if((x == 1 && y < height) || (x == 2 * n + 2 && y < height)
            || (x == length && y < height - (n / 2)))
                mx_printchar('|');
            else if(y == height && x > 1 && x < 2 * n + 2)
                mx_printchar('-');
            else if(x == length && y > height - n / 2 - 1)
                length--;
            else if(x == length - 1 && y > height - n / 2 - 1)
                mx_printchar('/');
            else
                mx_printchar(' ');
        }
        mx_printchar('\n');
    }
}
void mx_cube(int n) {
    if(n <= 1)
        return;
    top(n);
    bottom(n);
}
// int main() {
//     mx_cube(1);
// }