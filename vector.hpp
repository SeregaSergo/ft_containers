#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <type_traits>
#include "reverse_iterator.hpp"

namespace ft
{

#define CAPACITY_FACTOR 2
#define START_SIZE      2

template < class T >
class _RAIterator
{
public:
    typedef T                               value_type;
    typedef value_type *                    pointer;
    typedef value_type const *              const_pointer;
    typedef value_type&                     reference;
    typedef value_type const &              const_reference;
    typedef std::ptrdiff_t                  difference_type;
    typedef std::random_access_iterator_tag iterator_category;
    
private:
    pointer  _ptr;
    _RAIterator(void): _ptr(NULL) {}

public:
    _RAIterator(pointer ptr): _ptr(ptr) {}
	_RAIterator(_RAIterator const &src): _ptr(src._ptr) {}
	virtual ~_RAIterator(void) {}

    _RAIterator & operator=(const _RAIterator & src)
    {
        if (*src != this)
            _ptr = src._ptr;
        return (*this);
    }

    bool operator==(const _RAIterator & right) const {
        return (_ptr == right._ptr);
    }

    bool operator!=(const _RAIterator & right) const {
        return (_ptr != right._ptr);
    }

    bool operator<(const _RAIterator & right) const {
        return (_ptr < right._ptr);
    }

    bool operator>(const _RAIterator & right) const {
        return (_ptr > right._ptr);
    }
    
    bool operator<=(const _RAIterator & right) const {
        return (_ptr <= right._ptr);
    }

    bool operator>=(const _RAIterator & right) const {
        return (_ptr >= right._ptr);
    }

    pointer base(void) const {
        return (_ptr);
    }

    _RAIterator & operator++(void) {
        ++_ptr;
        return (*this);
    }

    _RAIterator operator++(int) {
        _RAIterator tmp(*this);
        ++_ptr;
        return (tmp);
    }

    _RAIterator & operator+=(difference_type pos) {
        _ptr += pos;
        return (*this);
    }

    _RAIterator operator+(difference_type pos) const {
        return (_ptr + pos);
    }

    _RAIterator & operator--(void) {
        --_ptr;
        return (*this);
    }

    _RAIterator operator--(int) {
        _RAIterator tmp(*this);
        +--_ptr;
        return (tmp);
    }

    _RAIterator & operator-=(difference_type pos) {
        _ptr -= pos;
        return (*this);
    }        

    _RAIterator operator-(difference_type pos) const {
        return (_ptr - pos);
    }

    difference_type operator-(_RAIterator const & right) const {
        return (_ptr - right._ptr);
    }

    reference operator*(void) const {
        return (*_ptr);
    }

    pointer operator->(void) {
        return (_ptr);
    }

    reference operator[](difference_type pos) {
        return (*(_ptr[pos]));
    }
};

template < class T, class A = std::allocator<T> > 
class vector
{
public:
    typedef T                                        value_type;
    typedef A                                        allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef _RAIterator<value_type>                  iterator;
	typedef _RAIterator<value_type const>            const_iterator;
	// typedef reverse_iterator<iterator>                reverse_iterator;
	// typedef reverse_iterator<const_iterator>          const_reverse_iterator;

private:
    pointer         _arr;
    size_type       _capacity;
    size_type       _size;
    A               _alloc;
    
    void    realloc(size_type newCapacity)
    {
        pointer newBlock = _alloc.allocate(newCapacity * sizeof(T));

        if (newCapacity < _size)
            _size = newCapacity;
        
        for (size_type i = 0; i < _size; ++i)
        {
            newBlock[i] = _arr[i];
            _alloc.destroy(_arr + i);
        }

        _alloc.deallocate(_arr, _capacity);
        _capacity = newCapacity;
    }

public:

    vector(void) : _capacity(START_SIZE), _size(0)
    {
       _arr = _alloc.allocate(_capacity * sizeof(T));
    };

    vector (size_type n, const T& val = T(), const A& alloc = A())
            : _capacity(n),
              _size(n),
              _alloc(alloc)
    {
        if (n > 0)
        {
            _arr = _alloc.allocate(n * sizeof(T));
            for (size_type i = 0; i < _size; ++i)
                _alloc.construct(_arr + i, val);
        }
    };

    // template <class InputIterator>
    //      vector (InputIterator first, InputIterator last,
    //              const allocator_type& alloc = allocator_type())
    // {

    // };

    // vector (const vector& x)
    // {

    // };

    void push_back (const T& val)
    {
        if (_size == _capacity)
            realloc(_capacity * CAPACITY_FACTOR);
        
        _alloc.construct(_arr + _size, val);
        ++_size;
    };

    size_type   size(void) const {
        return (_size);
    }

    size_type capacity(void) const {
        return (_capacity);
    };

    reference operator[] (size_type n) {
        return _arr[n];
    };

    const_reference operator[] (size_type n) const {
        return _arr[n];
    };

    iterator begin(void) {
        return (_arr);
    }

    const_iterator begin(void) const {
        return (_arr);
    }

    iterator end(void) {
        return (_arr + _size);
    }

    const_iterator end(void) const {
        return (_arr + _size);
    }
    
    reverse_iterator rbegin(void) {
        return (this->end());
    }

	const_reverse_iterator rbegin(void) const {
         return (this->end());
    }

	reverse_iterator rend(void) {
        return (this->begin());
    }

	const_reverse_iterator rend(void) const {
        return (this->begin());
    }
};

}

#endif