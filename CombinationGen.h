#ifndef __COMBINATION_GENERATOR__
#define __COMBINATION_GENERATOR__

#include "CombiIdxMgr.h"

template <typename T>
class CombinationGen
{
	public:
		CombinationGen(const std::vector<T>* target_set, int k, bool asc_order = true);
		const std::vector<T>* GetNextCombination();	 // when reaching the end, nullptr is returned.
	private:
		//void initIdxInfo();
		void moveToNextIdx(int target_idx, int sel_cnt, int unsel_cnt);
	private:
		CombiIdxMgr idxMgr;
		const std::vector<T>* pOrgSet;
		std::vector<T> selectionVec;
};

template <typename T>
CombinationGen<T>::CombinationGen(const std::vector<T>* target_set, int k, bool asc_order)
{
	pOrgSet = target_set;
	idxMgr.initIdxInfo(target_set->size(), k, asc_order);
}

template <typename T>
const std::vector<T>* CombinationGen<T>::GetNextCombination()
{
	selectionVec.clear();

	if (idxMgr.calcNextIdx()) {
		for (int i = 0; i < idxMgr.getSelectionVec().size(); i++) {
			if (idxMgr.getSelectionVec().at(i))
				selectionVec.push_back(pOrgSet->at(i));
		}
		return &selectionVec;
	}
	else
		return nullptr;
}

#endif
