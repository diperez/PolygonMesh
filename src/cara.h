#include "punto.h"
#include <vector>
using namespace std;
class cara
{
	public:
		cara();
		vector<int> c;
		vector<punto*>norm;
		punto * normal;
		punto * centro;
		int n;
};