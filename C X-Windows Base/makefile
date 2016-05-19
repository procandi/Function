# Common definitions
RM = /bin/rm -f
CC = /usr/bin/g++
LINK = /usr/bin/g++

# Compiler flags, paths for include files and libraries
CFLAGS = -g -Wall
LFLAGS = -L/usr/X11R6/lib -lXext -lX11
INCPATH = -I. -I/usr/include -I/usr/include/X11
LIBS = 
TARGET = base
OBJECTS = base.o

######## Implicit rules #########################################
.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

######## Build rule #############################################
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

clean:
	$(RM) *~ *.o $(TARGET)