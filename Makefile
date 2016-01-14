CC := gcc
CFLAGS := -Wall -lpthread

VPATH = src:sdk
BUILDDIR = build
BIN = bin

all: checkdirs matrixgen serialtester multiply


$(BUILDDIR)/%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

multiply: $(BUILDDIR)/multiply.o $(BUILDDIR)/utilities.o
	$(CC) -o $(BIN)/multiply $^ 

test: $(BUILDDIR)/test.o
	$(CC) -o $(BIN)/test $< $(CFLAGS)

matrixgen: build/matrixgen.o
	$(CC) -o $(BIN)/matrixgen $<

serialtester: build/lab1_IO.o build/serialtester.o 
	$(CC) -o $(BIN)/serialtester $^

checkdirs: $(BUILDDIR) $(BIN)

$(BUILDDIR):
	@mkdir -p $@

$(BIN):
	@mkdir -p $@	

clean:
	rm -rf $(BUILDDIR) 
	rm -rf $(BIN)