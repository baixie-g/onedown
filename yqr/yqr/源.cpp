#include<iostream>

using namespace std;
int main()
{
	time_t begin, end;
	begin = clock();
	int n;
	cin >> n;
	int* p = new int[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = rand() % 9999 + 0;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (p[i] > p[j])
			{
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	delete(p);
	end = clock();
	double time = double(end - begin) / CLOCKS_PER_SEC;
	cout << time;
}
