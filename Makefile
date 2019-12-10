CXX = g++

CXXFLAGS = -g -Wall

BINARY = hw14

TARFILE = hw14.tar

all: $(BINARY)

$(BINARY):
	$(CXX) $(CXXFLAGS) hw14.cpp doubly_linked_list.cpp  -o $(BINARY)

clean:
	rm -rf $(BINARY) $(TARFILE) *.o hw14.scr
tar:
	tar cf $(TARFILE) Makefile hw14.scr hw14.cpp doubly_linked_list.h doubly_linked_list.cpp