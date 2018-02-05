#include "KLine.h"
//一组数据
splitData g_Data[] = { { L"2013/1/24", 2320.26, 2320.26, 2287.3, 2362.94 }, { L"2013/1/25", 2300, 2291.3, 2288.26, 2308.38 }, { L"2013/1/28", 2295.35, 2346.5, 2295.35, 2346.92 },
{ L"2013/1/29", 2347.22, 2358.98, 2337.35, 2363.8 }, { L"2013/1/30", 2360.75, 2382.48, 2347.89, 2383.76 }, { L"2013/1/31", 2383.43, 2385.42, 2371.23, 2391.82 },
{ L"2013/2/1", 2377.41, 2419.02, 2369.57, 2421.15 }, { L"2013/1/4", 2425.92, 2428.15, 2417.58, 2440.38 }, { L"2013/2/5", 2411, 2433.13, 2403.3, 2437.42 },
{ L"2013/2/6", 2432.68, 2434.48, 2427.7, 2441.73 }, { L"2013/2/7", 2430.69, 2418.53, 2394.22, 2433.89 }, { L"2013/2/8", 2416.62, 2432.4, 2414.4, 2443.03 },
{ L"2013/2/18", 2441.91, 2421.56, 2415.43, 2444.8 }, { L"2013/2/19", 2420.26, 2382.91, 2373.53, 2427.07 }, { L"2013/2/20", 2383.49, 2397.18, 2370.61, 2397.94 },
{ L"2013/2/21", 2378.82, 2325.95, 2309.17, 2378.82 }, { L"2013/2/22", 2322.94, 2314.16, 2308.76, 2330.88 }, { L"2013/2/25", 2320.62, 2325.82, 2315.01, 2338.78 },
{ L"2013/2/26", 2313.74, 2293.34, 2289.89, 2340.71 }, { L"2013/2/27", 2297.77, 2313.22, 2292.03, 2324.63 }, { L"2013/2/28", 2322.32, 2365.59, 2308.92, 2366.16 },
{ L"2013/3/1", 2364.54, 2359.51, 2330.86, 2369.65 }, { L"2013/3/4", 2332.08, 2273.4, 2259.25, 2333.54 }, { L"2013/3/5", 2274.81, 2326.31, 2270.1, 2328.14 },
{ L"2013/3/6", 2333.61, 2347.18, 2321.6, 2351.44 }, { L"2013/3/7", 2340.44, 2324.29, 2304.27, 2352.02 }, { L"2013/3/8", 2326.42, 2318.61, 2314.59, 2333.67 },
{ L"2013/3/11", 2314.68, 2310.59, 2296.58, 2320.96 }, { L"2013/3/12", 2309.16, 2286.6, 2264.83, 2333.29 }, { L"2013/3/13", 2282.17, 2263.97, 2253.25, 2286.33 },
{ L"2013/3/14", 2255.77, 2270.28, 2253.31, 2276.22 }, { L"2013/3/15", 2269.31, 2278.4, 2250, 2312.08 }, { L"2013/3/18", 2267.29, 2240.02, 2239.21, 2276.05 },
{ L"2013/3/19", 2244.26, 2257.43, 2232.02, 2261.31 }, { L"2013/3/20", 2257.74, 2317.37, 2257.42, 2317.86 }, { L"2013/3/21", 2318.21, 2324.24, 2311.6, 2330.81 },
{ L"2013/3/22", 2321.4, 2328.28, 2314.97, 2332 }, { L"2013/3/25", 2334.74, 2326.72, 2319.91, 2344.89 }, { L"2013/3/26", 2318.58, 2297.67, 2281.12, 2319.99 },
{ L"2013/3/27", 2299.38, 2301.26, 2289, 2323.48 }, { L"2013/3/28", 2273.55, 2236.3, 2232.91, 2273.55 }, { L"2013/3/29", 2238.49, 2236.62, 2228.81, 2246.87 },
{ L"2013/4/1", 2229.46, 2234.4, 2227.31, 2243.95 }, { L"2013/4/2", 2234.9, 2227.74, 2220.44, 2253.42 }, { L"2013/4/3", 2232.69, 2225.29, 2217.25, 2241.34 },
{ L"2013/4/8", 2196.24, 2211.59, 2180.67, 2212.59 }, { L"2013/4/9", 2215.47, 2225.77, 2215.47, 2234.73 }, { L"2013/4/10", 2224.93, 2226.13, 2212.56, 2233.04 },
{ L"2013/4/11", 2236.98, 2219.55, 2217.26, 2242.48 }, { L"2013/4/12", 12218.09, 2206.78, 2204.44, 10026.26 }, { L"2013/4/15", 2199.91, 2181.94, 2177.39, 2204.99 },
{ L"2013/4/16", 2169.63, 2194.85, 2165.78, 2196.43 }, { L"2013/4/17", 2195.03, 2193.8, 2178.47, 2197.51 }, { L"2013/4/18", 2181.82, 2197.6, 2175.44, 2206.03 },
{ L"2013/4/19", 2201.12, 2244.64, 2200.58, 2250.11 }, { L"2013/4/22", 2236.4, 2242.17, 2232.26, 2245.12 }, { L"2013/4/23", 2242.62, 2184.54, 2182.81, 2242.62 },
{ L"2013/4/24", 2187.35, 2218.32, 2184.11, 2226.12 }, { L"2013/4/25", 2213.19, 2199.31, 2191.85, 2224.63 }, { L"2013/4/26", 2203.89, 2177.91, 2173.86, 2210.58 },
{ L"2013/5/2", 2170.78, 2174.12, 2161.14, 2179.65 }, { L"2013/5/3", 2179.05, 2205.5, 2179.05, 2222.81 }, { L"2013/5/6", 2212.5, 2231.17, 2212.5, 2236.07 },
{ L"2013/5/7", 2227.86, 2235.57, 2219.44, 2240.26 }, { L"2013/5/8", 2242.39, 2246.3, 2235.42, 2255.21 }, { L"2013/5/9", 2246.96, 2232.97, 2221.38, 2247.86 },
{ L"2013/5/10", 2228.82, 2246.83, 2225.81, 2247.67 }, { L"2013/5/13", 2247.68, 2241.92, 2231.36, 2250.85 }, { L"2013/5/14", 2238.9, 2217.01, 2205.87, 2239.93 },
{ L"2013/5/15", 2217.09, 2224.8, 2213.58, 2225.19 }, { L"2013/5/16", 2221.34, 2251.81, 2210.77, 2252.87 }, { L"2013/5/17", 2249.81, 2282.87, 2248.41, 2288.09 },
{ L"2013/5/20", 2286.33, 2299.99, 2281.9, 2309.39 }, { L"2013/5/21", 2297.11, 2305.11, 2290.12, 2305.3 }, { L"2013/5/22", 2303.75, 2302.4, 2292.43, 2314.18 },
{ L"2013/5/23", 2293.81, 2275.67, 2274.1, 2304.95 }, { L"2013/5/24", 2281.45, 2288.53, 2270.25, 2292.59 }, { L"2013/5/27", 2286.66, 2293.08, 2283.94, 2301.7 },
{ L"2013/5/28", 2293.4, 2321.32, 2281.47, 2322.1 }, { L"2013/5/29", 2323.54, 2324.02, 2321.17, 2334.33 }, { L"2013/5/30", 2316.25, 2317.75, 2310.49, 2325.72 },
{ L"2013/5/31", 2320.74, 2300.59, 2299.37, 2325.53 }, { L"2013/6/3", 2300.21, 2299.25, 2294.11, 2313.43 }, { L"2013/6/4", 2297.1, 2272.42, 2264.76, 2297.1 },
{ L"2013/6/5", 2270.71, 2270.93, 2260.87, 2276.86 }, { L"2013/6/6", 2264.43, 2242.11, 2240.07, 2266.69 }, { L"2013/6/7", 2242.26, 2210.9, 2205.07, 2250.63 },
{ L"2013/6/13", 2190.1, 2148.35, 2126.22, 2190.1 } };

void CDuiFrameWnd::PaintXY(HDC hDC)
{
	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	HPEN hPenOld = (HPEN)SelectObject(hDC, hPen);
	MoveToEx(hDC, 100, 0, NULL);
	LineTo(hDC, 100, 700);
	LineTo(hDC, 1000, 700);

	for (int y = COORDINATE1_LEN; y>=COORDINATE8_LEN; y = y - COORDINATE_DISTANCE)
	{
		MoveToEx(hDC, GET_X_COORDINATE(0), GET_Y_COORDINATE(y), NULL);
		LineTo(hDC, GET_X_COORDINATE(0) - 10, GET_Y_COORDINATE(y));
		
		std:; wstring str = std::to_wstring(y);
		SetTextColor(hDC, RGB(0, 0, 0));
		TextOutW(hDC, GET_X_COORDINATE(0) - 50, GET_Y_COORDINATE(y), str.data(), str.length());
	}
	DeleteObject(hPen);
	DeleteObject(hPenOld);
}

//绘制近MA天的K线
void CDuiFrameWnd::PaintMA(HDC hDC, COLORREF Color, int MA)
{
	HPEN hPen = CreatePen(PS_SOLID, 1, Color);
	HPEN hPenOld = (HPEN)SelectObject(hDC, hPen);
	int nResult = 0;
	for (int i = MA; i < sizeof(g_Data) / sizeof(splitData); ++i)
	{
		for (int j = i - 1; j >= i - MA; --j)
		{
			nResult += g_Data[j].close;
		}
		if (i == MA)
		{
			MoveToEx(hDC, GET_X_COORDINATE(i), GET_Y_COORDINATE(nResult / MA), NULL);
		}
		else
		{
			LineTo(hDC, GET_X_COORDINATE(i), GET_Y_COORDINATE(nResult / MA));
		}
		nResult = 0;
	}
	DeleteObject(hPen);
	DeleteObject(hPenOld);
}


void CDuiFrameWnd::PaintRec(HDC hDC, coordinate Coor1, coordinate Coor2, COLORREF Color)
{
	HPEN gPen = CreatePen(PS_SOLID, 1, RGB(0,0,0));
	HBRUSH bBrush = CreateSolidBrush(Color);
	HPEN oPen = (HPEN)SelectObject(hDC, gPen);
	SelectObject(hDC, bBrush);
	Rectangle(hDC, GET_X_COORDINATE(Coor1.x) - 2, GET_Y_COORDINATE(Coor1.y), GET_X_COORDINATE(Coor1.x) + 2, GET_Y_COORDINATE(Coor2.y));
	DeleteObject(gPen);
	DeleteObject(oPen);
}

void CDuiFrameWnd::PaintKLine(HDC hDC, coordinate Coor1, coordinate Coor2, COLORREF Color)
{
	HPEN hPen = CreatePen(PS_SOLID, 1, Color);
	HPEN hPenOld = (HPEN)SelectObject(hDC, hPen);
	MoveToEx(hDC, GET_X_COORDINATE(Coor1.x), GET_Y_COORDINATE(Coor1.y), NULL);
	LineTo(hDC, GET_X_COORDINATE(Coor2.x), GET_Y_COORDINATE(Coor2.y));
	DeleteObject(hPen);
	DeleteObject(hPenOld);
}


void CDuiFrameWnd::PaintDayK(HDC hDC)       //最高最低直线 开盘收盘矩形
{
	for (int i = 0; i<sizeof(g_Data) / sizeof(splitData); ++i)
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

	DeleteObject(gPen);
	DeleteObject(oPen);
}

LRESULT CDuiFrameWnd::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
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