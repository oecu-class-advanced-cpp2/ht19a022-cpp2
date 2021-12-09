/*
*	HT19A022 C++応用プログラミング演習2 レポート課題2
*/
#include <iostream> 
#include <vector>

#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。 

using std::cout;
using std::endl;

/*
*	素数判定
*/
bool IsPrime(const int num)
{
	if (num < 2) return false;
	else if (num % 2 == 0) return false;
	else if (num == 2) return true;


	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}
/* --------------------------------------------------------------- */
/*
 *  nth_prime
 *
 *  与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
 *  素数を返す。
 * 
 /* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n) {

	unsigned int* numptr;
	numptr = (unsigned int*)malloc(sizeof(unsigned int) * CPP2_PRIME_UPPER_LIMIT);

	unsigned int* prime;
	prime = (unsigned int*)malloc(sizeof(unsigned int) * CPP2_PRIME_UPPER_LIMIT);

	//最初の数字
	numptr[0] = a;

	for (int i = 1; i < CPP2_PRIME_UPPER_LIMIT; i++) {
		numptr[i] = numptr[i - 1] + d;
	}

	uint32_t prime_index = 0;
	for (int i = 0; i < CPP2_PRIME_UPPER_LIMIT; i++) {
		if (IsPrime(numptr[i]) == true) {
			prime[prime_index] = numptr[i];
			prime_index++;
		}
	}
	return prime[n - 1];
}
 unsigned int compare(unsigned int a, unsigned int d, unsigned int n) {
	
	for(;;){
		int m = a;
		//mには、初期値に初項aを代入。
		int count = 0;
		//countには初期値を設定。

		for(;;) {

			if (IsPrime(m)) {
				//素数判定
				count++;
			}

			if (count == n) {
				//もし、n番目の素数にたどり着いた場合
				return m;
			}
			m += d;
			//mに公差dを足していく。
		}
	}
}


int main() {

	cout << nth_prime(367, 186, 151) << ":" << compare(367, 186, 151) << endl;
	cout << nth_prime(179, 10, 203) << ":" << compare(179, 10, 203) << endl;
	cout << nth_prime(271, 37, 39)<< ":" << compare(271, 37, 39) << endl;
	cout << nth_prime(103, 230, 1) << ":" << compare(103, 230, 1) << endl;
	cout << nth_prime(27, 104, 185) << ":" << compare(27, 104, 185) << endl;
	cout << nth_prime(253, 50, 85) << ":" << compare(253, 50, 85) << endl;

	system("pause");
	return 0;
}
