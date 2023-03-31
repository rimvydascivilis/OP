CXX := g++
CXXFLAGS := -std=c++17
RELEASE_FLAGS = -O3

SRCDIR = src
BUILDDIR = build

EXEC = $(BUILDDIR)/program
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

.PHONY: release clean run list vector deque

deque:
	$(CXX) $(CXXFLAGS) $(RELEASE_FLAGS) -o $(EXEC) $(SRCDIR)/deque_main.cpp $(SRCDIR)/gen_stud_file.cpp $(SRCDIR)/student_io.cpp $(SRCDIR)/student.cpp $(SRCDIR)/utility.cpp

list:
	$(CXX) $(CXXFLAGS) $(RELEASE_FLAGS) -o $(EXEC) $(SRCDIR)/list_main.cpp $(SRCDIR)/gen_stud_file.cpp $(SRCDIR)/student_io.cpp $(SRCDIR)/student.cpp $(SRCDIR)/utility.cpp

vector:
	$(CXX) $(CXXFLAGS) $(RELEASE_FLAGS) -o $(EXEC) $(SRCDIR)/main.cpp $(SRCDIR)/gen_stud_file.cpp $(SRCDIR)/student_io.cpp $(SRCDIR)/student.cpp $(SRCDIR)/utility.cpp

run: $(EXEC)
	./$(EXEC)

release: CXXFLAGS += $(RELEASE_FLAGS)
release: all

clean:
	rm -f $(BUILDDIR)/*.o $(EXEC)