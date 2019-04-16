CC = gcc
CFLAGS = `pkg-config --cflags gtk+-2.0`
LDFLAGS = `pkg-config --libs gtk+-2.0`

test_troll: troll.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o 
	rm -f test_troll
	rm -f *~

