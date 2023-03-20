#ifndef SJTU_PRIORITY_QUEUE_HPP
#define SJTU_PRIORITY_QUEUE_HPP

#include <cstddef>
#include <functional>
#include "exceptions.hpp"

namespace sjtu {

/**
 * a container like std::priority_queue which is a heap internal.
 */
template<typename T, class Compare = std::less<T>>
class priority_queue {
public:
	/**
	 * TODO constructors
	 */
	class node {
	public:
		T val;
		int d = 0;
		node *ls = nullptr, *rs = nullptr;
		node(const T &e):val(e) {}
		node(const node &p):val(p.val) {}
	};
	node* root = nullptr;
	int sz = 0;

	priority_queue() {}
	void copyNode(node* &now, node* other) {
		now = new node(*other);
		if (other->ls) copyNode(now->ls, other->ls);
		if (other->rs) copyNode(now->rs, other->rs);
	} 
	priority_queue(const priority_queue &other):sz(other.sz) {
		copyNode(root, other.root);
	}
	/**
	 * TODO deconstructor
	 */
	void deleteNode(node* &p) {
		if (!p) return ;
		deleteNode(p->ls);
		deleteNode(p->rs);
		delete p;
	}
	~priority_queue() {
		deleteNode(root);
	}
	/**
	 * TODO Assignment operator
	 */
	priority_queue &operator=(const priority_queue &other) {
		if (&other == this) return *this;
		sz = other.sz;
		deleteNode(root);
		copyNode(root, other.root);
		return *this;
	}
	/**
	 * get the top of the queue.
	 * @return a reference of the top element.
	 * throw container_is_empty if empty() returns true;
	 */
	const T & top() const {
		if (!sz) throw container_is_empty();
		return root->val;
	}
	/**
	 * TODO
	 * push new element to the priority queue.
	 */
	
	node* merge(node* p1, node* p2) {
		//std::cout << "ok" << '\n';
		if (!p1) return p2;
		if (!p2) return p1;
		try {
			if (Compare()(p1->val, p2->val)) std::swap(p1, p2);
			p1->rs = merge(p1->rs, p2);
		}
		catch (...) {
			throw ;
		}
		if ((p1->ls && p1->rs && p1->ls->d < p1->rs->d) || (!p1->ls && p1->rs)) std::swap(p1->ls, p1->rs);
		if (p1->rs) p1->d = p1->rs->d + 1;
		else p1->d = 1;
		return p1;
	}

	void push(const T &e) {
		++sz;
		node* p = new node(e);
		try {
			root = merge(root, p);
		}
		catch (...) {
			delete p;
		}
	}
	/**
	 * TODO
	 * delete the top element.
	 * throw container_is_empty if empty() returns true;
	 */
	void pop() {
		if (!sz) throw container_is_empty();
		node* tmp = merge(root->ls, root->rs);
		delete root;
		root = tmp;
		--sz;
	}
	/**
	 * return the number of the elements.
	 */
	size_t size() const {
		return sz;
	}
	/**
	 * check if the container has at least an element.
	 * @return true if it is empty, false if it has at least an element.
	 */
	bool empty() const {
		return !sz;
	}
	/**
	 * merge two priority_queues with at least O(logn) complexity.
	 * clear the other priority_queue.
	 */
	void merge(priority_queue &other) {
		root = merge(root, other.root);
		sz += other.sz;
		other.root = nullptr;
		other.sz = 0;
	}
};

}

#endif
