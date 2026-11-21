#include "postgres.h"
#include "fmgr.h"

PG_MODULE_MAGIC;

typedef struct {
    float8 real;
    float8 imag;
} Complex;


PG_FUNCTION_INFO_V1(complex_in);


Datum
complex_in(PG_FUNCTION_ARGS) {
    char *str = PG_GETARG_CSTRING(0);
    float8 real;
    float8 imag;
    int n = 0;
    Complex *c;

    if (sscanf(str, " ( %lf , %lf ) %n", &real, &imag, &n) != 2 || str[n] != '\0')
        ereport(ERROR,
                (errcode(ERRCODE_INVALID_TEXT_REPRESENTATION),
                 errmsg("invalid input syntax for type %s: \"%s\"", "complex", str)));

    c = (Complex *) palloc(sizeof(Complex));
    c->real = real;
    c->imag = imag;
    PG_RETURN_POINTER(c);
}
