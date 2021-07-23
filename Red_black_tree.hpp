#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include "utils.hpp"
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

    _Node(void) : val(), parent(NULL), left(NULL), right(NULL), red(true) {}

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

    // bool operator==(const _Node& right)
    // {
    //     if (val == right.value)
    //         return (true);
    //     return (false);
    // }
};

template <class T, class Compare = ft::less<T>,
    class Alloc = std::allocator< _Node<T> > >
class Red_black_tree
{
public:
    typedef T                   value_type;
    typedef _Node<T>            node_type;
    typedef size_t              size_type;
	typedef value_type *        pointer;
	typedef value_type const *  const_pointer;
	typedef value_type &        reference;
	typedef value_type const &  const_reference;
    typedef node_type *         node_pointer;
    typedef Alloc               allocator_type;
    typedef std::ptrdiff_t      difference_type;

private:
    node_pointer    _root;
    Compare         _comp;
    allocator_type  _alloc;

    bool    isLeaf(node_pointer n) {
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
        else if (!s->red)
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

    node_pointer minimum(node_pointer n)
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

    int depth(void)
    {
        node_pointer ptr = _root;
        int n = 0;
        while (ptr)
        {
            if (ptr->left)
                ptr = ptr->left;
            else
                ptr = ptr->right;
            ++n;
        }
        return (n);
    }

    node_pointer findNode(const_reference value, node_pointer ptr)
    {
        if (ptr == NULL)
            return (NULL);
        else if (_comp(value, ptr->val))
            return (findNode(value, ptr->left));
        else if (_comp(ptr->val, value))
            return (findNode(value, ptr->right));
        else
            return (ptr);
    }

    template <class S>
    void printHelper(node_pointer root, std::string indent, bool last, S & out)
    {
	   	if (root != NULL) {
		   out << indent;
		   if (last) {
		      out << "R----";
		      indent += "     ";
		   } else {
		      out << "L----";
		      indent += "|    ";
		   }
            
           std::string sColor = root->red? "(R)" : "(B)";
		   out << root->val << sColor <<std::endl;
		   printHelper<S>(root->left, indent, false, out);
		   printHelper<S>(root->right, indent, true, out);
		}
	}


public:
    Red_black_tree(void) : _root(NULL) {}

	Red_black_tree(Red_black_tree const & src)
    {}

	virtual ~Red_black_tree(void)
    {}

    void insert(const_reference val)
    {
        node_pointer node = _alloc.allocate(1);
        node_pointer parent = NULL;
		node_pointer pos = _root;

		while (pos != NULL) {
			parent = pos;
			if (_comp(val, pos->val)) {
				pos = pos->left;
			} else {
				pos = pos->right;
			}
		}

        if (parent == NULL)
        {
            _alloc.construct(node, node_type(val, false));
			_root = node;
            return ;
		}
        else
        {
            _alloc.construct(node, node_type(val));
            node->parent = parent;
            if (_comp(val, parent->val))
			    parent->left = node;
            else
			    parent->right = node;
		}
        
        fixTreeInsert(node);
    }

    void erase(const_reference value)
    {
        node_pointer to_del = find(value);
        if (to_del == NULL)
            return;

        else if (to_del->left != NULL && to_del->right != NULL)
        {
            node_pointer tmp = maximum(to_del->left);
            to_del->val = tmp->val;
            to_del = tmp;
        }

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
    }


    node_pointer find(const_reference value) {
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

    node_pointer min(void) {
        if (_root == NULL)
            return (NULL);
        return (minimum(_root));
    }

    node_pointer max(void) {
        if (_root == NULL)
            return (NULL);
        return (maximum(_root));
    }

    template <class S>
    void print(S & out)
    {
        if (_root)
            printHelper<S>(this->_root, "", true, out);
    }
};

}

#endif