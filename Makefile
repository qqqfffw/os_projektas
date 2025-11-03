# Compiler & flags
CXX      ?= g++
CXXFLAGS ?= -O2 -std=c++17

# Project
TARGET := main
SRCS   := main.cpp commands.cpp
OBJS   := $(SRCS:.cpp=.o)

# --- OS-specific bits ---------------------------------------------------------
ifeq ($(OS),Windows_NT)
  EXE   := .exe
  RM    := del /F /Q
  RUN   := $(TARGET)$(EXE)         # cmd.exe searches current dir
else
  EXE   :=
  RM    := rm -f
  RUN   := ./$(TARGET)
endif

# --- Phony targets ------------------------------------------------------------
.PHONY: all run clean

# Default build
all: $(TARGET)$(EXE)

# Link
$(TARGET)$(EXE): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Compile (explicit deps for headers)
main.o:     main.cpp commands.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

commands.o: commands.cpp commands.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)$(EXE)
	$(RUN)

# Clean artifacts (the leading '-' ignores errors if files don't exist)
clean:
	-$(RM) $(TARGET)$(EXE)
	-$(RM) $(OBJS)
