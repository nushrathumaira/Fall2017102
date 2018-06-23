# ******************************************************** #
#	General Purpose C/C++ Makefile
# ******************************************************** #

# Compiler Config
CC=gcc
CFLAGS=-Wall -g
LFLAGS=-lm

# Output Config
TARGET=out
SRCDIR=src
OBJDIR=bin

# Run config
RUNARGS=puppy.ppm out.ppm

# Generate source and object lists
SRCS := \
	$(wildcard *.c) \
	$(wildcard *.cpp) \
	$(wildcard $(SRCDIR)/*.c) \
	$(wildcard $(SRCDIR)/*.cpp) \
	$(wildcard $(SRCDIR)/**/*.c) \
	$(wildcard $(SRCDIR)/**/*.cpp)

HDRS := \
	$(wildcard *.h) \
	$(wildcard *hcpp) \
	$(wildcard $(SRCDIR)/*.h) \
	$(wildcard $(SRCDIR)/*.hpp) \
	$(wildcard $(SRCDIR)/**/*.h) \
	$(wildcard $(SRCDIR)/**/*.hpp)

OBJS := $(patsubst %.c, $(OBJDIR)/%.o, $(wildcard *.c))
OBJS += $(patsubst %.cpp, $(OBJDIR)/%.o, $(wildcard *.cpp))
OBJS += $(filter %.o, $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS)))
OBJS += $(filter %.o, $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS)))

# Link all built objects
build: $(OBJS)
	@mkdir -p $(dir $(TARGET))
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

# Catch root directory src files
$(OBJDIR)/%.o: %.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: %.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Catch all nested directory files
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

which:
	@echo "FOUND SOURCES: ${SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "GENERATED OBJS: ${OBJS}"

clean:
	rm -f $(TARGET)
	rm -rf $(OBJDIR)

run: build
	./$(TARGET) $(RUNARGS)
