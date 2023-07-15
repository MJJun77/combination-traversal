#include "CombinationGen.h"
#include <string>
#include <iostream>
using namespace std;

template <typename T>
void printVector(const vector<T>& cur_vec)
{
	for (int i = 0; i < cur_vec.size(); i++)
		cout << cur_vec[i] << ", ";

	cout << endl;
}

#define STRING_TYPE_TEST
#ifdef STRING_TYPE_TEST
typedef std::string MY_VEC_TYPE;
#else
typedef int MY_VEC_TYPE;
#endif

int main()
{
#ifdef STRING_TYPE_TEST
	vector<MY_VEC_TYPE> v_arr = {"One", "Two", "Three", "Four", "Five", "Six", "Seven"};
#else
	vector<MY_VEC_TYPE> v_arr = {1, 2, 3, 4, 5, 6, 7};
#endif
	CombinationGen<MY_VEC_TYPE> combi_gen(&v_arr, 3, false);

	int found_combi_cnt = 0;
	const std::vector<MY_VEC_TYPE>* p_result = combi_gen.GetNextCombination();
	while (p_result) {
		found_combi_cnt++;
		printVector(*p_result);
		p_result = combi_gen.GetNextCombination();
	}

	cout << "Total " << found_combi_cnt << " combination set was found." << endl;
	return 0;
}