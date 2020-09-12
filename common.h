#ifndef __COMMON_H__
#define __COMMON_H__

#define ElEMLEN(l) (sizeof(l) / sizeof(l[0]))

#define COND(exp, retVal)    \
    do {                     \
        if (!(exp)) {        \
            return (retVal); \
        }                    \
    } while (0);

typedef enum { FALSE = 0, TRUE } BOOL;

#endif  // __COMMON_H__
