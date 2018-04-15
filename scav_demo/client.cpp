
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <thread>
#include <list>
#include <dos.h>

GameField field;

void get() {
	sf::TcpSocket socket;
	socket.connect("127.0.0.1", 55001);
	int online=1;
	while(online) {
		sf:Int16 actid = 0;
		sf:Int32 = 0;
		float x = 0;
		float y = 0;
		sf::Packet packet;
		socket.receive(packet);
		packet >> actid >> pbj >> x >> y;
		switch ( actid ) {
			case 1:
				{
					Action action(x,y,obj);
					field.execute(obj, action);
					break;
				}
			default:
				break;
		}
		sleep (20);
	}
	socket.disconnect();
}

void send() {
	sf::TcpSocket socket;
	socket.connect("127.0.0.1", 55001);
	int online=1;
	while(online) {
		sf::Uint8 keyBoardMove=0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
			keyBoardMove=1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			keyBoardMove=2;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			keyBoardMove=3;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			keyBoardMove=4;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			keyBoardMove=5;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			keyBoardMove=6;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			keyBoardMove=7;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			keyBoardMove=8;
		}
		if(keyBoardMove != 0) {
			sf::Packet packet;
			packet << keyBoardMove;
			socket.send(packet);
		}
		sleep (20);
	}
	socket.disconnect();
}


int main(int argc, char const *argv[])
{
	std::thread getThread(get);
	thr.detach();
	std::thread getThread(field.render);
	thr.detach();
	std::thread getThread(send);
	thr.detach();
	return 0;
}

