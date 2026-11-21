#include "postgres.h"
#include "fmgr.h"

PG_MODULE_MAGIC;

typedef struct {
    float8 real;
    float8 imag;
} Complex;
