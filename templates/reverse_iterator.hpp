/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 08:24:04 by amahla            #+#    #+#             */
/*   Updated: 2023/01/02 11:56:38 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REVERSE_ITERATOR__
# define __REVERSE_ITERATOR__

# include "metaprog.hpp"
# include <iterator>

namespace ft {


	template< typename It >
	class reverse_iterator : public 
		std::iterator<typename iterator_traits<It>::iterator_category,
				typename iterator_traits<It>::value_type,
				typename iterator_traits<It>::difference_type,
				typename iterator_traits<It>::pointer,
				typename iterator_traits<It>::reference> {

		protected:
			
			It	current;

		public:

			typedef It
				iterator_type;
			typedef typename iterator_traits<It>::difference_type
				difference_type;
			typedef typename iterator_traits<It>::reference
				reference;
			typedef typename iterator_traits<It>::pointer
				pointer;


			reverse_iterator( void ) { }

			explicit reverse_iterator( iterator_type x ) : current(x) { }

			template < class U >
			reverse_iterator(const reverse_iterator<U>	& u)
			{
				typedef typename enable_if< is_same<It, U>::value, U>::type
					__attribute__ ((unused))f;
				current = u;
			}

			iterator_type	base( void ) const
			{
				return this->current;
			}

			reference	operator*( void ) const
			{
				iterator_type tmp = current;
				return *(--tmp);
			}

			pointer	operator->( void ) const
			{
				return &(operator*());
			}

			reverse_iterator	& operator++( void )
			{
				(this->current)--;
				return *this;
			}

			reverse_iterator	operator++( int )
			{
				reverse_iterator tmp = *this;

				(this->current)--;
				return tmp;
			}

			reverse_iterator	& operator--( void )
			{
				(this->current)++;
				return *this;
			}

			reverse_iterator	operator--( int )
			{
				reverse_iterator tmp = *this;

				(this->current)++;
				return tmp;
			}

			reverse_iterator	operator+( difference_type n ) const
			{
				return reverse_iterator(this->current - n);
			}

			reverse_iterator	& operator+=( difference_type n )
			{
				this->current -= n;
				return *this;
			}

			reverse_iterator	operator-( difference_type n ) const
			{
				return reverse_iterator(this->current + n);
			}

			reverse_iterator	& operator-=( difference_type n )
			{
				this->current += n;
				return *this;
			}

			reference	operator[]( difference_type n ) const
			{
				return (this->current)[-n - 1];
			}

	};

	template <class Iterator>
	bool	operator==( const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y )
	{
		return x.base() == y.base();
	}

	template <class Iterator>
	bool	operator<( const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y )
	{
		return x.base() > y.base();
	}

	template <class Iterator>
	bool	operator!=( const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y )
	{
		return x.base() != y.base();
	}

	template <class Iterator>
	bool	operator>( const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y )
	{
		return x.base() < y.base();
	}

	template <class Iterator>
	bool	operator>=( const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y )
	{
		return x.base() <= y.base();
	}

	template <class Iterator>
	bool	operator<=( const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y )
	{
		return x.base() >= y.base();
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type	operator-(
		const reverse_iterator<Iterator>& x,
		const reverse_iterator<Iterator>& y )
	{
		return x.base() - y.base();
	}

	template <class Iterator>
	reverse_iterator<Iterator>	operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& x )
	{
		return reverse_iterator<Iterator>(x.base() - n);
	}

}


#endif
