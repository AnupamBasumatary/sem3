#include <bits/stdc++.h>
using namespace std;

int toInt(int err[], int r)
{
	int ans = 0;
	for(int i = r-1; i >= 0; i--)
		ans += err[i] * pow(2, r-1-i);

	return ans;
}

void print(int arr[], int n)
{
	for(int i = 1; i < n; i++)
		cout << arr[i];

	cout << endl;
}

void errorCorrection(int arr[], int n, int r)
{
	cout << "\nReceived data\n";
	print(arr, n);

	int err[r];
	for(int i = 0; i < r; i++)
	{
		int x = (int)pow(2, i), count = 0;

		for(int j = 1; j < n; j++)
			if(((j >> i) & 1) == 1)
				if(arr[j] == 1)
					count++;

		if(count % 2 == 0)
			err[r-i-1] = 0;
		else
			err[r-i-1] = 1;
	}

	int errBit = toInt(err, r);
	if(errBit == 0)
		cout << "\nNo error detected\n\n";

	else
	{
		cout << "\nError detected at bit " << errBit << endl;
		if(arr[errBit] == 0)
			arr[errBit] = 1;
		else
			arr[errBit] = 0;

		cout << "\nCorrected code is: ";
		for(int i = 1; i < n; i++)
			cout << arr[i];

		cout << endl;
	}
}


void calculateCode(string str, int n, int r)
{
	int arr[n];

	int j = 0;
	for(int i = 1; i < n; i++)
	{
		float f = log10(i) / log10(2);
		if(f - (int)f == 0)
			arr[i] == 0;

		else
			arr[i] = str[j++] - '0';
	}

	for(int i = 0; i < r; i++)
	{
		int x = (int)pow(2, i), count = 0;

		for(int j = 1; j < n; j++)
			if(((j >> i) & 1) == 1)
				if(x != j)
					if(arr[j] == 1)
						count++;

		if(count % 2 == 0)
			arr[x] = 0;
		else
			arr[x] = 1;

		cout << "R" << x << " = " << arr[x] << endl;
	}

	print(arr, n);

	srand(time(0));
	int temp1 = rand() % 2, temp2 = rand() % n;
	arr[temp2] = temp1;

	cout << "\nReceiver side......\n";
	errorCorrection(arr, n, r);
}



int main()
{
	cout << "Enter the Data: ";
	string str;
	cin >> str;

	int r = 1;
	while(pow(2, r) < (str.length() + r + 1))
		r++;

	cout << "\nGenerating Hamming Code..\n";
	calculateCode(str, str.length() + r + 1, r);
}











