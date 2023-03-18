.SUFIXES: .c .o .x .h .s
DIR = $(notdir $(CURDIR))

CXX := g++
CXXFLAGS := -Wall
LDFLAGS := -s

exec1 = Dict.x

.PHONY: all
all: clean $(exec1)

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $<

.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.x *.p core core* a.out &
	rm -rf .vscode
tar: clean
	(cd ../; tar -cvzf Mateusz_Dyszewski_$(DIR).tar.gz  $(DIR) )
