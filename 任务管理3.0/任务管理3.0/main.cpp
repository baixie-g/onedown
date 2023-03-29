// �����Ҫ��ͷ�ļ�
#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

// ����һ��������
class Window {
    public:
        // ���캯������ʼ����������
        Window() {
            // ���ô��ڱ���
            title = "C++����";
            // ���ô��ڿ�Ⱥ͸߶�
            width = 800;
            height = 600;
            // ���ô��ڱ�����ɫΪ��ɫ
            background = RGB(255, 255, 255);
        }

        // ��ʾ���ڵķ���
        void show() {
            // ����һ�����ھ��
            HWND hwnd;
            // ����һ��������ṹ��
            WNDCLASS wc;
            // ��ȡ��ǰʵ�����
            HINSTANCE hInstance = GetModuleHandle(NULL);
            
            // ��䴰����ṹ�������
            wc.style = CS_HREDRAW | CS_VREDRAW; // ������ʽ
            wc.lpfnWndProc = WindowProc; // ���ڹ��̺���ָ��
            wc.cbClsExtra = 0; // ��������ڴ��С
            wc.cbWndExtra = 0; // ����Ĵ����ڴ��С
            wc.hInstance = hInstance; // ʵ�����
            wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); // ͼ����
            wc.hCursor = LoadCursor(NULL, IDC_ARROW); // �����
            wc.hbrBackground = CreateSolidBrush(background); // ������ˢ��� 
			wc.lpszMenuName = NULL; // �˵�����ָ�� 
			wc.lpszClassName = "WindowClass"; // ����������ָ��

			// ע�ᴰ���� 
			RegisterClass(&wc);

			// �������� 
			hwnd = CreateWindow(
				"WindowClass",   	// ���������� 
				title.c_str(),   	// ���ڱ��� 
				WS_OVERLAPPEDWINDOW,// ������ʽ 
				CW_USEDEFAULT,  	// ��ʼx���� 
				CW_USEDEFAULT,  	// ��ʼy���� 
				width,   			// ���ڿ�� 
				height,  			// ���ڸ߶� 
				NULL,   			// �����ھ�� 
				NULL,   			// �˵���� 
				hInstance,  		// ʵ����� 
				NULL    			// �������ָ��  
			);

			if (hwnd == NULL) {  	// �������ʧ�ܣ���ӡ������Ϣ���˳�����  
				cout << "��������ʧ��: " << GetLastError() << endl;
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

// ����һ�����ڹ��̺���
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    // ������Ϣ���ͽ��в�ͬ�Ĵ���
    switch (uMsg) {
    case WM_DESTROY: // ����������Ϣ
        PostQuitMessage(0); // �����˳���Ϣ
        return 0;
    case WM_PAINT: // �����ػ���Ϣ
        PAINTSTRUCT ps; // ����һ����ͼ�ṹ��
        HDC hdc; // ����һ���豸�����ľ��
        hdc = BeginPaint(hwnd, &ps); // ��ʼ��ͼ

        // ��ȡ��ǰʱ�䲢��ʽ��Ϊ�ַ���
        time_t rawtime;
        struct tm* timeinfo;
        char buffer[80];
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo);

        // �ڴ���������ʾʱ���ַ���
        RECT rect; // ����һ�����νṹ��
        GetClientRect(hwnd, &rect); // ��ȡ���ڿͻ������С
        SetTextColor(hdc, RGB(0, 0, 0)); // �����ı���ɫΪ��ɫ 
        SetBkMode(hdc, TRANSPARENT);   	// ���ñ���ģʽΪ͸�� 
        DrawText(hdc, MultiByteToWideChar(buffer) , -1, &rect,// �����ı� 
            DT_SINGLELINE | DT_CENTER | DT_VCENTER);

        EndPaint(hwnd, &ps); 			// ������ͼ 
        return 0;

    case WM_CHAR: 					// �����ַ�������Ϣ 
        if (wParam >= '0' && wParam <= '9') {  	// ���������������ַ�  
            int n = wParam - '0'; 				// ת��Ϊ����  
            n *= 2; 							// ����������ֵ  
            cout << "��������ֵ�������: " << n << endl;  	// ��ӡ���������̨  
        }
        return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);// Ĭ�ϴ��ڹ��̺�������������Ϣ 
}



// ����һ��������
int main() {
    // ����һ�����ڶ���
    Window window;
    // ��ʾ����
    window.show();

    // ����һ����Ϣ�ṹ��
    MSG msg;
    // ������Ϣѭ��
    while (GetMessage(&msg, NULL, 0, 0)) {
        // ����ͷַ���Ϣ
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam; // �����˳��� 
}