#ifndef __COMBI_IDX_MGR__
#define __COMBI_IDX_MGR__

#include <vector>
#include <algorithm>	// for vector copy()

class CombiIdxMgr
{
	public:
		CombiIdxMgr();
		void initIdxInfo(int N, int K, bool order = true);
		bool calcNextIdx();
		const std::vector<bool>& getSelectionVec();
	private:
		void rearrangeTargetArea(int target_idx, int sel_cnt, int unsel_cnt);
	private:
		int iNumN;
		int iNumK;
		bool bInitState;
		bool bAscendingOrder;
		std::vector<bool> SelectionVec;
};

const std::vector<bool>& CombiIdxMgr::getSelectionVec() 
{
	return SelectionVec;
}

CombiIdxMgr::CombiIdxMgr()
{
	iNumN = 0;
	iNumK = 0;
	bInitState = true;
	bAscendingOrder = true;		// Actually, not implemented
}

void CombiIdxMgr::initIdxInfo(int N, int K, bool order) {
	iNumN = N;
	iNumK = K;
	SelectionVec.clear();
	bInitState = true;
	// bAscendingOrder = order;

	if ((iNumN < iNumK) || (iNumN <= 0))
		return;		// Stop when wrong setting

	for (int i = 0; i < iNumN - iNumK; i++)
		SelectionVec.push_back(false);
	for (int k = 0; k < iNumK; k++)
		SelectionVec.push_back(true);
}

bool CombiIdxMgr::calcNextIdx()
{
	if (bInitState) {	// For not skipping 1st array
		bInitState = false;
		return true;
	}

	bool b_sel_found = false;
	int sel_cnt = 0;
	int unsel_cnt = 0;
	for (int cur_idx = SelectionVec.size() - 1; cur_idx >= 0; cur_idx--) {
		if (SelectionVec[cur_idx] == true) {
			b_sel_found = true;
			sel_cnt++;
			continue;
		}
		else {
			if (b_sel_found == false) {
				unsel_cnt++;
				continue;
			}
			else {	// found the target pos
				rearrangeTargetArea(cur_idx, sel_cnt-1, unsel_cnt+1);
				return true;
			}
		}
	}

	return false;	// Reached to the biggest idx
}

void CombiIdxMgr::rearrangeTargetArea(int target_idx, int sel_cnt, int unsel_cnt)
{
	SelectionVec[target_idx++] = true;
	while (unsel_cnt-- > 0)
		SelectionVec[target_idx++] = false;
	while (sel_cnt-- > 0)
		SelectionVec[target_idx++] = true;
}

#endif
