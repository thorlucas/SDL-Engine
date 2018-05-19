CC = g++
CFLAGS = -std=c++11 -g
SDLFLAGS = -I/usr/local/include/SDL2 -I/usr/X11/include -D_THREAD_SAFE -L/usr/local/lib -lSDL2 -lSDL2_image
ENTITIES = CharacterEntity.o
COMPONENTS = RenderComponent.o
SYSTEMS = RenderSystem.o
OBJECTS = main.o Engine.o Renderer.o TextureManager.o $(ENTITIES) $(COMPONENTS) $(SYSTEMS)
EXECUTABLE = out
VPATH = src src/Component src/Entity src/System
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