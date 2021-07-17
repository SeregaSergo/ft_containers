#ifndef TRAITS_HPP
#define TRAITS_HPP

#include <type_traits>
#include <sstream>

namespace ft {

// template<class Iterator>
// struct iterator_traits
// {
//     typedef typename Iterator::difference_type difference_type;
//     typedef typename Iterator::value_type value_type;
//     typedef typename Iterator::pointer pointer;
//     typedef typename Iterator::reference reference;
//     typedef typename Iterator::iterator_category iterator_category;
// };

template <class _Iter, bool> struct __iterator_traits {};

template <class Iterator>
struct __iterator_traits<Iterator, true>
{
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category;
};

template <class _Iter>
struct iterator_traits
    : __iterator_traits<_Iter, std::__has_iterator_typedefs<_Iter>::value> {};

template<class T>
struct iterator_traits<T*>
{
    typedef T                               value_type;
    typedef T*                              pointer;
    typedef T&                              reference;
    typedef ptrdiff_t                       difference_type;
    typedef std::random_access_iterator_tag iterator_category;
};

template <class T>
struct iterator_traits<const T*>
{
    typedef T                               value_type;
    typedef const T*                        pointer;
    typedef const T&                        reference;
    typedef ptrdiff_t                       difference_type;
    typedef std::random_access_iterator_tag iterator_category;
};


// is_integral
// https://habr.com/ru/post/417027/

template <class Tp, Tp V>
struct integral_constant
{
    static const Tp                     value = V;
    typedef Tp                          value_type;
    typedef integral_constant<Tp, V>    type;
};

typedef integral_constant<bool,true>    true_type;
typedef integral_constant<bool,false>   false_type;

template <class _Tp> struct is_integral                     : public false_type{};

template <>          struct is_integral<bool>               : public true_type {};
template <>          struct is_integral<char>               : public true_type {};
template <>          struct is_integral<signed char>        : public true_type {};
template <>          struct is_integral<unsigned char>      : public true_type {};
template <>          struct is_integral<wchar_t>            : public true_type {};
template <>          struct is_integral<short>              : public true_type {};
template <>          struct is_integral<unsigned short>     : public true_type {};
template <>          struct is_integral<int>                : public true_type {};
template <>          struct is_integral<unsigned int>       : public true_type {};
template <>          struct is_integral<long>               : public true_type {};
template <>          struct is_integral<unsigned long>      : public true_type {};
template <>          struct is_integral<long long>          : public true_type {};
template <>          struct is_integral<unsigned long long> : public true_type {};
template <>          struct is_integral<__int128_t>         : public true_type {};
template <>          struct is_integral<__uint128_t>        : public true_type {};


// enable_if
// https://habr.com/ru/post/150654/

template<bool, typename _Tp = void>
struct enable_if {};

// Partial specialization for true.
template<typename _Tp>
struct enable_if<true, _Tp> {
    
    typedef _Tp type;
};

template<class InputIterator>
typename ft::iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
{
    typename ft::iterator_traits<InputIterator>::difference_type dist = 0;
    for (; first != last; ++first)
        ++dist;
    return (dist);
};

template <typename T>
std::string to_string(T smth)
{
    std::ostringstream ss;
    ss << smth;
    return (ss.str());
};

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
{
    while (first1 != last1)
    {
        if (*first2 < *first1 || first2 == last2)
            return false;
        else if (*first1 < *first2)
            return true;
        ++first1;
        ++first2;
    }
    return (first2 != last2);
}

template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2,
                                Compare comp)
{
    while (first1 != last1)
    {
        if (comp(*first2, *first1) || first2 == last2)
            return false;
        else if (comp(*first1, *first2))
            return true;
        ++first1;
        ++first2;
    }
    return (first2 != last2);
}

}

#endif