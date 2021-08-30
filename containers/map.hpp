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
        typedef ft::pair<const Key, T>      value_type;
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
    typedef Key                                     key_type;
    typedef T                                       mapped_type;
    typedef ft::pair<const key_type, mapped_type>   value_type;
    typedef Compare                                 key_compare;
    typedef _Node<value_type>                       node_type;
    typedef _Node_compare< Key, T, Compare>         node_compare;

    class value_compare : ft::binary_function<value_type, value_type, bool>
    {
        friend class map;
        public:
            typedef typename ft::binary_function<value_type, value_type, bool>  binary_function;
            typedef typename binary_function::result_type                       result_type;
            typedef typename binary_function::first_argument_type               first_argument_type;
            typedef typename binary_function::second_argument_type              second_argument_type;
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
        return (end());
    }

    const_reverse_iterator rbegin(void) const {
        return (end());
    }

    reverse_iterator rend(void) {
        return (begin());
    }

    const_reverse_iterator rend(void) const {
        return (begin());
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
        node_pointer node = _tree.find(ft::make_pair(k, mapped_type()));

		if (node)
			return (node->val.second);
		return ((*((insert(ft::make_pair(k, mapped_type()))).first)).second);
    }

    // 
    // Modifying member-functions
    //

    ft::pair<iterator,bool> insert(const value_type & val)
    {
        ft::pair<iterator,bool> res = _tree.insert(val);
        if (res.second)
            ++_size;
        return (res);
    }

    iterator insert(iterator position, const value_type & val)
    {
        ft::pair<iterator,bool> res = _tree.insert_hint(position, val);
        if (res.second)
            ++_size;
        return (res.first);
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

    void erase(iterator position)
    {
        _tree.erase_node(position.base());
        --_size;
    }

    size_type erase(const key_type & k)
    {
        iterator elem = find(k);

        if (elem == end())
			return (0);
		_tree.erase_node(elem.base());
        --_size;
		return (1);
    }

    void erase(iterator first, iterator last)
    {
        while (first != last)
			erase(first++);
    }

    void swap (map & x)
    {
        if (&x == this)
			return ;
        
        size_type s = _size;
        _size = x._size;
        x._size = s;
        _tree.swap(x._tree);
    }

    void clear(void) {
        _tree.clear();
        _size = 0;
    }

    //
    // Observers
    //
    
    key_compare key_comp(void) const {
        return (_comp);
    }

    value_compare value_comp(void) const {
        return (value_compare(_comp));
    }

    //
    // Operations
    //

    iterator find(const key_type & k)
    {
        node_pointer node = _tree.find(make_pair(k, mapped_type()));
		if (node)
			return (iterator(node));
		else
            return (end());
    }
    
    const_iterator find(const key_type & k) const
    {
        node_pointer node = _tree.find(make_pair(k, mapped_type()));
		if (node)
			return (const_iterator(node));
		else
            return (end());
    }

    size_type count(const key_type & k) const
    {
        const_iterator iter = begin();
		const_iterator end = end();

        while (iter != end)
        {
            if (!_comp(*iter, k) && !_comp(k, *iter))
                return (1);
            ++iter;
        }
        return (0);
    }

    iterator lower_bound(const key_type & k)
    {
        iterator iter = begin();
		iterator end = end();

		while (iter != end)
        {
			if (!_comp(*iter, k))
				return (iter);
			++iter;
		}
		return (end);
    }

    const_iterator lower_bound(const key_type & k) const
    {
        const_iterator iter = begin();
		const_iterator end = end();

		while (iter != end)
        {
			if (!_comp(*iter, k))
				return (iter);
			++iter;
		}
		return (end);
    }

    iterator upper_bound(const key_type & k)
    {
        iterator iter = begin();
		iterator end = end();

		while (iter != end)
        {
			if (_comp(k, *iter))
				return (iter);
			++iter;
		}
		return (end);
    }

    const_iterator upper_bound(const key_type & k) const
    {
        const_iterator iter = begin();
		const_iterator end = end();

		while (iter != end)
        {
			if (_comp(k, *iter))
				return (iter);
			++iter;
		}
		return (end);
    }

    ft::pair<const_iterator,const_iterator> equal_range(const key_type & k) const {
        return (ft::make_pair(lower_bound(k), upper_bound(k)));
    }

    ft::pair<iterator,iterator> equal_range(const key_type & k) {
        return (ft::make_pair(lower_bound(k), upper_bound(k)));
    }
    
    //
    // Allocator member-function
    //
    allocator_type get_allocator(void) const {
        return (_alloc);
    }

    // DELETE
    template <class S>
    void print_tree(S & out) const {
        _tree.print(out);
    }
};

};

#endif