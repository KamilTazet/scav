
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <thread>
#include <list>
#include <dos.h>

std::list<Action*> actions;
int get() {
	sf::TcpSocket socket;
	socket.connect("127.0.0.1", 55001);
	int online=1;
	while(true) {
		int actid = 0;
		int obj = 0;
		float x = 0;
		float y = 0;
		sf::Packet packet;
		socket.receive(packet);
		packet >> actid >> pbj >> x >> y;
		switch ( actid ) {
			case 1:
				{
					Action action = new Action(x,y,obj);
					actions.push_back(action);
					break;
				}
			default:
				break;
		}
		sleep (20);
	}
	socket.disconnect();
}
/*sosi guboy tryasi*/
int main(int argc, char const *argv[])
{
	std::thread getThread(get);
	thr.detach();
	return 0;
}

