#include <UIlib.h>
#include <string>
using namespace DuiLib;
#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_ud.lib")
#   else
#       pragma comment(lib, "DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "DuiLib_u.lib")
#   else
#       pragma comment(lib, "DuiLib.lib")
#   endif
#endif

#define COORDINATE1_LEN 2450
#define COORDINATE2_LEN 2400
#define COORDINATE3_LEN 2350
#define COORDINATE4_LEN 2300
#define COORDINATE5_LEN 2250
#define COORDINATE6_LEN 2200
#define COORDINATE7_LEN 2150
#define COORDINATE8_LEN 2100
#define COORDINATE_DISTANCE 50

//将指数的数值，天数转化为实际坐标
#define GET_X_COORDINATE(X) (((X)*10)+100)
#define GET_Y_COORDINATE(Y) ((COORDINATE1_LEN-(Y))*2)


typedef struct splitData
{
	std::wstring date;
	double open;
	double close;
	double lowest;
	double highest;
}splitData;

//坐标
typedef struct coordinate
{
	int x;
	int y;
}coordinate;


class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual void    Notify(TNotifyUI& msg) {}
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
	void PaintRec(HDC hDC, coordinate Coor1, coordinate Coor2, COLORREF Color);
	void PaintKLine(HDC hDC, coordinate Coor1, coordinate Coor2, COLORREF Color);

protected:
	CPaintManagerUI m_PaintManager;

protected:
	void PaintMA(HDC hDC, COLORREF Color, int MA);
	void PaintXY(HDC hDC);
	void PaintDayK(HDC hDC);
	void Background(HDC hDC);
};
