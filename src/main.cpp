#include "Engine/Engine.h"

using namespace Thor_Lucas_Development;

struct Entity {
	LogicComponent* logic;
	RenderComponent* render;
};

class ExLogic : public LogicComponent {
private:
	RenderComponent* render;
	bool move;
public:
	ExLogic() {};
	~ExLogic() {};

	void init() {};
	void init(EventSystem& es, RenderComponent* rc) {
		render = rc;
		es.attachKey(this, SDLK_d);
	}

	void quit() {};

	void event(SDL_Event& event) {
		if (event.key.type == SDL_KEYDOWN) {
			move = true;
		} else {
			move = false;
		}
	}

	void update() {
		if (move) {
			render->dest.x += 1;
		}
	}
};

int main(int argc, char const *argv[]) {
	// Engine engine = Engine();
	Engine& engine = Engine::get();
	engine.init();

	engine.getResourceSystem().loadTexture("bg", "./resources/bg.jpg");
	RenderComponent& rc = engine.getRenderSystem().getNewComponent();
	rc.init(engine.getResourceSystem().getTexture("bg"), 100, 100, 50, 50);
	ExLogic log;
	log.init(engine.getEventSystem(), &rc);
	engine.getLogicSystem().addLogicComponent(&log);
	Entity c = Entity{&log, &rc};

	engine.mainLoop();

	return 0;
}