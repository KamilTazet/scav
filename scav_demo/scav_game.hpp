#ifndef SCAV_GAME_HPP_
#define SCAV_GAME_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <map>

class Action {
 public:
	virtual void execute(GameObject* g);
};

class MoveAction: public Action {
private:
	float x;
	float y;
	int obj;
public:
	MoveAction(float dx, float dy, int id): x(dx), y(dy), obj(id) {}
	void execute();
};


class GameObject {
 private:
	int id;
 public:
 	GameObject(int _id);
 	virtual ~GameObject();
 	int get_id();
};

class GameField {
 private:
 	std::map<int, DrawableObject*> map;
 public:
 	void render();
 	void add(DrawableObject* obj);
 	void execute(int id, Action* act);
};

class DrawableObject {
 private:
 	sf::Vector2f pos;
 public:
 	const Vector2f& get_pos() const;
 	virtual void draw();
};

#endif
