/*
Problem link: https://www.hackerrank.com/challenges/exceptional-server/problem?isFullScreen=true

Resources:
https://www.geeksforgeeks.org/exception-handling-c/
https://stackoverflow.com/questions/7749066/how-to-catch-out-of-memory-exception-in-c/13327733
*/
#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) {
		long long A, B;
		cin >> A >> B;

		/* Enter your code here. */
        try {
            cout << Server::compute(A, B) << endl;
        }
        catch (bad_alloc& ba){
            /*
                we need to catch bad_alloc exception explicitly & show message accordingly.
                Hence catching this exception at first.
                If we declare other exception first, OOM exception will get caught in there.
            */
            cout << "Not enough memory" << endl;
        }
        catch (exception& ex) {
            cout<< "Exception: " << ex.what() << endl;
        }
        catch (...) {
            cout << "Other Exception" << endl;
        }
	}
	cout << Server::getLoad() << endl;
	return 0;
}
