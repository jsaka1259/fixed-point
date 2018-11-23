TARGET := fixed-point

SFR32  := fr32/

OBJS   := main.o $(SFR32)fr32.o

CC     := gcc
CFLAGS := -Wall
INC    := -I $(SFR32)
RM     := rm

.SUFFIXES: .c .o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -f $(OBJS) $(TARGET)
