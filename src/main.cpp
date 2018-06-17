#include "Engine/Engine.h"

using namespace Thor_Lucas_Development;

struct Entity {
	LogicComponent* logic;
	RenderComponent* render;
};

class ExLogic : public LogicComponent {
private:
	RenderComponent* render;
	bool moveLeft, moveRight, moveUp, moveDown;
public:
	ExLogic() {};
	~ExLogic() {};

	void init() {};
	void init(EventSystem& es, RenderComponent* rc) {
		render = rc;
		es.attachKey([&](Event::Event& event) {
			moveRight = (event.type == Event::KEYDOWN);
		}, Event::D);
		es.attachKey([&](Event::Event& event) {
			moveLeft = (event.type == Event::KEYDOWN);
		}, Event::A);
		es.attachKey([&](Event::Event& event) {
			moveUp = (event.type == Event::KEYDOWN);
		}, Event::W);
		es.attachKey([&](Event::Event& event) {
			moveDown = (event.type == Event::KEYDOWN);
		}, Event::S);
	}

	void quit() {};

	void update() {
		if (moveUp) 	render->dest.y -= 1;
		if (moveDown) 	render->dest.y += 1;
		if (moveRight)	render->dest.x += 1;
		if (moveLeft) 	render->dest.x -= 1;
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