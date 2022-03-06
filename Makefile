LDFLAGS = -lusb-1.0 -lm
CFLAGS = -g3 -gdwarf-4 # provide macro values to gdb

.PHONY: all clean

all: main

main: *.c *.h
	$(CC) -O0 -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf *.o main
