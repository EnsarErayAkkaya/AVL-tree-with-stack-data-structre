CC=g++

vpath %.h include
vpath %.cpp src
vpath %.o lib

OUT_DIR = bin
OBJDIR = lib

CFLAGS = -O2 -Wall -pedantic
LIBS = -lnsl -lm

OBJS = $(OBJDIR)/main.o $(OBJDIR)/AVLTree.o $(OBJDIR)/AVLTreeNode.o $(OBJDIR)/PersonData.o $(OBJDIR)/Stack.o

all:program

program:$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OUT_DIR)/program -static-libstdc++

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c -o  $@ $<

.PHONY : clean
clean :
	rm -f *.o $(OUT_DIR)/main.exe