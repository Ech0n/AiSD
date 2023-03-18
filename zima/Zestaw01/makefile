.SUFIXES: .c .o .x .h .s
DIR = $(notdir $(CURDIR))


CC := g++
CFLAGS := -Wall
LDFLAGS := -s
LDLIBS := -lm

names = ArrayStack 
onplib = onpStack.o
sources = $(addsuffix .cpp,$(names)) 
objects = $(addsuffix .o,$(names)) 
exec1 = Stack.x 
obj1 = Stack.o
exec2 = Generator.x
obj2 = Generator.o
exec3 = ONP.x
obj3 = ONP.o

all: $(exec3) $(exec2) $(exec1)

%.o: %.cpp # Reguła wzorcowa .cpp [+ .h] -> .o
	$(CC) $(CFLAGS) -c -o $@ $<

$(exec1): $(obj1) $(objects) # Stack.x
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(exec2): $(obj2) #Generator.x
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
$(exec3): $(obj3) #Onp.x
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)


.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.x *.p core core* a.out;
tar: clean
	(cd ../; tar -cvzf Mateusz_Dyszewski_$(DIR).tar.gz  $(DIR) )
