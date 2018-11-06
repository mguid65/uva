//0.010 seconds
//iterative is faster, avoid unecessary jumps to functions
//using dangerous, non thread safe unlocked operations
//unsafe ascii digit bound check
//since we only ever subtract from the char,
//we can unsafely assume it will never cross the upper bound

#include <cstdio>

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>


//custom getline function
ssize_t
getline_unlocked (char *lineptr, size_t n, int delimiter, FILE *fp) {
  ssize_t result;
  ssize_t cur_len = 0;
  ssize_t len;
  len = fp->_IO_read_end - fp->_IO_read_ptr;
  if (len <= 0)
    {
      if (__underflow (fp) == EOF)
        {
          result = -1;
          goto unlock_return;
        }
      len = fp->_IO_read_end - fp->_IO_read_ptr;
    }
  for (;;)
    {
      size_t needed;
      char *t;
      t = (char *) memchr ((void *) fp->_IO_read_ptr, delimiter, len);
      if (t != NULL)
        len = (t - fp->_IO_read_ptr) + 1;
      if (__glibc_unlikely (len >= SSIZE_MAX - cur_len))
        {
          result = -1;
          goto unlock_return;
        }
      /* Make enough space for len+1 (for final NUL) bytes.  */
      needed = cur_len + len + 1;
      if (needed > n)
        {
          char *new_lineptr;
          if (needed < 2 * n)
            needed = 2 * n;  /* Be generous. */
          new_lineptr = (char *) realloc (lineptr, needed);
          if (new_lineptr == NULL)
            {
              result = -1;
              goto unlock_return;
            }
          lineptr = new_lineptr;
          n = needed;
        }
      memcpy (lineptr + cur_len, (void *) fp->_IO_read_ptr, len);
      fp->_IO_read_ptr += len;
      cur_len += len;
      if (t != NULL || __underflow (fp) == EOF)
        break;
      len = fp->_IO_read_end - fp->_IO_read_ptr;
    }
  (lineptr)[cur_len] = '\0';
  result = cur_len;
unlock_return:
  return result;
}

union str_num {
  unsigned int i;
  char s[9];
};

int main() {
  int x, y, total, width, count, input, err;

  str_num s;
  char c;
  char buf[1024];
  char * pos = buf;
  static const int to_int{0x0F};

  while(scanf(" %d ", &width) != EOF) {
    total = 0;
    count = getchar_unlocked() & to_int;
    c = getchar_unlocked(); //danger, assuming the next character is correctly formatted
    err = getline_unlocked(s.s, 8, '\n', stdin);
    //while('0' <= c) { //unsafe ignore upper bound
    //  count = (count * 10) + (c & to_int) ;
    //  c = getchar_unlocked();
    //}
    s.i = (s.i & 0x0F0F0F0F) * 2561 >> 8;
    s.i = (s.i & 0x00FF00FF) * 6553601 >> 16;
    count = (s.i & 0x0000FFFF) * 42949672960001 >> 32;
    

    while(count--) {
      x = y = 0;
      x = getchar_unlocked() & to_int;
      c = getchar_unlocked(); //danger, assuming the next character is correct formatted
      while('0' <= c) {
        x = (x * 10) + (c & to_int);
        c = getchar_unlocked();
      }
      y = getchar_unlocked() & to_int;
      c = getchar_unlocked(); //danger, assuming the next character is correct formatted
      while('0' <= c) { //unsafe ignore upper bound
        y = (y * 10) + (c & to_int);
        c = getchar_unlocked();
      }
      total += x * y;
    }
    pos += sprintf(pos , "%d\n", total/width);
  }
  fwrite_unlocked(buf, 1, pos-buf, stdout);
}
