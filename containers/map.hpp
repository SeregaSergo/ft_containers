#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <type_traits>
#include "./utils/utils.hpp"
#include "tree.hpp"
#include "./utils/reverse_iterator.hpp"

namespace ft
{

template < class Key, class T, class Compare = ft::less<Key> >
class _Node_compare
{
    public:
        typedef pair<const Key, T>          value_type;
        typedef bool                        result_type;
        typedef value_type                  first_argument_type;
        typedef value_type                  second_argument_type;

    protected:
        Compare _comp;
    
    public:
        _Node_compare() : _comp() {}
        _Node_compare(Compare c) : _comp(c) {}
        result_type operator()(const first_argument_type & x,
                            const second_argument_type & y) const
        {
            return (_comp(x.first, y.first));
        }
};

template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
class map
{
public:
    typedef Key                                 key_type;
    typedef T                                   mapped_type;
    typedef pair<const key_type, mapped_type>   value_type;
    typedef Compare                             key_compare;
    typedef _Node<value_type>                   node_type;
    typedef _Node_compare< Key, T, Compare>     node_compare;

    class value_compare
    {
        // friend class map;
        public:
            typedef bool                        result_type;
            typedef value_type                  first_argument_type;
            typedef value_type                  second_argument_type;
    
        protected:
            Compare _comp;
            value_compare(Compare c) : _comp(c) {}
        
        public:
            result_type operator()(const first_argument_type & x,
                             const second_argument_type & y) const
            {
                return (_comp(x.first, y.first));
            }
    };
    
    typedef Alloc                                               allocator_type;
    typedef typename allocator_type::reference                  reference;
    typedef typename allocator_type::const_reference            const_reference;
    typedef typename allocator_type::pointer                    pointer;
    typedef typename allocator_type::const_pointer              const_pointer;
    // typedef _TreeIterator<value_type, node_type>                iterator;
	// typedef _TreeIterator<const value_type, const node_type>    const_iterator;
    typedef typename allocator_type::size_type                  size_type;
    typedef ft::tree<value_type, node_compare, allocator_type>  tree_type;
    typedef typename tree_type::node_pointer                    node_pointer;
    typedef typename tree_type::iterator                        iterator;
	typedef typename tree_type::const_iterator                  const_iterator;
	typedef ft::reverse_iterator<iterator>                      reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;
    typedef typename iterator_traits<iterator>::difference_type difference_type;

private:
    tree_type       _tree;
    size_type       _size;
    key_compare     _comp;
    allocator_type  _alloc;

public:

    // empty container constructor (default constructor)
    explicit map(const key_compare & comp = key_compare(),
                const allocator_type & alloc = allocator_type())
                : _tree(), _size(0), _comp(comp), _alloc(alloc) {}

    // range constructor
    template <class InputIterator>
    map(InputIterator first, InputIterator last,
            const key_compare & comp = key_compare(),
                const allocator_type & alloc = allocator_type())
        : _tree(), _size(0), _comp(comp), _alloc(alloc)
    {
        insert(first, last);
    }

    // copy constructor
    map(const map & src) : _tree(src._tree), _size(src._size),
                            _comp(src._comp), _alloc(src._alloc) {}

    virtual ~map(){}
    
    map & operator=(const map & src)
    {
        if (this == &src)
            return (*this);
        clear();
        insert(src.begin(), src.end());
        return (*this);
    }

    //
    // Iterator member-functions
    //
    iterator begin(void) {
        return (_tree.begin());
    }

    const_iterator begin(void) const {
        return (_tree.begin());
    }

    iterator end(void) {
        return (_tree.end());
    }

    const_iterator end(void) const {
        return (_tree.end());
    }

    reverse_iterator rbegin(void) {
        return (_tree.end());
    }

    const_reverse_iterator rbegin(void) const {
        return (_tree.end());
    }

    reverse_iterator rend(void) {
        return (_tree.begin());
    }

    const_reverse_iterator rend(void) const {
        return (_tree.begin());
    }
    
    
    // 
    // Capacity member-functions
    //

    bool empty(void) const {
        return (_size == 0);
    }

    size_type size(void) const {
        return (_size);
    }

    size_type max_size(void) const {
        return (_tree.max_size());
    }

    // 
    // Element access operation
    //

    mapped_type & operator[](const key_type & k)
    {
        node_pointer node = _tree.find(k);

		if (node)
			return (node->value.second);

		++_size;
		return ((*((insert(make_pair(k, mapped_type()))).first)).second);
    }

    // 
    // Modifying member-functions
    //

    pair<iterator,bool> insert(const value_type & val)
    {
        ft::pair<iterator,bool> res = _tree.insert(val);
        if (res.second)
            ++_size;
        return (res);
    }

    iterator insert(iterator position, const value_type & val)
    {
        ft::pair<iterator,bool> res = _tree.insert(position, val);
        if (res.second)
            ++_size;
        return (res);
    }
	
    template <class InputIterator>
    void insert(InputIterator first, InputIterator last)
    {
        while (first != last)
        {
            if (_tree.insert(*first).second)
                ++_size;
            ++first;
        }
    }

    //
    // Observers
    //
    
    //
    // Operations
    //

    //
    // Allocator member-function
    //
    allocator_type get_allocator(void) const {
        return (_alloc);
    }
};

}

#endif