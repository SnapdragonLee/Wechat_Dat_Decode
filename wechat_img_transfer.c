#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *p, *o;

char buf[32*1024*1024];

int main(int argc, char *argv[]) {
	for (int times = 0; times < argc; times++){
		p = fopen(argv[times + 1], "rb");
		int length = fread(buf, 1, 32*1024*1024, p);
		char coder = buf[0] ^ 0xff;
		
		for (int i = 0; i < length; i++){
			buf[i] ^= coder;
		}
		
		strcpy(argv[times + 1] + strlen(argv[times + 1]) - 4, ".jpg");
		o = fopen(argv[times + 1], "wb");
		fwrite(buf, length, 1, o);
		
		fclose(p), fclose(o);
	}
	
    return 0;
}
