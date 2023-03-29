.SUFIXES: .cpp .o .x .hpp .s
DIR = $(notdir $(CURDIR))

CXX := g++
CXXFLAGS := -Wall
LDFLAGS := -s

exec = tester.x
headers = PriorityQueue.hpp LinkedList.hpp Set.hpp BFS.hpp DirectedGraph.hpp
lib1 = DirectedGraph.o
lib2 = BFS.o


.PHONY: all
all: clean 

%.o: %.cpp $(headers)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.x: %.o $(lib1) $(lib2)
	$(CXX) $(LDFLAGS) -o $@ $^

run: $(exec) 
	./tester.x

.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.x *.p core core* a.out *.txt &
	rm -rf .vscode
tar: clean
	(cd ../; tar -cvzf Mateusz_Dyszewski_$(DIR).tar.gz  $(DIR) )
