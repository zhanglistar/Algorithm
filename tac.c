/*
* =====================================================================================
*
*       Filename:  tac.c
*
*    Description:  tac
*
*        Version:  1.0
*        Created:  2014年08月08日 10时21分44秒
*       Revision:  none
*       Compiler:  gcc
*
*         Author:  YOUR NAME (), 
*   Organization:  
*
* =====================================================================================
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define likely(x)   __builtin_expect(!!(x), 1)  
#define unlikely(x) __builtin_expect(!!(x), 0)  

#define LINE_BUF 8192

void tac(const char *file)
{
    if (!file) {
        fprintf(stderr, "%s", "filename empty!");
        return;
    }

    int fd = open(file, O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "open file failed:%s\n", strerror(errno));
        return;
    }
    int len = lseek(fd, 0, SEEK_END);
    if (len < 1) {
        return;
    }
    if (errno != 0) {
        if (errno == EBADF) {
            fprintf(stderr, "%s", "stream not seekable");
            goto __err_out;
        }
        goto __err_out;
    }

    int total_len = LINE_BUF * 2;
    char *big_buf = (char *) malloc(total_len);
    if (!big_buf) {
        fprintf(stderr, "oom");
        goto __err_out;
    }
    char *buf, *left, *end;
    buf = big_buf;
    left = big_buf + LINE_BUF;
    int file_pos = len - len % LINE_BUF;
    if (file_pos == len) {
        file_pos -= LINE_BUF;
    }

    ssize_t     r_len = 0;
    size_t      n_left = 0;
    while (file_pos >= 0) {
        lseek(fd, file_pos, SEEK_SET);
        r_len = read(fd, buf, LINE_BUF);
        if (r_len == 0) {
            // eof
            break;
        }
        char *p = buf + r_len - 1;
        char *pre = p;
        while (p >= buf) {
            if (*p != '\n') {
                --p;
                continue;
            }
            if (pre - p > 0) {
                fwrite(p + 1, 1, pre - p, stdout);
                if (n_left) {
                    fwrite(left, 1, n_left, stdout);
                    n_left = 0;
                }
            } else if (n_left) {
                fwrite(left, 1, n_left, stdout);
                n_left = 0;
            }
            pre = p--;
        }
        if (pre >= buf) {
            n_left += pre - buf + 1;
            if (unlikely(total_len - LINE_BUF < n_left)) {
                total_len *= 2;
                big_buf = realloc(big_buf, total_len);
                if (!big_buf) {
                    fprintf(stderr, "oom\n");
                    goto __err_out;
                }
                buf = big_buf;
                left = big_buf + LINE_BUF;
            }
            memcpy(left, buf, n_left);
        } else {
            n_left = 0;
        }
        file_pos -= LINE_BUF;
    }
    if (n_left) {
        fwrite(left, 1, n_left, stdout);
    }

    #if 0
    for (i = len - 1; i >= 0; --i) {
        fseek(f, i, SEEK_SET);
        unsigned char c = fgetc(f);
        if (c == '\n' && *pstr) {
            printf("%s\n", pstr);
            pstr = buf + buf_len - 1;
        } else {
            if (c == '\n') {
                continue;
            }
            --pstr;
            if (pstr == buf) { // full
                //printf("out of buffer");
                char *new_buf = NULL;
                new_buf = (char *) malloc(buf_len * 2);
                if (!new_buf) {
                    fprintf(stderr, "oom");
                    free(buf);
                    goto __err_out;
                }
                memcpy(new_buf + buf_len, buf, buf_len);
                buf = new_buf;
                buf_len *= 2;
                pstr = buf + buf_len/2;
            }
            *pstr = c;
        }
    }
    if (*pstr) {
        printf("%s\n", pstr);
    }
    #endif

    //fclose(f);
    close(fd);
    //free(buf);
    //free(left);
    free(big_buf);
    return;

__err_out:
    //fclose(f);
    close(fd);
    return;
}

int main(int argc, char *argv[])
{
    tac(argv[1]);
    return 0;
}

