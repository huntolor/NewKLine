#include "main.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);                 //实例句柄与渲染类关联
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());   // 设置资源的默认路径（此处设置为和exe在同一目录）
	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);     //注册窗口 注册超类 -注册窗口类-创建窗口-handlemessage（WM_CREATE消息处理）
	duiFrame.ShowModal();
	CPaintManagerUI::MessageLoop();                           //处理消息循环
	return 0;
}