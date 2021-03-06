#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include "./utils/utils.hpp"
#include <iostream>

namespace ft
{

template <class T>
struct _Node
{
    T           val;
    _Node*      parent;
    _Node*      left;
    _Node*      right;
    bool        red;

    _Node (_Node* left = NULL, _Node* right = NULL, _Node* parent = NULL)
            : val(), parent(parent), left(left), right(right), red(true) {}
    
    _Node (const T & val, bool red = true, _Node* left = NULL, _Node* right = NULL, _Node* parent = NULL)
            : val(val), parent(parent), left(left), right(right), red(red) {}

    _Node (const _Node & src) : val(src.val), parent(src.parent),
            left(src.left), right(src.right), red(src.red) {}

    virtual ~_Node(void) {}

    _Node & operator=(const _Node & src)
    {
        if (src == *this)
            return (*this);
        val = src.val;
        parent = src.parent;
        left = src.left;
        right = src.right;
        red = src.red;
        return (*this);
    }

};

template < class T, class N >
class _TreeIterator
{
public:
	typedef T                               value_type;
    typedef value_type *                    pointer;
    typedef value_type const *              const_pointer;
    typedef value_type &                    reference;
    typedef value_type const &              const_reference;
	typedef std::ptrdiff_t                  difference_type;
    typedef N                               node_type;
	typedef node_type *                     node_pointer;
    typedef std::bidirectional_iterator_tag iterator_category;

private:
	node_pointer _ptr;

    void next(void)
    {
		if (_ptr->right != NULL)
        {
            _ptr = _ptr->right;
			while (_ptr->left)
                _ptr = _ptr->left;
        }
        else
        {
            node_pointer prev = _ptr;
            _ptr = _ptr->parent;
            while (_ptr != NULL && _ptr->left != prev)
            {
                prev = _ptr;
                _ptr = _ptr->parent;
            }
        }
	}

    void prev(void)
    {
		if (_ptr->left != NULL)
        {
            _ptr = _ptr->left;
			while (_ptr->right)
                _ptr = _ptr->right;
        }
        else
        {
            node_pointer prev = _ptr;
            _ptr = _ptr->parent;
            while (_ptr != NULL && _ptr->right != prev)
            {
                prev = _ptr;
                _ptr = _ptr->parent;
            }
		}
	}

public:
	_TreeIterator(void): _ptr(NULL) {}
	_TreeIterator(node_pointer ptr): _ptr(ptr) {}
	_TreeIterator(_TreeIterator const & src): _ptr(src._ptr) {}
	virtual ~_TreeIterator(void) {}

    node_pointer base(void) const {
        return (_ptr);
    }

    _TreeIterator & operator=(_TreeIterator const & src) {
		_ptr = src._ptr;
		return (*this);
	}

	reference operator*() const {
		return (_ptr->val);
	}

	pointer operator->() const {
		return (&_ptr->val);
	}

    _TreeIterator & operator++() {
		next();
		return (*this);
	}

	_TreeIterator operator++(int) {
		_TreeIterator tmp(*this);
		next();
		return (tmp);
	}
	
    _TreeIterator & operator--() {
		prev();
		return (*this);
	}

	_TreeIterator operator--(int) {
		_TreeIterator tmp(*this);
		prev();
		return (tmp);
	}

	bool operator==(_TreeIterator const & r) const {
		return (_ptr == r._ptr);
	}

	bool operator!=(_TreeIterator const & r) const {
		return (_ptr != r._ptr);
	}
};

template < class T, class N >
class _TreeConstIterator
{
public:
	typedef T                               value_type;
    typedef value_type *                    pointer;
    typedef value_type const *              const_pointer;
    typedef value_type &                    reference;
    typedef value_type const &              const_reference;
	typedef std::ptrdiff_t                  difference_type;
    typedef N                               node_type;
	typedef node_type *                     node_pointer;
    typedef node_type const *               const_node_pointer;
    typedef std::bidirectional_iterator_tag iterator_category;

private:
	const_node_pointer _ptr;

    void next(void)
    {
		if (_ptr->right != NULL)
        {
            _ptr = _ptr->right;
			while (_ptr->left)
                _ptr = _ptr->left;
        }
        else
        {
            const_node_pointer prev = _ptr;
            _ptr = _ptr->parent;
            while (_ptr != NULL && _ptr->left != prev)
            {
                prev = _ptr;
                _ptr = _ptr->parent;
            }
        }
	}

    void prev(void)
    {
		if (_ptr->left != NULL)
        {
            _ptr = _ptr->left;
			while (_ptr->right)
                _ptr = _ptr->right;
        }
        else
        {
            const_node_pointer prev = _ptr;
            _ptr = _ptr->parent;
            while (_ptr != NULL && _ptr->right != prev)
            {
                prev = _ptr;
                _ptr = _ptr->parent;
            }
		}
	}

public:
	_TreeConstIterator(void): _ptr(NULL) {}
	_TreeConstIterator(const_node_pointer ptr): _ptr(ptr) {}
	_TreeConstIterator(_TreeConstIterator const & src): _ptr(src._ptr) {}
    _TreeConstIterator(_TreeIterator<T, N> const & src): _ptr(src.base()) {}
	virtual ~_TreeConstIterator(void) {}

    const_node_pointer base(void) {
        return (_ptr);
    }

    _TreeConstIterator & operator=(_TreeConstIterator const & src) {
		_ptr = src._ptr;
		return (*this);
	}

	const_reference operator*() const {
		return (_ptr->val);
	}

	const_pointer operator->() const {
		return (&_ptr->val);
	}

    _TreeConstIterator & operator++() {
		next();
		return (*this);
	}

	_TreeConstIterator operator++(int) {
		_TreeConstIterator tmp(*this);
		next();
		return (tmp);
	}
	
    _TreeConstIterator & operator--() {
		prev();
		return (*this);
	}

	_TreeConstIterator operator--(int) {
		_TreeConstIterator tmp(*this);
		prev();
		return (tmp);
	}

	bool operator==(_TreeConstIterator const & r) const {
		return (_ptr == r._ptr);
	}

	bool operator!=(_TreeConstIterator const & r) const {
		return (_ptr != r._ptr);
	}
};

template <class T, class Compare = ft::less<T>,
        class Alloc = std::allocator<T> >
class tree
{
public:
    typedef T                                       value_type;
    typedef _Node<T>                                node_type;
    typedef size_t                                  size_type;
	typedef value_type *                            pointer;
	typedef value_type const *                      const_pointer;
	typedef value_type &                            reference;
	typedef value_type const &                      const_reference;
    typedef node_type *                             node_pointer;
    typedef node_type const *                       const_node_pointer;
    typedef Alloc                                   allocator_type;
    typedef std::ptrdiff_t                          difference_type;
    typedef _TreeIterator<value_type, node_type>    iterator;
    typedef _TreeConstIterator<value_type,
                                node_type>          const_iterator;
    typedef typename Alloc::template 
                rebind<node_type>::other            node_allocator_type;

private:
    node_pointer            _root;
    node_pointer            _begin;
    node_pointer            _end;
    Compare                 _comp;
    node_allocator_type     _alloc;

    bool    isLeaf(node_pointer n)
    {
        return (n->left == NULL && n->right == NULL);
    }

    void replace_node_with_child(node_pointer n, node_pointer child)
    {
        if (child != NULL)
            child->parent = n->parent;
        if (n != _root)
        {
            if (n == n->parent->left)
                n->parent->left = child;
            else
                n->parent->right = child;
        }
        else
            _root = child;
    }

    node_pointer grandparent(node_pointer n)
    {
        if ((n != NULL) && (n->parent != NULL))
            return n->parent->parent;
        else
            return NULL;
    }

    node_pointer uncle(node_pointer n)
    {
        node_pointer g = grandparent(n);
        if (g == NULL)
            return NULL;
        if (n->parent == g->left)
            return g->right;
        else
            return g->left;
    }

    node_pointer sibling(node_pointer n)
    {
        if (n == n->parent->left)
            return n->parent->right;
        else
            return n->parent->left;
    }

    /*       |                  |
    **       n                pivot
    **     /   \              /   \
    **    x   pivot  ==>     n     z
    **        /   \        /   \
    **       y     z      x     y
    */
    void rotate_left(node_pointer n)
    {
        node_pointer pivot = n->right;
        
        pivot->parent = n->parent;
        if (pivot->parent == NULL)
            _root = pivot;
        if (n->parent != NULL) {
            if (n->parent->left == n)
                n->parent->left = pivot;
            else
                n->parent->right = pivot;
        }		
        
        n->right = pivot->left;
        if (pivot->left != NULL)
            pivot->left->parent = n;

        n->parent = pivot;
        pivot->left = n;
    }

    /*        |             |
    **        n           pivot
    **      /   \         /   \
    **   pivot   z  ==>  x     n
    **   /   \               /   \
    **  x     y             y     z
    */
    void rotate_right(node_pointer n)
    {
        node_pointer pivot = n->left;
        
        pivot->parent = n->parent;
        if (pivot->parent == NULL)
            _root = pivot;
        if (n->parent != NULL) {
            if (n->parent->left==n)
                n->parent->left = pivot;
            else
                n->parent->right = pivot;
        }		
        
        n->left = pivot->right;
        if (pivot->right != NULL)
            pivot->right->parent = n;

        n->parent = pivot;
        pivot->right = n;
    }

    void fixTreeInsert(node_pointer n)
    {
        node_pointer u = uncle(n);
        node_pointer g = grandparent(n);

        if (n->parent == NULL)   // case 1 (N is root)
            n->red = false;
        else if (!n->parent->red) // case 2 (P is black: nothing to do)
            return;
        else if ((u != NULL) && (u->red)) // case 3 (P & U are red: recolor)
        {
            n->parent->red = false;
            u->red = false;
            g->red = true;
            fixTreeInsert(g);
        }
        else if (n->parent == g->left)  // case 4 (P is left child of G: rotate 1-2 times)
        {
            if (n == n->parent->right)  // (N is inside: make it outer)
            {
                rotate_left(n->parent);
                n = n->left;
                g = grandparent(n);
            }
            n->parent->red = false;     // (N is outside)
            g->red = true;
            rotate_right(g);
        }
        else  // n->parent == grandparent(n)->right
        {
            if (n == n->parent->left)   // (N is inside: make it outer)
            {
                rotate_right(n->parent);
                n = n->right;
                g = grandparent(n);
            }
            n->parent->red = false;     // (N is outside)
            g->red = true;
            rotate_left(g);
        }
    }
    
    void    fixTreeDelete(node_pointer n)
    {
        if (n->parent == NULL)              // case 1
            return;

        node_pointer s = sibling(n);
        if (s->red)                         // case 2
        {
            n->parent->red = true;
            s->red = false;
            if (n == n->parent->left)
                rotate_left(n->parent);
            else
                rotate_right(n->parent);
            s = sibling(n);
        }
        if ((!n->parent->red) && (!s->red) && 
            (!s->left || !s->left->red) &&
            (!s->right || !s->right->red))          // case 3
        {
            s->red = true;
            fixTreeDelete(n->parent);
        }
        else
            fixTreeDelete2(n);
        
    }

    void    fixTreeDelete2(node_pointer n)
    {
        node_pointer s = sibling(n);
        if ((n->parent->red) && (!s->red) &&
            (!s->left || !s->left->red) &&
            (!s->right || !s->right->red))          // case 4
        {
            s->red = true;
            n->parent->red = false;
        }
        else 
        {
            if (!s->red)
            {
                if ((n == n->parent->left) &&
                    (!s->right || !s->right->red) &&
                    (s->left && s->left->red))
                {
                    s->red = true;
                    s->left->red = false;
                    rotate_right(s);
                }
                else if ((n == n->parent->right) &&
                        (!s->left || !s->left->red) &&
                        (s->right && s->right->red))
                {
                    s->red = true;
                    s->right->red = false;
                    rotate_left(s);
                }
            }
            s = sibling(n);
            s->red = n->parent->red;
            n->parent->red = false;
            if (n == n->parent->left)
            {
                if (s->right)
                    s->right->red = false;
                rotate_left(n->parent);
            }
            else
            {
                if (s->left)
                    s->left->red = false;
                rotate_right(n->parent);
            }
        }
    }

    // node_pointer    findParentHint(const_reference val, iterator hint)
    // {
    //     iterator prev = hint;
    //     iterator end(_end);
    //     iterator begin(_begin);

    //     if (hint != end && _comp(*hint, val))
    //     {
    //         while (hint != end && _comp(*hint, val))
    //             prev = hint++;
    //         if (hint == end)
    //             return (prev.base());
    //         return (hint.base());
    //     }
    //     else
    //     {
    //         while (hint != begin && _comp(val, *hint))
    //             prev = hint--;
    //         if (hint == begin)
    //             return (hint.base());
    //         return (prev.base());
    //     }
    // }

    node_pointer    findParentHint(const_reference val, iterator hint)
    {
        iterator end(_end);

        if (hint != end && _comp(*hint, val))
        {
            iterator prev = hint;
            ++hint;
            if (hint == end)
                return (prev.base());
            if (_comp(val, *hint))
                return (hint.base());
        }
        return (findParentRoot(val));
    }

    node_pointer    findParentRoot(const_reference val)
    {
        node_pointer parent = _end;
        node_pointer pos = _root;

		while (pos != NULL && pos != _end) {
			parent = pos;
			if (_comp(val, pos->val))
				pos = pos->left;
            else
				pos = pos->right;
		}
        return (parent);
    }

    node_pointer minimum(node_pointer n) const
    {
        while (n->left)
            n = n->left;
        return (n);
    }

    node_pointer maximum(node_pointer n)
    {
        while (n->right)
            n = n->right;
        return (n);
    }

    node_pointer findNode(const_reference value, node_pointer ptr)
    {
        if (ptr == NULL || ptr == _end)
            return (NULL);
        else if (_comp(value, ptr->val))
            return (findNode(value, ptr->left));
        else if (_comp(ptr->val, value))
            return (findNode(value, ptr->right));
        else
            return (ptr);
    }

    node_pointer findNode(const_reference value, node_pointer ptr) const
    {
        if (ptr == NULL || ptr == _end)
            return (NULL);
        else if (_comp(value, ptr->val))
            return (findNode(value, ptr->left));
        else if (_comp(ptr->val, value))
            return (findNode(value, ptr->right));
        else
            return (ptr);
    }

    // template <class S>
    // void printHelper(node_pointer root, std::string indent, bool last, S & out) const
    // {
	//    	if (root != NULL && root != _end)
    //     {
	// 	   out << indent;
	// 	   if (last) {
	// 	      out << "R----";
	// 	      indent += "     ";
	// 	   } else {
	// 	      out << "L----";
	// 	      indent += "|    ";
	// 	   }
            
    //        std::string sColor = root->red? "(R)" : "(B)";
	// 	   out << to_string(root->val) << sColor << std::endl;
	// 	   printHelper<S>(root->left, indent, false, out);
	// 	   printHelper<S>(root->right, indent, true, out);
	// 	}
	// }

    void    clearRecursive(node_pointer n)
    {
        if (n == NULL)
            return;
        clearRecursive(n->right);
        clearRecursive(n->left);
        _alloc.destroy(n);
        _alloc.deallocate(n, 1);
    }

    void    clear_subtree(node_pointer n)
    {
        if (n->parent != NULL)
        {
            if (n == n->parent->left)
                n->parent->left = NULL;
            else
                n->parent->right = NULL;
        }
        clearRecursive(n);
    }

    node_pointer copyRecursive(node_pointer src, node_pointer parent)
    {
        if (src == NULL)
            return (NULL);
        node_pointer tmp = _alloc.allocate(1);
        _alloc.construct(tmp, *src);
        tmp->parent = parent;
        tmp->left = copyRecursive(src->left, tmp);
        tmp->right = copyRecursive(src->right, tmp);
        return (tmp);
    }

    void    init_tree(void)
    {
        _root = _alloc.allocate(1);
        _alloc.construct(_root, node_type());
        _root->red = false;
		_begin = _root;
		_end = _begin;
	}

    void    restore_edges(void)
    {
        if (_root == NULL)
        {
            _root = _end;
            _end->parent = NULL;
            _begin = _end;
        }
        else
        {
            _end->parent = maximum(_root);
		    _end->parent->right = _end;
            _begin = minimum(_root);
        }
    }

    void    untie_end_edge(void)
    {
        if (_end->parent)
			_end->parent->right = NULL;
    }

    void swap_nodes(node_pointer x,node_pointer y)
    {   
        node_pointer x_parent = y->parent;
        node_pointer x_left = y->left;
        node_pointer x_right = y->right;
        node_pointer * x_parent_pointer = &_root;
        if (y->parent)
            x_parent_pointer = y->parent->left == y ? &y->parent->left : &y->parent->right;

        node_pointer y_parent = x->parent;
        node_pointer y_left = x->left;
        node_pointer y_right = x->right;
        node_pointer * y_parent_pointer = &_root;
        if (x->parent)
            y_parent_pointer = x->parent->left == x ? &x->parent->left : &x->parent->right;

        // if x and y are adjacent nodes
        if (y->parent == x)
        {
            x_parent = y;
            x_parent_pointer = NULL;
            if (x->left == y)
                y_left = x;
            else
                y_right = x;
        }
        else if (x->parent == y)
        {
            y_parent = x;
            y_parent_pointer = NULL;
            if (y->left == x)
                x_left = y;
            else
                x_right = y;
        }

        x->parent = x_parent;
        x->left = x_left;
        if (x->left)
            x->left->parent = x;
        x->right = x_right;
        if (x->right)
            x->right->parent = x;
        if (x_parent_pointer)
            *x_parent_pointer = x;

        y->parent = y_parent;
        y->left = y_left;
        if (y->left)
            y->left->parent = y;
        y->right = y_right;
        if (y->right)
            y->right->parent = y;
        if (y_parent_pointer)
            *y_parent_pointer = y;
        
        bool tmp = x->red;
        x->red = y->red;
        y->red = tmp;
    }

public:

    tree(void) : _comp() {
        init_tree();
    }

    tree(Compare const & comp) : _comp(comp) {
        init_tree();
    }

	tree(tree const & src) : _comp(src._comp)
    {
        this->_root = copyRecursive(src._root, NULL);
        this->_begin = minimum(this->_root);
		this->_end = maximum(this->_root);
    }

	virtual ~tree(void) {
        clear_subtree(_root);
    }

    tree & operator=(tree const & src)
    {
        if (this == &src)
            return (*this);
        clear_subtree(_root);
        _comp = src._comp;
        _root = copyRecursive(src._root, NULL);
		return (*this);
	}

    ft::pair<iterator, bool>    insert(const_reference val)
    {
        node_pointer parent = find(val);

        if (parent)
            return (ft::make_pair<iterator, bool>(iterator(parent), false));

        return (insert_base(findParentRoot(val), val));
    }

    ft::pair<iterator, bool>    insert_hint(iterator const & hint, const_reference val)
    {	
        node_pointer parent = find(val);

        if (parent)
            return (ft::make_pair<iterator, bool>(iterator(parent), false));

        return (insert_base(findParentHint(val, hint), val));
    }

    ft::pair<iterator, bool>    insert_base(node_pointer parent, const_reference val)
    {
        node_pointer node = _alloc.allocate(1);

        untie_end_edge();

        if (parent == _end)
        {
            _alloc.construct(node, node_type(val, false));
			_root = node;
		}
        else
        {
            _alloc.construct(node, node_type(val));
            node->parent = parent;
            if (_comp(val, parent->val))
			    parent->left = node;
            else
			    parent->right = node;
            fixTreeInsert(node);
		}

        restore_edges();

        return (ft::make_pair<iterator, bool>(iterator(node), true));
    }

    size_type erase(const_reference value)
    {
        node_pointer to_del = find(value);

        if (to_del == NULL)
            return (0);
        else
            return (erase_node(to_del));
    }

    size_type erase_node(node_pointer to_del)
    {
        untie_end_edge();

        if (to_del->left != NULL && to_del->right != NULL)
            swap_nodes(to_del, maximum(to_del->left));

        // In all cases node to delete has at maximum one child. 

        node_pointer child = to_del->right ? to_del->right : to_del->left;
    
        if (!to_del->red)
        {
            if (child && child->red)
                child->red = false;
            else
                fixTreeDelete(to_del);   // yes, we can do this
        }
        replace_node_with_child(to_del, child);
        _alloc.destroy(to_del);
        _alloc.deallocate(to_del, 1);
        restore_edges();
        return (1);
    }


    node_pointer find(const_reference value) {
        return(findNode(value, _root));
    }

    node_pointer find(const_reference value) const {
        return(findNode(value, _root));
    }

    node_pointer successor(node_pointer n)
    {
		if (n->right != NULL)
			return minimum(n->right);

		node_pointer p = n->parent;
		while (p != NULL && n != p->left)
        {
			n = p;
			p = p->parent;
		}
		return (p);
	}

    node_pointer predecessor(node_pointer n)
    {
		if (n->left != NULL)
			return maximum(n->left);

		node_pointer p = n->parent;
		while (p != NULL && n != p->right)
        {
			n = p;
			p = p->parent;
		}
		return (p);
	}

    node_pointer begin(void) {
        return (_begin);
    }

    const_node_pointer begin(void) const {
        return (_begin);
    }

    node_pointer end(void) {
        return (_end);
    }

    const_node_pointer end(void) const {
        return (_end);
    }

    void clear(void)
    {
        clear_subtree(_root);
        init_tree();
    }

    size_type max_size(void) const {
        return (_alloc.max_size());
    }

    void swap(tree<T, Compare, Alloc> & x)
    {
        if (&x == this)
            return ;
        
        node_pointer r = this->_root;
        node_pointer b = this->_begin;
        node_pointer e = this->_end;
        this->_root = x._root;
        this->_begin = x._begin;
        this->_end = x._end;
        x._root = r;
        x._begin = b;
        x._end = e;
    }

    // template <class S>
    // void print(S & out) const
    // {
    //     if (_begin != _end)
    //         printHelper<S>(this->_root, "", true, out);
    // }
};

}

#endif