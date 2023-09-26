CC = g++
TARGET = Steg
CFLAGS = -g -Wall -Wextra

$(TARGET): Steganography.o main.o
	$(CC) $(CFLAGS) -o $(TARGET) Steganography.o main.o

Steganography.o: Steganography.cpp Steganography.h
	$(CC) $(CFLAGS) -c Steganography.cpp

main.o: main.cpp Steganography.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) $(TARGET) *.o *~
