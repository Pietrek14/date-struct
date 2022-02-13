CC := clang++
SRC := src/main.cpp src/date/date.cpp
HEADERS := src/date/date.hpp
TARGETDIR := build
TARGETFILE := main.exe

TARGET := $(TARGETDIR)\$(TARGETFILE)

build: $(SRC) $(HEADERS)
	$(CC) -o $(TARGET) $(SRC)

run:
	cd $(TARGETDIR) && $(TARGETFILE)

clean:
	del $(TARGET)