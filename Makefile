SRCDIR = src
OBJDIR = obj

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS =  $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

CXX = g++
CXXFLAGS = -g -std=gnu++11 -O2 -Wall -Wextra
LDFLAGS = -g

all: ppgen

$(OBJDIR)/%.o : src/%.cpp src/%.hpp
	mkdir -p $(@D); $(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR)/%.o : src/%.cpp
	mkdir -p $(@D); $(CXX) $(CXXFLAGS) -c -o $@ $<

ppgen : $(OBJECTS)
	$(CXX) $(LDFLAGS) -o ppgen $(OBJECTS)
	
prod : ppgen
	strip ppgen
	
clean :
	rm -rf $(OBJDIR)/

remake :
	$(MAKE) clean
	$(MAKE) all
	
install : prod
	/usr/bin/install -c -g root -o root -m 755 ppgen /usr/bin/ppgen

.PHONY : all prod clean remake
