#include <stdio.h>
#include <string.h>

FILE *p, *o;

unsigned char buf[32 * 1024 * 1024];

int flag;
unsigned long long int coder, coder_extend;

int check_coder(unsigned char a, unsigned char b) {
    if ((a ^ 0xff) == (b ^ 0xd8)) {
        return a ^ 0xff;
    } else if ((a ^ 0x89) == (b ^ 0x50)) {
        return a ^ 0x89;
    } else if ((a ^ 0x42) == (b ^ 0x4d)) {
        return a ^ 0x42;
    } else if ((a ^ 0x47) == (b ^ 0x49)) {
        return a ^ 0x47;
    } else if ((a ^ 0x50) == (b ^ 0x4b)) {
        return a ^ 0x50;
    } else if ((a ^ 0x52) == (b ^ 0x61)) {
        return a ^ 0x52;
    } else if ((a ^ 0x41) == (b ^ 0x56)) {
        return a ^ 0x41;
    }
}

int main(int argc, char *argv[]) {
    for (int times = 0; times < argc - 1; times++) {
        p = fopen(argv[times + 1], "rb");
        int length = fread(buf, 1, 32 * 1024 * 1024, p);
        if (!flag) {
            coder = check_coder(buf[0], buf[1]);
            coder_extend =
                    (coder << 56) | (coder << 48) | (coder << 40) | (coder << 32) | (coder << 24) | (coder << 16) |
                    (coder << 8) | coder;
            flag = 1;
        }

        for (int i = 0; i < length; i += 8) {
            *(unsigned long long int *) (buf + i) ^= coder_extend;
        }

        strcpy(argv[times + 1] + strlen(argv[times + 1]) - 4, ".jpg");
        o = fopen(argv[times + 1], "wb");
        fwrite(buf, length, 1, o);

        fclose(p), fclose(o);
    }

    return 0;
}
