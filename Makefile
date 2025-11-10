CFLAGS=-c -g -Wall -Werror
CC=gcc
LDFLAGS=-lm

all: recv alarm segfault send handler sigaction

recv: recv_signal.o
	$(CC) -o recv recv_signal.o

alarm: signal_alarm.o
	$(CC) -o alarm signal_alarm.o

segfault: signal_segfault.o
	$(CC) -o segfault signal_segfault.o

send: send_signal.o
	$(CC) -o send send_signal.o

handler: signal_handler.o
	$(CC) -o handler signal_handler.o

sigaction: signal_sigaction.o
	$(CC) -o sigaction signal_sigaction.o

clean:
	rm -f *.o  recv alarm segfault send handler sigaction

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<
