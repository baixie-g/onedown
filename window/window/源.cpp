//#include <Windows.h>
//#include <string>
//
//// ȫ�ֱ���
//HWND main_window_handle;  // ����Ĵ��ھ��
//HWND child_window_handle; // �´��ڵľ��
//const int ID_CHILD_BUTTON = 1001;
//const int ID_CHILD_EDIT = 1002;
//const int ID_MAIN_EDIT = 1003;
//
//// ��������
//LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
//LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
//void CreateChildWindow();
//void AddTextToMainWindow(int num);
//
//// ������
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//    // ע����������
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
//    // ����������
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
//    // ��ʾ������
//    ShowWindow(main_window_handle, nCmdShow);
//    UpdateWindow(main_window_handle);
//
//    // ��Ϣѭ��
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
//// �����ڹ��̺���
//LRESULT CALLBACK MainWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//    switch (msg)
//    {
//    case WM_CREATE:
//    {
//        // �������򿪴��ڡ���ť
//        CreateWindow(
//            L"BUTTON",
//            L"�򿪴���",
//            WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
//            10, 10, 80, 30,
//            hWnd,
//            (HMENU)ID_CHILD_BUTTON,
//            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
//            NULL);
//
//        // ����������ʾʱ��ľ�̬�ı���
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
//        // ���ö�ʱ���Ը���ʱ��
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
//        // ����ʱ��
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
//// �Ӵ��ڹ��̺���
//LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//    switch (msg)
//    {
//    case WM_CREATE:
//    {
//        // ���������������ֵı༭��
//        CreateWindow(
//            L"EDIT",
//            L"",
//            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_NUMBER,
//            10, 10, 80, 30,
//            hWnd,
//            (HMENU)ID_CHILD_EDIT,
//            (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
//            NULL)
//            // �������ύ����ť
//            CreateWindow(
//                L"BUTTON",
//                L"�ύ",
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
//            // ��ȡ��������
//            wchar_t input_text[10];
//            GetWindowText(GetDlgItem(hWnd, ID_CHILD_EDIT), input_text, 10);
//            int input_num = _wtoi(input_text);
//
//            // ��������������ı���
//            AddTextToMainWindow(input_num * 2);
//
//            // �ر��Ӵ���
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
//// �����Ӵ���
//void CreateChildWindow()
//{
//    if (child_window_handle == NULL)
//    {
//        // ע���Ӵ�����
//        WNDCLASSEX wc = { 0 };
//        wc.cbSize = sizeof(WNDCLASSEX);
//        wc.style = CS_HREDRAW | CS_VREDRAW;
//        wc.lpfnWndProc = ChildWndProc;
//        wc.hInstance = (HINSTANCE)GetWindowLong(main_window_handle, GWL_HINSTANCE);
//        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
//        wc.lpszClassName = L"ChildWndClass";
//        RegisterClassEx(&wc);
//        // �����Ӵ���
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
//        // ��ʾ�Ӵ���
//        ShowWindow(child_window_handle, SW_SHOW);
//        UpdateWindow(child_window_handle);
//    }
//}
//
//// ��������������ı���
//void AddTextToMainWindow(int num)
//{
//    wchar_t num_text[10];
//    swprintf_s(num_text, L"%d", num);
//    // �����ı���
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
//    // ���ý���
//    SetFocus(edit_handle);
//
//    // ѡ���ı�
//    SendMessage(edit_handle, EM_SETSEL, 0, -1);
//
//    // ���������
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
//    // ע�ᴰ����
//    WNDCLASS wc = {};
//    wc.lpfnWndProc = WndProc;
//    wc.hInstance = hInstance;
//    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
//    wc.lpszClassName = L"MyWindowClass";
//    RegisterClass(&wc);
//
//    // ����������
//    HWND hWnd = CreateWindow(L"MyWindowClass", L"ʱ��", WS_OVERLAPPEDWINDOW,
//        CW_USEDEFAULT, CW_USEDEFAULT, 320, 240, NULL, NULL, hInstance, NULL);
//
//    // ���������Ͱ�ť
//    HWND hEdit = CreateWindow(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER,
//        10, 50, 100, 20, hWnd, NULL, hInstance, NULL);
//    HWND hButton = CreateWindow(L"BUTTON", L"�ύ", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
//        120, 50, 50, 20, hWnd, NULL, hInstance, NULL);
//
//    // ������ʱ��
//    SetTimer(hWnd, ID_TIMER, 1000, NULL);
//
//    // ��ʾ����
//    ShowWindow(hWnd, nCmdShow);
//    UpdateWindow(hWnd);
//
//    // ��Ϣѭ��
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
//        // �����������
//        hResultWnd = CreateWindow(L"STATIC", L"", WS_CHILD | WS_VISIBLE | SS_CENTER,
//            10, 80, 100, 20, hWnd, NULL, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
//        break;
//    case WM_COMMAND:
//        if (HIWORD(wParam) == BN_CLICKED)
//        {
//            if ((HWND)lParam == GetDlgItem(hWnd, 2))
//            {
//                // ��ȡ������е�����
//                WCHAR buf[100] = {};
//                GetWindowText(GetDlgItem(hWnd, 1), buf, 100);
//                int num = _wtoi(buf);
//
//                // �����������
//                WCHAR result[100] = {};
//                swprintf_s(result, L"%d", num * 2);
//                MessageBox(hWnd, result, L"���", MB_OK);
//            }
//        }
//        break;
//    case WM_TIMER:
//        if (wParam == ID_TIMER)
//        {
//            // ����ʱ�Ӵ����ϵ�ʱ��
//            SYSTEMTIME st = {};
//            GetLocalTime(&st);
//            WCHAR buf[100] = {};
//            swprintf_s(buf, L"%02d:%02d:%02d", st.wHour, st.wMinute, st.wSecond);
//            SetWindowText(hWnd, buf);
//        }
//        break;
//    case WM_DESTROY:
//        // ���ٽ������
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
//// ����һ������
//HWND hwnd = CreateWindow(
//    L"WindowClass", // ��������
//    L"My Window", // ���ڱ���
//    WS_OVERLAPPEDWINDOW, // ������ʽ
//    CW_USEDEFAULT, CW_USEDEFAULT, // ����λ��
//    500, 400, // ���ڴ�С
//    NULL, // �����ھ��
//    NULL, // �˵����
//    hInstance, // Ӧ�ó���ʵ�����
//    NULL); // ��������
//
//// ���ô��ڱ�����ɫΪ��ɫ
//HDC hdc = GetDC(hwnd); // ��ȡ�豸�����ľ��
//RECT rect; // ����һ�����νṹ��
//GetClientRect(hwnd, &rect); // ��ȡ���ڿͻ������С��λ��
//FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1)); // ���ͻ�����Ϊ��ɫ
//
//// ����һ������򣨵��б༭�ؼ���
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
//// ����һ���ύ��ť�����Ͱ�ť�ؼ���
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
//// �ڴ�������ʾʱ��
//SYSTEMTIME st; // ����һ��ϵͳʱ��ṹ��
//GetSystemTime(&st); // ��ȡ��ǰϵͳʱ��
//WCHAR szTime[20]; // ����һ�����ַ�����
//wsprintf(szTime, L"%02d:%02d:%02d", st.wHour, st.wMinute, st.wSecond); // ��ʽ��ʱ���ַ���
//TextOut(hdc, 10, 40, szTime, wcslen(szTime)); // ���豸�������л����ı�
//
//// ����һ���Ի���
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
//// �����´��ڲ���ʾ��������ֵ�����
//case WM_COMMAND: // ��������Ϣ
//{
//    if (LOWORD(wParam) == ID_BUTTON) // �ж��Ƿ��ǰ�ť�����
//    {
//        int len = GetWindowTextLength(hEdit); // ��ȡ������е��ı�����
//        WCHAR* buffer = new WCHAR[len + 1]; // ����һ����̬�������洢�ı�����
//        GetWindowText(hEdit, buffer, len + 1); // ��ȡ������е��ı�����
//        int num = _wtoi(buffer); // �����ַ�ת��Ϊ����
//        delete[] buffer; // �ͷŶ�̬�����ڴ�
//
//        DialogBox(hInstance,
//            MAKEINTRESOURCE(IDD_DIALOG),
//            hwnd,
//            DialogProc); // ��������ʾһ���Ի���
//
//        HWND hStatic = GetDlgItem(hwndDlg, IDC_STATIC); // ��ȡ�Ի����о�̬�ؼ��ľ��
//
//        WCHAR szResult[20]; // ����һ�����ַ��������洢�������ַ���
//        wsprintf(szResult, L"%d", num * 2); // ��ʽ���������ַ���
//
//        SetWindowText(hStatic, szResult); // ���þ�̬�ؼ��е��ı�����Ϊ�������ַ���
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
//    // ע�ᴰ����
//    WNDCLASS wc = {};
//    wc.lpfnWndProc = WindowProc;
//    wc.hInstance = hInstance;
//    wc.lpszClassName = "MyWindowClass";
//    RegisterClass(&wc);
//
//    // ��������
//    HWND hwnd = CreateWindowEx(0, "MyWindowClass", "My Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, hInstance, NULL);
//    if (hwnd == NULL)
//    {
//        return 0;
//    }
//
//    // ��ʾ����
//    ShowWindow(hwnd, nCmdShow);
//
//    // ������Ϣѭ��
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
//        // ���ñ���ɫΪ��ɫ
//        SetBkColor(hdc, RGB(255, 255, 255));
//
//        // ��ȡ��ǰʱ��
//        SYSTEMTIME st;
//        GetLocalTime(&st);
//        char timeString[20];
//        sprintf_s(timeString, "%02d:%02d:%02d", st.wHour, st.wMinute, st.wSecond);
//
//        // �ڴ������Ļ���ʱ���ı�
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
//        // ����û�������һ��������ô����һ���Ի������û�����һ������
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
