//Malvestio Andrea mat: 2032464
#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

template<typename T>
MyVector<T>::MyVector(std::initializer_list<T> l)
{
	if(l.size() >= this->max_size) this->reserve(l.size()*2);
	else this->elem = new T[max_size];
	std::copy(l.begin(), l.end(), elem);
	this->size = l.size();
}

template<typename T>
MyVector<T>::MyVector(size_t s){
	this->size = 0;
	this->elem = new T[s];
	this->max_size = s;
}

template<typename T>
MyVector<T>::MyVector(MyVector& vec)
	: size{vec.size}, max_size{vec.max_size}
{
	this->elem = new T[vec.max_size];
	std::copy(vec.elem, vec.elem + this->size, this->elem);
}

template<typename T>
MyVector<T>::MyVector(MyVector&& vec)
	: size{vec.size}, elem{vec.elem}, max_size{vec.max_size}
{
	vec.size = 0;
	vec.elem = nullptr;
}

template<typename T>
void MyVector<T>::reserve(size_t new_size)
{
	if(this->max_size < new_size){
		T* p = new T[new_size];
		if(size > 0) {
			std::copy(this->elem, this->elem + this->size, p);
			delete[] elem;
		}
		elem = p;
		this->max_size=new_size;
	}
	else return;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& vec)
{
	T* p = new T [vec.max_size];
	std::copy(vec.elem, vec.elem + vec.size , p);
	delete[] elem;
	elem = p;
	size = vec.size;
	max_size = vec.max_size;
	return *this;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& vec){
	delete[] elem;
	elem = vec.elem;
	size = vec.size;
	max_size = vec.max_size;
	vec.elem = nullptr;
	vec.size = 0;
	vec.max_size = 0;
	return *this;
}

template<typename T>
T& MyVector<T>::at(int n)
{
	if(n > this->max_size) throw OutOfBoundsException(std::to_string(n));
	else return elem[n];
}

template<typename T>
T MyVector<T>::at(int n) const
{
	if(n > this->max_size) throw OutOfBoundsException(std::to_string(n));
	else return elem[n];
}

template<typename T>
std::ostream& operator<<(std::ostream& os,const MyVector<T>& vec)
{
	os << "[ ";
	for(int i=0; i< vec.getSize(); i++){
		os << vec[i] << " ";
	}
	os << "]\n";
	return os;
}

template<typename T>
T MyVector<T>::safe_get(unsigned int n) const
{
	if(n < this->size) return elem[n];
	else{
		throw OutOfBoundsException(std::to_string(n));
		return 0;
	}
}

template<typename T>
bool MyVector<T>::safe_set(unsigned int n, T value)
{
	if(n < this->size -1){
		elem[n] = value;
		return true;
	}
	else{
		throw OutOfBoundsException(std::to_string(n));
		return false;
	}
}

template<typename T>
void MyVector<T>::push_back(T n)
{
	if(size >= max_size){
		this->reserve(max_size*2);
	}
	size++;
	this->at(size-1) = n;
}

template<typename T>
MyVector<T>& MyVector<T>::pop_back()
{
	if(this != nullptr)
	{
		if(size > 0){
			--size;
			auto p = new T[max_size];
			std::copy(elem, elem + size, p);
			delete[] elem;
			elem = p;
			return *this;
		}
		else throw OutOfBoundsException(std::to_string(size));
	}
	else return *this;
}


OutOfBoundsException::OutOfBoundsException(std::string s)
	:message{s} {}

std::string OutOfBoundsException::printError()
{
	return message;
}

#endif