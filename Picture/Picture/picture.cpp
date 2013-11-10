// Pictrue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Picture.class.cpp"

int _tmain(int argc, _TCHAR* argv[])
{
	

	char *init[]= {"Paris","in the","Spring"};  
	Picture p(init,3);  
	cout << frame(frame(p) & (p | frame(p))) << endl;

	cin.get();
	return 0;

}




