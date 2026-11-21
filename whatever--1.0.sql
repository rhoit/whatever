CREATE TYPE complex;

CREATE FUNCTION complex_in(cstring)
    RETURNS complex
    AS 'MODULE_PATHNAME', 'complex_in'
    LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION complex_out(complex)
    RETURNS cstring
    AS 'MODULE_PATHNAME', 'complex_out'
    LANGUAGE C IMMUTABLE STRICT;

CREATE TYPE complex (
    INPUT = complex_in,
    OUTPUT = complex_out,
    INTERNALLENGTH = 16,
    ALIGNMENT = double
);
