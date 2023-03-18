.SUFIXES: .c .o .x .h .s
DIR = $(notdir $(CURDIR))

CC := g++
CFLAGS := -Wall
LDFLAGS := -s
LDLIBS := -lm

exec1 = BubbleSort.x  
exec2 = InsertionSort.x
exec3 = SelectionSort.x
exec4 = Generator.x  
exec5 = OperationCounting.x  
exec6 = OperationTiming.x  

.PHONY: all
all: $(exec1) $(exec2) $(exec3) $(exec4) $(exec5) $(exec6)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $< $(LDLIBS)

.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.x *.p core core* a.out *.txt &
	rm -rf .vscode
tar: clean
	(cd ../; tar -cvzf Mateusz_Dyszewski_$(DIR).tar.gz  $(DIR) )
