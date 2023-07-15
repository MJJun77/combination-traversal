#ifndef __COMBINATION_GENERATOR__
#define __COMBINATION_GENERATOR__

#include "CombiIdxMgr.h"

template <typename T>
class CombinationGen
{
	public:
		CombinationGen(const std::vector<T>* target_set, int k, bool asc_order = false);
		const std::vector<T>* GetNextCombination();	 // when reaching the end, nullptr is returned.
	private:
		//void initIdxInfo();
		void moveToNextIdx(int target_idx, int sel_cnt, int unsel_cnt);
	private:
		CombiIdxMgr mIdxMgr;
		const std::vector<T>* pOrgSet;
		std::vector<T> mvSelection;
};

template <typename T>
CombinationGen<T>::CombinationGen(const std::vector<T>* target_set, int k, bool asc_order)
{
	pOrgSet = target_set;
	mIdxMgr.initIdxInfo((int)target_set->size(), k, asc_order);
}

template <typename T>
const std::vector<T>* CombinationGen<T>::GetNextCombination()
{
	mvSelection.clear();

	if (mIdxMgr.calcNextIdx()) {
		for (int i = 0; i < mIdxMgr.getSelectionVec().size(); i++) {
			if (mIdxMgr.getSelectionVec().at(i))
				mvSelection.push_back(pOrgSet->at(i));
		}
		return &mvSelection;
	}
	else
		return nullptr;
}

#endif
