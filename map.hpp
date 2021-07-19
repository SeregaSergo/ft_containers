#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include "utils.hpp"

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>,
            class Alloc = std::allocator<pair<const Key,T> > >
class map
{
public:
    typedef Key                                 key_type;
    typedef T                                   mapped_type;
    typedef pair<const key_type, mapped_type>   value_type;
    typedef Compare                             key_compare;
    
    class value_compare
    {
        public:
            typedef bool                        result_type;
            typedef value_type                  first_argument_type;
            typedef value_type                  second_argument_type;
    
        protected:
            Compare comp;
            value_compare (Compare c) : comp(c) {}
        
        public:
            result_type operator()(const first_argument_type & x,
                             const second_argument_type & y) const
            {
                return (comp(x.first, y.first));
            }
    }
    
    typedef Alloc                                               allocator_type;
    typedef typename allocator_type::reference                  reference;
    typedef typename allocator_type::const_reference            const_reference;
    typedef typename allocator_type::pointer                    pointer;
    typedef typename allocator_type::const_pointer              const_pointer;
    typedef _BDIterator<value_type>                             iterator;
	typedef _BDIterator<const value_type>                       const_iterator;
	typedef ft::reverse_iterator<iterator>                      reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;
    typedef typename iterator_traits<iterator>::difference_type difference_type;
    typedef typename allocator_type::size_type                  size_type;

private:
    Red_black_tree<value_type, Compare>         _bst;
    Compare                                     _cmp;
    allocator_type                              _alloc;

public:
    
};

}

#endif