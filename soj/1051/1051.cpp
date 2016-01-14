#include <iostream>
#include <iomanip>
using namespace std;

const float PI = 3.1415927;
const float DIS_FACTOR = PI/(5280*12);
const float MPH_FACTOR = float(60*60);

float getDistance(float d, int r) {
		//return (d*PI)*r/(5280*12);
		return DIS_FACTOR*d*r;
}

float getMPH(float dis, float t) {	
	//return dis/(t)*60*60;
	return dis*MPH_FACTOR/t;
}

int main() {
		float d; //diameter
		int r;	//revolution
		float t; 	//time second
		
		cin >> d >> r >> t;
		int n = 1;
		while (r) {
			//float dis = (d*PI)*r/(5280*12);
			//float mph = dis/(t)*60*60;
			float dis = getDistance(d, r);
			cout << "Trip #" << n <<  ": " << fixed << setprecision(2) << dis<< " " << getMPH(dis, t) << endl;
			
			n++;
			cin >> d >> r >> t;
		}
		
		return 0;
}