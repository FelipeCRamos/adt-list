#ifndef _LIST_HPP_
#define _LIST_HPP_

#define debug_state false


using size_type = size_t;

namespace sc
{
	<template T>
		class list{
		private:
			struct Node {
				T data;
				Node *prev;
				Node *next;
			};

			int m_size;
			Node *m_head;
			Node *m_tail;
		public:
		/* Iterators {{{*/
			class iterator{
			private:
				T *m_ptr;
			public:
				// Constructors 
				iterator( T *ptr = nullptr );
				iterator( const iterator & );

				// Destructors
				~iterator(  );

				// Operators
				iterator &operator=( const iterator & );
				T &operator*(  ) const;

				iterator operator++(  );			//!< ++it
				iterator operator++( size_type );	//!< it++
				iterator operator--(  );			//!< --it
				iterator operator--( size_type );	//!< it--
				iterator operator+( size_type );	//!< ptr - size_type
				iterator operator-( size_type );	//!< ptr + size_type

				bool operator==( const iterator & ) const;
				bool operator!=( const iterator & ) const;
			}
			class const_iterator{
			private:
				T *m_ptr;
			}
		/*}}}*/
		/* Constructors, Destructors and Assignment {{{*/
			/** Default constructor that creates an empty list */
			list(  );

			/** Constructs the list with `count` default-inserted instances */		
			explicit list( size_type count );

			/** Constructs the list with the contents of the range [first, last) */	
			template< class InputIt >
			list( InputIt first, InputIt last );

			/** Copy constructor. Constructs the list with the deep copy of other */
			list( const list &other );

			/** Constructs the list with the contents of the initializer list ilist */
			list( std::initializer_list<T> ilist );

			/** Destructs the list  */
			~list(  );

			/** Copy assignment operator */
			list &operator=( const list &other );

			/** Replaces the contents with those identified by initializer list */
			list &operator=( std::initializer_list<T> ilist );
		/*}}}*/

		/* Common operations to all list implementations {{{*/
			/** Return the number of elements in the container */
			size_type size(  ) const;	
			
			/** Remove (either logically or physically) all elements */
			void clear(  );

			/** Returns `true` if the container contains no elements */
			bool empty(  );

			/** Adds `value` to the front of the list */
			void push_front( const T &value );

			/** Adds `value` to the end of the list */
			void push_back( const T &value );

			/** Removes the object at the end of the list */
			void pop_back(  );

			/** Removes the object at the front of the list */
			void pop_front(  );

			/** Returns the object at the end of the list */
			const T &back(  ) const;

			/** Returns the object at the beginning of the list */
			const T &front(  ) const;

			/** Replaces the content of the list with copies of `value` */
			void assign( const T &value );
		/*}}}*/

		/* Operator overloading -- Non-member functions {{{*/ 
			/** Checks if contents of lhs and rhs are equal */
			bool operator==( const list &lhs, const list &rhs );

			/** Checks if contents of lhs and rhs are not equal */
			bool operator!=( const list &lhs, const list &rhs );
		/*}}}*/
		}
}

#endif
