#include "../include/plate_detect.h"

/*! \namespace easypr
    Namespace where all the C++ EasyPR functionality resides
*/
namespace easypr{

CPlateDetect::CPlateDetect()
{
	//cout << "CPlateDetect" << endl;
	m_plateLocate = new CPlateLocate();
	m_plateJudge = new CPlateJudge();
}

void CPlateDetect::LoadSVM(string s)
{
	m_plateJudge->LoadModel(s.c_str());
}

int CPlateDetect::plateDetect(Mat src, vector<Mat>& resultVec)
{
	//可能是车牌的图块集合
	vector<Mat> matVec;

	int resultLo = m_plateLocate->plateLocate(src, matVec);

	if (0 != resultLo)
		return -1;

	int resultJu = m_plateJudge->plateJudge(matVec, resultVec);

	if (0 != resultJu)
		return -1;

	return 0;
}

}	/*! \namespace easypr*/