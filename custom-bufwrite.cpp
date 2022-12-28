
/* Custom output buffer writer for boj PS.
 * Use as `inline` if needed.
 * Author : rpopic2
 */

/* boilerplates */
#include <unistd.h>
constexpr size_t BUF_SIZE = 1 << 16;
char rbuf[BUF_SIZE], *p = rbuf;
void buf_flush()
{
    write(1, rbuf, p - rbuf);
    p = rbuf;
}

/* List of custom buf writers
 * bufw 
 *      : no_suffix -> primitive form, sign agnostic(not recognising).
 *      : au->  auto-flushed
 *      : s ->  signed. recognises sign.
 *      : ln->  write newline
 * bufrw
 *      : reverse write
 */ 
void bufw(int num)
{
    int digits = 1;
    for (int j = num; j >= 10; j /= 10) ++digits;
    for (int j = digits; j--; num /= 10) p[j] = num % 10 + '0';
    p += digits;
}
// char * const buf_end = buf + BUF_SIZE;
/* void bufw_au(int num)
{
    //for ...<snip>
    if (p + [len_to_write] > buf_end) buf_flush();
    //for ...<snip>
}
* buf_end = 
*/
void bufw_s(int num)
{
    if (num < 0) {
        *p++ = '-';
        num = -num;
    }
    bufw(num);
}
void bufw_ln(int num)
{
    bufw(num);
    *p++ = '\n';
}
inline void bufw_c(char c)
{
    *p++ = c;
}
void bufw_s(char *c, size_t len)
{
    for (int i = 0; i < len; ++i)
    {
        bufw_c(c[i]);
    }
}
//reverse write
void bufrw_s(char *c, size_t len)
{
    while (len--)
    {
        bufw_c(c[len]);
    }
}

int main()
{
    bufw_ln(40003);
    buf_flush();
    bufw(10);
    buf_flush();
    bufw_s("hello world", 10);
    bufrw_s("hello world", 10);
    buf_flush();
}
