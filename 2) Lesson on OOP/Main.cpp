#include <iostream>
#include <vector>
// �������� ���������� ������� ������.

template<typename Type>

class LinkedList {
public:
	LinkedList();
	LinkedList(int n); // ���� � ��� ���������� n ���������� 
	LinkedList(const LinkedList &other);
	LinkedList(LinkedList &&other); // ����� �� ������, �� ��� ����������� �������� ������ ��������� ������� 
	// ��� �� ����� ���������� ������������ �� ������ �������������, ����� ����� 

	~LinkedList();

	// ������������ ������������ 
	LinkedList& operator = (const LinkedList &other);

	// ������������ ���������
	LinkedList& operator = (LinkedList &&other);


	Type & operator[](int i);
	const Type& operator[](int i) const;

	Type &at(int i);
	const Type &at(int i) const;

	void push_back(const Type& obj); // �������� ����� ������� � ����� ������
	void push_front(const Type& obj); // �������� ����� ������� � ������ ������

	void pop_back(); // ���������� ������ � ����� ������
	void pop_front(); // ���������� ������ � ������ ������

	/*
	 emplace (�����)/insert (�����) - ��� ������ ����� ������ � ������������ ����� ���������
	 erise - ��� ����� ��� ����������� ������ � ������������ ����� ���������
	*/

	int size()const;

	/*
	 ������ ��� ������� �� ��������� ������ ����������� �� ���� ����������� �������
	*/

private:
	class Node {
	public:
		Node() :Node(Type()) {} // ��� ��������� �� �������� ����������� �� ��������� ��������� ���� ������.
		// ������ ��������� ��������� ������������ ���� ���� ������ ����� ������ ������ 
		// (�������� ������������ ���������� �����) ����������.
		Node(const Type& data, Node* place = nullptr) :data_(data), next_(place) {}

		Type& Data() {
			return data_;
		}
		const Type& Data() const {
			return data_;
		}

		Node* Next() const { // �������������� ���������� ��� ���������� � �������������� ��������� �����
			return next_;
		}

		void Next(Node *next) { // �������� ������ �������� ��� ��������� �����
			next_ = next;
		}

	private:
		Type data_;
		Node* next_;
		

		Node* start_;
		Node* end_;
		int size_;
	};

};

int main() {
	setlocale(LC_ALL, "rus");
	int arr[10];
	std::vector<int>vec(10);
	LinkedList<int> list;
	arr[5] = 34;
	vec[5] = 23;
	list[5] = 12;



























	return 0;
}