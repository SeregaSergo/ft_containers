#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "utils.hpp"

template <class Iter>
class reverse_iterator {

public:
    typedef Iter                                                        iterator_type;
    typedef typename ft::iterator_traits<Iterator>::iterator_category   iterator_category;
    typedef typename ft::iterator_traits<Iterator>::value_type          value_type;
    typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
    typedef typename ft::iterator_traits<Iterator>::pointer             pointer;
    typedef typename ft::iterator_traits<Iterator>::reference           reference;

private:
    iterator_type   _it;

public:
    reverse_iterator(void) : _it() {}
    reverse_iterator(iterator_type const & it) : _it(it) {}
	reverse_iterator(reverse_iterator const & src): _it(src._it) {}

	reverse_iterator & operator=(reverse_iterator const & src) {
		_it = src._it;
		return (*this);
	}

    iterator_type base(void) const {
        return (_it);
    }
};

#endif