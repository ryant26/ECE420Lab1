CC := gcc
CFLAGS := -Wall -lpthread

VPATH = src:sdk
BUILDDIR = build
EXECUTABLES = executables

all: lab1_IO


$(BUILDDIR)/%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

matrixgen: build/matrixgen.o
	$(CC) -o $(EXECUTABLES)/matrixgen $<

checkdirs: $(BUILDDIR) $(EXECUTABLES)

$(BUILDDIR):
	@mkdir -p $@

$(EXECUTABLES):
	@mkdir -p $@	

clean:
	rm -rf $(BUILDDIR) 
	rm -rf $(EXECUTABLES)