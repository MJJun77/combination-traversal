#include "CombiIdxMgr.h"

const std::vector<bool>& CombiIdxMgr::getSelectionVec() 
{
	return mvSelection;
}

CombiIdxMgr::CombiIdxMgr()
{
	miNumN = 0;
	miNumK = 0;
	mbInitState = true;
	mbAscendingOrder = true;
}

void CombiIdxMgr::initIdxInfo(int N, int K, bool ascOrder) {
	miNumN = N;
	miNumK = K;
	mvSelection.clear();
	mbInitState = true;
	mbAscendingOrder = ascOrder;

	if ((miNumN < miNumK) || (miNumN <= 0))
		return;		// Stop when wrong setting

	if (mbAscendingOrder)
	{
		for (int i = 0; i < miNumN - miNumK; i++)
			mvSelection.push_back(false);
		for (int k = 0; k < miNumK; k++)
			mvSelection.push_back(true);
	}
	else
	{
		for (int k = 0; k < miNumK; k++)
			mvSelection.push_back(true);
		for (int i = 0; i < miNumN - miNumK; i++)
			mvSelection.push_back(false);
	}
}

bool CombiIdxMgr::calcNextIdx()
{
	if (mbInitState) {	// For not skipping 1st array
		mbInitState = false;
		return true;
	}

	bool b_pivot_found = false;
	int sel_cnt = 0;
	int unsel_cnt = 0;

	if (mbAscendingOrder)
	{
		for (int cur_idx = (int)mvSelection.size() - 1; cur_idx >= 0; cur_idx--) {
			if (mvSelection[cur_idx] == true) {
				b_pivot_found = true;
				sel_cnt++;
				continue;
			}
			else {
				if (b_pivot_found == false) {
					unsel_cnt++;
					continue;
				}
				else {	// found the target pos: Found initial 0 -> 1 position
					rearrangeTargetArea(cur_idx, sel_cnt-1, unsel_cnt+1);
					return true;
				}
			}
		}
	}
	else // Descending order
	{
		for (int cur_idx = (int)mvSelection.size() - 1; cur_idx >= 0; cur_idx--) {
			if (mvSelection[cur_idx] == false) {
				b_pivot_found = true;
				unsel_cnt++;
				continue;
			}
			else {
				if (b_pivot_found == false) {
					sel_cnt++;
					continue;
				}
				else {	// found the target pos: Found initial 1 -> 0 position
					rearrangeTargetArea(cur_idx, sel_cnt+1, unsel_cnt-1);
					return true;
				}
			}
		}
	}

	return false;	// Reached to the smallest/largest index order
}

void CombiIdxMgr::rearrangeTargetArea(int target_idx, int sel_cnt, int unsel_cnt)
{
	if (mbAscendingOrder)
	{
		mvSelection[target_idx++] = true;
		while (unsel_cnt-- > 0)
			mvSelection[target_idx++] = false;
		while (sel_cnt-- > 0)
			mvSelection[target_idx++] = true;
	}
	else
	{
		mvSelection[target_idx++] = false;
		while (sel_cnt-- > 0)
			mvSelection[target_idx++] = true;
		while (unsel_cnt-- > 0)
			mvSelection[target_idx++] = false;
	}
}
