#Todo mal esto, no funca
# CFLAGS = -g -std=gnu99 -Wall -Wconversion -Wno-sign-conversion -Werror
# EXEC = pruebas
# OBJ = dc.o calc_helper.o strutil.o testing.o
# CC = gcc
#
# all : $(EXEC)
#
# dc.o : dc.c
# 	$(CC) $(CFLAGS) -c dc.c
#
# calc_helper.o : calc_helper.h calc_helper.c
# 	$(CC) $(CFLAGS) -c calc_helper.c
#
# strutil.o : strutil.h strutil.c
# 	$(CC) $(CFLAGS) -c strutil.c
#
# testing.o : testing.h testing.c
# 	$(CC) $(CFLAGS) -c testing.c
#
# $(EXEC) : $(OBJ) pruebas_tp1.c
# 	$(CC) $(CFLAGS) $(OBJ)  -o $(EXEC) -lm
