#pragma once
#include<iostream>
#include<list>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class SetByList {
private:
	Node* head;
	int size;

public:
	SetByList():head(NULL),size(0){
		
	}
	friend istream& operator>>(istream& in, SetByList& s) {
		int data;
		while (in >> data) {
			s.add(data);
		}
		return in;
	}
	SetByList(const SetByList& other) {
		this->head = NULL;
		this->size = 0;
		Node* temp = other.head;
		while (temp != NULL) {
			this->add(temp->data);
			temp = temp->next;
		}
	}
	~SetByList() {
		Node* temp = head;
		while (temp != NULL) {
			Node* temp2 = temp;
			temp = temp->next;
			delete temp2;
		}
	}
	void add(int data) {
		if (head == NULL) {
			head = new Node(data);
			size++;
			return;
		}
		Node* temp = head;
		while (temp->next != NULL) {
			if (temp->data == data) {
				return;
			}
			temp = temp->next;
		}
		if (temp->data == data) {
			return;
		}
		temp->next = new Node(data);
		size++;
	}
	void remove(int data) {
		if (head == NULL) {
			return;
		}
		Node* temp = head;
		if (temp->data == data) {
			head = temp->next;
			delete temp;
			size--;
			return;
		}
		while (temp->next != NULL) {
			if (temp->next->data == data) {
				Node* temp2 = temp->next;
				temp->next = temp->next->next;
				delete temp2;
				size--;
				return;
			}
			temp = temp->next;
		}
	}
	bool contains(int data) const {
		for (Node* curr = head; curr != nullptr; curr = curr->next)
			if (curr->data == data) return true;
		return false;
	}
	int getSize() const {
		return size;
	}
	void print() const {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	SetByList operator+(const SetByList& other) const {
		SetByList result;
		for (Node* curr = head; curr != nullptr; curr = curr->next)
			result.add(curr->data);
		for (Node* curr = other.head; curr != nullptr; curr = curr->next)
			result.add(curr->data);
		return result;
	}
	SetByList operator*(const SetByList& other) const {
		SetByList result;
		for (Node* curr = head; curr != nullptr; curr = curr->next)
			if (other.contains(curr->data)) result.add(curr->data);
		return result;
	}
	SetByList operator-(const SetByList& other) const {
		SetByList result;
		for (Node* curr = head; curr != nullptr; curr = curr->next)
			if (!other.contains(curr->data)) result.add(curr->data);
		return result;
	}
	bool operator==(const SetByList& other) const {
		if (size != other.size) return false;
		for (Node* curr = head; curr != nullptr; curr = curr->next)
			if (!other.contains(curr->data)) return false;
		return true;
	}
	SetByList& operator=(const SetByList& other) {
		if (this == &other) return *this;
		Node* temp = head;
		while (temp != NULL) {
			Node* temp2 = temp;
			temp = temp->next;
			delete temp2;
		}
		head = NULL;
		size = 0;
		Node* temp3 = other.head;
		while (temp3 != NULL) {
			this->add(temp3->data);
			temp3 = temp3->next;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const SetByList& s) {
		out << "{";
		for (Node* curr = s.head; curr != nullptr; curr = curr->next) {
			out << curr->data;
			if (curr->next != nullptr) out << ", ";
		}
		out << "}";
		out << endl;
		return out;
	}
};

//在这个示例代码中， << 运算符重载函数是用于将集合对象以字符串的形式输出到标准输出流的。该函数接受两个参数：一个是 ostream 对象，表示输出流；另一个是 const Set & 类型的集合对象，表示需要输出的集合。
//
//在函数实现中，首先会在输出流中插入左括号{ ，然后遍历集合中的每个元素，将其输出到输出流中，并在元素之间插入逗号和空格。最后，在输出流中插入右括号 }，并返回输出流对���的引用，以便支持多个输出语句的级联调用。
//具体地说，在 Set 类中，重载了加号、乘号和减号等运算符时，为了实现这些运算符的操作，需要访问集合对象的私有成员（如链表头指针和大小），但是这些运算符本身不属于集合类的成员函数。因此，我们就需要使用 friend 关键字来声明这些运算符为当前类的友元函数，以便它们可以在不违反访问控制规则的前提下访问集合对象的私有成员。
//而 result 则是在加号、乘号、减号等运算符重载函数中定义的用于存储运算结果的临时变量。由于这些运算符都是双目运算符，需要同时操作两个集合，因此需要在函数内部创建一个新的 Set 对象来存储运算结果。具体地说，在加号运算符重载函数中，定义的 result 变量用于存储两个集合的并集；在乘号运算符重载函数中，定义的 result 变量用于存储两个集合的交集；在减号运算符重载函数中，定义的 result 变量用于存储两个集合的差集。最后，这些运算符函数都通过返回 result 变量来返回最终的运算结果。
//operator= 函数：需要先删除当前对象中的所有元素，然后将另一个对象中的所有元素插入到当前对象中。由于需要遍历另一个集合，所以时间复杂度为 O(n)，其中 n 为集合大小。由于没有额外的空间开销，空间复杂度为 O(1)。
//operator<< 函数：需要遍历一个集合中的所有元素，并将它们输出到标准输出流中。由于每个元素只会被输出一次，所以时间复杂度为 O(n)，其中 n 为集合大小。不需要额外的空间，空间复杂度为 O(1)。
//综上所述，这个算法的时间复杂度和空间复杂度都与集合大小相关，具体取决于所执行的操作。其中最耗时和最占空间的是 operator+ 和 operator* 函数，在最坏情况下的时间复杂度分别为 O(m + n) 和 O(mn)，空间复杂度分别为 O(m + n) 和 O(min(m, n))。
//operator+ 函数：需要遍历两个集合中的所有元素，将它们插入到一个新的集合中。由于每个元素只会被插入一次，所以时间复杂度为 O(m + n)，其中 m 和 n 分别为两个集合的大小。由于需要创建一个新的集合对象来存储结果，空间复杂度为 O(m + n)。
//operator* 函数：需要遍历一个集合中的所有元素，并检查它们是否在另一个集合中出现。由于需要遍历两个集合，所以时间复杂度为 O(mn)，其中 m 和 n 分别为两个集合的大小。由于需要创建一个新的集合对象来存储结果，空间复杂度为 O(min(m, n))。
//operator- 函数：需要遍历一个集合中的所有元素，并检查它们是否在另一个集合中出现。由于需要遍历两个集合，所以时间复杂度为 O(mn)，其中 m 和 n 分别为两个集合的大小。由于需要创建一个新的集合对象来存储结果，空间复杂度为 O(m)。
//insert 函数：由于需要查找元素是否已经存在，所以时间复杂度为 O(n)，其中 n 为集合大小。由于每个插入操作都需要创建一个新的节点，因此空间复杂度为 O(1)。
//contains 函数：由于需要遍历整个链表来查找元素，所以时间复杂度为 O(n)，其中 n 为集合大小。不需要额外的空间，空间复杂度为 O(1)。
//remove 函数：与 contains 函数类似，也需要遍历链表来查找元素，并在找到元素后删除它。因此时间复杂度为 O(n)，空间复杂度为 O(1)。
//getSize 函数：只需要返回记录集合大小的变量，时间复杂度为 O(1)，空间复杂度为 O(1)。
