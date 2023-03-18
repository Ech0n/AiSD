.SUFIXES: .c .o .x .h .s
DIR = $(notdir $(CURDIR))

CC := g++
CFLAGS := -Wall
LDFLAGS := -s
LDLIBS := -lm

exec1 = Queue.x 
exec2 = Radix.x
exec3 = Generator.x


all: $(exec1) $(exec2) $(exec3)


%.o: %.cpp 
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $< $(LDLIBS)

.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.x *.p core core* a.out *.txt &
	rm -rf .vscode
tar: clean
	(cd ../; tar -cvzf Mateusz_Dyszewski_$(DIR).tar.gz  $(DIR) )
