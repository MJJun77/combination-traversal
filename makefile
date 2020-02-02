CC = g++
OBJS = main.o
SRCS = $(OBJS:.o=.cpp)
TARGET = CombiTest

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
	./$(TARGET)
dep :
	gccmakedep $(SRCS)
new :
	touch $(SRCS)
	$(MAKE)
clean :
	$(RM) $(OBJS) $(TARGET)
