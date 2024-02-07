#include <iostream>
#include <vector>
// Создание шаблонного связног списка.

template<typename Type>

class LinkedList {
public:
	LinkedList();
	LinkedList(int n); // лист с уже созданными n элементами 
	LinkedList(const LinkedList &other);
	LinkedList(LinkedList &&other); // можно не делать, но для оптимизации скозости работы программы полезно 
	// тут не будет реализации конструктора от списка инициализации, внесём позже 

	~LinkedList();

	// присваивание копированием 
	LinkedList& operator = (const LinkedList &other);

	// присваивание переносом
	LinkedList& operator = (LinkedList &&other);


	Type & operator[](int i);
	const Type& operator[](int i) const;

	Type &at(int i);
	const Type &at(int i) const;

	void push_back(const Type& obj); // добавить новый элемент в конец списка
	void push_front(const Type& obj); // добавить новый элемент в начало списка

	void pop_back(); // уничтожить данные в конце списка
	void pop_front(); // уничтожить данные в начале списка

	/*
	 emplace (новое)/insert (копия) - это методы новых данных в произвольное место коллекции
	 erise - это метод для уничтожения данных в произвольной точке коллекции
	*/

	int size()const;

	/*
	 методы для прохода по коллекции умными указателями мы пока сознательно опустим
	*/

private:
	class Node {
	public:
		Node() :Node(Type()) {} // при делигации мы вызываем конструктор по умолчанию хранимого типа данных.
		// Данный синтаксис корректно отрабатывает даже если прямой вызов такого метода 
		// (например конструктора встроенных типов) недоступен.
		Node(const Type& data, Node* place = nullptr) :data_(data), next_(place) {}

		Type& Data() {
			return data_;
		}
		const Type& Data() const {
			return data_;
		}

		Node* Next() const { // предоставление информации для информации о местоположении следующей точки
			return next_;
		}

		void Next(Node *next) { // устанока нового значения для следующей точки
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