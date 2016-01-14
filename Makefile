CC := gcc
CFLAGS := -Wall -lpthread

VPATH = src:sdk
BUILDDIR = build
EXECUTABLES = executables

all: checkdirs matrixgen serialtester


$(BUILDDIR)/%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(BUILDDIR)/test.o
	$(CC) -o $(EXECUTABLES)/test $< $(CFLAGS)

matrixgen: build/matrixgen.o
	$(CC) -o $(EXECUTABLES)/matrixgen $<

serialtester: build/lab1_IO.o build/serialtester.o 
	$(CC) -o $(EXECUTABLES)/serialtester $^

checkdirs: $(BUILDDIR) $(EXECUTABLES)

$(BUILDDIR):
	@mkdir -p $@

$(EXECUTABLES):
	@mkdir -p $@	

clean:
	rm -rf $(BUILDDIR) 
	rm -rf $(EXECUTABLES)