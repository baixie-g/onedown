//#include <Windows.h>
//#include <string>
//
//// 全局变量
//HWND main_window_handle;  // 最初的窗口句柄
//HWND child_window_handle; // 新窗口的句柄
//const int ID_CHILD_BUTTON = 1001;
//const int ID_CHILD_EDIT = 1002;
//const int ID_MAIN_EDIT = 1003;
//
//// 函数声明
//LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
//LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
//void CreateChildWindow();
//void AddTextToMainWindow(int num);
//
//// 主函数
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//    // 注册主窗口类
//    WNDCLASSEX wc = { 0 };
//    wc.cbSize = sizeof(WNDCLASSEX);
//    wc.style = CS_HREDRAW | CS_VREDRAW;
//    wc.lpfnWndProc = MainWndProc;
//    wc.hInstance = hInstance;
//    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
//    wc.lpszClassName = L"MainWndClass";
//    RegisterClassEx(&wc);
//
//    // 创建主窗口
//    main_window_handle = CreateWindowEx(
//        0,
//        L"MainWndClass",
//        L"Main Window",
//        WS_OVERLAPPEDWINDOW,
//        CW_USEDEFAULT, CW_USEDEFAULT,
//        400, 300,
//        NULL, NULL, hInstance, NULL);
//
//    if (main_window_handle == NULL)
//    {
//        return 1;
//    }
//
//    // 显示主窗口
//    ShowWindow(main_window_handle, nCmdShow);
//    UpdateWindow(main_window_handle);
//
//    // 消息循环
//    MSG msg = { 0 };
//    while (GetMessage(&msg, NULL, 0, 0))
//    {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//    }
//
//    return msg.wParam;
//}
//
//// 主窗口过程函数
//LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//    switch (msg)
//    {
//    case WM_CREATE:
//    {
//        // 创建“打开窗口”按钮
//        CreateWindow(
//            L"BUTTON",
//            L"打开窗口",
//            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
//            10, 10, 80, 30,
//            hWnd,
//            (HMENU)ID_CHILD_BUTTON,
//            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
//            NULL);
//
//        // 创建用于显示时间的静态文本框
//        CreateWindow(
//            L"STATIC",
//            L"",
//            WS_VISIBLE | WS_CHILD | SS_CENTER,
//            0, 50, 400, 50,
//            hWnd,
//            NULL,
//            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
//            NULL);
//
//        // 设置定时器以更新时间
//        SetTimer(hWnd, 1, 1000, NULL);
//
//        break;
//    }
//    case WM_COMMAND:
//    {
//        switch (LOWORD(wParam))
//        {
//        case ID_CHILD_BUTTON:
//            CreateChildWindow();
//            break;
//        }
//
//        break;
//    }
//    case WM_TIMER:
//    {
//        // 更新时间
//        SYSTEMTIME st;
//        GetLocalTime(&st);
//        wchar_t time_text[9];
//        swprintf_s(time_text, L"%02d:%02d:%02d", st.wHour, st.wMinute, st.wSecond);
//        SetWindowText(GetDlgItem(hWnd, ID_MAIN_EDIT), time_text);
//
//        break;
//    }
//    case WM_DESTROY:
//    {
//        PostQuitMessage(0);
//        break;
//    }
//    default:
//        return DefWindowProc(hWnd, msg, wParam, lParam);
//    }
//
//    return 0;
//}
//
//// 子窗口过程函数
//LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//    switch (msg)
//    {
//    case WM_CREATE:
//    {
//        // 创建用于输入数字的编辑框
//        CreateWindow(
//            L"EDIT",
//            L"",
//            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER,
//            10, 10, 80, 30,
//            hWnd,
//            (HMENU)ID_CHILD_EDIT,
//            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
//            NULL)
//            // 创建“提交”按钮
//            CreateWindow(
//                L"BUTTON",
//                L"提交",
//                WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
//                100, 10, 80, 30,
//                hWnd,
//                (HMENU)1,
//                (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
//                NULL);
//
//        break;
//    }
//    case WM_COMMAND:
//    {
//        switch (LOWORD(wParam))
//        {
//        case 1:
//        {
//            // 获取输入数字
//            wchar_t input_text[10];
//            GetWindowText(GetDlgItem(hWnd, ID_CHILD_EDIT), input_text, 10);
//            int input_num = _wtoi(input_text);
//
//            // 在主窗口中添加文本框
//            AddTextToMainWindow(input_num * 2);
//
//            // 关闭子窗口
//            DestroyWindow(hWnd);
//
//            break;
//        }
//        }
//
//        break;
//    }
//    case WM_DESTROY:
//    {
//        child_window_handle = NULL;
//        break;
//    }
//    default:
//        return DefWindowProc(hWnd, msg, wParam, lParam);
//    }
//
//    return 0;
//}
//
//// 创建子窗口
//void CreateChildWindow()
//{
//    if (child_window_handle == NULL)
//    {
//        // 注册子窗口类
//        WNDCLASSEX wc = { 0 };
//        wc.cbSize = sizeof(WNDCLASSEX);
//        wc.style = CS_HREDRAW | CS_VREDRAW;
//        wc.lpfnWndProc = ChildWndProc;
//        wc.hInstance = (HINSTANCE)GetWindowLong(main_window_handle, GWL_HINSTANCE);
//        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
//        wc.lpszClassName = L"ChildWndClass";
//        RegisterClassEx(&wc);
//        // 创建子窗口
//        child_window_handle = CreateWindowEx(
//            0,
//            L"ChildWndClass",
//            L"Child Window",
//            WS_OVERLAPPEDWINDOW,
//            CW_USEDEFAULT, CW_USEDEFAULT,
//            400, 300,
//            main_window_handle, NULL, (HINSTANCE)GetWindowLong(main_window_handle, GWL_HINSTANCE), NULL);
//        if (child_window_handle == NULL)
//        {
//            return;
//        }
//
//        // 显示子窗口
//        ShowWindow(child_window_handle, SW_SHOW);
//        UpdateWindow(child_window_handle);
//    }
//}
//
//// 在主窗口中添加文本框
//void AddTextToMainWindow(int num)
//{
//    wchar_t num_text[10];
//    swprintf_s(num_text, L"%d", num);
//    // 创建文本框
//    HWND edit_handle = CreateWindow(
//        L"EDIT",
//        num_text,
//        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY | ES_CENTER,
//        10, 100, 80, 30,
//        main_window_handle,
//        (HMENU)ID_MAIN_EDIT,
//        (HINSTANCE)GetWindowLong(main_window_handle, GWL_HINSTANCE),
//        NULL);
//
//    if (edit_handle == NULL)
//    {
//        return;
//    }
//
//    // 设置焦点
//    SetFocus(edit_handle);
//
//    // 选中文本
//    SendMessage(edit_handle, EM_SETSEL, 0, -1);
//
//    // 滚动到最后
//    SendMessage(edit_handle, EM_SCROLLCARET, 0, 0);
//}















//
//#include <windows.h>
//#include <string>
//using namespace std;
//
//const int ID_TIMER = 1;
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//    // 注册窗口类
//    WNDCLASS wc = {};
//    wc.lpfnWndProc = WndProc;
//    wc.hInstance = hInstance;
//    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
//    wc.lpszClassName = L"MyWindowClass";
//    RegisterClass(&wc);
//
//    // 创建主窗口
//    HWND hWnd = CreateWindow(L"MyWindowClass", L"时钟", WS_OVERLAPPEDWINDOW,
//        CW_USEDEFAULT, CW_USEDEFAULT, 320, 240, NULL, NULL, hInstance, NULL);
//
//    // 创建输入框和按钮
//    HWND hEdit = CreateWindow(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER,
//        10, 50, 100, 20, hWnd, NULL, hInstance, NULL);
//    HWND hButton = CreateWindow(L"BUTTON", L"提交", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
//        120, 50, 50, 20, hWnd, NULL, hInstance, NULL);
//
//    // 启动定时器
//    SetTimer(hWnd, ID_TIMER, 1000, NULL);
//
//    // 显示窗口
//    ShowWindow(hWnd, nCmdShow);
//    UpdateWindow(hWnd);
//
//    // 消息循环
//    MSG msg = {};
//    while (GetMessage(&msg, NULL, 0, 0))
//    {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//    }
//    return (int)msg.wParam;
//}
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    static HWND hResultWnd = NULL;
//    switch (message)
//    {
//    case WM_CREATE:
//        // 创建结果窗口
//        hResultWnd = CreateWindow(L"STATIC", L"", WS_CHILD | WS_VISIBLE | SS_CENTER,
//            10, 80, 100, 20, hWnd, NULL, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
//        break;
//    case WM_COMMAND:
//        if (HIWORD(wParam) == BN_CLICKED)
//        {
//            if ((HWND)lParam == GetDlgItem(hWnd, 2))
//            {
//                // 获取输入框中的数字
//                WCHAR buf[100] = {};
//                GetWindowText(GetDlgItem(hWnd, 1), buf, 100);
//                int num = _wtoi(buf);
//
//                // 弹出结果窗口
//                WCHAR result[100] = {};
//                swprintf_s(result, L"%d", num * 2);
//                MessageBox(hWnd, result, L"结果", MB_OK);
//            }
//        }
//        break;
//    case WM_TIMER:
//        if (wParam == ID_TIMER)
//        {
//            // 更新时钟窗口上的时间
//            SYSTEMTIME st = {};
//            GetLocalTime(&st);
//            WCHAR buf[100] = {};
//            swprintf_s(buf, L"%02d:%02d:%02d", st.wHour, st.wMinute, st.wSecond);
//            SetWindowText(hWnd, buf);
//        }
//        break;
//    case WM_DESTROY:
//        // 销毁结果窗口
//        KillTimer(hWnd, ID_TIMER);
//        PostQuitMessage(0);
//        break;
//    default:
//        return DefWindowProc(hWnd, message, wParam, lParam);
//    }
//    return 0;
//}
//
//
//
//
//
//
//
//// 创建一个窗口
//HWND hwnd = CreateWindow(
//    L"WindowClass", // 窗口类名
//    L"My Window", // 窗口标题
//    WS_OVERLAPPEDWINDOW, // 窗口样式
//    CW_USEDEFAULT, CW_USEDEFAULT, // 窗口位置
//    500, 400, // 窗口大小
//    NULL, // 父窗口句柄
//    NULL, // 菜单句柄
//    hInstance, // 应用程序实例句柄
//    NULL); // 附加数据
//
//// 设置窗口背景颜色为白色
//HDC hdc = GetDC(hwnd); // 获取设备上下文句柄
//RECT rect; // 定义一个矩形结构体
//GetClientRect(hwnd, &rect); // 获取窗口客户区域大小和位置
//FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1)); // 填充客户区域为白色
//
//// 创建一个输入框（单行编辑控件）
//HWND hEdit = CreateWindowEx(
//    WS_EX_CLIENTEDGE,
//    L"EDIT",
//    L"",
//    WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
//    10, 10,
//    200, 20,
//    hwnd,
//    (HMENU)ID_EDIT,
//    hInstance,
//    NULL);
//
//// 创建一个提交按钮（推送按钮控件）
//HWND hButton = CreateWindow(
//    L"BUTTON",
//    L"Submit",
//    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
//    220,
//    10,
//    100,
//    20,
//    hwnd,
//    (HMENU)ID_BUTTON,
//    hInstance,
//    NULL);
//
//
//
//
//
//
//
//
//
//
//
//
//
//// 在窗口上显示时间
//SYSTEMTIME st; // 定义一个系统时间结构体
//GetSystemTime(&st); // 获取当前系统时间
//WCHAR szTime[20]; // 定义一个宽字符数组
//wsprintf(szTime, L"%02d:%02d:%02d", st.wHour, st.wMinute, st.wSecond); // 格式化时间字符串
//TextOut(hdc, 10, 40, szTime, wcslen(szTime)); // 在设备上下文中绘制文本
//
//// 创建一个对话框
//INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam,
//    LPARAM lParam)
//{
//    switch (uMsg)
//    {
//    case WM_INITDIALOG:
//        return TRUE;
//    case WM_COMMAND:
//        switch (LOWORD(wParam))
//        {
//        case IDOK:
//            EndDialog(hDlg, IDOK);
//            return TRUE;
//        case IDCANCEL:
//            EndDialog(hDlg, IDCANCEL);
//            return TRUE;
//        }
//        break;
//    }
//    return FALSE;
//}
//
//// 弹出新窗口并显示输入的数字的两倍
//case WM_COMMAND: // 处理窗口消息
//{
//    if (LOWORD(wParam) == ID_BUTTON) // 判断是否是按钮被点击
//    {
//        int len = GetWindowTextLength(hEdit); // 获取输入框中的文本长度
//        WCHAR* buffer = new WCHAR[len + 1]; // 分配一个动态数组来存储文本内容
//        GetWindowText(hEdit, buffer, len + 1); // 获取输入框中的文本内容
//        int num = _wtoi(buffer); // 将宽字符转换为整数
//        delete[] buffer; // 释放动态数组内存
//
//        DialogBox(hInstance,
//            MAKEINTRESOURCE(IDD_DIALOG),
//            hwnd,
//            DialogProc); // 创建并显示一个对话框
//
//        HWND hStatic = GetDlgItem(hwndDlg, IDC_STATIC); // 获取对话框中静态控件的句柄
//
//        WCHAR szResult[20]; // 定义一个宽字符数组来存储计算结果字符串
//        wsprintf(szResult, L"%d", num * 2); // 格式化计算结果字符串
//
//        SetWindowText(hStatic, szResult); // 设置静态控件中的文本内容为计算结果字符串
//
//    }
//}
//break;


//
//#include <iostream>
//#include <windows.h>
//
//using namespace std;
//
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//    // 注册窗口类
//    WNDCLASS wc = {};
//    wc.lpfnWndProc = WindowProc;
//    wc.hInstance = hInstance;
//    wc.lpszClassName = "MyWindowClass";
//    RegisterClass(&wc);
//
//    // 创建窗口
//    HWND hwnd = CreateWindowEx(0, "MyWindowClass", "My Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, hInstance, NULL);
//    if (hwnd == NULL)
//    {
//        return 0;
//    }
//
//    // 显示窗口
//    ShowWindow(hwnd, nCmdShow);
//
//    // 进入消息循环
//    MSG msg = {};
//    while (GetMessage(&msg, NULL, 0, 0))
//    {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//    }
//
//    return 0;
//}
//
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//    switch (uMsg)
//    {
//    case WM_PAINT:
//    {
//        PAINTSTRUCT ps;
//        HDC hdc = BeginPaint(hwnd, &ps);
//
//        // 设置背景色为白色
//        SetBkColor(hdc, RGB(255, 255, 255));
//
//        // 获取当前时间
//        SYSTEMTIME st;
//        GetLocalTime(&st);
//        char timeString[20];
//        sprintf_s(timeString, "%02d:%02d:%02d", st.wHour, st.wMinute, st.wSecond);
//
//        // 在窗口中心绘制时间文本
//        RECT rect;
//        GetClientRect(hwnd, &rect);
//        DrawText(hdc, timeString, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
//
//        EndPaint(hwnd, &ps);
//        break;
//    }
//
//    case WM_DESTROY:
//    {
//        PostQuitMessage(0);
//        break;
//    }
//
//    case WM_KEYDOWN:
//    {
//        // 如果用户按下了一个键，那么弹出一个对话框，让用户输入一个数字
//        if (wParam == VK_RETURN)
//        {
//            int number;
//            char buffer[256];
//            MessageBox(hwnd, "Please enter a number:", "Input", MB_OK);
//            GetWindowText(GetForegroundWindow(), buffer, sizeof(buffer));
//            number = atoi(buffer);
//            int result = number * 2;
//            char message[256];
//            sprintf_s(message, "The result is %d", result);
//            MessageBox(hwnd, message, "Result", MB_OK);
//        }
//        break;
//    }
//
//    default:
//    {
//        return DefWindowProc(hwnd, uMsg, wParam, lParam);
//    }
//    }
//
//    return 0;
//}
