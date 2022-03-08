#ifndef VECTOR_H
#define VECTOR_H

template <class R>
class Vector{
	template<class R>
	friend ostream& operator<< (ostream& out, const Vector<R>& v);
	template<class R>
	friend istream& operator>> (istream& in, Vector<R>& v);


	R* vec;
	unsigned int size;
	unsigned int cap;

public:
	// INTERFACCIA 
	Vector(); // costruttore di default
	Vector(const Vector<R>&); // costruttore di copia

	~Vector(); // distruttore

	unsigned int size() const { return size; };
	unsigned int capacity() const { return cap; };

	R& operator[](unsigned int i); // versione (default, read-write)
	R operator[](unsigned int i) const; // versione per oggetti costanti (read-only)

	Vector& operator= (const Vector<R>&); // overload dell'assegnazione


	void pushBack(const R&); // aggiungi elemento in fondo
	const R& back() const; // leggi ultimo elemento
	void popBack(); // elimina ultimo elemento
	void reserve(unsigned int size);
	void resize (unsigned int size);


};


#endif
