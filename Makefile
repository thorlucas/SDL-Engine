CC = g++
CFLAGS = -std=c++11 -g
SDLFLAGS = -I/usr/local/include/SDL2 -I/usr/X11/include -D_THREAD_SAFE -lSDL2 -lSDL2_image # -L/usr/local/lib
ENTITIES = 
COMPONENTS = 
SYSTEMS = RenderSystem.o ResourceSystem.o DebugSystem.o EventSystem.o LogicSystem.o
OBJECTS = main.o Engine.o $(ENTITIES) $(COMPONENTS) $(SYSTEMS)
EXECUTABLE = out
VPATH = src src/Engine src/Engine/Component src/Engine/Entity src/Engine/System
DOXYGENFILE = Doxyfile
DOXYGEN = doxygen

out: $(OBJECTS)
	$(CC) $(CFLAGS) $(SDLFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o : %.cpp
	$(CC) $(CFLAGS) $(SDLFLAGS) -c $< -o $@

.PHONY: docs clean

docs:
	$(DOXYGEN) $(DOXYGENFILE)

clean:
	rm $(OBJECTS) $(EXECUTABLE)