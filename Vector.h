#ifndef VECTOR
#define VECTOR
#include <iostream>
#include <array>
#include <vector>
#include <cstdarg>
#include <string.h>

using namespace std;


template<typename T1, int T2>
class Vector {

private:
	T1* TypeOfElement;
	int SizeOfVector = T2;
	//T1 Elem;

public:
	Vector() : TypeOfElement(new T1[T2]), SizeOfVector(T2) {}//default constructor

	Vector(T1 elem) {

		this->TypeOfElement = new T1[SizeOfVector];

		for (int i = 0; i < SizeOfVector; i++)
		{
			TypeOfElement[i] = elem;
		}
	}//initialization constructor

	Vector(const Vector <T1, T2>& otherVector) {

		this->SizeOfVector = otherVector.SizeOfVector;
		this->TypeOfElement = new T1[otherVector.SizeOfVector];

		for (int i = 0; i < otherVector.SizeOfVector; i++)
		{
			this->TypeOfElement[i] = otherVector.TypeOfElement[i];
		}

	}//copy constructor

	~Vector() {
		delete[] TypeOfElement;
		//cout << "called destructor    " << this  <<  endl;
	}



	T1* GetType() const
	{
		return TypeOfElement;
	}

	void SetType(T1 value) const // alternative: void SetType(T1* value) const {delete[] TypeOfElement; TypeOfElement = value;}
	{

		for (size_t i = 0; i < SizeOfVector; i++)
		{
			TypeOfElement[i] = value;
		}
	}

	const void Print() const {
		for (int i = 0; i < SizeOfVector; i++)
		{
			cout << this->TypeOfElement[i] << "\t";
		}
		cout << endl;
	}

	int GetSize()
	{
		cout << SizeOfVector << endl;
		return SizeOfVector;
	}


	void operator= (Vector<T1, T2> other) {
		for (int i = 0; i < SizeOfVector; i++)
		{
			this->TypeOfElement[i] = other[i];
		}
	}

	T1& operator[] (int i) {
		if (i < 0) {
			i = this->SizeOfVector + i;
		}

		return TypeOfElement[i];
	}

	template <typename TB>
	friend const Vector<T1, T2> operator+ (Vector<T1, T2>& a, Vector<TB, T2>& b)
	{
		Vector<T1, T2> res(0);

		for (int i = 0; i < T2; i++)
		{
			res[i] = a[i] + (T1)b[i];
		}

		return res;
	}


	template <typename TB>
	friend const Vector<T1, T2> operator+ (Vector<T1, T2>& a,  TB b)
	{
		Vector<T1, T2> res(0);

		for (int i = 0; i < T2; i++)
		{
			res[i] = a[i] + (T1)b;
		}

		return res;
	}

	template <typename TB>
	friend const Vector<T1, T2> operator- (Vector<T1, T2>& a, Vector<TB, T2>& b)
	{
		Vector<T1, T2> res(0);

		for (int i = 0; i < T2; i++)
		{
			res[i] = a[i] - (T1)b[i];
		}

		return res;
	}

	template <typename TB>
	friend const Vector<T1, T2> operator- (Vector<T1, T2>& a, TB b)
	{
		Vector<T1, T2> res(0);

		for (int i = 0; i < T2; i++)
		{
			res[i] = a[i] - (T1)b;
		}

		return res;
	}

	template <typename TB>
	friend const Vector<T1, T2> operator* (Vector<T1, T2>& a, Vector<TB, T2>& b)
	{
		Vector<T1, T2> res(0);

		for (int i = 0; i < T2; i++)
		{
			res[i] = a[i] * (T1)b[i];
		}

		return res;
	}

	template <typename TB>
	friend const Vector<T1, T2> operator* (Vector<T1, T2>& a, TB b)
	{
		Vector<T1, T2> res(0);

		for (int i = 0; i < T2; i++)
		{
			res[i] = a[i] * (T1)b;
		}

		return res;
	}

	template <typename TB>
	friend const Vector<T1, T2> operator/ (Vector<T1, T2>& a, Vector<TB, T2>& b)
	{
		Vector<T1, T2> res(0);

		for (int i = 0; i < T2; i++)
		{
			res[i] = a[i] / (T1)b[i];
		}

		return res;
	}

	template <typename TB>
	friend const Vector<T1, T2> operator/ (Vector<T1, T2>& a, TB b)
	{
		Vector<T1, T2> res(0);

		for (int i = 0; i < T2; i++)
		{
			res[i] = a[i] / (T1)b;
		}

		return res;
	}

	template<int  T_Size>
	const Vector<T1, T_Size> resize()
	{
		T1 values = 0;
		Vector <T1, T_Size> vec(0);
		for (size_t i = 0; i < T2; i++)
		{
			vec[i] = this->TypeOfElement[i];
		}
		for (size_t i = T2; i < T_Size; i++)
		{
			vec[i] = values;
		}
		//vec.Print();
		return vec;
	}

	template<typename T_other>
	const Vector<T_other, T2> convert()
	{
		Vector<T_other, T2> vec(0);
		for (size_t i = 0; i < T2; i++)
		{
			vec[i] = this->TypeOfElement[i];
		}
		return vec;
	}

	template<int T1_slice, int T2_slice>
	const Vector<T1, (T1_slice < 0 && T2_slice < 0) ?
		(
			((T2 + T1_slice) < (T2 + T2_slice)) ?
			(
				(T2 + T2_slice) - (T2 + T1_slice) + 1
				) :
			(
				(T2 + T1_slice) - (T2 + T2_slice) + 1
				)
			) :

		(

			(T1_slice < 0) ?
			(
				((T2 + T1_slice) < T2_slice) ?
				(
					T2_slice - (T2 + T1_slice) + 1
					) :
				(
					(T2 + T1_slice) - T2_slice + 1
					)
				) :
			(T2_slice < 0) ?
			(
				(T1_slice < (T2 + T2_slice)) ?
				(
					(T2 + T2_slice) - T1_slice + 1
					) :
				(
					T1_slice - (T2 + T2_slice) + 1
					)
			):
			(
					(T1_slice < T2_slice) ?
					(T2_slice - T1_slice + 1) : (T1_slice - T2_slice + 1)
				)
			) > slice() const

	{
		
		Vector<T1, T2> vec(0);
		Vector <T1, (T1_slice < 0 && T2_slice < 0) ?
			(
				((T2 + T1_slice) < (T2 + T2_slice)) ?
				(
					(T2 + T2_slice) - (T2 + T1_slice) + 1
					) :
				(
					(T2 + T1_slice) - (T2 + T2_slice) + 1
					)
				) :

			(

				(T1_slice < 0) ?
				(
					((T2 + T1_slice) < T2_slice) ?
					(
						T2_slice - (T2 + T1_slice) + 1
						) :
					(
						(T2 + T1_slice) - T2_slice + 1
						)
					) :
				(T2_slice < 0) ?
				(
					(T1_slice < (T2 + T2_slice)) ?
					(
						(T2 + T2_slice) - T1_slice + 1
						) :
					(
						T1_slice - (T2 + T2_slice) + 1
						)
				) :
				(
					(T1_slice < T2_slice) ?
					(T2_slice - T1_slice + 1) : (T1_slice - T2_slice + 1)
				)
			) > vec_slice(0);

		
		int T1_slice_variable = T1_slice;
		int T2_slice_variable = T2_slice;

		if (T1_slice < 0 && T2_slice < 0)
		{
			T1_slice_variable = T2 + T1_slice;
			T2_slice_variable = T2 + T2_slice;
		}
		else 
			if (T1_slice < 0)
			{
				T1_slice_variable = T2 + T1_slice;
			}	
			if (T2_slice < 0)
			{
				T2_slice_variable = T2 + T2_slice;
			}
			
		
		

		if (T1_slice_variable < T2_slice_variable)
		{
			for (size_t i = T1_slice_variable ; i <= T2_slice_variable; i++)
			{
				vec_slice[i - T1_slice_variable] = this->TypeOfElement[i];
			}
		}
			
		else
		{
			for (size_t i = T1_slice_variable; i >= T2_slice_variable; i--)
			{
				vec_slice[T1_slice_variable - i] = this->TypeOfElement[i];

			}
		}
			

		cout << endl;
		return vec_slice;

	}

	template<typename T1_V1, typename T2_V2>
	const Vector<T1_V1 , T2> weighted_sum(Vector<T1_V1, T2>& vec1, double a , Vector<T2_V2 , T2>& vec2, double b)
	{
		Vector<T1_V1, T2> sum(0);

		for (int i = 0; i < T2; i++)
		{
			sum[i] = ((T1_V1)vec1[i] * a) + ((T1_V1)vec2[i] * b);
		}
		return sum;
	}




	template<typename T1_S1, typename T2_S2>
	const Vector<T1_S1, T2 + T2> concat(Vector<T1_S1, T2>& a, Vector<T2_S2, T2>& b)
	{
		Vector <T1_S1, T2 + T2> cont(0);
		for (size_t i = 0; i < T2; i++)
		{
			cont[i + T2 * 0] = (T1_S1)a[i];
			cont[i + T2 * 1] = (T1_S1)b[i];
			
		}
		
		return cont;
	}





	
};



#endif


//template<typename T1, typename ...Args>
//Vector<T1, T2> concat(Vector<T1, T2>& element)
//{
//
//	return element;
//}
//
//
//template<typename T1, typename ...Args>
//auto concat(Vector<T1, T2>& element, Args& ...arguments)
//{
//
//	Vector <T1, T2 * sizeof...(arguments)> sum(0);
//	int a = sizeof...(arguments);
//	cout << a << endl;
//	for (size_t i = 0; i < T2; i++)
//	{
//		sum[i] = (T1)element[i];
//	}
//	for (size_t j = 1; j < a; j++)
//	{
//		for (size_t i = 0; i < T2; i++)
//		{
//
//			sum[i + T2 * 1] = concat(arguments...)[i];
//		}
//	}
//
//	return sum;
//}
