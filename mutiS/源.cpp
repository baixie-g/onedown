//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//struct Point {
//    double x, y;
//    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
//};
//
//// ������
//double cross(const Point& A, const Point& B, const Point& C) {
//    return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
//}
//
//// �ж������Ƿ���
//bool is_collinear(const Point& A, const Point& B, const Point& C) {
//    return fabs(cross(A, B, C)) < 1e-6;
//}
//
//// �ж������Ƿ񹹳���ʱ�뷽��
//bool is_ccw(const Point& A, const Point& B, const Point& C) {
//    return cross(A, B, C) > 0;
//}
//
//// �жϵ㼯�Ƿ񹹳�͹�����
//bool is_convex(const vector<Point>& points) {
//    int n = points.size();
//    if (n < 3) return false;
//    bool cw = is_ccw(points[0], points[1], points[2]);
//    for (int i = 1; i < n; i++) {
//        if (is_ccw(points[i], points[(i + 1) % n], points[(i + 2) % n]) != cw) {
//            return false;
//        }
//    }
//    return true;
//}
//
//// ��������β��Ϊ���ɸ�͹�����
//vector<vector<Point>> split_polygon(const vector<Point>& points) {
//    int n = points.size();
//    vector<vector<Point>> res;
//    vector<Point> poly;
//    for (int i = 0; i < n; i++) {
//        poly.push_back(points[i]);
//        if (i < n - 2 && !is_ccw(points[i], points[i + 1], points[i + 2])) {
//            res.push_back(poly);
//            poly.clear();
//        }
//    }
//    if (!poly.empty()) res.push_back(poly);
//    return res;
//}
//
//// �������������
//double triangle_area(const Point& A, const Point& B, const Point& C) {
//    double a = hypot(B.x - C.x, B.y - C.y);
//    double b = hypot(C.x - A.x, C.y - A.y);
//    double c = hypot(A.x - B.x, A.y - B.y);
//    double p = (a + b + c) / 2;
//    return sqrt(p * (p - a) * (p - b) * (p - c));
//}
//
//double polygon_area(const vector<Point>& points) {
//    double area = 0.0;
//    int n = points.size();
//    for (int i = 1; i < n - 1; i++) {
//        area += triangle_area(points[0], points[i], points[i + 1]);
//    }
//    return area;
//}
//
//int main() {
//    int n;
//    cout << "Enter the number of points: ";
//    cin >> n;
//    vector<Point> points(n);
//    for (int i = 0; i < n; i++) {
//        double x, y;
//        cout << "Enter x and y coordinates of point " << i + 1 << ": ";
//        cin >> x >> y;
//        points[i] = Point(x, y);
//    }
//    double area = polygon_area(points);
//    cout << "The area of the polygon is " << area << endl;
//    return 0;
//}

// ��������㰼����ε����
#include <iostream> // ��������/�����
#include <vector> // ����������
#include <cmath> // ������ѧ��

using namespace std;

struct Point { // ����һ����Ľṹ��
    double x, y; // ����x��y����
};

double polygon_area(const vector<Point>& points) { // ����һ���������������ε����
    double area = 0; // �������ʼ��Ϊ0
    int n = points.size(); // ��ȡ����εĶ�����

    for (int i = 0; i < n; i++) { // ѭ����������ε�ÿ������
        Point p1 = points[i]; // ��ȡ��ǰ����
        Point p2 = points[(i + 1) % n]; // ��ȡ��һ������
        area += p1.x * p2.y - p2.x * p1.y; // �����ɵ�ǰ����һ�������γɵ����ε����
    }

    return abs(area / 2.0); // ��������ľ���ֵ����2
}

int main() { // ����������
    int n; // ��ʼ������εĶ�����
    cout << "�������εĶ�������"; // ��ʾ�û��������εĶ�����
    cin >> n; // ��ȡ����εĶ�����

    vector<Point> points(n); // ��ʼ��һ����СΪn�ĵ�����

    for (int i = 0; i < n; i++) { // ѭ����������ε�ÿ������
        cout << "����� " << i + 1 << " �������x��y���꣺"; // ��ʾ�û����뵱ǰ�����x��y����
        cin >> points[i].x >> points[i].y; // ��ȡ��ǰ�����x��y����
    }

    double area = polygon_area(points); // �������ε����
    cout << "����ε����Ϊ��" << area << endl; // �������ε����

    return 0; // �˳�����
}


//���ڰ�����Σ����԰����зֳ����ɸ������Σ�Ȼ��ֱ������Щ�����ε������
//�����ͼ��ɵõ�������ε������
//����һ�������� ABC������������������� AB �� AC �Ĳ�������㣺
//area = (AB �� AC) / 2������ �� ��ʾ�����Ĳ����
//�������� ABC ���������ʵ���Ͼ��ǵ� A��B��C ���ɵ�˳���������ģ�
//������ǿ���ͨ����ȡ�������ڵ�Ĳ��֮�͵õ�������ε������
//������˵�����ڰ�����ε� n �����㣬
//�������μ����������ڵ�������������ԭ���γɵ������ε��������֮�ͣ����ȡ����ֵ���ɡ�