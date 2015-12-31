CXX=g++
CXXFLAGS=-g -Wall -std=c++11
LDFLAGS=
BUILDDIR=build
TARGET=bin
SRCEXT=cpp
SRCDIR=src
SOURCES=$(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS=$(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
LIB=
INC=-I include



all:	$(TARGET)
	mv $(TARGET).exe $(TARGET)/SmartOrderRouter.exe

$(TARGET):	$(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o:	$(SRCDIR)/%.$(SRCEXT)
	mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<


clean:
		rm -rf $(BUILDDIR)/*
		rm -rf $(TARGET)/*
		rm -rf *stackdump*

debug:	
	echo "Sources: $(SOURCES) "
	echo "Objects: $(OBJECTS)"
	echo "Target:  $(TARGET)"
	echo "Buil Dir: $(BUILDDIR)"

