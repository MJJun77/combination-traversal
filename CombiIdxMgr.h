#ifndef __COMBI_IDX_MGR__
#define __COMBI_IDX_MGR__

#include <vector>

class CombiIdxMgr
{
	public:
		CombiIdxMgr();
		void initIdxInfo(int N, int K, bool ascOrder = true);
		bool calcNextIdx();
		const std::vector<bool>& getSelectionVec();
	private:
		void rearrangeTargetArea(int target_idx, int sel_cnt, int unsel_cnt);
	private:
		int miNumN;
		int miNumK;
		bool mbInitState;
		bool mbAscendingOrder;
		std::vector<bool> mvSelection;
};

#endif
