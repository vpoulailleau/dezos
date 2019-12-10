DEBUG=yes
EXEC=application.exe

SRC = $(wildcard *.c) \
	  $(wildcard ../sources/*.c)

ifeq ($(DEBUG),yes)
	CFLAGS=-W -Wall -g -std=c99
else
	CFLAGS=-W -Wall -std=c99
endif
LDFLAGS= -Wall

###############################################
# end of the configuration
###############################################

all: $(EXEC)

obj = $(SRC:.c=.o)
dep = $(obj:.o=.d)

$(EXEC): $(obj)
	$(CC) $(LDFLAGS) -o $@ $^

-include $(dep)

%.d: %.c
	@$(CC) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -f $(obj) $(EXEC) $(dep)
