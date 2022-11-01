/*
- Vector
- List (Forward list)
- Stack (Adaptors) / Queue / Priority queue
- Unordered map (Associative containers) / Map


FORWARD LIST
                        Nodo   Nodo   Nodo
testa / head / first --> [A] -> [B] -> [C] <-- coda / tail / last 

Sappiamo che sono collegati grazie ai puntatori. Ogni nodo punta a quello successivo, quindi è altamente dinamica
L'ultimo nodo punterà a null
*/


template <class T>
class Node{
    T value;
    Node<T> * nextNode;
    friend class List <T>;

    public:
        Node (const T& v): nextNode(0), value(v){};                     // costruttore di deafult

        // Metodi di utilità
        T getValue(){return value;}
        Node<T> * getNextNode() const {return nextNode;};
};

template <class T>
class List{
    
    protected:
        Node<T> * first;
        Node<T> * last; 
        Node<T> * newNode(const T&);
    
    public:
        List(): first(0), last(0){};                                    // costruttore di deafult
        ~List();                                                        // distruttore

        // Metodi di utilità
        void pushFront(const T&);
        void pushBack(const T&);
        bool popFront(T& v);
        bool popBack(T& v);
        bool empty()const{return first == 0;};
        Node<T>* front();
        void remove(const T& v);
        void delNode(Node<T>*&);
        void moveAtFirst();
        void moveAtLast();
};


template <class T>
List<T> :: ~List(){
    if (first == 0) return;
    Node<T> * curr = first;
    Node<T> * tmp;
    while(curr != 0){
        tmp = curr;
        curr = curr -> nextNode;
        delete tmp;
    }
}

template <class T>
void List<T> :: pushFront(const T& v){
    Node<T> * n = newNode(v);
    if(empty()) first = last = n;
    else{
        n -> nextNode = first;
        first = n;
    }
}

template <class T>
bool List<T> :: popBack(T& v){
    if (empty()) return false;
    node<T>* tmp = last;
    if (first == last) first = last = 0;
    else{
        Node<T> * curr = first;
        while(curr -> nextNode != last) curr = curr -> nextNode;
        last = curr;
        last -> nextNode = 0;
       
    }
    v = tmp -> value;
    delete tmp;
    return true;
}

template <class T>
class iterator{
    Node<T> *prec;
    Node<T> *corr;
    List<T> &l;

    public:
        iterator(List<t> &lista): l(lista), corr(lista.first), prec(0){};
        T operator * (){if (corr != 0) return corr -> value;}
        T operator ++(){prec = corr; corr -> nextNode;};
        void insert(const T& v);
};

template <class T>
void iterator<T> :: insert(const T& v){
    if (corr == first){
        l.pushFront(v);
        corr = l.first;
        prec = 0;
    }
    else if(prec == l.last){
        l.pushBack(v);
        corr = l.last;
    }
    else{
        Node<T> * N = newNode(v);
        N -> nextNode = corr;
        prec -> nextNode = N;
        corr = N;                   
    }
}