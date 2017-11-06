CC_PTHREAD_FLAGS   = -lpthread
CC_FLAGS           = -c
CC_OUTPUT_FLAGS    = -o
CC                 = gcc
RM                 = rm
RM_FLAGS           = -f
TARGET             = mymenu
OBJS               = linktable.o menu.o mymenu.o

all:    $(OBJS)
	$(CC) $(CC_OUTPUT_FLAGS) $(TARGET) $(OBJS)

.c.o:
	$(CC) $(CC_FLAGS) $<

clean:
	$(RM) $(RM_FLAGS) $(OBJS) $(TARGET) *.bak
