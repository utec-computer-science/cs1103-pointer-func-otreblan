// Bubble
// Copyright © 2020 otreblan
//
// integer is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// integer is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with integer.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
using namespace std;

void * _bubblesort_(
	void * _array_,
	void (*_puntero_) (void *, int _i, int _k),
	int _tam_
){
	for (int i = 0; i < _tam_ ; ++i)
		for(int k = 0; k < _tam_-i-1; ++k)
		{
			_puntero_(_array_,k,k+1);
		}
	return _array_;
}

template <typename T>
void _b_void_(T* _vector_, int _i, int _k)
{
	if(_vector_[_k] < _vector_[_i])
	{
		swap(_vector_[_k], _vector_[_i]);
	}
}

void  _b_int_ (void * _vector_, int _i,int _k){
	_b_void_((int*)_vector_, _i, _k);
}

void  _b_float_ (void * _vector_, int _i,int _k){
	_b_void_((float*)_vector_, _i, _k);
}

void  _b_double_ (void * _vector_, int _i,int _k){
	_b_void_((double*)_vector_, _i, _k);
}

void  _b_char_ (void * _vector_, int _i,int _k){
	_b_void_((char*)_vector_, _i, _k);
}

template <typename T>
void print(T* _vector_, size_t size)
{
	for(size_t i = 0; i < size; ++i)
	{
		std::cout << _vector_[i] << '\n';
	}
	std::cout << '\n';
}

int main(){
	int _array_1 [5] = {2,20,7,108,9}; // RANDOMS
	float _array_2 [5] = {4.4,5.4,9.1,7.4,2.2};
	double _array_3 [5] = {3.0,8.0,2.0,4.0,15.0};
	char _array_4 [6] = {'k','a','r','l','o','s'};

	_bubblesort_(_array_1,_b_int_,5);
	print(_array_1, 5);

	_bubblesort_(_array_2,_b_float_,5);
	print(_array_2, 5);

	_bubblesort_(_array_3,_b_double_,5);
	print(_array_3, 5);

	_bubblesort_(_array_4,_b_char_,6);
	print(_array_4, 6);

	return 0;
}
