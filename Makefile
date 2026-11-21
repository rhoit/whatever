EXTENSION = whatever
DATA = whatever--1.0.sql
PG_CONFIG ?= pg_config

MODULE_big = whatever
OBJS = whatever.o

PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
