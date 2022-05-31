#include<iostream>
#include<string>

using namespace std;

class Clock {
	public:
		int hr, min, sec;
		string mer;
		Clock(int a, int b, int c, string d) {
			hr = a;
			min = b;
			sec = c;
			mer = d;
		}
		display() {
			cout << hr << ":" << min << ":" << sec << " " << mer << endl;
		}
}; 

class StandardClock : Clock {
	public:
		StandardClock(int a, int b, int c, string d) : Clock(a, b, c, d){
			hr = a;
			min = b;
			sec = c;
			mer = d;
		}
		display() {
			if (mer == "AM") {
				cout << "¤W¤È " << hr << ":" << min << ":" << sec << endl;
			} else if (mer == "PM") {
				cout << "¤U¤È " << hr << ":" << min << ":" << sec << endl;
			}
		}
};

class MilitaryClock : Clock {
	public:
		MilitaryClock(int a, int b, int c, string d) : Clock(a, b, c, d){
			hr = a;
			min = b;
			sec = c;
			mer = d;
		}
		display() {
			if (mer == "AM") {
				cout << hr << ":" << min << ":" << sec << endl;
			} else if (mer == "PM") {
				cout << hr+12 << ":" << min << ":" << sec << endl;
			}
		}
};

int main() {
	Clock cc(10, 25, 43, "AM");
	StandardClock sc(10, 25, 43, "AM");
	MilitaryClock mc(10, 25, 43, "PM");
	cc.display();
	sc.display();
	mc.display();
	return 0;
}
