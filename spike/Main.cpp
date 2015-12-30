#include "FixMessage.h"
#include <algorithm>

using namespace std;

int main(void)
{
	string s("8=FIX.4.49=156535=D");
	FixMessage fm;
	fm.parse(s);
	string msg = fm.create();
	fm.parse(msg);
}
