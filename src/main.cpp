#include "Engine/Engine.h"
#include "Engine/Entity/Entity.h"

using namespace Thor_Lucas_Development;

class ExLogic : public LogicComponent {
private:
	RenderComponent* render;
	bool moveLeft, moveRight, moveUp, moveDown;
public:
	ExLogic(EventSystem& es, RenderComponent* rc) {
		moveLeft = false; moveRight = false; moveUp = false; moveDown = false;
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
	};

	~ExLogic() {
		// TODO: Remove function from event system.
	};

	void update() {
		if (moveUp) 	render->dest.y -= 1;
		if (moveDown) 	render->dest.y += 1;
		if (moveRight)	render->dest.x += 1;
		if (moveLeft) 	render->dest.x -= 1;
	}
};


class ExEntity : public Entity {
private:
	LogicHandle lHandle;
	RenderHandle rHandle;
public:
	ExEntity() {
		rHandle = Engine::get().getRenderSystem().registerComponent(
			new RenderComponent(
				Engine::get().getResourceSystem().getTexture("bg"),
				(SDL_Rect){100, 100, 50, 50}
			)
		);
		lHandle = Engine::get().getLogicSystem().registerComponent(
			new ExLogic(
				Engine::get().getEventSystem(),
				rHandle->render
			)
		);
	};

	~ExEntity() {
		Engine::get().getLogicSystem().removeComponent(lHandle);
		Engine::get().getRenderSystem().removeComponent(rHandle);
	};
};

int main(int argc, char const *argv[]) {
	Engine& engine = Engine::get();
	engine.init();

	engine.getResourceSystem().loadTexture("bg", "./resources/bg.jpg");

	ExEntity* entity = new ExEntity;

	engine.mainLoop();

	delete entity;

	return 0;
}