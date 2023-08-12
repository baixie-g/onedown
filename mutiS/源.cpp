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
//// 计算叉积
//double cross(const Point& A, const Point& B, const Point& C) {
//    return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
//}
//
//// 判断三点是否共线
//bool is_collinear(const Point& A, const Point& B, const Point& C) {
//    return fabs(cross(A, B, C)) < 1e-6;
//}
//
//// 判断三点是否构成逆时针方向
//bool is_ccw(const Point& A, const Point& B, const Point& C) {
//    return cross(A, B, C) > 0;
//}
//
//// 判断点集是否构成凸多边形
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
//// 将凹多边形拆分为若干个凸多边形
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
//// 计算三角形面积
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

// 本程序计算凹多边形的面积
#include <iostream> // 包含输入/输出库
#include <vector> // 包含向量库
#include <cmath> // 包含数学库

using namespace std;

struct Point { // 定义一个点的结构体
    double x, y; // 定义x和y坐标
};

double polygon_area(const vector<Point>& points) { // 定义一个函数来计算多边形的面积
    double area = 0; // 将面积初始化为0
    int n = points.size(); // 获取多边形的顶点数

    for (int i = 0; i < n; i++) { // 循环遍历多边形的每个顶点
        Point p1 = points[i]; // 获取当前顶点
        Point p2 = points[(i + 1) % n]; // 获取下一个顶点
        area += p1.x * p2.y - p2.x * p1.y; // 计算由当前和下一个顶点形成的梯形的面积
    }

    return abs(area / 2.0); // 返回面积的绝对值除以2
}

int main() { // 定义主函数
    int n; // 初始化多边形的顶点数
    cout << "输入多边形的顶点数："; // 提示用户输入多边形的顶点数
    cin >> n; // 获取多边形的顶点数

    vector<Point> points(n); // 初始化一个大小为n的点向量

    for (int i = 0; i < n; i++) { // 循环遍历多边形的每个顶点
        cout << "输入第 " << i + 1 << " 个顶点的x和y坐标："; // 提示用户输入当前顶点的x和y坐标
        cin >> points[i].x >> points[i].y; // 获取当前顶点的x和y坐标
    }

    double area = polygon_area(points); // 计算多边形的面积
    cout << "多边形的面积为：" << area << endl; // 输出多边形的面积

    return 0; // 退出程序
}


//对于凹多边形，可以把它切分成若干个三角形，然后分别计算这些三角形的面积，
//最后求和即可得到凹多边形的面积。
//对于一个三角形 ABC，它的面积可以用向量 AB 和 AC 的叉积来计算：
//area = (AB × AC) / 2，其中 × 表示向量的叉积。
//而三角形 ABC 的有向面积实际上就是点 A、B、C 构成的顺序所决定的，
//因此我们可以通过求取所有相邻点的叉积之和得到凹多边形的面积。
//具体来说，对于凹多边形的 n 个顶点，
//我们依次计算它们相邻的两个点与坐标原点形成的三角形的有向面积之和，最后取绝对值即可。