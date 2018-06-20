#include "Engine/Engine.h"
#include "Engine/Entity/Entity.h"
#include "Engine/Component/SpriteRenderComponent.h"
#include <cstdio>

using namespace Thor_Lucas_Development;

class ExLogic : public LogicComponent {
private:
	SpriteRenderComponent* render;
	bool moveLeft, moveRight, moveUp, moveDown;
	Vector moveX;
	Vector moveY;
public:
	ExLogic(EventSystem& es, SpriteRenderComponent* rc) {
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

		moveX = Vector{200, 0};
		moveY = Vector{0, 200};
	};

	~ExLogic() {
		// TODO: Remove function from event system.
	};

	void update(Uint32 deltaTime) {
		float deltaSec = float(deltaTime)/1000.f;
		if (moveUp) 	render->move(moveY * -deltaSec);
		if (moveDown) 	render->move(moveY * deltaSec);
		if (moveRight)	render->move(moveX * deltaSec);
		if (moveLeft) 	render->move(moveX * -deltaSec);
	}
};


class ExEntity : public Entity {
private:
	LogicHandle lHandle;
	RenderHandle rHandle;
public:
	ExEntity() {
		SpriteRenderComponent* rc = new SpriteRenderComponent(
			Engine::get().getResourceSystem(),
			"bg",
			(Rect){100, 100, 50, 50}
		);

		rHandle = Engine::get().getRenderSystem().registerComponent(rc);
		lHandle = Engine::get().getLogicSystem().registerComponent(
			new ExLogic(
				Engine::get().getEventSystem(),
				rc
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