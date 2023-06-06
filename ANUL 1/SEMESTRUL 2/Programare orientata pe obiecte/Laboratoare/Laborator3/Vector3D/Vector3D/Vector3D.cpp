#include <iostream>
#include <vector>
using namespace std;

class Vector3D
{
private:
	double x, y, z;
public:
	Vector3D(int x = 0, int y = 0,int z=0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	double get_x()
	{
		return x;
	}
	double get_y()
	{
		return y;
	}
	double get_z()
	{
		return z;
	}
	double operator!()
	{
		double lungime;
		lungime = x * x + y * y + z * z;
		return sqrt(lungime);
	}
	bool operator<(Vector3D a)
	{
		return (!this < !a);
	}
	double operator*(Vector3D obj)
	{
		double produs_scalar = 0;
		produs_scalar = this->x * obj.x + this->y * obj.y + this->z * obj.z;
		return produs_scalar;
	}

	Vector3D operator+(Vector3D v2)
	{
		Vector3D sum;
		sum.x = x + v2.x;
		sum.y = y + v2.y;
		sum.z = z + v2.z;
		return sum;
	}
	
	friend istream& operator>>(istream& fi, Vector3D& obj);
	friend ostream& operator<<(ostream& fo,const Vector3D& obj);
	friend Vector3D operator*(double val, Vector3D& obj);
};
Vector3D operator*(double val, Vector3D& obj)
{
	Vector3D aux;
	aux.x = obj.x * val;
	aux.y = obj.y * val;
	aux.z = obj.z * val;
	return aux;
}

istream &operator>>(istream& fi, Vector3D& obj)
{
	fi >> obj.x;
	fi >> obj.y;
	fi >> obj.z;
	return fi;
}

ostream &operator<<(ostream& fo,const Vector3D &obj)
{
	fo << obj.x<<" ";
	fo << obj.y<<" ";
	fo << obj.z<<" ";
	return fo;
}

int main()
{
	std::vector<Vector3D> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Vector3D obj;
		cin >> obj;
		v.push_back(obj);
	}
	Vector3D maxi = v[0], mini = v[0];
	for (int i = 1; i < n; i++)
	{
		if (!v[i] > !maxi)
		{
			maxi = v[i];
		}
		if (!v[i] < !mini)
		{
			mini = v[i];
		}
	}
	cout << mini * maxi;
	cout << endl;

	Vector3D suma=v[0];
	for (int i = 1; i < n; i++)
	{
		Vector3D aux;
		aux = (i + 1) * v[i];
		suma = suma + aux;
	}
	cout << suma;
}

