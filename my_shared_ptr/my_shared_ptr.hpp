#ifndef MY_SHARESD_PTR_HPP
#define MY_SHARESD_PTR_HPP
#include <memory>
#include <utility>

template<class Type, class TDeleter = std::default_delete<Type>>
class SharedPTR {
    typedef SharedPTR<Type, TDeleter> t_SharedPTR;
    Type *pointer = nullptr;
    int *pointer_count = nullptr;
    TDeleter deleter;

public: // Constructors and destructor.
    SharedPTR() = default;

    SharedPTR(Type *pObj);
    SharedPTR(Type *pObj, TDeleter& _deleter);

    SharedPTR(const t_SharedPTR &);

    SharedPTR(t_SharedPTR &&sharedPTR); // Move constructor.
    ~SharedPTR();

public: // Assignment.
    t_SharedPTR &operator=(t_SharedPTR &&sharedPTR);

    t_SharedPTR &operator=(Type *pObject);

    t_SharedPTR &operator=(const t_SharedPTR &);

public: // Observers.
    Type &operator*() const; // Dereference the stored pointer.
    Type *operator->() const; // Return the stored pointer.
    Type *get() const; // Return the stored pointer.
    inline friend int *const get_count(t_SharedPTR &sharedPTR) { return sharedPTR.pointer_count; }; // Return the pointer to counter
    TDeleter &get_deleter(); // Return a reference to the stored deleter.
    operator bool() const; // Return false if the stored pointer is null.
public: // Modifiers.
    void release(); // Release ownership of any stored pointer.
    void reset(Type *pObject = nullptr); // Replace the stored pointer.
    void swap(t_SharedPTR &sharedPTR); // Exchange the pointer with another object.
};

template<class Type, class TDeleter>
inline SharedPTR<Type, TDeleter>::SharedPTR(Type *pObject): pointer(pObject),
                                                            pointer_count(new int(1)) {}

template<class Type, class TDeleter>
inline SharedPTR<Type, TDeleter>::SharedPTR(Type *pObject, TDeleter& _deleter):pointer(pObject),
                                                                           pointer_count(new int(1)),
                                                                           deleter(_deleter){}

template<class Type, class TDeleter>
SharedPTR<Type, TDeleter>::SharedPTR(const SharedPTR::t_SharedPTR &object) {
    pointer = (object.pointer);
    pointer_count = (object.pointer_count);
    if (object.pointer != nullptr) {
        *pointer_count += 1;
    }

}

template<class Type, class TDeleter>
inline SharedPTR<Type, TDeleter>::SharedPTR(t_SharedPTR &&sharedPTR) {
    std::swap(sharedPTR.pointer, pointer);
    std::swap(sharedPTR.pointer_count, pointer_count);
    std::swap(sharedPTR.deleter, deleter);
}


template<class Type, class TDeleter>
inline SharedPTR<Type, TDeleter> &SharedPTR<Type, TDeleter>::operator=(t_SharedPTR &&sharedPTR) {
    if (&sharedPTR != this) {
        std::swap(sharedPTR.pointer, pointer);
        std::swap(sharedPTR.pointer_count, pointer_count);
        std::swap(sharedPTR.deleter, deleter);
    }
    return *this;
}

template<class Type, class TDeleter>
inline SharedPTR<Type, TDeleter> &SharedPTR<Type, TDeleter>::operator=(Type *pObject) {
    reset(pObject);
    return *this;
}

template<class Type, class TDeleter>
inline SharedPTR<Type, TDeleter> &SharedPTR<Type, TDeleter>::operator=(const t_SharedPTR &sharedPTR) {
    if (sharedPTR.pointer != pointer) {
        release();
        pointer = sharedPTR.pointer;
        deleter = sharedPTR.deleter;
        pointer_count = sharedPTR.pointer_count;
        if(pointer_count != nullptr){
            *pointer_count += 1;
        }
    }
    return *this;
}

template<class Type, class TDeleter>
inline Type &SharedPTR<Type, TDeleter>::operator*() const {
    return *pointer;
}

template<class Type, class TDeleter>
inline Type *SharedPTR<Type, TDeleter>::operator->() const {
    return pointer;
}

template<class Type, class TDeleter>
inline Type *SharedPTR<Type, TDeleter>::get() const {
    return pointer;
}

template<class Type, class TDeleter>
inline TDeleter &SharedPTR<Type, TDeleter>::get_deleter() {
    return deleter;
}

template<class Type, class TDeleter>
inline SharedPTR<Type, TDeleter>::operator bool() const {
    if (pointer == nullptr)
        return false;
    else
        return true;
}

template<class Type, class TDeleter>
inline void SharedPTR<Type, TDeleter>::release() {
    if (pointer == nullptr) {
        return;
    } else {
        *pointer_count -= 1;
        if (*pointer_count == 0) {
            deleter(pointer);
            delete pointer_count;
        }
        pointer = nullptr;
        pointer_count = nullptr;
    }
}

template<class Type, class TDeleter>
SharedPTR<Type, TDeleter>::~SharedPTR() {
    release();
}

template<class Type, class TDeleter>
inline void SharedPTR<Type, TDeleter>::reset(Type *pObject) {
    if (pointer != pObject) {
        release();
        if(pObject == nullptr){
            pointer = nullptr;
            pointer_count = nullptr;
        }else{
            pointer = pObject;
            pointer_count = new int(1);
        }
    }
}

template<class Type, class TDeleter>
inline void SharedPTR<Type, TDeleter>::swap(t_SharedPTR &sharedPTR) {
    std::swap(pointer_count, sharedPTR.pointer_count);
    std::swap(pointer, sharedPTR.pointer);
    std::swap(deleter, sharedPTR.deleter);
}



#endif //MY_SHARESD_PTR_HPP
