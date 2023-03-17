CXX := g++
CXXFLAGS := -std=c++17 
RELEASE_FLAGS = -O3

SRCDIR = src
BUILDDIR = build

EXEC = $(BUILDDIR)/program
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

.PHONY: all release clean

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: $(EXEC)
	./$(EXEC)

release: CXXFLAGS += $(RELEASE_FLAGS)
release: all

clean:
	rm -f $(BUILDDIR)/*.o $(EXEC)