// 引入必要的头文件
#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

// 创建一个窗口类
class Window {
    public:
        // 构造函数，初始化窗口属性
        Window() {
            // 设置窗口标题
            title = "C++程序";
            // 设置窗口宽度和高度
            width = 800;
            height = 600;
            // 设置窗口背景颜色为白色
            background = RGB(255, 255, 255);
        }

        // 显示窗口的方法
        void show() {
            // 创建一个窗口句柄
            HWND hwnd;
            // 定义一个窗口类结构体
            WNDCLASS wc;
            // 获取当前实例句柄
            HINSTANCE hInstance = GetModuleHandle(NULL);
            
            // 填充窗口类结构体的属性
            wc.style = CS_HREDRAW | CS_VREDRAW; // 窗口样式
            wc.lpfnWndProc = WindowProc; // 窗口过程函数指针
            wc.cbClsExtra = 0; // 额外的类内存大小
            wc.cbWndExtra = 0; // 额外的窗口内存大小
            wc.hInstance = hInstance; // 实例句柄
            wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); // 图标句柄
            wc.hCursor = LoadCursor(NULL, IDC_ARROW); // 光标句柄
            wc.hbrBackground = CreateSolidBrush(background); // 背景画刷句柄 
			wc.lpszMenuName = NULL; // 菜单名称指针 
			wc.lpszClassName = "WindowClass"; // 窗口类名称指针

			// 注册窗口类 
			RegisterClass(&wc);

			// 创建窗口 
			hwnd = CreateWindow(
				"WindowClass",   	// 窗口类名称 
				title.c_str(),   	// 窗口标题 
				WS_OVERLAPPEDWINDOW,// 窗口样式 
				CW_USEDEFAULT,  	// 初始x坐标 
				CW_USEDEFAULT,  	// 初始y坐标 
				width,   			// 窗口宽度 
				height,  			// 窗口高度 
				NULL,   			// 父窗口句柄 
				NULL,   			// 菜单句柄 
				hInstance,  		// 实例句柄 
				NULL    			// 额外参数指针  
			);

			if (hwnd == NULL) {  	// 如果创建失败，打印错误信息并退出程序  
				cout << "创建窗口失败: " << GetLastError() << endl;
				exit(1);
			}

			ShowWindow(hwnd, SW_SHOW);  					 	  	  	 	 	 	 	 	          	  	  	  	  	  	  	  	          	 	 	 	          	  	  	          	 	 	          	  	  	          	 	 	          	  	  	          	 	 	          	  	  	          	 	 	          	  
			UpdateWindow(hwnd); 

			
        }

    private:
        string title; 	  	   	   	   	   	   	   	   	   	   	   	   	 
        int width;
        int height;
        COLORREF background;

        
};

// 定义一个窗口过程函数
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    // 根据消息类型进行不同的处理
    switch (uMsg) {
    case WM_DESTROY: // 窗口销毁消息
        PostQuitMessage(0); // 发送退出消息
        return 0;
    case WM_PAINT: // 窗口重绘消息
        PAINTSTRUCT ps; // 定义一个画图结构体
        HDC hdc; // 定义一个设备上下文句柄
        hdc = BeginPaint(hwnd, &ps); // 开始画图

        // 获取当前时间并格式化为字符串
        time_t rawtime;
        struct tm* timeinfo;
        char buffer[80];
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo);

        // 在窗口中央显示时间字符串
        RECT rect; // 定义一个矩形结构体
        GetClientRect(hwnd, &rect); // 获取窗口客户区域大小
        SetTextColor(hdc, RGB(0, 0, 0)); // 设置文本颜色为黑色 
        SetBkMode(hdc, TRANSPARENT);   	// 设置背景模式为透明 
        DrawText(hdc, MultiByteToWideChar(buffer) , -1, &rect,// 绘制文本 
            DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        EndPaint(hwnd, &ps); 			// 结束画图 
        return 0;

    case WM_CHAR: 					// 键盘字符输入消息 
        if (wParam >= '0' && wParam <= '9') {  	// 如果输入的是数字字符  
            int n = wParam - '0'; 				// 转换为整数  
            n *= 2; 							// 计算两倍的值  
            cout << "输入的数字的两倍是: " << n << endl;  	// 打印结果到控制台  
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);// 默认窗口过程函数处理其他消息 
}



// 定义一个主函数
int main() {
    // 创建一个窗口对象
    Window window;
    // 显示窗口
    window.show();

    // 定义一个消息结构体
    MSG msg;
    // 进入消息循环
    while (GetMessage(&msg, NULL, 0, 0)) {
        // 翻译和分发消息
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam; // 返回退出码 
}