# Compiler
CXX = g++

DEFINEFLAGS     =       -Dnooutput
# see the #ifdef nooutput in overflow.cpp


# Compiler flags
# CXXFLAGS is a standard variable name for flags for the C++ compiler
# -std=c++11 specifies to use the C++11 standard
# -Wall enables all compiler's warning messages
# -fopenmp enables the OpenMP directive for parallel programming
CXXFLAGS = -std=c++11 -Wall -fopenmp $(DEFINEFLAGS)

# Target executable
# TARGET is the name of the final executable file
TARGET = ACO_practice

# Source files: SRCS is a list of source files
SRCS = overflow.cpp MainArgs.cpp openmp-example.cpp pi.cpp pointer-dam.cpp pointer-dam3D.cpp \
		pointer-update-parameter.cpp IO.cpp class.cpp structure.cpp Sort_index.cpp vector.cpp \
		different_arrays.cpp openmp-nested-for-loop.cpp openp-no-parallel.cpp openmp-parallle-output.cpp \
		openmp-sections.cpp problemtic_program_for_gdb.cpp advanced_functions.cpp

# Object files
# The $(SRCS:.cpp=.o) is a substitution reference which replaces the .cpp extension with .o in SRCS
OBJS = $(SRCS:.cpp=.o)

# Executables
EXECS = overflow MainArgs openmp-example pi pointer-dam pointer-dam3D IO pointer-update-parameter \
 		class structure Sort_index vector different_arrays openmp-nested-for-loop openmp-no-parallel \
 		openmp-parallle-output openmp-sections problemtic_program_for_gdb advanced_functions

# Number of threads for OpenMP
# OMP_NUM_THREADS is an environment variable that specifies the number of threads to use for OpenMP
OMP_NUM_THREADS=4
export OMP_NUM_THREADS

# Default target
# all is a standard target that will be built if no target is specified
# It depends on the TARGET
all: $(EXECS)

# Individual targets for each source file
# Each target has a rule that specifies how to build it
# The $(CXX) $(CXXFLAGS) -o $@ $< command compiles the source file into an executable
# $@ is the name of the target and $< is the name of the first prerequisite
overflow: overflow.o
	$(CXX) $(CXXFLAGS) -o overflow overflow.o

MainArgs: MainArgs.o
	$(CXX) $(CXXFLAGS) -o MainArgs MainArgs.o

openmp-example: openmp-example.o
	$(CXX) $(CXXFLAGS) -o openmp-example openmp-example.o

pi: pi.o
	$(CXX) $(CXXFLAGS) -o pi pi.o

pointer-dam: pointer-dam.o
	$(CXX) $(CXXFLAGS) -o pointer-dam pointer-dam.o

pointer-dam3D: pointer-dam3D.o
	$(CXX) $(CXXFLAGS) -o pointer-dam3D pointer-dam3D.o

IO: IO.o
	$(CXX) $(CXXFLAGS) -o IO IO.o

pointer-update-parameter: pointer-update-parameter.o
	$(CXX) $(CXXFLAGS) -o pointer-update-parameter pointer-update-parameter.o

class: class.o
	$(CXX) $(CXXFLAGS) -o class class.o

structure: structure.o
	$(CXX) $(CXXFLAGS) -o structure structure.o

Sort_index: Sort_index.o
	$(CXX) $(CXXFLAGS) -o Sort_index Sort_index.o

vector: vector.o
	$(CXX) $(CXXFLAGS) -o vector vector.o

different_arrays: different_arrays.o
	$(CXX) $(CXXFLAGS) -o different_arrays different_arrays.o

openmp-nested-for-loop: openmp-nested-for-loop.o
	$(CXX) $(CXXFLAGS) -o openmp-nested-for-loop openmp-nested-for-loop.o

openmp-no-parallel: openmp-no-parallel.o
	$(CXX) $(CXXFLAGS) -o openmp-no-parallel openmp-no-parallel.o

openmp-parallle-output: openmp-parallle-output.o
	$(CXX) $(CXXFLAGS) -o openmp-parallle-output openmp-parallle-output.o

openmp-sections: openmp-sections.o
	$(CXX) $(CXXFLAGS) -o openmp-sections openmp-sections.o

problemtic_program_for_gdb: problemtic_program_for_gdb.o
	$(CXX) $(CXXFLAGS) -o problemtic_program_for_gdb problemtic_program_for_gdb.o

segfault_examples: segfault_examples.o
	$(CXX) $(CXXFLAGS) -o segfault_examples segfault_examples.o

advanced_functions: advanced_functions.o
	$(CXX) $(CXXFLAGS) -o advanced_functions advanced_functions.o

# Rule for building object files from source files
# The $(CXX) $(CXXFLAGS) -c $< -o $@ command compiles the source file into an object file
# -c tells the compiler to generate an object file, -o specifies the output file
# $< is the name of the first prerequisite and $@ is the name of the target
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

# Clean target
# clean is a standard target that deletes all generated files
# The $(RM) $(OBJS) $(TARGET) $(EXECS) command deletes the object files, the target executable, and the executables
clean:
	$(RM) $(OBJS) $(TARGET) $(EXECS)
