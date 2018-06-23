# ******************************************************** #
#	General Purpose C/C++ Makefile
# ******************************************************** #

# Output Config
TARGET :=out
SRCDIR :=src
OBJDIR :=bin

# Compiler Config
CC :=g++
CFLAGS :=-Wall -Wextra -Weffc++ -pedantic -std=c++11
LFLAGS :=-lm

# Generate source and object lists

C_SRCS := $(shell find * -type f -name '*.c')
CPP_SRCS := $(shell find * -type f -name '*.cpp')
HDRS := $(shell find * -type f -name '*.h')

OBJS := $(patsubst %.c, $(OBJDIR)/%.o, $(wildcard *.c))
OBJS += $(patsubst %.cpp, $(OBJDIR)/%.o, $(wildcard *.cpp))
OBJS += $(filter %.o, $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(C_SRCS)))
OBJS += $(filter %.o, $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(CPP_SRCS)))

# Link all built objects
$(TARGET): $(OBJS)
	@mkdir -p $(dir $(TARGET))
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

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
	@echo "FOUND C SOURCES: ${C_SRCS}"
	@echo "FOUND C++ SOURCES: ${CPP_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "TARGET OBJS: ${OBJS}"

clean:
	rm -f $(TARGET)
	rm -rf $(OBJDIR)
