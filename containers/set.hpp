#ifndef SET_HPP
#define SET_HPP

#include <memory>
#include <type_traits>
#include "./utils/utils.hpp"
#include "tree.hpp"
#include "./utils/reverse_iterator.hpp"

namespace ft
{

template < class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
class set
{
public:
    typedef T                                                       key_type;
    typedef T                                                       value_type;
    typedef Compare                                                 key_compare;
    typedef Compare                                                 value_compare;  
    typedef Alloc                                                   allocator_type;
    typedef typename allocator_type::reference                      reference;
    typedef typename allocator_type::const_reference                const_reference;
    typedef typename allocator_type::pointer                        pointer;
    typedef typename allocator_type::const_pointer                  const_pointer;
    typedef typename allocator_type::size_type                      size_type;
    typedef ft::tree<const value_type, key_compare, allocator_type> tree_type;
    typedef typename tree_type::node_type                           node_type;
    typedef typename tree_type::node_pointer                        node_pointer;
    typedef typename tree_type::const_node_pointer                  const_node_pointer;
    // typedef _TreeIterator<const value_type, node_type>              iterator;
	// typedef _TreeIterator<const value_type, node_type>              const_iterator;
    typedef typename tree_type::iterator                            iterator;
	typedef typename tree_type::const_iterator                      const_iterator;
	typedef ft::reverse_iterator<iterator>                          reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
    typedef typename iterator_traits<iterator>::difference_type     difference_type;

private:
    tree_type       _tree;
    size_type       _size;
    key_compare     _comp;
    allocator_type  _alloc;

public:

    // empty container constructor (default constructor)
    explicit set(const key_compare & comp = key_compare(),
                const allocator_type & alloc = allocator_type())
                : _tree(), _size(0), _comp(comp), _alloc(alloc) {}

    // range constructor
    template <class InputIterator>
    set(InputIterator first, InputIterator last,
            const key_compare & comp = key_compare(),
                const allocator_type & alloc = allocator_type())
        : _tree(), _size(0), _comp(comp), _alloc(alloc)
    {
        insert(first, last);
    }

    // copy constructor
    set(const set & src) : _tree(src._tree), _size(src._size),
                            _comp(src._comp), _alloc(src._alloc) {}

    virtual ~set(){}
    
    set & operator=(const set & src)
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

    void swap (set & x)
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
        return (_comp);
    }

    //
    // Operations
    //
    
    iterator find(const value_type & val) const
    {
        node_pointer node = _tree.find(val);
		if (node)
			return (iterator(node));
		else
            return (const_cast<node_pointer>(_tree.end()));
    }

    size_type count(const value_type & val) const
    {
        const_iterator iter = begin();
		const_iterator end_iter = end();

        while (iter != end_iter)
        {
            if (!_comp(*iter, val) && !_comp(val, *iter))
                return (1);
            ++iter;
        }
        return (0);
    }

    iterator lower_bound(const value_type & val) const
    {
        iterator iter = const_cast<node_pointer>(_tree.begin());
		iterator end_iter = const_cast<node_pointer>(_tree.end());

		while (iter != end_iter)
        {
			if (!_comp(*iter, val))
				return (iter);
			++iter;
		}
		return (end_iter);
    }

    iterator upper_bound(const value_type & val) const
    {
        iterator iter = const_cast<node_pointer>(_tree.begin());
		iterator end_iter = const_cast<node_pointer>(_tree.end());

		while (iter != end_iter)
        {
			if (_comp(val, *iter))
				return (iter);
			++iter;
		}
		return (end_iter);
    }

    ft::pair<iterator,iterator> equal_range(const value_type& val) const {
        return (ft::make_pair(lower_bound(val), upper_bound(val)));
    }
    
    //
    // Allocator member-function
    //
    allocator_type get_allocator(void) const {
        return (_alloc);
    }
};

template < class Key, class Compare, class Alloc >
bool operator==(const set<Key,Compare,Alloc> & lhs,
                        const set<Key,Compare,Alloc> & rhs )
{
    if (lhs.size() != rhs.size())
        return (false);
    typename set<Key,Compare,Alloc>::const_iterator rit = rhs.begin();
    for(typename set<Key,Compare,Alloc>::const_iterator lit = lhs.begin(); lit != lhs.end(); ++lit)
    {
        if (*lit != *rit)
            return (false);
        ++rit;
    }
    return (true);
}

template < class Key, class Compare, class Alloc >
bool operator!=(const set<Key,Compare,Alloc> & lhs,
                        const set<Key,Compare,Alloc> & rhs ) {
    return (!(lhs == rhs));
}

template < class Key, class Compare, class Alloc >
bool operator<(const set<Key,Compare,Alloc> & lhs,
                        const set<Key,Compare,Alloc> & rhs ) {
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template < class Key, class Compare, class Alloc >
bool operator<=(const set<Key,Compare,Alloc> & lhs,
                        const set<Key,Compare,Alloc> & rhs ) {
    return (!(rhs < lhs));
}

template < class Key, class Compare, class Alloc >
bool operator>(const set<Key,Compare,Alloc> & lhs,
                        const set<Key,Compare,Alloc> & rhs ) {
    return (rhs < lhs);
}

template< class Key, class Compare, class Alloc >
bool operator>=(const set<Key,Compare,Alloc> & lhs,
                        const set<Key,Compare,Alloc> & rhs ) {
    return (!(lhs < rhs));
}

template < class Key, class Compare, class Alloc >
void swap(set<Key,Compare,Alloc> & lhs, set<Key,Compare,Alloc> & rhs) {
    lhs.swap(rhs);
}

};

#endif