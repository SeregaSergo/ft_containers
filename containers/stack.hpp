#ifndef STACK_HPP
#define STACK_HPP

#include <type_traits>
#include "./utils/reverse_iterator.hpp"
#include "./vector.hpp"

namespace ft
{

template <class T, class Container = ft::vector<T> >
class stack
{
public:
    typedef Container                                   container_type;
    typedef typename container_type::value_type         value_type;
    typedef typename container_type::reference          reference;
    typedef typename container_type::const_reference    const_reference;
    typedef size_t                                      size_type;
    static_assert((std::is_same<T, value_type>::value), "" );  // if types are equel

protected:
    container_type _c;

public:
    explicit stack(const container_type & ctnr = container_type()) : _c(ctnr) {};
    stack(const stack & src) : _c(src._c) {}
    ~stack() {}
    stack & operator=(const stack & src)
    {
        _c = src._c;
        return (*this);
    }
    
    //
    // Element access member-function
    //

    value_type & top(void) {
        return (_c.back());
    }

    const value_type & top(void) const {
        return (_c.back());
    }

    //
    // Capacity and size member-functions
    //

    bool empty(void) const {
        return (_c.empty());
    }

    size_type size(void) const {
        return (_c.size());
    }

    //
    // Modifying member-functions
    //

    void push(const value_type & val) {
        _c.push_back(val);
    }

    void pop(void) {
        _c.pop_back();
    }
    
    //
    // Non-member function overloads of relational operators
    //

    template <class _T, class _Container>
    friend bool operator==(const ft::stack<_T,_Container> & lhs, const ft::stack<_T,_Container> & rhs);
    
    template <class _T, class _Container>
    friend bool operator!=(const ft::stack<_T,_Container> & lhs, const ft::stack<_T,_Container> & rhs);

    template <class _T, class _Container>
    friend bool operator<(const ft::stack<_T,_Container> & lhs, const ft::stack<_T,_Container> & rhs);

    template <class _T, class _Container>
    friend bool operator<=(const ft::stack<_T,_Container> & lhs, const ft::stack<_T,_Container> & rhs);

    template <class _T, class _Container>
    friend bool operator>(const ft::stack<_T,_Container> & lhs, const ft::stack<_T,_Container> & rhs);

    template <class _T, class _Container>
    friend bool operator>=(const ft::stack<_T,_Container> & lhs, const ft::stack<_T,_Container> & rhs);

};

template <class T, class Container>
bool operator==(const ft::stack<T,Container> & lhs, const ft::stack<T,Container> & rhs) {
    return (lhs._c == rhs._c);
};

template <class T, class Container>
bool operator!=(const ft::stack<T,Container> & lhs, const ft::stack<T,Container> & rhs) {
    return (lhs._c != rhs._c);
};

template <class T, class Container>
bool operator<(const ft::stack<T,Container> & lhs, const ft::stack<T,Container> & rhs) {
    return (lhs._c < rhs._c);
};

template <class T, class Container>
bool operator<=(const ft::stack<T,Container> & lhs, const ft::stack<T,Container> & rhs) {
    return (lhs._c <= rhs._c);
};

template <class T, class Container>
bool operator>(const ft::stack<T,Container> & lhs, const ft::stack<T,Container> & rhs) {
    return (lhs._c > rhs._c);
};

template <class T, class Container>
bool operator>=(const ft::stack<T,Container> & lhs, const ft::stack<T,Container> & rhs) {
    return (lhs._c >= rhs._c);
};

}
#endif