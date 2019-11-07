SRCDIR  := src
FR32DIR := $(SRCDIR)/fr32

OUTDIR  := build
SRCS    := $(wildcard $(SRCDIR)/*.c)
SRCS    += $(wildcard $(FR32DIR)/*.c)
OBJS    := $(addprefix $(OUTDIR)/,$(patsubst %.c,%.o,$(SRCS)))
BIN     := $(OUTDIR)/fr32

CC     := gcc
CFLAGS := -Wall
RM     := rm

.PHONY: clean rebuild

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OUTDIR)/%.o:%.c
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -rf $(OUTDIR)

rebuild: clean $(BIN)
