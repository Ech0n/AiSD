.SUFIXES: .cpp .o .x .hpp .s
DIR = $(notdir $(CURDIR))

CXX := g++
CXXFLAGS := -Wall
LDFLAGS := -s

exec = tester.x
headers = PriorityQueue.hpp

.PHONY: all
all: clean $(exec1)

%.o: %.cpp $(headers)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.x: %.o 
	$(CXX) $(LDFLAGS) -o $@ $<

run: $(exec) 
	./tester.x

.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.x *.p core core* a.out *.txt &
	rm -rf .vscode
tar: clean
	(cd ../; tar -cvzf Mateusz_Dyszewski_$(DIR).tar.gz  $(DIR) )
