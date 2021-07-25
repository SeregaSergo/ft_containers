#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "utils.hpp"

namespace ft
{

template <class Iter>
class reverse_iterator {

public:
    typedef Iter                                                    iterator_type;
    typedef typename ft::iterator_traits<Iter>::iterator_category   iterator_category;
    typedef typename ft::iterator_traits<Iter>::value_type          value_type;
    typedef typename ft::iterator_traits<Iter>::difference_type     difference_type;
    typedef typename ft::iterator_traits<Iter>::pointer             pointer;
    typedef typename ft::iterator_traits<Iter>::reference           reference;

private:
    Iter   _it;

public:
    reverse_iterator(void) : _it() {}
    reverse_iterator(iterator_type const & it) : _it(it) {}
    virtual ~reverse_iterator() {}

    template <class _I>
	reverse_iterator(reverse_iterator<_I> const & src): _it(src.base()) {}

    template <class _I>
	reverse_iterator & operator=(reverse_iterator<_I> const & src) {
		_it = src.base();
		return (*this);
	}

    iterator_type base(void) const {
        return (_it);
    }

    reference operator*(void) const {
        Iter tmp = _it;
        --tmp;
        return (*tmp);
    }

    pointer  operator->(void) const {
        Iter tmp = _it;
        --tmp;
        return (&(*tmp));
    }

    reverse_iterator & operator++(void) {
        --_it;
        return (*this);
    }

    reverse_iterator  operator++(int) {
        reverse_iterator tmp(*this);
        --_it;
        return (tmp);
    }

    reverse_iterator & operator--(void) {
        ++_it;
        return (*this);
    }

    reverse_iterator  operator--(int) {
        reverse_iterator tmp(*this);
        ++_it;
        return (tmp);
    }

    reverse_iterator  operator+(difference_type pos) const {
        return (reverse_iterator(_it - pos));
    }

    reverse_iterator& operator+=(difference_type pos) {
        _it -= pos;
        return (*this);
    }

    reverse_iterator  operator-(difference_type pos) const {
        return (reverse_iterator(_it + pos));
    }

    reverse_iterator& operator-=(difference_type pos) {
        _it += pos;
        return (*this);
    }

    reference   operator[](difference_type pos) const {
        return (*(*this + pos));
    }

};

template <class Iterator>
bool operator==(const reverse_iterator<Iterator>& l,
                   const reverse_iterator<Iterator>& r) {
    return (l.base() == r.base());
}

template <class Iterator>
bool operator!=(const reverse_iterator<Iterator>& l,
                   const reverse_iterator<Iterator>& r) {
    return (l.base() != r.base());
}

template <class Iterator>
bool operator<(const reverse_iterator<Iterator>& l,
                   const reverse_iterator<Iterator>& r) {
    return (l.base() > r.base());
}

template <class Iterator>
bool operator>(const reverse_iterator<Iterator>& l,
                   const reverse_iterator<Iterator>& r) {
    return (l.base() < r.base());
}

template <class Iterator>
bool operator<=(const reverse_iterator<Iterator>& l,
                   const reverse_iterator<Iterator>& r) {
    return (l.base() >= r.base());
}

template <class Iterator>
bool operator>=(const reverse_iterator<Iterator>& l,
                   const reverse_iterator<Iterator>& r) {
    return (l.base() <= r.base());
}

template <class Iterator>
reverse_iterator<Iterator> operator+(
        typename reverse_iterator<Iterator>::difference_type n,
            const reverse_iterator<Iterator>& rev_it)
{
    return (rev_it + n);
}

template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator-(
        const reverse_iterator<Iterator>& l,
            const reverse_iterator<Iterator>& r)
{
    return (r.base() - l.base());
}

}

#endif