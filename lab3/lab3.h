#include <iostream>

template <typename T>
class DList
{
	struct Node
	{
		T data_;
		Node *next_;
		Node *prev_;
		Node(const T &data = T{}, Node *next = nullptr, Node *prev = nullptr)
		{
			data_ = data;
			next_ = next;
			prev_ = prev;
		}
	};
	Node *front_;
	Node *back_;

public:
	DList()
	{
		front_ = nullptr;
		back_ = nullptr;
	}
	void push_front(const T &data);
	void push_back(const T &data);
	void pop_front();
	void pop_back();
	int getData(int data[]) const;
	int getReverseData(int data[]) const;
	~DList();
};

template <typename T>
void DList<T>::push_front(const T &data)
{
	Node *new_node = new Node(data, front_, nullptr);
	if (front_ != nullptr)
	{
		front_->prev_ = new_node;
	}
	else
	{
		back_ = new_node;
	}
	front_ = new_node;
}

template <typename T>
void DList<T>::push_back(const T &data)
{
	Node *new_node = new Node(data, nullptr, nullptr);
	if (!(front_))
	{
		front_ = new_node;
	}
	else if (back_)
	{
		new_node->prev_ = back_;
		back_->next_ = new_node;
	}
	back_ = new_node;
}

template <typename T>
void DList<T>::pop_front()
{
	Node *remove_node = front_;
	front_ = remove_node->next_;
	if (!front_)
	{
		back_ = nullptr;
	}
	else
	{
		front_->prev_ = nullptr;
	}
	delete remove_node;
}

template <typename T>
void DList<T>::pop_back()
{
	Node *remove_node = back_;
	back_ = remove_node->prev_;
	if (!back_)
	{
		front_ = nullptr;
	}
	else
	{
		back_->next_ = nullptr;
	}
	delete remove_node;
}
template <typename T>
int DList<T>::getData(int data[]) const
{
	Node *curr = front_;
	int numData = 0;
	while (curr != nullptr)
	{
		data[numData++] = curr->data_;
		curr = curr->next_;
	}
	return numData;
}
template <typename T>
int DList<T>::getReverseData(int data[]) const
{
	Node *curr = back_;
	int numData = 0;
	while (curr != nullptr)
	{
		data[numData++] = curr->data_;
		curr = curr->prev_;
	}
	return numData;
}
template <typename T>
DList<T>::~DList()
{
	Node *current = front_;
	Node *next;

	while (current != nullptr)
	{
		next = current->next_;
		delete current;
		current = next;
	}
}
template <typename T>
class Sentinel{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data=T{},Node* next=nullptr, Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* front_;
	Node* back_;
public:
	Sentinel(){
		front_=new Node();
		back_=new Node();
		front_->next_=back_;
		back_->prev_=front_;
	}
	void push_front(const T& data);
	void push_back(const T& data);
	void pop_front();
	void pop_back();
	int getData(int data[]) const;
	int getReverseData(int data[]) const;
	~Sentinel();
};


template <typename T>
void Sentinel<T>::push_front(const T& data){

}

template <typename T>
void Sentinel<T>::push_back(const T& data){

}

template <typename T>
void Sentinel<T>::pop_front(){

}

template <typename T>
void Sentinel<T>::pop_back(){

}

template <typename T>
int Sentinel<T>::getData(int data[]) const{
	Node* curr=front_->next_;
	int numData=0;
	while(curr!=back_){
		data[numData++]=curr->data_;
		curr=curr->next_;
	}
	return numData;
}

template <typename T>
int Sentinel<T>::getReverseData(int data[]) const{
	Node* curr=back_->prev_;
	int numData=0;
	while(curr!=front_){
		data[numData++]=curr->data_;
		curr=curr->prev_;
	}
	return numData;
}

template <typename T>
Sentinel<T>::~Sentinel(){

}
