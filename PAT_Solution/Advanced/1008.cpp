#include <bits/stdc++.h>
using namespace std;

int main(){
	int now = 0, sum = 0, a;
	cin >> a;
	while(cin >> a){ // ���д��ֵ��ѧϰ ctrl+z ��ֹ���� 
		if(a > now)
			sum = sum + (now-a) * 6;
		else
			sum = sum + (now-a) * 4;
		
		sum+=5;
		now = a;
	}
	
	cout << sum;
	return 0;
}
