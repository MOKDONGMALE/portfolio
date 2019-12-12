#include "POSInfoModel.h"

struct PCinfo {
	string m_strID;
	string m_strPW;
	string m_strName;
	int seat;
	int cycle;
	int money;
	int time1;
	int time2;
	int m_nBirth;
};

bool POSInfoModel::LoadTransPOSInfoFile(list<POSInfo>* POSList)
{
	FILE* fp = NULL;
	fopen_s(&fp, FILE_NAME, "rb");
	if (fp == NULL)
		return false;

	int len = 0;
	fread(&len, sizeof(len), 1, fp);
	POSInfo* posinfo = new POSInfo[len]();
	fread(posinfo, sizeof(POSInfo), len, fp);
	fclose(fp);

	for (int i = 0; i < len; i++)
	{
		POSList->push_back(posinfo[i]);
	}

	//delete[] posinfo;

	return true;
}

bool POSInfoModel::SaveTransPOSInfoFile(list<POSInfo>* POSList)
{
	FILE* fp = NULL;
	int len = POSList->size();
	POSInfo* posinfo = new POSInfo[len]();
	list<POSInfo>::iterator it = POSList->begin();
	int i = 0;
	for (; it != POSList->end(); it++) {
		posinfo[i++] = *it;
	}

	fopen_s(&fp, FILE_NAME, "wb");
	if (fp == NULL)
		return false;
	fwrite(&len, sizeof(len), 1, fp);
	fwrite(posinfo, sizeof(POSInfo), 1, fp);
	fclose(fp);

	delete[] posinfo;

	return true;
}

//bool POSInfoModel::LoadPOSInfoFile(list<POSInfo>* POSList)
//{
//	FILE* fp = NULL;
//	fopen_s(&fp, FILE_NAME, "rb");
//	if (fp == NULL)
//		return false;
//
//	while (!feof(fp))
//	{
//		POSInfo pi;
//		char temp[1000];
//		char* ret = 0;
//		
//		ret = fgets(temp, sizeof(temp), fp);
//		if (ret == NULL)
//			break;
//		temp[strlen(temp) - 1] = '\0';
//		pi.SetName(temp);
//
//		fgets(temp, sizeof(temp), fp);
//		temp[strlen(temp) - 1] = '\0';
//		pi.SetID(temp);
//
//		fgets(temp, sizeof(temp), fp);
//		temp[strlen(temp) - 1] = '\0';
//		pi.SetPW(temp);
//
//		int birth = 0;
//		fscanf_s(fp, "%d\n", &birth);
//
//		pi.SetBirth(birth);
//
//		POSList->push_back(pi);
//	}
//	fclose(fp);
//	return true;
//}

//bool POSInfoModel::SavePOSInfoFile(list<POSInfo>* POSList)
//{
//	FILE* fp = NULL;
//	fopen_s(&fp, FILE_NAME, "wb");
//	if (fp == NULL)
//		return false;
//
//	list<POSInfo>::iterator it = POSList->begin();
//	while (it != POSList->end())
//	{
//		fputs(it->GetName().c_str(), fp);		// 문자열 저장
//		fputc('\n', fp);						// 개행 저장
//		fputs(it->GetID().c_str(), fp);
//		fputc('\n', fp);
//		fputs(it->GetPW().c_str(), fp);
//		fputc('\n', fp);
//		fprintf(fp, "%d\n", it->GetBirth());
//
//		it++;
//	}
//	fclose(fp);
//	return true;
//}