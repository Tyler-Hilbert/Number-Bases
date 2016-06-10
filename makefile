DEPS = main.cpp

converter: $(DEPS)
	g++ -std=c++11 -o converter $(DEPS) -I. -g
