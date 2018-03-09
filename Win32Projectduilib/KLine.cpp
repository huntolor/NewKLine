#include "KLine.h"
/*
1.数据放入文件
2.从文件中读取数据并检查合法性，合法则放入vector
*/

LPCTSTR lpFilePath = L"E:\\project\\KLineProject\\Debug\\data.txt";
std::vector<splitData> g_Data;

#define BEGIN_INDEX 4

bool IsVaild(splitData& data)
{
	if (data.open > 2450 || data.open < 2100)
		return false;
	if (data.close > 2450 || data.close < 2100)
		return false;
	if (data.lowest > 2450 || data.lowest < 2100)
		return false;
	if (data.highest > 2450 || data.highest < 2100)
		return false;
	return true;
}

void ReadData()
{
	HANDLE hDataFile = INVALID_HANDLE_VALUE;
	if ((hDataFile = CreateFile(lpFilePath, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL)) != INVALID_HANDLE_VALUE)
	{
		int nFileSize = GetFileSize(hDataFile, NULL);
		int nLen = nFileSize + 1;
		DWORD nBytesRead = 0;
		byte *ptr = new byte[nLen];
		if (ReadFile(hDataFile, ptr, nLen, &nBytesRead, NULL))
		{
			std::wstring data = (WCHAR*)ptr;
			while (data.find(L",")!=-1)
			{
				splitData temp;
				double open, close, lowest, highest;
				std::wstring Strdate, StrOpen, StrClose, StrLowest, StrHighest;
				int SymbolFirst, SymbolSecond, SymbolThird, SymbolFourth, SymbolFifth;
				SymbolFirst = data.find(L",");
				SymbolSecond = data.find(L",", SymbolFirst+1);
				SymbolThird = data.find(L",", SymbolSecond + 1);
				SymbolFourth = data.find(L",", SymbolThird + 1);
				SymbolFifth = data.find(L",", SymbolFourth + 1);

				Strdate.assign(data, BEGIN_INDEX, SymbolFirst - BEGIN_INDEX -1);
				StrOpen.assign(data, SymbolFirst + 2, SymbolSecond - SymbolFirst-2);
				StrClose.assign(data, SymbolSecond + 2, SymbolThird - SymbolSecond-2);
				StrLowest.assign(data, SymbolThird + 2, SymbolFourth - SymbolThird-2);
				StrHighest.assign(data, SymbolFourth + 2, SymbolFifth - SymbolFourth-4);

				open = stod(StrOpen,0);
				close = stod(StrClose, 0);
				lowest = stod(StrLowest, 0);
				highest = stod(StrHighest, 0);

				temp = { Strdate, open, close, lowest, highest };
				if (IsVaild(temp))
				{
					g_Data.push_back(temp);
				}
				data.assign(data, SymbolFifth + 1, data.length() - SymbolFifth);
			}
		}
		else
		{
			CloseHandle(hDataFile);
		}
	}
	else
	{
		return;
	}
	CloseHandle(hDataFile);
}


CDuiFrameWnd::CDuiFrameWnd()
{
	CRender = new CRenderEngine();
	pManager = new CPaintManagerUI();
}

CDuiFrameWnd::~CDuiFrameWnd()
{
	delete CRender;
}

//将原使用GDI绘制改为Duilib
void CDuiFrameWnd::PaintXY(HDC hDC)
{
	RECT RcFirst = { 100, 0, 100, 700 };
	RECT RcSecond = { 100, 0, 1000, 700 };
	CRender->DrawLine(hDC, RcFirst, 1, RGB(0, 0, 0), PS_SOLID);
	CRender->DrawLine(hDC, RcSecond, 1, RGB(0, 0, 0), PS_SOLID);


	for (int y = COORDINATE1_LEN; y>=COORDINATE8_LEN; y = y - COORDINATE_DISTANCE)
	{
		RECT RcFirst = { GET_X_COORDINATE(0), GET_Y_COORDINATE(y), GET_X_COORDINATE(0) - 10, GET_Y_COORDINATE(y) };
		CRender->DrawLine(hDC, RcFirst, 1, RGB(0, 0, 0), PS_SOLID);
		
	    std:: wstring str = std::to_wstring(y);
		RECT RcSecond = { GET_X_COORDINATE(0) - 50, GET_Y_COORDINATE(y) - 5, GET_X_COORDINATE(0) - 10, GET_Y_COORDINATE(y) +5};
		CRender->DrawTextW(hDC, pManager, RcSecond, str.c_str(), RGB(0, 0, 0), SYSTEM_FONT, DT_CENTER);
	}
}

//绘制近MA天的K线
void CDuiFrameWnd::PaintMA(HDC hDC, COLORREF Color, int MA)
{
	int nResult = 0;
	RECT Rc = {0,0,0,0};

	for (int i = MA; i < g_Data.size(); ++i)
	{
		for (int j = i - 1; j >= i - MA; --j)
		{
			nResult += g_Data[j].close;
		}

		if (i == MA)
		{
			Rc = { GET_X_COORDINATE(i), GET_Y_COORDINATE(nResult / MA), GET_X_COORDINATE(i), GET_Y_COORDINATE(nResult / MA) };
		}
		else
		{
			CRender->DrawLine(hDC, Rc, 1, Color, PS_SOLID);
			Rc = { Rc.right, Rc.bottom, GET_X_COORDINATE(i), GET_Y_COORDINATE(nResult / MA) };        //rc前两个成员为上一日的点，后两个为当日的点
		}
		nResult = 0;
	}
}


void CDuiFrameWnd::PaintRec(HDC hDC, coordinate Coor1, coordinate Coor2, COLORREF Color)
{
	RECT Rc = { GET_X_COORDINATE(Coor1.x) - 2, GET_Y_COORDINATE(Coor1.y), GET_X_COORDINATE(Coor1.x) + 2, GET_Y_COORDINATE(Coor2.y) };
	CRender->DrawRect(hDC, Rc, 1, RGB(0, 0, 0), PS_SOLID);
}

void CDuiFrameWnd::PaintKLine(HDC hDC, coordinate Coor1, coordinate Coor2, COLORREF Color)
{
	RECT Rc = { GET_X_COORDINATE(Coor1.x), GET_Y_COORDINATE(Coor1.y), GET_X_COORDINATE(Coor2.x), GET_Y_COORDINATE(Coor2.y) };
	CRender->DrawLine(hDC, Rc, 1, Color, PS_SOLID);
}

//日K线
void CDuiFrameWnd::PaintDayK(HDC hDC)       //最高最低直线 开盘收盘矩形
{
	for (int i = 0; i<g_Data.size(); ++i)
	{
		coordinate top = { i, (int)g_Data[i].highest }, bottom = { i, (int)g_Data[i].lowest };
		coordinate open = { i, (int)g_Data[i].open }, close = { i, (int)g_Data[i].close };
		if (open.y > close.y)
		{
			PaintKLine(hDC, top, bottom, RGB(0, 255, 0));
			PaintRec(hDC, close, open, RGB(0, 255, 0));
		}
		else
		{
			PaintKLine(hDC, top, bottom, RGB(255, 0, 0));
			PaintRec(hDC, open, close, RGB(255, 0, 0));
		}
	}
}

void CDuiFrameWnd::Background(HDC hDC)
{
	HPEN gPen = CreatePen(PS_SOLID, 1, RGB(192, 192, 192));
	HBRUSH bBrush = CreateSolidBrush(RGB(192, 192, 192));
	HPEN oPen = (HPEN)SelectObject(hDC, gPen);
	SelectObject(hDC, bBrush);

	Rectangle(hDC, 100, GET_Y_COORDINATE(COORDINATE1_LEN), 1000, GET_Y_COORDINATE(COORDINATE2_LEN));
	Rectangle(hDC, 100, GET_Y_COORDINATE(COORDINATE3_LEN), 1000, GET_Y_COORDINATE(COORDINATE4_LEN));
	Rectangle(hDC, 100, GET_Y_COORDINATE(COORDINATE5_LEN), 1000, GET_Y_COORDINATE(COORDINATE6_LEN));
	Rectangle(hDC, 100, GET_Y_COORDINATE(COORDINATE7_LEN), 1000, GET_Y_COORDINATE(COORDINATE8_LEN));

	if (gPen != NULL)
	{
		DeleteObject(gPen);
	}
}

LRESULT CDuiFrameWnd::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)  //重写HandleMessage处理感兴趣的消息
{
	LRESULT lRes = 0;

	if (uMsg == WM_CREATE)
	{
		m_PaintManager.Init(m_hWnd);

		return lRes;
	}
	if (uMsg == WM_PAINT)
	{
		HDC hDC = m_PaintManager.GetPaintDC();
		PAINTSTRUCT ps;
		hDC = BeginPaint(m_hWnd, &ps);

		Background(hDC);
		PaintXY(hDC);
		PaintMA(hDC, RGB(0, 0, 255), 5);
		PaintMA(hDC, RGB(0, 0, 128), 10);
		PaintMA(hDC, RGB(255, 255, 0), 20);
		PaintMA(hDC, RGB(128, 0, 0), 30);
		PaintDayK(hDC);
		EndPaint(m_hWnd, &ps);
	}

	if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
	{
		return lRes;
	}

	return __super::HandleMessage(uMsg, wParam, lParam);
}