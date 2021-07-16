#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <type_traits>
#include "reverse_iterator.hpp"
#include <cstring>

namespace ft
{

#define CAPACITY_FACTOR 2


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
    typedef T                                                   value_type;
    typedef A                                                   allocator_type;
    typedef typename allocator_type::reference                  reference;
    typedef typename allocator_type::const_reference            const_reference;
    typedef typename allocator_type::pointer                    pointer;
    typedef typename allocator_type::const_pointer              const_pointer;
    typedef _RAIterator<value_type>                             iterator;
	typedef _RAIterator<value_type const>                       const_iterator;
	typedef ft::reverse_iterator<iterator>                      reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;
    typedef typename allocator_type::size_type                  size_type;
    typedef typename iterator_traits<iterator>::difference_type difference_type;
    

private:
    pointer         _arr;
    size_type       _capacity;
    size_type       _size;
    A               _alloc;

    void    _moveForward(pointer pos, size_type n) {

        pointer ptr = _arr + _size - 1;
        while (ptr != pos - 1) {
            _alloc.construct(ptr + n, *ptr);
            _alloc.destroy(ptr);
            --ptr;
        }
    }

public:

    // empty container constructor (default constructor)
    explicit vector(const allocator_type & alloc = allocator_type())
            : _arr(NULL), _capacity(0), _size(0), _alloc(alloc) {}

    // fill constructor
    explicit vector(size_type n, const value_type & val = value_type(), const A & alloc = A())
            : _capacity(n), _size(n), _alloc(alloc)
    {
        if (n > 0)
        {
            _arr = _alloc.allocate(n * sizeof(value_type));
            for (size_type i = 0; i < _size; ++i)
                _alloc.construct(_arr + i, val);
        }
        else
            _arr = NULL;
    }

    // range constructor
    template <class InputIterator>
    vector (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, 
            InputIterator>::type last, const allocator_type& alloc = allocator_type())
            : _arr(NULL), _capacity(0), _size(0), _alloc(alloc)
    {
        size_type dist = ft::distance<InputIterator>(first, last);
        size_type i = 0;

        if (dist > 0) {
            _arr = _alloc.allocate(dist);
            _capacity = dist;
        }
        for (; first != last; ++first) {
            _alloc.construct(_arr + i, *first);
            ++i;
        }
        _size = dist;
    }
        
    // copy constructor
    vector (const vector& x) : _capacity(0), _size(0)
    {
        reserve(x._capacity);
		std::memcpy(this->_arr, x._arr, x._size * sizeof(value_type));
        _size = x._size;
    }

    virtual ~vector(void)
    {
        clear();
        if (_capacity)
            _alloc.deallocate(_arr, _capacity);
    }

    vector& operator=(const vector& x)
    {
        if (x == *this)
			return (*this);
		clear();
        if (_capacity < x._capacity)
			this->reserve(x._capacity);
        std::memcpy(_arr, x._arr, x._size * sizeof(value_type));
        _size = x._size;
        return (*this);
    }

    //
    // Capacity and size member-functions
    //
    size_type   size(void) const {
        return (_size);
    }

    size_type max_size(void) const {
        return (_alloc.max_size());
    }

    void resize(size_type n, value_type val = value_type())
    {
        if (n > max_size())
			throw (std::length_error("ft::vector::resize: Can not allocate memory more then " \
            + ft::to_string(max_size())));
        if (n < _size) {
            for (size_type i = n; i != _size; ++i)
                _alloc.destoy(_arr + i);
            _size = n;
        }
        else {
            reserve(n);
            for (size_type i = _size; i != n; ++i)
                _alloc.construct(_arr + i, val);
            _size = n;
        }
    }

    size_type capacity(void) const {
        return (_capacity);
    };

    bool empty(void) const {
        return (_size == 0);
    }

    void reserve(size_type n)
    {
        if (n > max_size())
			throw (std::length_error("ft::vector::reserve: Can not allocate memory more then " \
            + ft::to_string(max_size())));
        else if (n > _capacity)
		{
            pointer newBlock = _alloc.allocate(n * sizeof(T));
            for (size_type i = 0; i < _size; ++i)
            {
                _alloc.construct(newBlock + i, _arr[i]);
                _alloc.destroy(_arr + i);
            }
            if (_capacity)
                _alloc.deallocate(_arr, _capacity);
            _capacity = n;
            _arr = newBlock;
        }
    }

    //
    // Modifying member-functions
    //
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last)
    {
        clear();
        size_type dist = ft::distance(first, last);
        size_type i = 0;

        if (_capacity < dist)
        {
            _alloc.deallocate(_arr, _capacity);
            _arr = _alloc.allocate(dist);
            _capacity = dist;
        }
        for (; first != last; ++first) {
            _alloc.construct(_arr + i, *first);
            ++i;
        }
        _size = dist;
    }	
    
    void assign(size_type n, const value_type& val)
    {
        clear();
        if (_capacity < n)
        {
            _alloc.deallocate(_arr, _capacity);
            _arr = _alloc.allocate(n);
            _capacity = n;
        }
        for (size_type i = 0; i != n; ++i)
            _alloc.construct(_arr + i, val);
        _size = n;
    }

    void push_back(const T& val)
    {
        if (_size == _capacity) {
            if (_size > 0)
                reserve(_capacity * CAPACITY_FACTOR);
            else
                reserve(1);
        }
        _alloc.construct(_arr + _size, val);
        ++_size;
    };

    void pop_back(void)
    {
        if (_size > 0) {
            _alloc.destroy(_arr + _size - 1);
            --_size;
        }
    }

    iterator insert(iterator position, const value_type& val)
    {
        difference_type dist = position.base() - _arr;
        insert(position, 1, val);
        return (_arr + dist + 1);
    }
	
    void insert(iterator position, size_type n, const value_type& val)
    {
        if (n == 0)
			return;
        difference_type dist = position.base() - _arr;
        if (_capacity - _size >= n)
            reserve(_size + n);
        _moveForward(_arr + dist, n);
        for (size_type i = n; i != 0; --i)
            _alloc.construct(_arr + dist + (i - 1), val);
        _size += n;
    }
	
    template <class InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last)
    {
        size_type n = last - first;
        difference_type dist = position.base() - _arr;

        if (n == 0)
			return;
        if (_capacity - _size >= n)
            reserve(_size + n);
        _moveForward(_arr + dist, n);
        for (size_type i = n; i != 0; --i) {
            _alloc.construct(_arr + dist + (i - 1), *first);
            ++first;
        }
        _size += n;
    }

    iterator erase(iterator position)
    {
        pointer pos = position.base();
        _alloc.destroy(pos);
        pointer end = _arr + _size - 1;
        for (; pos < end; ++pos)
        {
            _alloc.construct(pos, *(pos + 1));
            _alloc.destroy(pos + 1);
        }
        --_size;
        return (position); // check this !!!
    }

    iterator erase(iterator first, iterator last)
    {
        pointer p_start = first.base();
        pointer p_end = last.base();
        size_type dist = p_end - p_start;
        for (; first != last; ++first)
            _alloc.destroy(first.base());
        size_type end = _arr + _size - 1;
        for (size_type i = 0; i < dist; ++i)
        {
            _alloc.construct(p_start + i, *(p_end + i));
            _alloc.destroy(p_end + i);
        }
        _size -= dist;
        return (iterator(p_start));
    }

    void swap(vector& x)
    {
        if (x == *this)
			return;

        pointer tmp_arr = x._arr;
        size_type tmp_cap = x._capacity;
        size_type tmp_size = x._size;
        allocator_type tmp_alloc = x._alloc;

        x._arr = this->_arr;
        x._capacity = this->_capacity;
        x._size = this->_capacity;
        x._alloc = this->_alloc;

        this->_arr = tmp_arr;
        this->_capacity = tmp_cap;
        this->_size = tmp_size;
        this->_alloc = tmp_alloc;
    }

    void clear(void) {
        for (size_type i = 0; i != _size; ++i)
            _alloc.destroy(_arr + i);
        _size = 0;
    }

    //
    // Element access member-functions:
    //
    reference operator[] (size_type n) {
        return _arr[n];
    };

    const_reference operator[] (size_type n) const {
        return _arr[n];
    };

    reference at (size_type n) {
        if (n >= _size)
			throw std::out_of_range("ft::vector: index is out of range");
		return (_arr[n]);
    }

    const_reference at (size_type n) const {
        if (n >= _size)
			throw std::out_of_range("ft::vector: index is out of range");
		return (_arr[n]);
    }
    
    reference front(void) {
        return (*_arr);
    }

    const_reference front(void) const {
        return (*_arr);
    }

    reference back(void) {
        return (_arr[_size - 1]);
    }

    const_reference back(void) const {
        return (_arr[_size - 1]);
    }

    //
    // Iterator member-functions
    //
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

template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>&y) {
    x.swap(y);
}

template <class T, class Alloc>
bool operator==(const vector<T, Alloc> & left, const vector<T, Alloc> & right)
{
    if (left.size() != right.size())
        return (false);
    typename vector<T, Alloc>::const_iterator rit = right.begin();
    for(typename vector<T, Alloc>::const_iterator lit = left.begin(); lit != left.end(); ++lit)
    {
        if (*lit != *rit)
            return (false);
        ++rit;
    }
    return (true);
}

}

#endif