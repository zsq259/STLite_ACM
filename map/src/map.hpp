/**
 * implement a container like std::map
 */
#ifndef SJTU_MAP_HPP
#define SJTU_MAP_HPP

// only for std::less<T>
#include <functional>
#include <cstddef>
#include "utility.hpp"
#include "exceptions.hpp"

namespace sjtu {

template<
	class Key,
	class T,
	class Compare = std::less<Key>
> class map {
public:
	/**
	 * the internal type of data.
	 * it should have a default constructor, a copy constructor.
	 * You can use sjtu::map as value_type by typedef.
	 */
	typedef pair<const Key, T> value_type; 
	enum Color : bool { RED = false, BLACK = true };
	struct nodebase {
		nodebase *ls = nullptr, *rs = nullptr, *fa = nullptr;
		bool c = RED;
		nodebase(nodebase *p = nullptr, bool c_ = RED) : ls(p),rs(p),fa(p),c(c_) {}
		nodebase(const nodebase &rhs) = default;
		nodebase* nextnode() {
			if (!this->rs) {
				nodebase* p = this;
				while (p) {
					if (p->fa && p == p->fa->ls) return p->fa;
					p = p->fa;
				}
				throw invalid_iterator();
			}
			else {
				nodebase* p = this->rs;
				while (p->ls) p = p->ls;
				return p;
			}
			return nullptr;
		}
		nodebase* prevnode() {
			if (!this->ls) {
				nodebase* p = this;
				while (p) {
					if (p->fa && p == p->fa->rs) return p->fa;
					p = p->fa;
				}
				throw invalid_iterator();
			}
			else {
				nodebase* p = this->ls;
				while (p->rs) p = p->rs;
				return p;
			}
			return nullptr;
		}
	};
	class node : public nodebase{
	public:
		value_type o;
		node() {}
		node(const value_type &o_, bool c_ = RED): o(o_), nodebase(nullptr, c_) {}
		node(const node &other):o(other.o), nodebase(other) {} 
		
	};
	nodebase* root = nullptr;
	size_t sz = 0;
	/**
	 * see BidirectionalIterator at CppReference for help.
	 *
	 * if there is anything wrong throw invalid_iterator.
	 *     like it = map.begin(); --it;
	 *       or it = map.end(); ++end();
	 */
	class const_iterator;
	class iterator {
	private:
		/**
		 * TODO add data members
		 *   just add whatever you want.
		 */
		
	public:
		node* p = nullptr;
		const map* container = nullptr;
		friend class map;
		iterator() {
			// TODO
		}
		iterator(node* p_, const map* con_):p(p_), container(con_) {}
		iterator(const iterator &other):p(other.p), container(other.container) {
			// TODO
		}
		/**
		 * TODO iter++
		 */
		iterator operator++(int) {
			iterator tmp = *this;
			if (!p) throw invalid_iterator();
			try {
				p = (node*)p->nextnode();
			}
			catch(...){ throw; }
			return tmp;
		}
		/**
		 * TODO ++iter
		 */
		iterator & operator++() {
			if (!p) throw invalid_iterator();
			try {
				p = (node*)p->nextnode();
			}
			catch(...) { throw; }
			return *this;
		}
		/**
		 * TODO iter--
		 */
		iterator operator--(int) {
			iterator tmp = *this;
			if (!p) throw invalid_iterator();
			try {
				p = (node*)p->prevnode();
			}
			catch(...){ throw; }
			return tmp;
		}
		/**
		 * TODO --iter
		 */
		iterator & operator--() {
			if (!p) throw invalid_iterator();
			try {
				p = (node*)p->prevnode();
			}
			catch(...) { throw; }
			return *this;
		}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		value_type & operator*() const { return p->o; }
		bool operator==(const iterator &rhs) const { 
			return p == rhs.p;
		}
		bool operator==(const const_iterator &rhs) const { 
			return p == rhs.p;
		}
		/**
		 * some other operator for iterator.
		 */
		bool operator!=(const iterator &rhs) const { return !((*this) == rhs); }
		bool operator!=(const const_iterator &rhs) const { return !((*this) == rhs); }

		/**
		 * for the support of it->first. 
		 * See <http://kelvinh.github.io/blog/2013/11/20/overloading-of-member-access-operator-dash-greater-than-symbol-in-cpp/> for help.
		 */
		value_type* operator->() const noexcept { return &(p->o); }
	};
	class const_iterator {
		// it should has similar member method as iterator.
		//  and it should be able to construct from an iterator.
		private:
			// data members.
			
		public:
			node* p = nullptr;
			const map* container;
			const_iterator() {
				// TODO
			}
			const_iterator(node* p_, const map* con_):p(p_), container(con_) {}
			const_iterator(const const_iterator &other):p(other.p), container(other.container) {
				// TODO
			}
			const_iterator(const iterator &other):p(other.p), container(other.container) {
				// TODO
			}
			// And other methods in iterator.
			// And other methods in iterator.
			// And other methods in iterator.
			/**
		 	* TODO iter++
			*/
			const_iterator operator++(int) {
				const_iterator tmp = *this;
				if (!p) throw invalid_iterator();
				try {
					p = (node*)p->nextnode();
				}
				catch(...){ throw; }
				return tmp;
			}
			/**
			* TODO ++iter
			*/
			const_iterator & operator++() {
				if (!p) throw invalid_iterator();
				try {
					p = (node*)p->nextnode();
				}
				catch(...) { throw; }
				return *this;
			}
			/**
			* TODO iter--
			*/
			const_iterator operator--(int) {
				const_iterator tmp = *this;
				if (!p) throw invalid_iterator();
				try {
					p = (node*)p->prevnode();
				}
				catch(...){ throw; }
				return tmp;
			}
			/**
			* TODO --iter
			*/
			const_iterator & operator--() {
				if (!p) throw invalid_iterator();
				try {
					p = (node*)p->prevnode();
				}
				catch(...) { throw; }
				return *this;
			}
			/**
			* a operator to check whether two iterators are same (pointing to the same memory).
			*/
			value_type & operator*() const { return p->o; }
			bool operator==(const iterator &rhs) const { 
				return p == rhs.p;
			}
			bool operator==(const const_iterator &rhs) const { 
				return p == rhs.p;
			}
			/**
			* some other operator for iterator.
			*/
			bool operator!=(const iterator &rhs) const { return !((*this) == rhs); }
			bool operator!=(const const_iterator &rhs) const { return !((*this) == rhs); }

			/**
			* for the support of it->first. 
			* See <http://kelvinh.github.io/blog/2013/11/20/overloading-of-member-access-operator-dash-greater-than-symbol-in-cpp/> for help.
			*/
			value_type* operator->() const noexcept { return &(p->o); }
	};
	/**
	 * TODO two constructors
	 */
	map() { root = new nodebase; }

	void copynode(nodebase* &a, const nodebase* const &b) {
		a = new node(((node*)b)->o, b->c);
		if (b->ls) copynode(a->ls, b->ls), a->ls->fa = a;
		if (b->rs) copynode(a->rs, b->rs), a->rs->fa = a;
	}

	map(const map &other):sz(other.sz) {
		root = new nodebase;
		if (other.root->ls) {
			copynode(root->ls, other.root->ls);
			root->ls->fa = root;
		}	
	}
	/**
	 * TODO assignment operator
	 */
	map & operator=(const map &other) {
		if (&other != this) {
			clear();
			sz = other.sz;
			if (other.root->ls) {
				copynode(root->ls, other.root->ls);
				root->ls->fa = root;
			}
		}
		return *this;
	}
	/**
	 * TODO Destructors
	 */
	~map() { this->clear(); delete root; }
	/**
	 * TODO
	 * access specified element with bounds checking
	 * Returns a reference to the mapped value of the element with key equivalent to key.
	 * If no such element exists, an exception of type `index_out_of_bound'
	 */
	nodebase* findnode(nodebase* p, const Key &key) const {
		while (p) {
			bool o1 = Compare()(key, ((node*)p)->o.first), o2 = Compare()(((node*)p)->o.first, key);
			if (!(o1 || o2)) return p;
			if (p->ls && o1) p = p->ls;
			else if (p->rs && o2) p = p->rs;
			else throw index_out_of_bound();
		}
		throw index_out_of_bound();
	}
	
	T & at(const Key &key) {
		try {
			return ((node*)findnode(root->ls, key))->o.second;
		}
		catch(...) {throw ;}
	}
	const T & at(const Key &key) const {
		try {
			return ((node*)findnode(root->ls, key))->o.second;
		}
		catch(...) {throw ;}
	}
	/**
	 * TODO
	 * access specified element 
	 * Returns a reference to the value that is mapped to a key equivalent to key,
	 *   performing an insertion if such key does not already exist.
	 */
	T & operator[](const Key &key) {
		try {
			return ((node*)findnode(root->ls, key))->o.second;
		}
		catch(...) { return insert(pair<Key, T>(key, T())).first->second; }
	}
	/**
	 * behave like at() throw index_out_of_bound if such key does not exist.
	 */
	const T & operator[](const Key &key) const {
		try {
			return ((node*)findnode(root->ls, key))->o.second;
		}
		catch(...) {throw ;}
	}
	/**
	 * return a iterator to the beginning
	 */
	iterator begin() {
		nodebase* p = root;
		while (p->ls) p = p->ls;
		return iterator((node*)p, this);
	}
	const_iterator cbegin() const {
		nodebase* p = root;
		while (p->ls) p = p->ls;
		return const_iterator((node*)p, this);
	}
	/**
	 * return a iterator to the end
	 * in fact, it returns past-the-end.
	 */
	iterator end() { return iterator((node*)root, this); }
	const_iterator cend() const { return const_iterator((node*)root, this); }
	/**
	 * checks whether the container is empty
	 * return true if empty, otherwise false.
	 */
	bool empty() const { return !sz; }
	/**
	 * returns the number of elements.
	 */
	size_t size() const { return sz; }
	/**
	 * clears the contents
	 */
	
	void deletenode(nodebase* p) {
		if (!p) return ;
		deletenode(p->ls);
		deletenode(p->rs);
		p->ls = p->rs = nullptr;
		delete (node*)p;
	}

	void clear() {
		deletenode(root->ls);
		sz = 0; root->ls = nullptr;
	}
	/**
	 * insert an element.
	 * return a pair, the first of the pair is
	 *   the iterator to the new element (or the element that prevented the insertion), 
	 *   the second one is true if insert successfully, or false.
	 */
	
	void L_rotate(nodebase* &p) {
		if (!p->rs) return ;
		nodebase* o = p->rs;
		p->rs = o->ls; 
		if (o->ls) o->ls->fa = p;
		o->ls = p; 
		if (p->fa->ls == p) p->fa->ls = o;
		else p->fa->rs = o;
		o->fa = p->fa;
		p->fa = o;
		p = o;
	}

	void R_rotate(nodebase* &p) {
		if (!p->ls) return ;
		nodebase* o = p->ls;
		p->ls = o->rs; 
		if (o->rs) o->rs->fa = p;
		o->rs = p;
		if (p->fa->ls == p) p->fa->ls = o;
		else p->fa->rs = o;
		o->fa = p->fa;
		p->fa = o;
		p = o;
	}

	pair<iterator, bool> insert(const value_type &value) {
		nodebase *p = root->ls, *q = root;
		bool op = false;
		while (p) {
			bool o1 = Compare()(((node*)p)->o.first, value.first), o2 = Compare()(value.first, ((node*)p)->o.first);
			if (!(o1 || o2)) return pair<iterator, bool>(iterator((node*)p, this), false);
			if (o2) q = p, p = p->ls, op = false;
			else q = p, p = p->rs, op = true;
		}
		p = new node(value, RED); 
		++sz;
		p->fa = q; 
		op? q->rs = p:q->ls = p;
		return pair<iterator, bool>(iterator((node*)p, this), true);
	}

	/**
	 * erase the element at pos.
	 *
	 * throw if pos pointed to a bad element (pos == this->end() || pos points an element out of this)
	 */

	void erase(iterator pos) {
		if (pos.container != this || pos.p == root) throw exception();
		nodebase *q = root, *p = root->ls;
		bool op = false;
		while (p) {
			//std::cout << "p=" << p << '\n';
			bool o1 = Compare()(((node*)p)->o.first, pos->first), o2 = Compare()(pos->first, ((node*)p)->o.first);
			//std::cout << "p=" << p << ' ' << q << '\n';
			if (!(o1 || o2)) {
				if (!p->ls && !p->rs) { op? q->rs = nullptr:q->ls = nullptr; delete (node*)p; --sz; return ; }
				else {
					if (p->ls && (!p->rs || Compare()(((node*)p->ls)->o.first, ((node*)p->rs)->o.first))) {	
						R_rotate(p); 
						q = p, p = p->rs, op = true;
					}
					else {
						L_rotate(p);
						q = p, p = p->ls, op = false;
					}
				}
			}
			else {
				q = p;
				if (o1) p = p->rs, op = true;
				else p = p->ls, op = false;
			}
		}
		throw exception();
	}
	/**
	 * Returns the number of elements with key 
	 *   that Compare()s equivalent to the specified argument,
	 *   which is either 1 or 0 
	 *     since this container does not allow duplicates.
	 * The default method of check the equivalence is !(a < b || b > a)
	 */
	size_t count(const Key &key) const {
		try{
			findnode(root->ls, key);
			return 1;
		}
		catch(...){ return 0; }
		
	}
	/**
	 * Finds an element with key equivalent to key.
	 * key value of the element to search for.
	 * Iterator to an element with key equivalent to key.
	 *   If no such element is found, past-the-end (see end()) iterator is returned.
	 */
	iterator find(const Key &key) {
		try{
			return iterator((node*)findnode(root->ls, key), this);
		}
		catch(...){ return this->end();}
	}
	const_iterator find(const Key &key) const {
		try{
			return iterator((node*)findnode(root->ls, key), this);
		}
		catch(...){ return this->cend();}
	}
};

}

#endif
