#include "CombinationGen.h"
#include <string>
#include <cstdlib>		// for atoi()
#include <iostream>
using namespace std;

void printIdxInfo(const vector<bool>& vec_info)
{
	for (int i = 0; i < vec_info.size(); i++) {
		cout << vec_info[i]? "1 " : "0 ";
		if ((i + 1) % 10 == 0)
			cout << "  ";
	}
	cout << endl;
}

/*
# This main() is for validating CombiIdxMgr class.
int main(int argc, char* argv[])
{
	if (argc != 3) {
		cout << "Usage : program num_N num_K => for nCk" << endl;
		return -1;
	}

	CombiIdxMgr combi_mgr;
	combi_mgr.initIdxInfo(atoi(argv[1]), atoi(argv[2]));

	int combi_cnt = 0;
	bool b_next_combi = combi_mgr.calcNextIdx();
	while (b_next_combi) {
		combi_cnt++;
		//printIdxInfo(combi_mgr.getSelectionVec());
		b_next_combi = combi_mgr.calcNextIdx();
	}

	cout << "Total combi count : " << combi_cnt << endl;

	return 0;
}
*/

template <typename T>
void printVector(const vector<T>& cur_vec)
{
	for (int i = 0; i < cur_vec.size(); i++)
		cout << cur_vec[i] << ", ";

	cout << endl;
}

typedef std::string MY_VEC_TYPE;
int main()
{
	vector<MY_VEC_TYPE> v_arr = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Zeta", "Eta", "Theta"};
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