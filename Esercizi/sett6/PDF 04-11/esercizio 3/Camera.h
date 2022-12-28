#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include <iostream>

using namespace std;

class Camera{
    protected:
    string tipo;
    int costo;
    
    public:
    Camera(){};
    Camera(string tipo, int costo):
        tipo{tipo},
        costo{costo}
    {}

    /* per calcolare il costo delle camere, che varia in base alla tipologia: 30 euro per una camera singola, 50 euro per una camera doppia, 75 euro per una camera tripla. */
    virtual int calcolaCosto() const = 0;
    
    /*che restituisca un numero identificativo della tipologia: 1 per le camere singole, 2 per le camere doppie, 3 per le camere triple.*/
    virtual string tipologia() const = 0;

    friend ostream& operator<<(ostream& o, const Camera& c);
};


class Singola: public Camera{
    public:
    Singola(): Camera{"1", 30}{}
    virtual string tipologia() const override {
		return tipo;
	}
    virtual int calcolaCosto() const override {
		return costo;
	}
};

class Doppia: public Camera{
    public:
    Doppia(): Camera{"2", 50}{}
    virtual string tipologia() const override {
		return tipo;
	}
    virtual int calcolaCosto() const override {
		return costo;
	}
};

class Tripla: public Camera{
    public:
    Tripla():Camera{"3", 75}{}
    virtual string tipologia() const override {
		return tipo;
	}
    virtual int calcolaCosto() const override {
		return costo;
	}
};
#endif