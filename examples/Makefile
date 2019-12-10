DEBUG=yes
EXEC=application.exe

PROJECT_ROOT=../..
SRC = $(wildcard *.c) \
	  $(wildcard $(PROJECT_ROOT)/sources/*.c)
INC = $(PROJECT_ROOT)/sources/ $(PROJECT_ROOT)/other_directory/

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

INC_FLAGS = $(addprefix -I,$(INC))

%.d: %.c
	@$(CC) $(CFLAGS) $(INC_FLAGS) $< -MM -MT $(@:.d=.o) >$@

%.o: %.c
	echo $(INC_FLAGS)
	$(CC) $(CFLAGS) $(INC_FLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -f $(obj) $(EXEC) $(dep)
