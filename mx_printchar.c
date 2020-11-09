#include <unistd.h>

void mx_printchar(char c) {
	write(1, &c, 1);
}

/*int main() {
	char c = 'c';
	mx_printchar(c);
}*/
