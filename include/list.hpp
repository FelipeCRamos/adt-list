#ifndef _LIST_HPP_ #define _LIST_HPP_
#include <iostream>
#include <cmath>
#include <algorithm>

#define debug_state false

/*
 * 	\file	list.hpp
 * 	\author	Felipe Ramos
 */

using size_type = size_t;
using value_type = int;

namespace sc
{
	/** Consists in the implementation of a double linked list using classes. */
	template <class T>
		class list{
		private:
			/** Contains nodes previous/next adresses, and it's data. */
			struct Node {
				T data;
				Node *prev;
				Node *next;
				Node( T d = T(), Node *p = nullptr, Node *n = nullptr ):
					data(d), prev(p), next(n){}
			};

			size_type m_size;			//!< Total size of the list
			Node *m_head;				//!< Head node of the list
			Node *m_tail;				//!< Tail node of the list
		public:
		/* Iterators {{{*/
			/** A simple const_iterator class */
			class const_iterator{
/* Declaration {{{*/
				public:
					/** Default const_iterator initializer */
					const_iterator() = default;

					/** Default const_iterator dereferencier */
					const T &operator*() const;

					/** Overload on the ++it operator */
					const_iterator &operator++();

					/** Overload on the it++ operator */
					const_iterator operator++( value_type );

					/** Overload on the --it operator */
					const_iterator &operator--();

					/** Overload on the it-- operator */
					const_iterator operator--( value_type );

					/** Overload on the it - value operator */
					const_iterator &operator-( value_type );

					/** Overload on the it + value operator */
					const_iterator &operator+( value_type );

					/** Overload on the == operator */
					bool operator==( const const_iterator & ) const;

					/** Overload on the != operator */
					bool operator!=( const const_iterator & ) const;

				protected:
					/** Current Node that the iterator is on */
					Node *current;

					/** Initialize the const_iterator to a Node */
					const_iterator( Node *p ): current(p){}

					/** Get's access to list<T> methods */
					friend class list<T>;
			};
/*}}}*/

			/** A simple iterator class */
			class iterator: public const_iterator{
			/* Declaration {{{*/
				public:

					/** Default initializes the iterator() with const_iterator() methods */
					iterator() : const_iterator(){}

					/** Default desreferencier of the iterator class */
					T &operator*();

					/** Overload on the ++it operator */
					iterator &operator++();

					/** Overload on the it++ operator */
					iterator operator++( value_type );

					/** Overload on the --it operator */
					iterator &operator--();

					/** Overload on the it-- operator */
					iterator operator--( value_type );

					/** Overload on the it - value operator */
					iterator &operator-( value_type );

					/** Overload on the it + value operator */
					iterator &operator+( value_type );

					/** Overload on the == operator */
					bool operator==( const iterator & ) const;

					/** Overload on the != operator */
					bool operator!=( const iterator & ) const;


				protected:
					/** Default initializes the iterator with a node */
					iterator( Node *p ): const_iterator(p) {}

					/** Get's access to all list<T> methods */
					friend class list<T>;
			};
			/*}}}*/

			/** A normal iterator to the begin of the list */
			iterator begin();

			/** A normal iterator to the end of the list */
			iterator end();

			/** A constant iterator to the begin of the list */
			const_iterator cbegin() const;

			/** A constant iterator to the end of the list */
			const_iterator cend() const;

		/*}}}*/

		/* Constructors, Destructors and Assignment {{{*/
			/** Default constructor that creates an empty list. */

			void init();

			list(  );

			/** Constructs the list with `count` default-inserted instances. */		
			explicit list( size_type count );

			/** Constructs the list with the contents of the range [first, last). */	
			template <class InitIt>
			list( InitIt first, InitIt last );

			/** Copy constructor. Constructs the list with the deep copy of other. */
			list( const list &other );

			/** Constructs the list with the contents of the initializer list ilist. */
			list( std::initializer_list<T> ilist );

			/** Destructs the list  */
			~list(  );

			/** Copy assignment operator */
			list &operator=( const list &other );

			/** Replaces the contents with those identified by initializer list */
			list &operator=( std::initializer_list<T> ilist );
		/*}}}*/

		/* Common operations to all list implementations {{{*/
			/** Return the number of elements in the container. */
			size_type size(  ) const;	
			
			/** Remove (either logically or physically) all elements. */
			void clear(  );

			/** Returns `true` if the container contains no elements. */
			bool empty(  );

			/** Adds `value` to the front of the list. 
			 * \param 	const T &value : Whatever we want to add to the end of a
			 * list, must followup with list's class.
			 */
			void push_front( const T &value );

			/** Adds `value` to the end of the list.
			 * \param const T &value : Whatever we want to add to the beggining
			 * of the list, must follow-up with list's class.
			 */
			void push_back( const T &value );

			/** Removes the object at the end of the list. */
			void pop_back(  );

			/** Removes the object at the front of the list. */
			void pop_front(  );

			/** Returns the object at the end of the list. */
			const T &back(  ) const;

			/** Returns the object at the beginning of the list. */
			const T &front(  ) const;

			/** Replaces the content of the list with copies of `value`. */
			void assign( const T &value );
		/*}}}*/

		/* Operator overloading -- Non-member functions {{{*/ 
			/** Checks if contents of lhs and rhs are equal.
			 * \param 	const list &rhs : The list that we want to make the
			 * comparisson.
			 * \return 	True if they're equal, false otherwise. */
			bool operator==( const list &rhs );

			/** Checks if contents of lhs and rhs are not equal.
			 * \param 	const list &rhs : The list that we want to make the
			 * comparisson.
			 * \return 	True if they're not equal, false otherwise. */
			bool operator!=( const list &rhs );
		/*}}}*/

		/* List container operations that require iterators {{{*/


			/** Adds value into the list before the position given */
			iterator insert( list::iterator, const T & );

			/** Inserts elements from the range [first, last) before position given. */
			template <class InitIt>
			iterator insert( list::iterator, InitIt, InitIt );

			/** Inserts elements from the initializer list before position given. */
			iterator insert( list::const_iterator , std::initializer_list<T> );

			/** Removes the object at position pos. */
			iterator erase( list::iterator );

			/** Removes the object(s) on the range [first, last). */
			iterator erase( list::iterator, list::iterator );

			/** Replaces the contents of the list with copies of the elements
			 * in the range [first, last).*/
			void assign( T, T );

			/** Replaces the contents of the list with elements from the
			 * initializer list `ilist`. */
			void assign( std::initializer_list<T> );

		/*}}}*/

		};

/* Source code {{{*/
/* Iterators sources {{{*/

/* const_iterator sources {{{*/
	// TODO: Make const_iterator a real const_iterator
	template <class T>
	const T &sc::list<T>::const_iterator::operator*() const{
	/* Function implementation {{{*/
		return this->current->data;
	}
	/*}}}*/

	template <class T>
	typename sc::list<T>::const_iterator &sc::list<T>::const_iterator::operator++(){
	/* Function implementation {{{*/
		this->current = this->current->next;
		return *this;
	}
	/*}}}*/

	template <class T>
	typename sc::list<T>::const_iterator sc::list<T>::const_iterator::operator++( value_type ){
	/* Function implementation {{{*/
		auto copy = *this;
		this->current = this->current->next;
		return copy;
	}
	/*}}}*/

	template <class T>
	typename sc::list<T>::const_iterator &sc::list<T>::const_iterator::operator--(){
	/* Function implementation {{{*/
		this->current = this->current->prev;
		return *this;
	}
	/*}}}*/

	template <class T>
	typename sc::list<T>::const_iterator sc::list<T>::const_iterator::operator--( value_type ){
	/* Function implementation {{{*/
		auto copy = *this;
		this->current = this->current->prev;
		return copy;
	}
	/*}}}*/

	template <class T>
	typename sc::list<T>::const_iterator &sc::list<T>::const_iterator::operator+( value_type add ){
	/* Function implementation {{{*/
		for( int i = 0; i < add; ++i ){
			if( this->current == nullptr ){
				// TODO: Throw exp
			}
			this->current = this->current->next;
		}
		return *this;
	}
	/*}}}*/

	template <class T>
	typename sc::list<T>::const_iterator &sc::list<T>::const_iterator::operator-( value_type sub ){
/* Function implementation {{{*/
		for( int i = 0; i < sub; ++i ){
			if( this->current == nullptr ){
				// TODO: Throw exp
			}
			this->current = this->current->prev;
		}
		return *this;
	}
/*}}}*/

	template <class T>
	bool sc::list<T>::const_iterator::operator==( const const_iterator &rhs ) const{
	/* Function implementation {{{*/
		return this->current == rhs.current;
	}
	/*}}}*/

	template <class T>
	bool sc::list<T>::const_iterator::operator!=( const const_iterator &rhs ) const{
	/* Function implementation {{{*/
		return this->current != rhs.current;
	}
	/*}}}*/
	/*}}}*/

/* iterator sources {{{*/
	template <class T>
	T &sc::list<T>::iterator::operator*(){
	/* Function implementation {{{*/
		return this->current->data;
	}
	/*}}}*/

	template <class T>
	typename sc::list<T>::iterator &sc::list<T>::iterator::operator++(){
	/* Function implementation {{{*/
		this->current = this->current->next;
		return *this;
	}
	/*}}}*/

	template <class T>
	typename sc::list<T>::iterator sc::list<T>::iterator::operator++( value_type ){
	/* Function implementation {{{*/
		auto copy = *this;
		this->current = this->current->next;
		return copy;
	}
	/*}}}*/

	template <class T>
	typename sc::list<T>::iterator &sc::list<T>::iterator::operator--(){
	/* Function implementation {{{*/
		this->current = this->current->prev;
		return *this;
	}
	/*}}}*/

	template <class T>
	typename sc::list<T>::iterator sc::list<T>::iterator::operator--( value_type ){
	/* Function implementation {{{*/
		auto copy = *this;
		this->current = this->current->prev;
		return copy;
	}
	/*}}}*/

	template <class T>
	typename sc::list<T>::iterator &sc::list<T>::iterator::operator+( value_type add ){
	/* Function implementation {{{*/
		for( int i = 0; i < add; ++i ){
			if( this->current == nullptr ){
				// TODO: Throw exp
			}
			this->current = this->current->next;
		}
		return *this;
	}
	/*}}}*/

	template <class T>
	typename sc::list<T>::iterator &sc::list<T>::iterator::operator-( value_type sub ){
/* Function implementation {{{*/
		for( int i = 0; i < sub; ++i ){
			if( this->current == nullptr ){
				// TODO: Throw exp
			}
			this->current = this->current->prev;
		}
		return *this;
	}
/*}}}*/

	template <class T>
	bool sc::list<T>::iterator::operator==( const iterator &rhs ) const{
	/* Function implementation {{{*/
		return this->current == rhs.current;
	}
	/*}}}*/

	template <class T>
	bool sc::list<T>::iterator::operator!=( const iterator &rhs ) const{
	/* Function implementation {{{*/
		return this->current != rhs.current;
	}
	/*}}}*/
/*}}}*/

//=============================================================================

	template <class T>
	typename sc::list<T>::iterator sc::list<T>::begin(){
/* Function implementation {{{*/
		return sc::list<T>::iterator(this->m_head->next);
	}
/*}}}*/
		
	template <class T>
	typename sc::list<T>::iterator sc::list<T>::end(){
/* Function implementation {{{*/
		return sc::list<T>::iterator(this->m_tail);
	}
/*}}}*/
		
	template <class T>
	typename sc::list<T>::const_iterator sc::list<T>::cbegin() const{
/* Function implementation {{{*/
		return sc::list<T>::const_iterator(this->m_head->next);
	}
/*}}}*/
		
	template <class T>
	typename sc::list<T>::const_iterator sc::list<T>::cend() const{
/* Function implementation {{{*/
		return sc::list<T>::const_iterator(this->m_tail);
	}
/*}}}*/
	
/*}}}*/

/* Constructors, Destructors and Assignment sources {{{*/
	template <class T>
	void list<T>::init(){
/* Function implementation {{{*/
		this->m_size = 0;
		this->m_head = new Node();
		this->m_tail = new Node();
		this->m_head->next = m_tail;
		this->m_tail->prev = m_head;
		if( debug_state ) std::cout << ">> Init given with success!!" << std::endl;
	 }
/*}}}*/

	template <class T>
	list<T>::list(){
/* Function implementation {{{*/
		init();
	}
/*}}}*/
	
	template <class T>
	list<T>::list( size_type count ){
/* Function implementation {{{*/
		init();
		for( auto i = 0; i < count; i++ ){
			push_back(0);
		}
	}
/*}}}*/
	
	template <class T>
	template <class InitIt>
	list<T>::list( InitIt first, InitIt last ){
	/* Function implementation {{{*/
		init();
		insert( begin(), first, last );
	}
	/*}}}*/
	
	template <class T>
	list<T>::list( const list &other ){
	/* Function implementation {{{*/
		init();
		for( auto i = other.cbegin(); i != other.cend(); i++ ){
			push_back(*i);
		}
	}
	/*}}}*/
	
	template <class T>
	list<T>::list( std::initializer_list<T> ilist ){
	/* Function implementation {{{*/
		init();
		for( auto &i : ilist ){
			push_back(i);
		}
	}
	/*}}}*/
	
	template <class T>
	list<T>::~list(){
	/* Function implementation {{{*/
		Node *temp = this->m_head;	
		while( temp != this->m_tail ){
			temp = temp->next;
			if(temp->prev != this->m_head){
				delete temp->prev;
			}
		}

		delete this->m_head;
		delete this->m_tail;
	}
	/*}}}*/
	
	template <class T>
	list<T> &list<T>::operator=( const list &other ){
	/* Function implementation {{{*/
		clear();
		init();
		for( auto i = other.cbegin(); i != other.cend(); i++ ){
			push_back(*i);
		}
		return *this;
	}
	/*}}}*/

	template <class T>
	list<T> &list<T>::operator=( std::initializer_list<T> ilist ){
	/* Function implementation {{{*/
		clear();
		init();
		for( auto &i : ilist ){
			push_back(i);
		}
		return *this;
	}
	/*}}}*/

/*}}}*/

/* Common operations to all list implementations sources {{{*/
	template <class T>
	size_type list<T>::size() const{
/* Function implementation {{{*/
		return this->m_size;
	}
/*}}}*/

	template <class T>
	void list<T>::clear(){
/* Function implementation {{{*/
		erase(begin(), end());
		this->m_size = 0;
	}
/*}}}*/

	template <class T>
	bool list<T>::empty(){
/* Function implementation {{{*/
		// kinda of ambiguos, but necessary check
		bool cond1 = this->m_head->next == this->m_tail;
		bool cond2 = this->m_tail->prev == this->m_head;
		return cond1 and cond2;
	}
/*}}}*/

	template <class T>
	void list<T>::push_front( const T &value ){
/* Function implementation {{{*/
		Node *push = new Node(value, this->m_head, this->m_head->next);
		this->m_head->next->prev = push;
		this->m_head->next = push;
		this->m_size++;
	}
/*}}}*/

	template <class T>
	void list<T>::push_back( const T &value ){
/* Function implementation {{{*/
		Node *push = new Node(value, this->m_tail->prev, this->m_tail);
		this->m_tail->prev->next = push;
		this->m_tail->prev = push;
		this->m_size++;
	}
/*}}}*/

	template <class T>
	void list<T>::pop_back(){
/* Function implementation {{{*/
		erase( this->m_head->next );
	}
/*}}}*/

	template <class T>
	void list<T>::pop_front(){
/* Function implementation {{{*/
		erase( this->m_tail->prev );
	}
/*}}}*/

	template <class T>
	const T &list<T>::back() const{
	/* Function implementation {{{*/
		return this->m_tail->prev->data;
	}
	/*}}}*/

	template <class T>
	const T &list<T>::front() const{
/* Function implementation {{{*/
		return this->m_head->next->data;
	}
/*}}}*/

	template <class T>
	void list<T>::assign( const T &value ){
	/* Function implementation {{{*/
		for( auto i = begin(); i != end(); i++ ){
			*i = value;
		}	
	}
	/*}}}*/

/*}}}*/

/* Operator overloading -- Non-member functions {{{*/

	template <class T>
	bool list<T>::operator==( const list &rhs ){					// TODO
/* Function implementation {{{*/
		if( this->m_size != rhs.m_size ) return false;
		for( int i = 0; i < m_size; i++ ){
			if( *(cbegin() + i) != *(rhs.cbegin() + i) ) return false;
		}
		return true;
	}
/*}}}*/

	template <class T>
	bool list<T>::operator!=( const list &rhs ){					// TODO
	/* Function implementation {{{*/
		if ((*this) == rhs) return false;
		return true;
	}
	/*}}}*/

/*}}}*/

/* List container operations sources {{{*/

	template <class T>
	typename list<T>::iterator list<T>::insert(	
			list<T>::iterator pos,
			const T &value ){
	/* Function implementation {{{*/
		typename list<T>::Node* inserted =
			new typename list<T>::Node(value, pos.current->prev, pos.current);
		m_size++;
		pos.current->prev->next = inserted;
		pos.current->prev = inserted;
		return inserted;
	}
	/*}}}*/

	template <class T>
	template <class InitIt>
	typename list<T>::iterator list<T>::insert(	
			list<T>::iterator pos,
			InitIt first,
			InitIt last ){
	/* Function implementation {{{*/
		list<T>::iterator itr(pos);		
		int size = 0;
		for( auto i = first; i != last; ++i ){
			itr = list<T>::insert(pos, *i);
			size++;
		}
		if(itr == begin()) return itr;
		return itr - size + 1;
	}
	/*}}}*/

	template <class T>
	typename list<T>::iterator list<T>::insert(	
			list<T>::const_iterator pos,
			std::initializer_list<T> ilist ){
	/* Function implementation {{{*/
		list<T>::iterator itr;	
		for( auto i = ilist.begin(); i < ilist.end(); ++i ){
			itr = list<T>::insert(pos, *i);
		}
		if( itr == begin() ) return itr;
		int size = ilist.size();
		return itr - size + 1;
	}
	/*}}}*/

	template <class T>
	typename list<T>::iterator list<T>::erase( list::iterator pos ){
/* Function implementation {{{*/
		auto ret = list<T>::iterator(pos.current->next);
		if( pos != end() ){
			pos.current->next->prev = pos.current->prev;
			pos.current->prev->next = pos.current->next;
			delete pos.current;
		}
		m_size--;
		return ret;
	}
/*}}}*/

	template <class T>
	typename list<T>::iterator list<T>::erase( list<T>::iterator first, list<T>::iterator last ){
	/* Function implementation {{{*/
		list<T>::iterator itr = erase(first);
		while( itr != last ){
			itr = erase(itr);
		}
		return itr;
	}
	/*}}}*/

	template <class T>
	void list<T>::assign( T first, T last ){
	/* Function implementation {{{*/
		if( this->m_size != 0 ){
			list<T>::clear();
		}	
		insert(begin(), first, last);
	}
	/*}}}*/

	template <class T>
	void list<T>::assign( std::initializer_list<T> ilist ){	
	/* Function implementation {{{*/
		if( this->m_size != 0 ) list<T>::clear();	
		insert(begin(), ilist.begin(), ilist.end());
	}
	/*}}}*/


/*}}}*/

/*}}}*/

}

#endif
